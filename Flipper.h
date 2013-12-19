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


class Flipper
{
public:
    //    point2D objectPoint;
    //    color objectColor;
    float objectSize;
    //store positions of object
    double posX, posY, posZ;
    
    double platformNormal[6][3] ={{-1,0,0},{1,0,0},{0,-1,0},{0,0,1},{0,0,-1}};
    double platformPoints[6][3] = {{-2.5,-0.7,2.5}, {2.5,4.7,0},{2.5,4.7,2.5},{2.5,4.7,0},{2.5,4.7,2.5}};
    
    //cube vertices
    
    //constructor
    Flipper();
};

#endif /* defined(__Graphics_Final_Project__Flipper__) */
