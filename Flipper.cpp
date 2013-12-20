//
//  Flipper.cpp
//  Graphics-Final-Project
//
//  Created by Kirisanth Subramaniam on 2013-12-19.
//  Copyright (c) 2013 Kirisanth Subramaniam. All rights reserved.
//

#include "Flipper.h"


Flipper::Flipper()
{
    
}


//TODO:modularize this
void Flipper::CalculateNormal()
{
//    float color[2][3] = {{0.3, 0, 1},{0.3, 0, 1}};
    
    //vertex 2
    
//    float vertex[2][4][3] = {{{0.4,movFlip1,2.5}, {2.5,-0.7,2.5}, {2.5,-0.7,0}, {0.4,movFlip1,0}}, {{-0.4,movFlip2,2.5}, {-2.5,-0.7,2.5}, {-2.5,-0.7,0}, {-0.4,movFlip2,0}}};
    
    Vec3D vector1;
    Vec3D vector2;
    
//    {0.4,movFlip1,2.5},{2.5,-0.7,2.5},{2.5,-0.7,0},{0.4,movFlip1,0}
    vector1 = math.createVector(vertex[0][0][0], vertex[0][0][1], vertex[0][0][2], vertex[0][3][0], vertex[0][3][1], vertex[0][3][2]);
    
    vector2 = math.createVector(vertex[0][2][0], vertex[0][2][1], vertex[0][2][2], vertex[0][3][0], vertex[0][3][1], vertex[0][3][2]);
    
    
//    float flipperNormal[2][3];
//    u x v
    Vec3D normalVector1 = math.crossProduct(vector1, vector2);

    flipperNormal[0][0] = normalVector1.xComponent;
    flipperNormal[0][1] = normalVector1.yComponent;
    flipperNormal[0][2] = normalVector1.zComponent;

    //
    //------------------------------------------------------------------
    //2nd Flipper
    
    Vec3D vector3;
    Vec3D vector4;
    
    vector3 = math.createVector(vertex[1][0][0], vertex[1][0][1], vertex[1][0][2], vertex[1][3][0], vertex[1][3][1], vertex[1][3][2]);
    vector4 = math.createVector(vertex[1][2][0], vertex[1][2][1], vertex[1][2][2], vertex[1][3][0], vertex[1][3][1], vertex[1][3][2]);
    
    Vec3D normalVector2 = math.crossProduct(vector3, vector4);
    
    flipperNormal[1][0] = normalVector2.xComponent;
    flipperNormal[1][1] = normalVector2.yComponent;
    flipperNormal[1][2] = normalVector2.zComponent;
    
    //CrossProduct
//    flipperNormal[0][0] = u2*v3 - u3*v2;
//    flipperNormal[0][1] = u3*v1 - u1*v3;
//    flipperNormal[0][2] = u1*v2 - u2*v1;
}


void Flipper::setFlipperColor()
{
    
}


void Flipper::RenderFlippers()
{
//    glColor3f(0.3, 0, 1);
//    glVertex3f(0.4,movFlip1,2.5);
//    glVertex3f(2.5,-0.7,2.5);
//    glVertex3f(2.5,-0.7,0);
//    glVertex3f(0.4,movFlip1,0);
//    
//    glColor3f(0.3, 0, 1);
//    glVertex3f(-0.4,movFlip2,2.5);
//    glVertex3f(-2.5,-0.7,2.5);
//    glVertex3f(-2.5,-0.7,0);
//    glVertex3f(-0.4,movFlip2,0);
}