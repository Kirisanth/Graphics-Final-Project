//
//  PhysicsEngine.h
//  Graphics-Final-Project
//
//  Created by Kirisanth Subramaniam on 2013-12-18.
//  Copyright (c) 2013 Kirisanth Subramaniam. All rights reserved.
//

#ifndef __Graphics_Final_Project__PhysicsEngine__
#define __Graphics_Final_Project__PhysicsEngine__

#include <iostream>
#include <vector>
#include "Particle.h"
#include "ObjectsModel.h"
#include "Walls.h"
#include "ray.h"
#include "MathLibrary.h"
#include "Points.h"
#include "Flipper.h"



class PhysicsEngine {
    
public:
    //fields
    float time;
    Particle ball = Particle();//store particle
    std::vector<ObjectsModel> ActiveObjects;//stores all active objects
    Walls pinballStruct;//stores pinball machine walls
    Flipper flipperStruct;//stores pinball flippers
    ray collision;
    Points points;
    //constructor
    PhysicsEngine();
    //methods
    bool groundPlane; //forst line test
    void addObject();
    void moveParticle();
    void collisionTest();    //collision detection
    Vec3D CalculateBounceVector(double n1,double n2,double n3,double v1,double v2,double v3);
};




#endif /* defined(__Graphics_Final_Project__PhysicsEngine__) */
