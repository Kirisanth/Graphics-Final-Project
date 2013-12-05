//
//  ray.cpp
//  Graphics-Final-Project
//
//  Created by Meraj Patel on 12/4/2013.
//  Copyright (c) 2013 Kirisanth Subramaniam. All rights reserved.
//

#include "ray.h"
#include <math.h>


//intilize objects
ray::ray(){
    org[0] = 0;
    org[1] = 0;
    org[2] = 0;
    
    dir[0] = 0;
    dir[1] = 0;
    dir[2] = 0;
    
    norm[0] = 0;
    norm[1] = 0;
    norm[2] = 0;
};

void ray::normalizeDirection(){
    
    float length;
    length = sqrt((dir[0]*dir[0]) + (dir[1] * dir[1]) + (dir[2] * dir[2]));
    norm[0] = dir[0]/length *-1;
    norm[1] = dir[1]/length *-1;
    norm[2] = dir[2]/length *-1;
    
}


/*
float ray::normalMultiplyOrgin(int i, float t){
    return  (-1* (objectPlaneNormal[i][0] * org[0] + objectPlaneNormal[i][1] * org[1] + objectPlaneNormal[i][2] * org[2] + findDistance(i)))/t;
}
*/