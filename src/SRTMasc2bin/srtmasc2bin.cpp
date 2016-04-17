//
// $Id$

#include <srtmasc2bin.h>
#include <cmdline.h>

gengetopt_args_info args_info;

// $ -> head -6 srtm_w_250m.asc
// ncols         72010
// nrows         57610
// xllcorner     -180.01041653225
// yllcorner     -60.01041666665
// cellsize      0.00208333333
// NODATA_value  -9999

int main (int argc, char* argv[])
{
	// Analysis of the command line arguments, exit if error
	if ( cmdline_parser(argc, argv, &args_info) != 0 ) exit(1);

	if (! args_info.quiet_flag) { COPYRIGHT("strmasc2bin", CMDLINE_PARSER_VERSION); }

	// If no file given, print help and exit
	if ( args_info.inputs_num != 1 ) {
		cmdline_parser_print_help();
		exit(0);
	}

	// opening data file
	ifstream ind(args_info.inputs[0]);
	if (!ind) ERROPENF(args_info.inputs[0]);

	ofstream oud;
	if (args_info.output_given) {
		oud.open(args_info.output_arg, ios::out | ios::binary);
		if(!oud) ERROPENF(args_info.output_arg);
	} else {
		assabib::FileName oudfn (args_info.inputs[0]);
		oudfn.SetExt("bin");
		oud.open(oudfn.FullName(), ios::out | ios::binary);
		if(!oud) ERROPENF(oudfn.FullName().c_str());
	}

	// read and parse 6 first lines
	string line;
	// ncols         72010
	getline(ind, line, '\n');
	size_t pos = line.find_last_of(' ');
	size_t ncols = atol(&line.c_str()[++pos]);
	WATCH(ncols);
	oud.write(reinterpret_cast<char*>(&ncols), sizeof(ncols));

	// nrows         57610
	getline(ind, line, '\n');
	pos = line.find_last_of(' ');
	size_t nrows = atol(&line.c_str()[++pos]);
	WATCH(nrows);
	oud.write(reinterpret_cast<char*>(&nrows), sizeof(nrows));

	// xllcorner     -180.01041653225
	getline(ind, line, '\n');
	pos = line.find_last_of(' ');
	double xllcorner = atof(&line.c_str()[++pos]);
	WATCH(xllcorner);
	oud.write(reinterpret_cast<char*>(&xllcorner), sizeof(xllcorner));

	// yllcorner     -60.01041666665
	getline(ind, line, '\n');
	pos = line.find_last_of(' ');
	double yllcorner = atof(&line.c_str()[++pos]);
	WATCH(yllcorner);
	oud.write(reinterpret_cast<char*>(&yllcorner), sizeof(yllcorner));

	// cellsize      0.00208333333
	getline(ind, line, '\n');
	pos = line.find_last_of(' ');
	double cellsize = atof(&line.c_str()[++pos]);
	WATCH(cellsize);
	oud.write(reinterpret_cast<char*>(&cellsize), sizeof(cellsize));

	// NODATA_value  -9999
	getline(ind, line, '\n');
	pos = line.find_last_of(' ');
	long na = atol(&line.c_str()[++pos]);
	WATCH(na);
	oud.write(reinterpret_cast<char*>(&na), sizeof(na));

	// to split line on spaces
	assabib::CSVline csvl(true, ' ');
	// loop on rows
	for (size_t ii = 0 ; ii < nrows ; ++ii ) {
		if ( (ii % 100) == 0 ) {
			cout<<'.';
			cout.flush();
		}
		// get line and keep cols wc to ec
		getline(ind, line, '\n');
		if(ind.fail()) break;
		// warning : there is an extra field with a CR at the end of the line
		if(!line.empty() && *line.rbegin() == '\r') {
			line.erase( line.length()-1, 1);
		}
		// and an extra space
		if(!line.empty() && *line.rbegin() == ' ') {
			line.erase( line.length()-1, 1);
		}
		// analyse the line
		csvl.split(line);
		csvl.remove_empty();
		if ( csvl.size() < ncols ) {
			WATCH(csvl.size());
			WATCH(csvl[0]);
			WATCH(csvl[ncols-2]);
			WATCH(csvl[ncols-1]);
		}

		for (size_t jj = 0 ; jj < ncols ; ++jj ) {
			int16_t height = static_cast<int16_t>(stoi(csvl[jj]));
			oud.write(reinterpret_cast<char*>(&height), sizeof(height));
		}
	}

	ind.close();
	cout<<"\nDone\n";
    return 0;
}

//./tst -f totofile.dat --outDir=~/Data/ -e essai.ini -q file1.dat file2.dat
