// Filename: odeJointGroup.cxx
// Created by:  joswilso (27Dec06)
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

#include "config_ode.h"
#include "odeJointGroup.h"

TypeHandle OdeJointGroup::_type_handle;

OdeJointGroup::
OdeJointGroup() :
  _id(dJointGroupCreate(0)) {
}

OdeJointGroup::
~OdeJointGroup() {
}

void OdeJointGroup::
destroy() {
  dJointGroupDestroy(_id);
}
