//
// $Id$

#include <main.h>
#include <cmdline.h>

gengetopt_args_info args_info;

// $ -> head -6 srtm_w_250m.asc
// ncols         72010
// nrows         57610
// xllcorner     -180.01041653225
// yllcorner     -60.01041666665
// cellsize      0.00208333333
// NODATA_value  -9999

// xlrcorner
// -180.01041653225 + 72010 * 0.00208333333 = -29.98958
// yulcorner
//  -60.01041666665 + 57610 * 0.00208333333 =  60.01042

int main (int argc, char* argv[])
{
    COPYRIGHT("test AppConfig", "0.1");
	// Analysis of the command line arguments, exit if error
	if ( cmdline_parser(argc, argv, &args_info) != 0 ) exit(1);

	if (! args_info.quiet_flag) { COPYRIGHT("xtractFasc", CMDLINE_PARSER_VERSION); }

	// If no file given, print help and exit
	if ( args_info.inputs_num != 1 ) {
		cmdline_parser_print_help();
		exit(0);
	}

	// opening data file
	ifstream ind(args_info.inputs[0]);
	if (! ind) ERROPENF(args_info.inputs[0]);

	// read and parse 6 first lines
	string line;
	// ncols         72010
	getline(ind, line, '\n');
	size_t pos = line.find_last_of(' ');
	size_t ncols = atol(&line.c_str()[++pos]);
	WATCH(ncols);
	// nrows         57610
	getline(ind, line, '\n');
	pos = line.find_last_of(' ');
	size_t nrows = atol(&line.c_str()[++pos]);
	WATCH(nrows);
	// xllcorner     -180.01041653225
	getline(ind, line, '\n');
	pos = line.find_last_of(' ');
	double xllcorner = atof(&line.c_str()[++pos]);
	WATCH(xllcorner);
	// yllcorner     -60.01041666665
	getline(ind, line, '\n');
	pos = line.find_last_of(' ');
	double yllcorner = atof(&line.c_str()[++pos]);
	WATCH(yllcorner);
	// cellsize      0.00208333333
	getline(ind, line, '\n');
	pos = line.find_last_of(' ');
	double cellsize = atof(&line.c_str()[++pos]);
	WATCH(cellsize);
	// NODATA_value  -9999
	getline(ind, line, '\n');
	pos = line.find_last_of(' ');
	long na = atol(&line.c_str()[++pos]);
	WATCH(na);

	// compute limits of rectangle
	double ww = args_info.wlimit_arg;
	double ee = args_info.elimit_arg;
	double nn = args_info.nlimit_arg;
	double ss = args_info.slimit_arg;

	// row start
	double NN = yllcorner +  nrows * cellsize;
	size_t nr = (NN-nn)/cellsize;
	WATCH(nr);
	// row end
	size_t sr = (NN-ss)/cellsize;
	WATCH(sr);
	// col start
	double WW = xllcorner;
	size_t wc = fabs(WW-ww)/cellsize;
	WATCH(wc);
	// col end
	size_t ec = fabs(WW-ee)/cellsize;
	WATCH(ec);

	// Storage area
	size_t cc = ec-wc;
	size_t rr = sr-nr;
	cout <<"Map ("<<rr<<'x'<<cc<<")\n";
	HMap map(args_info.output_arg, rr, cc);
	map = na-1;

	// count rows until nr
	size_t ir=0;
	for (ir = 0 ; ir < nr ; ++ir ) {
		if ( (ir % 100) == 0 ) {
			cout<<'-';
			cout.flush();
		}
		getline(ind, line, '\n');
	}

	// to split line on spaces
	assabib::CSVline csvl(true, ' ');
	size_t rowi = 0;
	// count cols until sr
	for (size_t ii = ir ; ii < sr ; ++ii ) {
		if ( (ii % 100) == 0 ) {
			cout<<'.';
			cout.flush();
		}
		// get line and keep cols wc to ec
		getline(ind, line, '\n');
		size_t countspace = 0;
		size_t start = 0;
		size_t stop = 0;
		for ( size_t jj = 0 ; jj < line.length() ; ++jj ) {
			if ( line[jj] == ' ' ) {
				++countspace;
				if ( countspace == wc ) start=jj;
				if ( countspace == ec ) { stop=jj; break;}
			}
		}
		if ( stop == 0 ) stop = line.length();
		string keptl = line.substr(start, stop-start);

		// analyse the line
		csvl.split(keptl);
		csvl.remove_empty();
		if ( csvl.size() != cc ) WATCH(csvl.size());

		for (size_t it = 0 ; it < cc ; ++it ) {
			map(rowi, it) = stod(csvl[it]);
		}
		++rowi;
	}

	// Transform matrix
	// set border for the coasts
	double zbottom = -5;
	double border = zbottom/args_info.zfactor_arg;
	// row wise, start of data
	for ( size_t ii = 0 ; ii < rr ; ++ii ) {
		for ( size_t jj = 0 ; jj < cc-1 ; ++jj ) {
			if ( map(ii, jj) == na && map(ii, jj+1) != na) map(ii, jj) = border;
		}
	}
	// row wise, end of data
	for ( size_t ii = 0 ; ii < rr ; ++ii ) {
		for ( size_t jj = cc-1 ; jj > 1 ; --jj ) {
			if ( map(ii, jj) == na && map(ii, jj-1) != na) map(ii, jj) = border;
		}
	}

	// colwise, start of data
	for ( size_t jj = 0 ; jj < cc ; ++jj ) {
		for ( size_t ii = 0 ; ii < rr-1 ; ++ii ) {
			if ( map(ii, jj) == na && map(ii+1, jj) != na) map(ii, jj) = border;
		}
	}

	// colwise, end of data
	for ( size_t jj = 0 ; jj < cc ; ++jj ) {
		for ( size_t ii = rr-1 ; ii > 1 ; --ii ) {
			if ( map(ii, jj) == na && map(ii-1, jj) != na) map(ii, jj) = border;
		}
	}

	// write matrix squized to useful area, xyz format
		assabib::FileName oudfn (args_info.output_arg);
		oudfn.SetExt("xyz");
		ofstream oud(oudfn.FullName());
		if(!oud) ERROPENF(oudfn.FullName().c_str());
		for ( size_t ii = 0 ; ii < rr ; ++ii ) {
			for ( size_t jj = 0 ; jj < cc-1 ; ++jj ) {
				if ( map(ii, jj) != na ) oud<<ii<<' '<<jj<<' '<<map(ii, jj)*args_info.zfactor_arg<<'\n';
			}
		}
		oud.close();

	// write matrix in stl format
	oudfn.SetExt("stl");
	ofstream stl(oudfn.FullName());
	if(!stl) ERROPENF(oudfn.FullName().c_str());
	map.WriteSTL(stl);
	stl.close();

	ind.close();
	cout<<"\nDone\n";

    return 0;
}
