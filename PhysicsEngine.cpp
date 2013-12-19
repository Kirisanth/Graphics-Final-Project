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
void PhysicsEngine::collision(Particle ball, std::vector<ObjectsModel>& currentObjects, std::vector<ObjectsModel>& wall, std::vector<ObjectsModel>& flippers)
{
    //iterations through all objects and find if ball is close to objects
    //iteration for objects (cube)
    for (int i=0; i < currentObjects.size(); i++) {
        currentObjects.at(i).posX = 0;
    }
    //iteration for walls
    for (int i=0; i < wall.size(); i++) {
        wall.at(i).posX = 0;
    }
    //iteration for flippers
    for (int i=0; i < flippers.size(); i++) {
        flippers.at(i).posZ = 0;
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