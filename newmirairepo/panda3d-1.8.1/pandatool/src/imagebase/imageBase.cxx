// Filename: imageBase.cxx
// Created by:  drose (19Jun00)
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

#include "imageBase.h"

////////////////////////////////////////////////////////////////////
//     Function: ImageBase::Constructor
//       Access: Public
//  Description:
////////////////////////////////////////////////////////////////////
ImageBase::
ImageBase() {
}


////////////////////////////////////////////////////////////////////
//     Function: ImageBase::post_command_line
//       Access: Protected, Virtual
//  Description:
////////////////////////////////////////////////////////////////////
bool ImageBase::
post_command_line() {
  return ProgramBase::post_command_line();
}

