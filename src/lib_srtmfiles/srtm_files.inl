//
// $Id$

		//! default construct
		SRTMFiles();
		//! Dtor
		~SRTMFiles();
		//! set the rectangle boundary
		void SetLimits(double east, double north, double west, double south);
		//! Standard info function.
		void info(ostream& s=cout, bool debug=false) const;
