//
//  PhysicsEngine.cpp
//  Graphics-Final-Project
//
//  Created by Kirisanth Subramaniam on 2013-12-18.
//  Copyright (c) 2013 Kirisanth Subramaniam. All rights reserved.
//

#include "PhysicsEngine.h"
#include "ray.h"

PhysicsEngine::PhysicsEngine()
{
    time = 0.0002;
}


//used to uppdate points by applying kinematic equation
void PhysicsEngine::moveParticle()
{
    ball.posX += (ball.velX * time) + (0.5 * (ball.accX * (time * time)));
    ball.velX = ball.velX + (ball.accX * time);
    ball.posY += (ball.velY * time) + (0.5 * (ball.accY * (time * time)));
    ball.velX = ball.velX + (ball.accX * time);
    ball.posZ += (ball.velZ * time) + (0.5 * (ball.accZ * (time * time)));
    ball.velX = ball.velX + (ball.accX * time);
};

//used to test for collisions.
//all objects are passed by reference
//Takes 4 Parametes
//Parameter 1: variable ball
//Parameter 2: vector block objects in pin ball machine (cube)
//Parameter 3: vector walls of pin ball machine
//Parameter 4: vector flippers
void PhysicsEngine::collisionTest()
{
    //iterations through all objects and find if ball is close to objects
    //iteration for objects (cube)
    
    //store ray orgin
    collision.org[0] = ball.posX;
    collision.org[1] = ball.posY;
    collision.org[2] = ball.posZ;
    
    //ray direction is the vector (pFar - pNear)
    collision.dir[0] = ball.velX;
    collision.dir[1] = ball.velY;
    collision.dir[2] = ball.velZ;
    
    //for objects
    for (int x=0; x < ActiveObjects.size(); x++) {
        for(int y = 0; y < 6; y++){
        
        //normalize direction vector
        collision.normalizeDirection();
        
        //undergoe ray plane test
        groundPlane = collision.rayPlaneTest(x, y, ActiveObjects);
        
        //update the position of the object to the intersection point
        if ( groundPlane == true){
            collision.objectPos[0] = collision.inter[0];
            collision.objectPos[1] = collision.inter[1];
            collision.objectPos[2] = collision.inter[2];
            //printf("\nOC: %f, %f, %f\n", objectPos[0],objectPos[1],objectPos[2]);
            //check if object is hit between min and max bounds
            float t1 = collision.inter[0] - ball.posX;
            float t2 = collision.inter[1] - ball.posY;
            //printf("t2 = %f", t2);
            float t3 = collision.inter[2] - ball.posZ;
            
            if (t1 < 0.25 && t2 < 0.25 && 0 < t2 && t3 < 0.25){
                //if (inter[0] < 2.5 && inter[0] > -2.5 && inter[2] < 2.5 && inter[2] > 0 && inter[1] == 4.700000){
                printf("WORKS");
                break;
            }
        }
        }
    }
    
    for (int count = 0; count < 5; count++){
        //normalize direction vector
        collision.normalizeDirection();
        
        //undergoe ray plane test
        groundPlane = collision.rayPlaneTest(count, pinballStruct);
        //update the position of the object to the intersection point
        if ( groundPlane == true){
            collision.objectPos[0] = collision.inter[0];
            collision.objectPos[1] = collision.inter[1];
            collision.objectPos[2] = collision.inter[2];
            //printf("\nOC: %f, %f, %f\n", objectPos[0],objectPos[1],objectPos[2]);
            //check if object is hit between min and max bounds
            float t1 = collision.inter[0] - ball.posX;
            float t2 = collision.inter[1] - ball.posY;
            //printf("t2 = %f", t2);
            float t3 = collision.inter[2] - ball.posZ;
            
            if (t1 < 0.25 && t2 < 0.25 && 0 < t2 && t3 < 0.25){
                //if (inter[0] < 2.5 && inter[0] > -2.5 && inter[2] < 2.5 && inter[2] > 0 && inter[1] == 4.700000){
                printf("WORKS");
                break;
            }
        }

    }
    
    


};


//void collisionTest(double vecX, double vexY, double vecZ, double posX, double posY, double posZ){
//    ray collision;
//    //store ray orgin
//    collision.org[0] = posX;
//    collision.org[1] = posY;
//    collision.org[2] = posZ;
//    
//    //ray direction is the vector (pFar - pNear)
//    collision.dir[0] = vecX;
//    collision.dir[1] = vexY;
//    collision.dir[2] = vecZ;
//    
//    //normalize direction vector
//    collision.normalizeDirection();
//    
//    for (int i = 0; i < 6; i++){
//        
//        //undergoe ray plane test
//        groundPlane = rayPlaneTest(i);
//        
//        //update the position of the object to the intersection point
//        if ( groundPlane == true){
//            objectPos[0] = inter[0];
//            objectPos[1] = inter[1];
//            objectPos[2] = inter[2];
//            
//            //check if object is hit between min and max bounds
//            if ((minZ <= objectPos[2] && objectPos[2] <= maxZ && objectPos[1] <= maxY && minY <= objectPos[1]) && maxX == objectPos[0]){
//                hit1 = true;
//                //break;
//            }
//        }
//    }
    
//};