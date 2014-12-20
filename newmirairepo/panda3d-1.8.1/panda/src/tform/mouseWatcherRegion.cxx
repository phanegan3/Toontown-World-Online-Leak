// Filename: mouseWatcherRegion.cxx
// Created by:  drose (13Jul00)
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

#include "mouseWatcherRegion.h"

#include "indent.h"


TypeHandle MouseWatcherRegion::_type_handle;

////////////////////////////////////////////////////////////////////
//     Function: MouseWatcherRegion::output
//       Access: Published
//  Description:
////////////////////////////////////////////////////////////////////
void MouseWatcherRegion::
output(ostream &out) const {
  out << get_name() << " lrbt = " << _frame;
}

////////////////////////////////////////////////////////////////////
//     Function: MouseWatcherRegion::write
//       Access: Published
//  Description:
////////////////////////////////////////////////////////////////////
void MouseWatcherRegion::
write(ostream &out, int indent_level) const {
  indent(out, indent_level)
    << get_name() << " lrbt = " << _frame
    << ", sort = " << _sort << "\n";
}

////////////////////////////////////////////////////////////////////
//     Function: MouseWatcherRegion::enter_region
//       Access: Public, Virtual
//  Description: This is a callback hook function, called whenever the
//               mouse enters the region.  The mouse is only
//               considered to be "entered" in one region at a time;
//               in the case of nested regions, it exits the outer
//               region before entering the inner one.
////////////////////////////////////////////////////////////////////
void MouseWatcherRegion::
enter_region(const MouseWatcherParameter &) {
}

////////////////////////////////////////////////////////////////////
//     Function: MouseWatcherRegion::exit_region
//       Access: Public, Virtual
//  Description: This is a callback hook function, called whenever the
//               mouse exits the region.  The mouse is only considered
//               to be "entered" in one region at a time; in the case
//               of nested regions, it exits the outer region before
//               entering the inner one.
////////////////////////////////////////////////////////////////////
void MouseWatcherRegion::
exit_region(const MouseWatcherParameter &) {
}

////////////////////////////////////////////////////////////////////
//     Function: MouseWatcherRegion::within_region
//       Access: Public, Virtual
//  Description: This is a callback hook function, called whenever the
//               mouse moves within the boundaries of the region, even
//               if it is also within the boundaries of a nested
//               region.  This is different from "enter", which is
//               only called whenever the mouse is within only that
//               region.
////////////////////////////////////////////////////////////////////
void MouseWatcherRegion::
within_region(const MouseWatcherParameter &) {
}

////////////////////////////////////////////////////////////////////
//     Function: MouseWatcherRegion::without_region
//       Access: Public, Virtual
//  Description: This is a callback hook function, called whenever the
//               mouse moves completely outside the boundaries of the
//               region.  See within_region().
////////////////////////////////////////////////////////////////////
void MouseWatcherRegion::
without_region(const MouseWatcherParameter &) {
}

////////////////////////////////////////////////////////////////////
//     Function: MouseWatcherRegion::press
//       Access: Public, Virtual
//  Description: This is a callback hook function, called whenever a
//               mouse or keyboard button is depressed while the mouse
//               is within the region.
////////////////////////////////////////////////////////////////////
void MouseWatcherRegion::
press(const MouseWatcherParameter &) {
}

////////////////////////////////////////////////////////////////////
//     Function: MouseWatcherRegion::release
//       Access: Public, Virtual
//  Description: This is a callback hook function, called whenever a
//               mouse or keyboard button previously depressed with
//               press() is released.
////////////////////////////////////////////////////////////////////
void MouseWatcherRegion::
release(const MouseWatcherParameter &) {
}

////////////////////////////////////////////////////////////////////
//     Function: MouseWatcherRegion::keystroke
//       Access: Public, Virtual
//  Description: This is a callback hook function, called whenever a
//               keystroke is generated by the user.
////////////////////////////////////////////////////////////////////
void MouseWatcherRegion::
keystroke(const MouseWatcherParameter &) {
}

////////////////////////////////////////////////////////////////////
//     Function: MouseWatcherRegion::candidate
//       Access: Public, Virtual
//  Description: This is a callback hook function, called whenever an
//               IME candidate is highlighted by the user.
////////////////////////////////////////////////////////////////////
void MouseWatcherRegion::
candidate(const MouseWatcherParameter &) {
}

////////////////////////////////////////////////////////////////////
//     Function: MouseWatcherRegion::move
//       Access: Public, Virtual
//  Description: This is a callback hook function, called whenever a
//               mouse is moved within the region.
////////////////////////////////////////////////////////////////////
void MouseWatcherRegion::
move(const MouseWatcherParameter &) {
}
