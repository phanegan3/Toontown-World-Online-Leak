// Filename: fltVertexList.cxx
// Created by:  drose (25Aug00)
//
////////////////////////////////////////////////////////////////////
//
// PANDA 3D SOFTWARE
// Copyright (c) Carnegie Mellon University.  All rights reserved.
//
// All use of this software is subject to the terms of the revised BSD
// license.  You should have received a copy of this license along
// with this source code in a file named "LICENSE."
//
////////////////////////////////////////////////////////////////////

#include "fltVertexList.h"
#include "fltRecordReader.h"
#include "fltRecordWriter.h"
#include "fltHeader.h"

TypeHandle FltVertexList::_type_handle;

////////////////////////////////////////////////////////////////////
//     Function: FltVertexList::Constructor
//       Access: Public
//  Description:
////////////////////////////////////////////////////////////////////
FltVertexList::
FltVertexList(FltHeader *header) : FltRecord(header) {
}

////////////////////////////////////////////////////////////////////
//     Function: FltVertexList::get_num_vertices
//       Access: Public
//  Description: Returns the number of vertices in this vertex list.
////////////////////////////////////////////////////////////////////
int FltVertexList::
get_num_vertices() const {
  return _vertices.size();
}

////////////////////////////////////////////////////////////////////
//     Function: FltVertexList::get_vertex
//       Access: Public
//  Description: Returns the nth vertex of this vertex list.
////////////////////////////////////////////////////////////////////
FltVertex *FltVertexList::
get_vertex(int n) const {
  nassertr(n >= 0 && n < (int)_vertices.size(), 0);
  return _vertices[n];
}

////////////////////////////////////////////////////////////////////
//     Function: FltVertexList::clear_vertices
//       Access: Public
//  Description: Removes all vertices from this vertex list.
////////////////////////////////////////////////////////////////////
void FltVertexList::
clear_vertices() {
  _vertices.clear();
}

////////////////////////////////////////////////////////////////////
//     Function: FltVertexList::add_vertex
//       Access: Public
//  Description: Adds a new vertex to the end of the vertex list.
////////////////////////////////////////////////////////////////////
void FltVertexList::
add_vertex(FltVertex *vertex) {
  _header->add_vertex(vertex);
  _vertices.push_back(vertex);
}

////////////////////////////////////////////////////////////////////
//     Function: FltVertexList::output
//       Access: Public
//  Description: Writes a quick one-line description of the record, but
//               not its children.  This is a human-readable
//               description, primarily for debugging; to write a flt
//               file, use FltHeader::write_flt().
////////////////////////////////////////////////////////////////////
void FltVertexList::
output(ostream &out) const {
  out << _vertices.size() << " vertices";
}

////////////////////////////////////////////////////////////////////
//     Function: FltVertexList::extract_record
//       Access: Protected, Virtual
//  Description: Fills in the information in this bead based on the
//               information given in the indicated datagram, whose
//               opcode has already been read.  Returns true on
//               success, false if the datagram is invalid.
////////////////////////////////////////////////////////////////////
bool FltVertexList::
extract_record(FltRecordReader &reader) {
  if (!FltRecord::extract_record(reader)) {
    return false;
  }

  nassertr(reader.get_opcode() == FO_vertex_list, false);
  DatagramIterator &iterator = reader.get_iterator();

  _vertices.clear();
  while (iterator.get_remaining_size() >= 4) {
    int vertex_offset = iterator.get_be_int32();
    _vertices.push_back(_header->get_vertex_by_offset(vertex_offset));
  }

  check_remaining_size(iterator);
  return true;
}

////////////////////////////////////////////////////////////////////
//     Function: FltVertexList::build_record
//       Access: Protected, Virtual
//  Description: Fills up the current record on the FltRecordWriter with
//               data for this record, but does not advance the
//               writer.  Returns true on success, false if there is
//               some error.
////////////////////////////////////////////////////////////////////
bool FltVertexList::
build_record(FltRecordWriter &writer) const {
  if (!FltRecord::build_record(writer)) {
    return false;
  }

  writer.set_opcode(FO_vertex_list);
  Datagram &datagram = writer.update_datagram();

  Vertices::const_iterator vi;
  for (vi = _vertices.begin(); vi != _vertices.end(); ++vi) {
    datagram.add_be_uint32(_header->get_offset_by_vertex(*vi));
  }

  return true;
}
