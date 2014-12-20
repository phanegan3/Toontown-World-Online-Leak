// Filename: dcTypedef.cxx
// Created by:  drose (17Jun04)
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

#include "dcTypedef.h"
#include "dcParameter.h"
#include "dcSimpleParameter.h"
#include "dcindent.h"

////////////////////////////////////////////////////////////////////
//     Function: DCTypedef::Constructor
//       Access: Public
//  Description: The DCTypedef object becomes the owner of the
//               supplied parameter pointer and will delete it upon
//               destruction.
////////////////////////////////////////////////////////////////////
DCTypedef::
DCTypedef(DCParameter *parameter, bool implicit) :
  _parameter(parameter),
  _bogus_typedef(false),
  _implicit_typedef(implicit),
  _number(-1)
{
}

////////////////////////////////////////////////////////////////////
//     Function: DCTypedef::Constructor
//       Access: Public
//  Description: Creates a bogus typedef reference.
////////////////////////////////////////////////////////////////////
DCTypedef::
DCTypedef(const string &name) :
  _parameter(new DCSimpleParameter(ST_invalid)),
  _bogus_typedef(true),
  _implicit_typedef(false),
  _number(-1)
{
  _parameter->set_name(name);
}

////////////////////////////////////////////////////////////////////
//     Function: DCTypedef::Destructor
//       Access: Public, Virtual
//  Description:
////////////////////////////////////////////////////////////////////
DCTypedef::
~DCTypedef() {
  delete _parameter;
}

////////////////////////////////////////////////////////////////////
//     Function: DCTypedef::get_number
//       Access: Published
//  Description: Returns a unique index number associated with this
//               typedef definition.  This is defined implicitly when
//               the .dc file(s) are read.
////////////////////////////////////////////////////////////////////
int DCTypedef::
get_number() const {
  return _number;
}

////////////////////////////////////////////////////////////////////
//     Function: DCTypedef::get_name
//       Access: Published
//  Description: Returns the name of this typedef.
////////////////////////////////////////////////////////////////////
const string &DCTypedef::
get_name() const {
  return _parameter->get_name();
}

////////////////////////////////////////////////////////////////////
//     Function: DCTypedef::get_description
//       Access: Published
//  Description: Returns a brief decription of the typedef, useful for
//               human consumption.
////////////////////////////////////////////////////////////////////
string DCTypedef::
get_description() const {
  ostringstream strm;
  _parameter->output(strm, true);
  return strm.str();
}

////////////////////////////////////////////////////////////////////
//     Function: DCTypedef::is_bogus_typedef
//       Access: Public
//  Description: Returns true if the typedef has been flagged as a bogus
//               typedef.  This is set for typedefs that are generated by
//               the parser as placeholder for missing typedefs, as
//               when reading a partial file; it should not occur in a
//               normal valid dc file.
////////////////////////////////////////////////////////////////////
bool DCTypedef::
is_bogus_typedef() const {
  return _bogus_typedef;
}

////////////////////////////////////////////////////////////////////
//     Function: DCTypedef::is_implicit_typedef
//       Access: Public
//  Description: Returns true if the typedef has been flagged as an
//               implicit typedef, meaning it was created for a
//               DCClass that was referenced inline as a type.
////////////////////////////////////////////////////////////////////
bool DCTypedef::
is_implicit_typedef() const {
  return _implicit_typedef;
}

////////////////////////////////////////////////////////////////////
//     Function: DCTypedef::make_new_parameter
//       Access: Public
//  Description: Returns a newly-allocated DCParameter object that
//               uses the same type as that named by the typedef.
////////////////////////////////////////////////////////////////////
DCParameter *DCTypedef::
make_new_parameter() const {
  DCParameter *new_parameter = _parameter->make_copy();
  new_parameter->set_name(string());
  new_parameter->set_typedef(this);
  return new_parameter;
}

////////////////////////////////////////////////////////////////////
//     Function: DCTypedef::set_number
//       Access: Public
//  Description: Assigns the unique number to this typedef.  This is
//               normally called only by the DCFile interface as the
//               typedef is added.
////////////////////////////////////////////////////////////////////
void DCTypedef::
set_number(int number) {
  _number = number;
}

////////////////////////////////////////////////////////////////////
//     Function : DCTypedef::output
//       Access : Public, Virtual
//  Description : Write a string representation of this instance to
//                <out>.
////////////////////////////////////////////////////////////////////
void DCTypedef::
output(ostream &out, bool brief) const {
  out << "typedef ";
  _parameter->output(out, false);
}

////////////////////////////////////////////////////////////////////
//     Function: DCTypedef::write
//       Access: Public, Virtual
//  Description: 
////////////////////////////////////////////////////////////////////
void DCTypedef::
write(ostream &out, bool brief, int indent_level) const {
  indent(out, indent_level)
    << "typedef ";

  // We need to preserve the parameter name in the typedef (this is
  // the typedef name); hence, we pass brief = false to output().
  _parameter->output(out, false);
  out << ";";

  if (!brief) {
    out << "  // typedef " << _number;
  }
  out << "\n";
}
