//
// $Id: matrix_fcts.inl 1600 2010-08-20 09:21:55Z micheli $

//******* matrix member functions ***********************************
void
HMap::info(ostream& s, bool debug) const
{
    s<<"[ object HMap ]\n"
        <<"Name  = \""<< m_name <<"\"\n"
        <<"nRows = "<<m_r<<'\n'
        <<"nCols = "<<m_c<<'\n'
        <<"fSize = "<<m_size<<'\n'
        <<"Square size = "<<m_sqsize<<'\n'
		<<"No data = "<<m_na<<'\n'
		<<"Bottom altitude = "<<m_bottom<<endl;

	if ( debug ) {
		if ( m_size >= 10 ) {
			s<<"Data [0:9] :\n";
			for(size_t ii=0; ii<10; ++ii) {
				s<<m_v[ii]<<' ';
				if ( (ii % m_c) == (m_c-1) ) s<<'\n';
			}
		}
	}
}

