### Generated automatically by ppremake 1.22 from direct.prc.pp.
################################ DO NOT EDIT ###########################
model-path      $DMODELS
sound-path      $DMODELS
# Define a new egg object type.  See the comments in _panda.prc about this.
egg-object-type-direct-widget   <Scalar> collide-mask { 0x80000000 } <Collide> { Polyset descend }
# Define a new cull bin that will render on top of everything else.
cull-bin gui-popup 60 unsorted
