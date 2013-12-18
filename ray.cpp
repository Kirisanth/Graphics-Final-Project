//
//  ray.cpp
//  Graphics-Final-Project
//
//  Created by Meraj Patel on 12/5/2013.
//  Copyright (c) 2013 Kirisanth Subramaniam. All rights reserved.
//

#include <math.h>
#include "ray.h"

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