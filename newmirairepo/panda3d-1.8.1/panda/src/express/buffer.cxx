// Filename: buffer.cxx
// Created by:  mike (09Jan97)
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

#include "buffer.h"

////////////////////////////////////////////////////////////////////
//     Function: Buffer::Constructor
//       Access: Public
//  Description:
////////////////////////////////////////////////////////////////////
Buffer::
Buffer(int size) {
  _length = size;
  _buffer = (char *)PANDA_MALLOC_ARRAY(_length);
}

////////////////////////////////////////////////////////////////////
//     Function: Buffer::Destructor
//       Access: Public
//  Description:
////////////////////////////////////////////////////////////////////
Buffer::
~Buffer() {
  PANDA_FREE_ARRAY(_buffer);
}

