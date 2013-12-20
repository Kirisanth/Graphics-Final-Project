//
//  Walls.h
//  Graphics-Final-Project
//
//  Created by Meraj Patel on 12/18/2013.
//  Copyright (c) 2013 Kirisanth Subramaniam. All rights reserved.
//

#ifndef __Graphics_Final_Project__Walls__
#define __Graphics_Final_Project__Walls__

#include <iostream>
#include <GLUT/glut.h>

class Walls
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
    Walls();
    void RenderWalls();
};

#endif /* defined(__Graphics_Final_Project__Walls__) */
