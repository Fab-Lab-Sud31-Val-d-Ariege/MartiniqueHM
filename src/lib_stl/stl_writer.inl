//
// $Id$

// void construct
inline STLWriter::STLWriter()
{}

// Ordinary contructor
inline STLWriter::STLWriter(const string& filename)
{
	m_fn = filename;
}

// Dtor
inline STLWriter::~STLWriter()
{
	if(m_oud) m_oud.close();
}

// return the file name
inline assabib::FileName STLWriter::FileName() const
{
	return m_fn;
}

// set the file name
inline assabib::FileName& STLWriter::FileName()
{
	return m_fn;
}


// void construct
inline STLWriterAscii::STLWriterAscii()
{}

// Ordinary contructor
inline STLWriterAscii::STLWriterAscii(const string& filename) : STLWriter(filename)
{
	m_oud.open(m_fn.FullName());
	if(!m_oud) ERROPENF(m_fn.FullName().c_str());
}

// Dtor
inline STLWriterAscii::~STLWriterAscii()
{}



// void construct
inline STLWriterBinary::STLWriterBinary()
{}

// Ordinary contructor
inline STLWriterBinary::STLWriterBinary(const string& filename) : STLWriter(filename)
{
	m_oud.open(m_fn.FullName(), std::ofstream::binary);
	if(!m_oud) ERROPENF(m_fn.FullName().c_str());
}

// Dtor
inline STLWriterBinary::~STLWriterBinary()
{}
