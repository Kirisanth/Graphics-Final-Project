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
    point2D particlePoint;
    color particleColor;
    float particleSize;
    double posX, posY, posZ;//store positions of particle
    double velX, velY, velZ;//store velocity of particles
    double accX, accY, accZ;//store accerleration of particles
    double friction;//store friction coeffecitent of particles
    //store rotation angles of particles
    int rotationX;
    int rotationY;
    int rotationZ;
    int age;//store age of particle
    double speed = 0.018;//store speed of particle
    bool rainMode = true, snowMode, normalMode = false;//particle type
    Particle();
    void updatePosition();
    void resetParticlePosition();
    void particleManipulation();
    void resetParticleProperties ();
    void rainParticles();
    void snowParticles();
    void windFan();
};
#endif /* defined(__GC3AssignmentTwo__Particle__) */
