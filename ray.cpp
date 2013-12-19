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

void ray::Get3DPos(int x, int y, float winz, GLdouble point[3])
{
	GLint viewport[4];
	GLdouble modelview[16];
	GLdouble projection[16];
	
	//get the matrices
	glGetDoublev( GL_MODELVIEW_MATRIX, modelview );
	glGetDoublev( GL_PROJECTION_MATRIX, projection );
	glGetIntegerv( GL_VIEWPORT, viewport );
    
	//"un-project" the 2D point giving the 3D position corresponding to the provided depth (winz)
	gluUnProject( (float)x, (float)(viewport[3]-y), winz, modelview, projection, viewport, &point[0], &point[1], &point[2]);
    
}

void ray::normalizeDirection(){
    
    float length;
    length = sqrt((dir[0]*dir[0]) + (dir[1] * dir[1]) + (dir[2] * dir[2]));
    norm[0] = dir[0]/length *-1;
    norm[1] = dir[1]/length *-1;
    norm[2] = dir[2]/length *-1;
    
}

//objects
double ray::distance(int x, int y, std::vector<ObjectsModel> currentObject){
    return -1 * (currentObject.at(x).pointsForNormal[y][0]* currentObject.at(x).normal[y][0] + currentObject.at(x).pointsForNormal[y][1]* currentObject.at(x).normal[y][1] + currentObject.at(x).pointsForNormal[y][2]* currentObject.at(x).normal[y][2]);
}

//pinball stru
double ray::distance(int count, Walls wallObject){
        return -1 * (wallObject.platformPoints[count][0]* wallObject.platformNormal[count][0] + wallObject.platformPoints[count][1]* wallObject.platformNormal[count][1] + wallObject.platformPoints[count][2]* wallObject.platformNormal[count][2]);
}

//flipper
double distance(int count, Flipper flipperObject){
    return -1 * (flipperObject.pointsForNormal[count][0]* flipperObject.flipperNormal[count][0] + flipperObject.pointsForNormal[count][1]* flipperObject.flipperNormal[count][1] + flipperObject.pointsForNormal[count][2]* flipperObject.flipperNormal[count][2]);
}






//objects
float ray::normalMultiplyDirection(int x, int y, std::vector<ObjectsModel> currentObject){
    return (currentObject.at(x).normal[y][0] *  norm[0] + currentObject.at(x).normal[y][1] * norm[1] + currentObject.at(x).normal[y][2] * norm[2]);
}

//structure
float ray::normalMultiplyDirection(int count, Walls wallObject){
        return (wallObject.platformNormal[count][0] *  norm[0] + wallObject.platformNormal[count][1] * norm[1] + wallObject.platformNormal[count][2] * norm[2]);
}

//flipper
float ray::normalMultiplyDirection(int count, Flipper flipperObject){
        return (flipperObject.flipperNormal[count][0] *  norm[0] + flipperObject.flipperNormal[count][1] * norm[1] + flipperObject.flipperNormal[count][2] * norm[2]);
}






//for objects
float ray::normalMultiplyOrgin(int x, int y, float t,std::vector<ObjectsModel> currentObject){
    return  (-1* (currentObject.at(x).normal[y][0] * org[0] + currentObject.at(x).normal[y][1] * org[1] + currentObject.at(x).normal[y][2] * org[2] + distance(x,y,currentObject)))/t;
}

//for platform 
float ray::normalMultiplyOrgin(int count, float t, Walls wallObject){
    return  (-1* (wallObject.platformNormal[count][0] * org[0] + wallObject.platformNormal[count][1] * org[1] + wallObject.platformNormal[count][2] * org[2] + distance(count, wallObject)))/t;
}

//for flipper
float ray::normalMultiplyOrgin(int count, float t, Flipper flipperObject){
    return  (-1* (flipperObject.flipperNormal[count][0] * org[0] + flipperObject.flipperNormal[count][1] * org[1] + flipperObject.flipperNormal[count][2] * org[2] + distance(count, flipperObject)))/t;
}








////Function performs a ray plan test to check if ray intersected object other then sphere
//for objects
bool ray::rayPlaneTest(int x, int y, std::vector<ObjectsModel> currentObject){
    float t = 0;
    normalMultiplyDirection(x,y,currentObject);
    t = (currentObject.at(x).normal[y][0] *  norm[0] + currentObject.at(x).normal[y][1] * norm[1] + currentObject.at(x).normal[y][2] * norm[2]);
    //printf("%f",currentObject.at(x).normal[y][0]);
    if (t != 0){
        t = normalMultiplyOrgin(x,y,t, currentObject);
        //store instesection points if it did
        inter[0] = org[0] + t*norm[0];
        inter[1] = org[1] + t*norm[1];
        inter[2] = org[2] + t*norm[2];
        
        return true;
    }
    else {
        return false;
    }
    
}

//for platform 
bool ray::rayPlaneTest(int count, Walls wallObject){
    float t = 0;
    normalMultiplyDirection(count,wallObject);
    t = (wallObject.platformNormal[count][0] *  norm[0] + wallObject.platformNormal[count][1] * norm[1] + wallObject.platformNormal[count][2] * norm[2]);
    if (t != 0){
        t = normalMultiplyOrgin(count,t, wallObject);
        //store instesection points if it did
        inter[0] = org[0] + t*norm[0];
        inter[1] = org[1] + t*norm[1];
        inter[2] = org[2] + t*norm[2];
        
        return true;
    }
    else {
        return false;
    }
}

//for flipper
bool ray::rayPlaneTest(int count, Flipper flipperObject){
    float t = 0;
    normalMultiplyDirection(count,flipperObject);
    t = (flipperObject.flipperNormal[count][0] *  norm[0] + flipperObject.flipperNormal[count][1] * norm[1] + flipperObject.flipperNormal[count][2] * norm[2]);
    if (t != 0){
        t = normalMultiplyOrgin(count,t, flipperObject);
        //store instesection points if it did
        inter[0] = org[0] + t*norm[0];
        inter[1] = org[1] + t*norm[1];
        inter[2] = org[2] + t*norm[2];
        
        return true;
    }
    else {
        return false;
    }
}




