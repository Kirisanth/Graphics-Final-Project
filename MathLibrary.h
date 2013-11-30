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

class point2D
{
public:
    float x;//point x
    float y;//point y
    point2D();
    point2D(float newX, float newY);
    
};

class vec2D
{
public:
    float x;//vector point x
    float y;//vector point y
    double magnitude;//vector magnitude
    vec2D();
    vec2D(float newX, float newY);
    
};

class color
{
public:
    float r;//color red
    float g;// color green
    float b;//color blue
    color();
    color(float newR, float newG, float newB);
    
};


class Math2d
{
public:
    double distance (point2D p1, point2D p2);
    double fastDistance (point2D p1, point2D p2);
    static double length (vec2D vector);
    static vec2D normalize (vec2D vector);
    static vec2D vectorMultiply (vec2D vector, double s);
    static vec2D createVector (point2D p1, point2D p2);
    static vec2D movePoint (point2D p, vec2D vector);
    
};


#endif /* defined(__GC3AssignmentTwo__MathLibrary__) */
