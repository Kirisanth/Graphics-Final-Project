//
//  MathLibrary.h
//  GC3AssignmentTwo
//
//  Created by Meraj Patel on 11/8/2013.
//  Copyright (c) 2013 Meraj Patel. All rights reserved.
//

#ifndef __GC3AssignmentTwo__MathLibrary__
#define __GC3AssignmentTwo__MathLibrary__

#include <iostream>

class Vec3D
{
public:
    double xComponent;
    double yComponent;
    double zComponent;
    Vec3D();
    Vec3D(double x, double y, double z);
    
};

class Math3dhelpers
{
public:
    double dot (double vX1, double vY1,double vZ1,double vX2,double vY2,double vZ2);
    double dot (Vec3D v1,Vec3D v2);
    Vec3D scalarVectorMultiply(double scalar, double vX, double vY, double xZ);
    Vec3D vectorSubtract(Vec3D v1, Vec3D v2);
    double distance3D(Vec3D v);
    Vec3D createVector(double p1X,double p1Y,double p1Z,double p2X,double p2Y,double p2Z);
    Vec3D crossProduct(Vec3D v1, Vec3D v2);
};

#endif /* defined(__GC3AssignmentTwo__MathLibrary__) */
