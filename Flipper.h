//
//  Flipper.h
//  Graphics-Final-Project
//
//  Created by Kirisanth Subramaniam on 2013-12-19.
//  Copyright (c) 2013 Kirisanth Subramaniam. All rights reserved.
//

#ifndef __Graphics_Final_Project__Flipper__
#define __Graphics_Final_Project__Flipper__

#include <iostream>
#include "MathLibrary.h"
#include <GLUT/glut.h>

//Definition of Flipper in Pinball Machine
class Flipper
{
public:
    float objectSize;
    //store positions of object
    double posX, posY, posZ;
    double movFlip1 = -2;
    double movFlip2 = -2;
    
    Math3dhelpers math;//Used to call math helper functions, find another way to do this line
    
    float color[2][3] = {{0.3, 0, 1},{0.3, 0, 1}};
    double vertex[2][4][3] = {{{0.4,movFlip1,2.5},{2.5,-0.7,2.5},{2.5,-0.7,0},{0.4,movFlip1,0}},{{-0.4,movFlip2,2.5},{-2.5,-0.7,2.5},{-2.5,-0.7,0},{-0.4,movFlip2,0}}};
    double flipperNormal[2][3];
    double pointsForNormal[2][3] = {{vertex[0][0][0], vertex[0][0][1], vertex[0][0][2]},{vertex[1][0][0], vertex[1][0][1], vertex[1][0][2]}};
    
    //constructor
    Flipper();
    //methods
    void CalculateNormal();
    void RenderFlippers();
    void setFlipperColor();
    void setUpdatedYValue1(double value1);
    void setUpdatedYValue2(double value1);
};

#endif /* defined(__Graphics_Final_Project__Flipper__) */
