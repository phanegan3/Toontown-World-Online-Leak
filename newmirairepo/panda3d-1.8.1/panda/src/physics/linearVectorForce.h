// Filename: linearVectorForce.h
// Created by:  charles (13Jun00)
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

#ifndef LINEARVECTORFORCE_H
#define LINEARVECTORFORCE_H

#include "linearForce.h"

////////////////////////////////////////////////////////////////
//       Class : LinearVectorForce
// Description : Simple directed vector force.  Suitable for
//               gravity, non-turbulent wind, etc...
////////////////////////////////////////////////////////////////
class EXPCL_PANDAPHYSICS LinearVectorForce : public LinearForce {
PUBLISHED:
  LinearVectorForce(const LVector3& vec, PN_stdfloat a = 1.0f, bool mass = false);
  LinearVectorForce(const LinearVectorForce &copy);
  LinearVectorForce(PN_stdfloat x = 0.0f, PN_stdfloat y = 0.0f, PN_stdfloat z = 0.0f,
              PN_stdfloat a = 1.0f, bool mass = false);
  virtual ~LinearVectorForce();

  INLINE void set_vector(const LVector3& v);
  INLINE void set_vector(PN_stdfloat x, PN_stdfloat y, PN_stdfloat z);

  INLINE LVector3 get_local_vector() const;
  
  virtual void output(ostream &out) const;
  virtual void write(ostream &out, unsigned int indent=0) const;

public:
  INLINE LinearVectorForce& operator += (const LinearVectorForce &other);

private:
  LVector3 _fvec;

  virtual LinearForce *make_copy();
  virtual LVector3 get_child_vector(const PhysicsObject *po);

public:
  static TypeHandle get_class_type() {
    return _type_handle;
  }
  static void init_type() {
    LinearForce::init_type();
    register_type(_type_handle, "LinearVectorForce",
                  LinearForce::get_class_type());
  }
  virtual TypeHandle get_type() const {
    return get_class_type();
  }
  virtual TypeHandle force_init_type() {init_type(); return get_class_type();}

private:
  static TypeHandle _type_handle;
};

#include "linearVectorForce.I"

#endif // LINEARVECTORFORCE_H
