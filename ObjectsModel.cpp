//
//  ObjectsModel.cpp
//  Graphics-Final-Project
//
//  Created by Kirisanth Subramaniam on 2013-12-17.
//  Copyright (c) 2013 Kirisanth Subramaniam. All rights reserved.
//

#include "ObjectsModel.h"

ObjectsModel::ObjectsModel()
{
//    point2D particlePoint;
//    color objectColor;
    
    normal[0][0] = 0;
    normal[0][1] = 0;
    normal[0][2] = 1;
    pointsForNormal[0][0] = 0.25;
    pointsForNormal[0][1] = -0.25;
    pointsForNormal[0][2] = 0.25;
    
    normal[1][0] = 0;
    normal[1][1] = 0;
    normal[1][2] = -1;
    pointsForNormal[1][0] = -0.25;
    pointsForNormal[1][1] = -0.25;
    pointsForNormal[1][2] = -0.25;
    
    normal[2][0] = 1;
    normal[2][1] = 0;
    normal[2][2] = 0;
    pointsForNormal[2][0] = 0.25;
    pointsForNormal[2][1] = -0.25;
    pointsForNormal[2][2] = -0.25;
    
    normal[3][0] = -1;
    normal[3][1] = 0;
    normal[3][2] = 0;
    pointsForNormal[3][0] = -0.25;
    pointsForNormal[3][1] = -0.25;
    pointsForNormal[3][2] = -0.25;
    
    normal[4][0] = 0;
    normal[4][1] = 1;
    normal[4][2] = 0;
    pointsForNormal[4][0] = 0.25;
    pointsForNormal[4][1] = 0.25;
    pointsForNormal[4][2] = 0.25;
    
    normal[5][0] = 0;
    normal[5][1] = 1;
    normal[5][2] = 0;
    pointsForNormal[5][0] = -0.25;
    pointsForNormal[5][1] = -0.25;
    pointsForNormal[5][2] = -0.25;

    
    objectSize = 0;
    
};



