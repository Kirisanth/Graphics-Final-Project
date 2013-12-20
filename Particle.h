//
//  Particle.h
//  GC3AssignmentTwo
//
//  Created by Meraj Patel on 11/8/2013.
//  Copyright (c) 2013 Meraj Patel. All rights reserved.
//

#ifndef __GC3AssignmentTwo__Particle__
#define __GC3AssignmentTwo__Particle__

#include <iostream>
#include <stdlib.h>
#include <GLUT/glut.h>
#include "MathLibrary.h"

class Particle
{
public:
    //field properties
//    float particleSize;//store size property
    double posX, posY, posZ;//store positions of particle (center)
    double velX, velY, velZ;//store velocity of particles


    //constructor
    Particle();
    
    //methods
    void drawSphere();
    
    //TODO: Move to PhysicsEngine
    double accX, accY, accZ;//store accerleration of particles

};
#endif /* defined(__GC3AssignmentTwo__Particle__) */
