//
//  MathLibrary.cpp
//  GC3AssignmentTwo
//
//  Created by Meraj Patel on 11/8/2013.
//  Copyright (c) 2013 Meraj Patel. All rights reserved.
//


#include "MathLibrary.h"
#include <math.h>

//intilize point
point2D::point2D()
{
    x = 0;
    y = 0;
};

//intilize point specified by user
point2D::point2D(float newX, float newY)
{
    x = newX;
    y = newY;
};

//intilize vector
vec2D::vec2D()
{
    x = -1;
    y = -1;
    magnitude = 0;
}

//intilize vector specified by user
vec2D::vec2D(float newX, float newY)
{
    x = newX;
    y = newY;
    magnitude = 0;
}
//TODO: Seperate to another class
//intilize color
color::color()
{
    r = 0;
    g = 0;
    b = 0;
}

//intilize color specified by user
color::color(float newR, float newG, float newB)
{
    r = newR;
    g = newG;
    b = newB;
}

//find the distance between two points
double Math2d::distance (point2D p1, point2D p2)
{
    double d;
    d = sqrt((p2.x - p1.x)*(p2.x - p1.x) + (p2.y - p1.y)*(p2.y - p1.y));
    return d;
};

//find the distance between two points
double Math2d::fastDistance (point2D p1, point2D p2)
{
    return (p2.x - p1.x)*(p2.x - p1.x) + (p2.y - p1.y)*(p2.y - p1.y);;
};

//find the length of a vector
double Math2d::length (vec2D vector)
{
    double vectorLength;
    vectorLength = sqrt((vector.x)*(vector.x) + (vector.y)*(vector.y));
    vector.magnitude = vectorLength;
    return vectorLength;
};

//normlize a vectore
vec2D Math2d::normalize (vec2D newVector)
{
    vec2D normalize;
    normalize.x = newVector.x/length(newVector);
    normalize.y =  newVector.y/length(newVector);
    return normalize;
};

//multiply a vector by a scalar
vec2D Math2d::vectorMultiply (vec2D vector, double s)
{
    vec2D scalar;
    scalar.x = s * vector.x;
    scalar.y = s * vector.y;
    return scalar;
};

//create a vector using two points
vec2D Math2d::createVector (point2D p1, point2D p2)
{
    vec2D createVector;
    createVector.x = p2.x - p1.x;
    createVector.y = p2.y - p1.y;
    return createVector;
};

//move to a point on a vector
vec2D Math2d::movePoint (point2D p, vec2D vector)
{
    vector.x = vector.x + p.x;
    vector.y = vector.y + p.y;
    return vector;
};

Vec3D::Vec3D()
{
    xComponent = 1;
    yComponent = 1;
    zComponent = 1;
};

Vec3D::Vec3D(double vX, double vY, double vZ)
{
    xComponent = vX;
    yComponent = vY;
    zComponent = vZ;
};

double Math3dhelpers::dot (double vX1, double vY1,double vZ1,double vX2,double vY2,double vZ2)
{
    return vX1*vX2 + vY2*vY2 + vZ1*vZ2;
};

double Math3dhelpers::dot (Vec3D v1, Vec3D v2)
{
    return v1.xComponent*v2.xComponent + v1.yComponent*v2.yComponent + v1.zComponent*v2.zComponent;
};

Vec3D Math3dhelpers::scalarVectorMultiply(double scalar, double vX, double vY, double vZ)
{
    Vec3D newVector;
    
    newVector.xComponent = vX * scalar;
    newVector.yComponent = vY * scalar;
    newVector.zComponent = vZ * scalar;
    
    return newVector;
};

Vec3D Math3dhelpers::vectorSubtract(Vec3D v1,Vec3D v2)
{
    Vec3D newVector;
    newVector.xComponent = v1.xComponent - v2.xComponent;
    newVector.yComponent = v1.yComponent - v2.yComponent;
    newVector.zComponent = v1.zComponent - v2.zComponent;

    return newVector;
};

double Math3dhelpers::distance3D(Vec3D v)
{
    return sqrt(v.xComponent*v.xComponent + v.yComponent*v.yComponent + v.zComponent*v.zComponent);
}



//Vec3D::Vec3D()
//{
//    
//};
