#define BUILD_DIRECTORY $[HAVE_BULLET]
#define BUILDING_DLL BUILDING_PANDABULLET

#define OTHER_LIBS p3interrogatedb:c p3dconfig:c p3dtoolconfig:m p3dtoolutil:c p3dtoolbase:c p3dtool:m p3prc:c

#begin lib_target
  #define TARGET p3bullet
  #define LOCAL_LIBS p3pgraph p3linmath p3grutil
  #define USE_PACKAGES bullet
  #define COMBINED_SOURCES $[TARGET]_composite.cxx

  #define SOURCES \
    bulletAllHitsRayResult.I \
    bulletAllHitsRayResult.h \
    bulletBodyNode.I \
    bulletBodyNode.h \
    bulletBoxShape.I \
    bulletBoxShape.h \
    bulletCapsuleShape.I \
    bulletCapsuleShape.h \
    bulletCharacterControllerNode.I \
    bulletCharacterControllerNode.h \
    bulletClosestHitRayResult.I \
    bulletClosestHitRayResult.h \
    bulletClosestHitSweepResult.I \
    bulletClosestHitSweepResult.h \
    bulletConeShape.I \
    bulletConeShape.h \
    bulletConeTwistConstraint.I \
    bulletConeTwistConstraint.h \
    bulletConstraint.I \
    bulletConstraint.h \
    bulletContactCallbacks.h \
    bulletContactResult.I \
    bulletContactResult.h \
    bulletConvexHullShape.I \
    bulletConvexHullShape.h \
    bulletConvexPointCloudShape.I \
    bulletConvexPointCloudShape.h \
    bulletCylinderShape.I \
    bulletCylinderShape.h \
    bulletDebugNode.I \
    bulletDebugNode.h \
    bulletGenericConstraint.I \
    bulletGenericConstraint.h \
    bulletGhostNode.I \
    bulletGhostNode.h \
    bulletHeightfieldShape.I \
    bulletHeightfieldShape.h \
    bulletHelper.I \
    bulletHelper.h \
    bulletHingeConstraint.I \
    bulletHingeConstraint.h \
    bulletManifoldPoint.I \
    bulletManifoldPoint.h \
    bulletPersistentManifold.I \
    bulletPersistentManifold.h \
    bulletPlaneShape.I \
    bulletPlaneShape.h \
    bulletRigidBodyNode.I \
    bulletRigidBodyNode.h \
    bulletShape.I \
    bulletShape.h \
    bulletSliderConstraint.I \
    bulletSliderConstraint.h \
    bulletSoftBodyConfig.I \
    bulletSoftBodyConfig.h \
    bulletSoftBodyMaterial.I \
    bulletSoftBodyMaterial.h \
    bulletSoftBodyNode.I \
    bulletSoftBodyNode.h \
    bulletSoftBodyShape.I \
    bulletSoftBodyShape.h \
    bulletSoftBodyWorldInfo.I \
    bulletSoftBodyWorldInfo.h \
    bulletSphereShape.I \
    bulletSphereShape.h \
    bulletSphericalConstraint.I \
    bulletSphericalConstraint.h \
    bulletTriangleMesh.I \
    bulletTriangleMesh.h \
    bulletTriangleMeshShape.I \
    bulletTriangleMeshShape.h \
    bulletVehicle.I \
    bulletVehicle.h \
    bulletWheel.I \
    bulletWheel.h \
    bulletWorld.I \
    bulletWorld.h \
    bullet_includes.h \
    bullet_utils.I \
    bullet_utils.h \
    config_bullet.h \

  #define INCLUDED_SOURCES \
    bulletAllHitsRayResult.cxx \
    bulletBodyNode.cxx \
    bulletBoxShape.cxx \
    bulletCapsuleShape.cxx \
    bulletCharacterControllerNode.cxx \
    bulletClosestHitRayResult.cxx \
    bulletClosestHitSweepResult.cxx \
    bulletConeShape.cxx \
    bulletConeTwistConstraint.cxx \
    bulletConstraint.cxx \
    bulletContactResult.cxx \
    bulletConvexHullShape.cxx \
    bulletConvexPointCloudShape.cxx \
    bulletCylinderShape.cxx \
    bulletDebugNode.cxx \
    bulletGenericConstraint.cxx \
    bulletGhostNode.cxx \
    bulletHeightfieldShape.cxx \
    bulletHelper.cxx \
    bulletHingeConstraint.cxx \
    bulletManifoldPoint.cxx \
    bulletPersistentManifold.cxx \
    bulletPlaneShape.cxx \
    bulletRigidBodyNode.cxx \
    bulletShape.cxx \
    bulletSliderConstraint.cxx \
    bulletSoftBodyConfig.cxx \
    bulletSoftBodyMaterial.cxx \
    bulletSoftBodyNode.cxx \
    bulletSoftBodyShape.cxx \
    bulletSoftBodyWorldInfo.cxx \
    bulletSphereShape.cxx \
    bulletSphericalConstraint.cxx \
    bulletTriangleMesh.cxx \
    bulletTriangleMeshShape.cxx \
    bulletVehicle.cxx \
    bulletWheel.cxx \
    bulletWorld.cxx \
    p3bullet_composite.cxx \
    bullet_utils.cxx \
    config_bullet.cxx \

  #define INSTALL_HEADERS \
    bulletAllHitsRayResult.I \
    bulletAllHitsRayResult.h \
    bulletBodyNode.I \
    bulletBodyNode.h \
    bulletBoxShape.I \
    bulletBoxShape.h \
    bulletCapsuleShape.I \
    bulletCapsuleShape.h \
    bulletCharacterControllerNode.I \
    bulletCharacterControllerNode.h \
    bulletClosestHitRayResult.I \
    bulletClosestHitRayResult.h \
    bulletClosestHitSweepResult.I \
    bulletClosestHitSweepResult.h \
    bulletConeShape.I \
    bulletConeShape.h \
    bulletConeTwistConstraint.I \
    bulletConeTwistConstraint.h \
    bulletConstraint.I \
    bulletConstraint.h \
    bulletContactCallbacks.h \
    bulletContactResult.I \
    bulletContactResult.h \
    bulletConvexHullShape.I \
    bulletConvexHullShape.h \
    bulletConvexPointCloudShape.I \
    bulletConvexPointCloudShape.h \
    bulletCylinderShape.I \
    bulletCylinderShape.h \
    bulletDebugNode.I \
    bulletDebugNode.h \
    bulletGenericConstraint.I \
    bulletGenericConstraint.h \
    bulletGhostNode.I \
    bulletGhostNode.h \
    bulletHeightfieldShape.I \
    bulletHeightfieldShape.h \
    bulletHelper.I \
    bulletHelper.h \
    bulletHingeConstraint.I \
    bulletHingeConstraint.h \
    bulletManifoldPoint.I \
    bulletManifoldPoint.h \
    bulletPersistentManifold.I \
    bulletPersistentManifold.h \
    bulletPlaneShape.I \
    bulletPlaneShape.h \
    bulletRigidBodyNode.I \
    bulletRigidBodyNode.h \
    bulletShape.I \
    bulletShape.h \
    bulletSliderConstraint.I \
    bulletSliderConstraint.h \
    bulletSoftBodyConfig.I \
    bulletSoftBodyConfig.h \
    bulletSoftBodyMaterial.I \
    bulletSoftBodyMaterial.h \
    bulletSoftBodyNode.I \
    bulletSoftBodyNode.h \
    bulletSoftBodyShape.I \
    bulletSoftBodyShape.h \
    bulletSoftBodyWorldInfo.I \
    bulletSoftBodyWorldInfo.h \
    bulletSphereShape.I \
    bulletSphereShape.h \
    bulletSphericalConstraint.I \
    bulletSphericalConstraint.h \
    bulletTriangleMesh.I \
    bulletTriangleMesh.h \
    bulletTriangleMeshShape.I \
    bulletTriangleMeshShape.h \
    bulletVehicle.I \
    bulletVehicle.h \
    bulletWheel.I \
    bulletWheel.h \
    bulletWorld.I \
    bulletWorld.h \
    bullet_includes.h \
    bullet_utils.I \
    bullet_utils.h \

  #define IGATESCAN all

#end lib_target
