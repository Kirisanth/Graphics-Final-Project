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

//Model for the object (cube)
class ObjectsModel
{
public:
//    point2D objectPoint;
//    color objectColor;
    float objectSize;
    //store positions of object
    double posX, posY, posZ;
    
    float pointsForNormal[6][3];
    float normal[6][3];
    
    //cube vertices

    //constructor
    ObjectsModel();
};
#endif /* defined(__Graphics_Final_Project__ObjectsModel__) */
