//
//  MathLibrary.cpp
//  GC3AssignmentTwo
//
//  Created by Meraj Patel on 11/8/2013.
//  Copyright (c) 2013 Meraj Patel. All rights reserved.
//


#include "MathLibrary.h"
#include <math.h>

//Constructor for Vector Definition
Vec3D::Vec3D()
{
    xComponent = 1;
    yComponent = 1;
    zComponent = 1;
};

//Constructor for Vector Definition
Vec3D::Vec3D(double vX, double vY, double vZ)
{
    xComponent = vX;
    yComponent = vY;
    zComponent = vZ;
};

//Used to find dot product of two vectors
//Parameter: Six component vectors (Two vectors -> Three Components)
double Math3dhelpers::dot (double vX1, double vY1,double vZ1,double vX2,double vY2,double vZ2)
{
    return vX1*vX2 + vY2*vY2 + vZ1*vZ2;
};

//Used to find dot product of two vectors
//Parameter: Two Vectors
double Math3dhelpers::dot (Vec3D v1, Vec3D v2)
{
    return v1.xComponent*v2.xComponent + v1.yComponent*v2.yComponent + v1.zComponent*v2.zComponent;
};

//Used to multiply vector by scalar
//Parameters: Two Vectors
Vec3D Math3dhelpers::scalarVectorMultiply(double scalar, double vX, double vY, double vZ)
{
    Vec3D newVector;
    
    newVector.xComponent = vX * scalar;
    newVector.yComponent = vY * scalar;
    newVector.zComponent = vZ * scalar;
    
    return newVector;
};

//Used to subtract vectors
//Parameters: Two Vectors
Vec3D Math3dhelpers::vectorSubtract(Vec3D v1,Vec3D v2)
{
    Vec3D newVector;
    newVector.xComponent = v1.xComponent - v2.xComponent;
    newVector.yComponent = v1.yComponent - v2.yComponent;
    newVector.zComponent = v1.zComponent - v2.zComponent;

    return newVector;
};

//Calculates magnitude of vector
//Parameters: Takes one Vector
double Math3dhelpers::distance3D(Vec3D v)
{
    return sqrt(v.xComponent*v.xComponent + v.yComponent*v.yComponent + v.zComponent*v.zComponent);
}

//Used to create a vector using vertices
//Parameters: Takes six points
Vec3D Math3dhelpers::createVector(double p1X,double p1Y,double p1Z,double p2X,double p2Y,double p2Z)
{
    Vec3D newVector;
    
    newVector.xComponent = p1X - p2X;
    newVector.yComponent = p1Y - p2Y;
    newVector.zComponent = p1Z - p2Z;
    
    return newVector;
}

//Calculates the cross product of vectors u and v
//Parameters: Two Vectors
Vec3D Math3dhelpers::crossProduct(Vec3D u, Vec3D v)
{
    Vec3D newVector;
    
    newVector.xComponent = u.yComponent*v.zComponent - u.zComponent*v.yComponent;
    newVector.yComponent = u.zComponent*v.xComponent - u.xComponent*v.zComponent;
    newVector.zComponent = u.xComponent*v.yComponent - u.yComponent*v.xComponent;

    return newVector;
}
