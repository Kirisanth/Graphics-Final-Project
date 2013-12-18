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
    color particleColor;//store color properties of object
    float particleSize;//store size property
    double posX, posY, posZ;//store positions of particle (center)
    double velX, velY, velZ;//store velocity of particles

    //constructor
    Particle();
    Particle(float initialSpeed);
    
    
    
    //methods
    void drawSphere();
    
    void resetParticleProperties ();
    void particleManipulation();
    void updatePosition();
    void resetParticlePosition();
    
    
    //------------------------------------------------------
    //TODO: DO WE NEED THIS
    point2D particlePoint;
    double speed = 0.018;//store speed of particle
    
    //store rotation angles of particles
    int rotationX;
    int rotationY;
    int rotationZ;
    
    //TODO: Move to PhysicsEngine
    double accX, accY, accZ;//store accerleration of particles
    double friction;//store friction coeffecitent of particles

    //TODO: Remove
    int age;//store age of particle
    bool rainMode = true, snowMode, normalMode = false;//particle type
    void rainParticles();
    void snowParticles();
    void windFan();
};
#endif /* defined(__GC3AssignmentTwo__Particle__) */
