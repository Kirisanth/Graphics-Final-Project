//
//  ray.h
//  Graphics-Final-Project
//
//  Created by Meraj Patel on 12/5/2013.
//  Copyright (c) 2013 Kirisanth Subramaniam. All rights reserved.
//

#ifndef __Graphics_Final_Project__ray__
#define __Graphics_Final_Project__ray__

#include <iostream>
#include <vector>
#include "ObjectsModel.h"
#include "Walls.h"
#include "Flipper.h"

class ray{
    public:
    double org[3];
    double dir[3];
    double norm[3];
    double inter[3];
    double objectPos[3];
    GLdouble newPoint [3];//creates new point
    GLdouble pNear[3];//depth for z
    GLdouble pFar[3]; //depth for z
    ray();
    void normalizeDirection();
    bool rayPlaneTest(int x, int y, std::vector<ObjectsModel> currentObject);
    bool rayPlaneTest(int count, Walls wallObject);
    bool rayPlaneTest(int count, Flipper flipperObject);
    
    
    float normalMultiplyDirection(int x, int y, std::vector<ObjectsModel> currentObject);
    float normalMultiplyDirection(int count, Walls wallObject);
    float normalMultiplyDirection(int count, Flipper flipperObject);
    
    float normalMultiplyOrgin(int x, int y, float t, std::vector<ObjectsModel> currentObject);
    float normalMultiplyOrgin(int count, float t, Walls wallObject);
    float normalMultiplyOrgin(int count, float t, Flipper flipperObject);
    
    double distance(int x , int y, std::vector<ObjectsModel> currentObject);
    double distance(int count, Walls wallObject);
    double distance(int count, Flipper flipperObject);
    
    //ray casting for objects
    void Get3DPos(int x, int y, float winz, GLdouble point[3]);
    void rayCast(float x, float y, std::vector<ObjectsModel> currentObject);
    
    
};

#endif /* defined(__Graphics_Final_Project__ray__) */
