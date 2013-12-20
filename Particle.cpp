//
//  Particle.cpp
//  GC3AssignmentTwo
//
//  Created by Meraj Patel on 11/8/2013.
//  Copyright (c) 2013 Meraj Patel. All rights reserved.
//

#include "Particle.h"

//Particle Constructor
Particle::Particle()
{
    velY = -500;
    velX = (rand() % (70 - 50) + 1);
    velZ = (rand() % (70 - 50) + 1);
    posX = 1;
    posZ = 0.5;
    posY = 4.2;
    accX = 0;
    accY = -9.8;
    accY = -1;
};

//Renders into OpenGl enviroment
void Particle::drawSphere(){
    glPushMatrix();
    glTranslatef(posX, posY, posZ);
    glColor3f(1,1,1);
    glutSolidSphere(0.1, 10, 10);
    glPopMatrix();
}


