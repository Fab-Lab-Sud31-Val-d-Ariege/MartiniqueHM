//
// $Id$

#include <martiniquehm/stl_writer.h>

namespace MartiniqueHM {

	// Standard info function.
	inline void STLWriter::info(ostream& s, bool debug) const
	{
		s<<"Destination file ="<<m_fn.FullName()<<'\n';
		s<<"Stream status =";
		if(m_oud) {
			s<<"open";
		} else {
			s<<"close";
		}
		s<<'\n';
	}



	// Standard info function.
	inline void STLWriterAscii::info(ostream& s, bool debug) const
	{
		s<<"[STLWriterAscii]\n";
		STLWriter::info(s, debug);
	}

	// stl header
	inline void STLWriterAscii::write_header(size_t nbt) const
	{
		m_oud<<"solid "<<m_fn.FullName()<<'\n';
	}

	// stl data
	inline void STLWriterAscii::write_data(const STLTriangle& tr) const
	{
		m_oud<<tr;
	}

	//  stl trailer, if any
	inline void STLWriterAscii::write_trailer() const
	{
		m_oud<<"endsolid "<<m_fn.FullName()<<'\n';
	}



	// Standard info function.
	void STLWriterBinary::info(ostream& s, bool debug) const
	{
		s<<"[STLWriterBinary]\n";
		STLWriter::info(s, debug);
	}

	// stl header
	/*! UINT8[80] – Header
	 *  UINT32 – Number of triangles
	 */
	void STLWriterBinary::write_header(size_t nbt) const
	{
		char hh[80];
		memset(hh, 0, 80);
		memccpy(hh, m_fn.Name().c_str(), 0, 79);
		m_oud.write(hh, 80);
		uint32_t nn = static_cast<uint32_t>(nbt);
		m_oud.write(reinterpret_cast<char*>(&nn), sizeof(uint32_t));
	}

	// stl data
	void STLWriterBinary::write_data(const STLTriangle& tr) const
	{
		tr.write(m_oud);
	}

	//  stl trailer, if any
	void STLWriterBinary::write_trailer() const
	{}


} // namespace
