//
// $Id: matrix_io.inl 1296 2005-12-14 08:50:45Z micheli $

//******* matrix member functions ***********************************
template <class T>
inline void
matrix<T>::write(ostream& out) const
{
    TRACE("matrix<T>::write(ostream)");
    out<<"<XSIL Type=\"matrix_T\" Name=\""<<m_name<<"\">\n";
    writeXSIL_Head(out);
    writeXSIL_Data(out);
    writeXSIL_Foot(out);
    out<<"</XSIL>"<<endl;
}

template <class T>
inline void
matrix<T>::writeXSIL_Head(ostream& out) const
{
    TRACE("matrix<T>::writeXSIL_Head(.)");
    out<<"<Param Name=\"Name\">"<<m_name<<"</Param>\n";
    out<<"<Param Name=\"FullSize\">"<<m_size<<"</Param>\n";
    out<<"<Param Name=\"ValueType\">"<< typeid(T).name() <<"</Param>\n";
}

/*!  data inbetween the Table tags, Column and stream included. */
template <class T>
inline void
matrix<T>::writeXSIL_Data(ostream& out) const
{
    TRACE("matrix<T>::writeXSIL_Data(.)");
    out<<"<Array Name=\""<<m_name<<"\">\n";
    out<<"<Dim Name=\"Rows\">"<<m_r<<"</Dim>\n";
    out<<"<Dim Name=\"Columns\">"<<m_c<<"</Dim>\n";
    out<<"<Stream Type=\"Local\" Encoding=\"Text\" Delimiter=\" \">";
    for(size_t ii=0; ii<m_size; ++ii) {
        out<<m_v[ii]<<' ';
        if ( (ii % m_c) == (m_c-1) ) out<<'\n';
    }
    out<<"</Stream>\n";
    out<<"</Array>"<<endl;
}

// write footer of XSIL format
template <class T>
inline void 
matrix<T>::writeXSIL_Foot(ostream& out) const
{
    TRACE("matrix<T>::writeXSIL_Foot(ostream)");
}
