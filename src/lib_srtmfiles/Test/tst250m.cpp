//
// $Id$

#include <martiniquehm/srtm_files.h>

using namespace MartiniqueHM;

int main (int argc, char* argv[])
{
    COPYRIGHT("tst250m", "0.1");

	SRTMbin250m s250;
	assabib::FileName fn("/opt/Depot/SRTM/250/W_ASCII/srtm_w_250m.bin");
	s250.open(fn);
	s250.SetLimits(-60.7, 14.9, -61.5, 14.2);
	s250.info();

	// output file
	ofstream oud("roi.xyz");

	while ( s250.Next() ) {
// 		cout<<s250.XLon()<<' '<<s250.YLat()<<' '<<s250.ZCur()<<endl;
		if ( s250.IsValid() ) {
			oud<<s250.XLon()<<' '<<s250.YLat()<<' '<<s250.ZCur()<<'\n';
		}
	}
	oud.close();

	return 0;
}
