//
//  PhysicsEngine.cpp
//  Graphics-Final-Project
//
//  Created by Kirisanth Subramaniam on 2013-12-18.
//  Copyright (c) 2013 Kirisanth Subramaniam. All rights reserved.
//

#include "PhysicsEngine.h"


PhysicsEngine::PhysicsEngine()
{
    
}


//used to uppdate points by applying kinematic equation
void PhysicsEngine::moveParticle(Particle ball)
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