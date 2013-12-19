//
//  ObjectsModel.h
//  Graphics-Final-Project
//
//  Created by Kirisanth Subramaniam on 2013-12-17.
//  Copyright (c) 2013 Kirisanth Subramaniam. All rights reserved.
//

#ifndef __Graphics_Final_Project__ObjectsModel__
#define __Graphics_Final_Project__ObjectsModel__

#include <iostream>
#include <stdlib.h>
#include <GLUT/glut.h>

//Model for the object (cube)
class ObjectsModel
{
public:
//    point2D objectPoint;
//    color objectColor;
    float objectSize;
    //store positions of object
    double posX, posY, posZ;
    float r, g, b;
    float scale;
    float pointsForNormal[6][3];
    float normal[6][3];
    double translateX, translateY, translateZ;
    void drawObjects();
    double min = -0.25, max  = 0.25;
    bool hit;
    
    //cube vertices

    //constructor
    ObjectsModel();
};
#endif /* defined(__Graphics_Final_Project__ObjectsModel__) */
