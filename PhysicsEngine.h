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
    
    //method
    //TODO: Functions needed
    //constructor
public:
    //fields
    float time;
    Particle ball = Particle();
    //store particle
    //stores all active objects
    std::vector<ObjectsModel> ActiveObjects;
    Walls pinballStruct;
    Flipper flipperStruct;
    ray collision;
    Points points;
    //movement gravity
    //constructor
    PhysicsEngine();
    
    bool groundPlane; //forst line test

    //methods
    void addObject();
//    void moveParticle(Particle ball);
    void moveParticle();
    //collision detection
//    void collision(std::vector<Particle>& ball, std::vector<ObjectsModel>& vector);
    void collisionTest();
    Vec3D CalculateBounceVector(double n1,double n2,double n3,double v1,double v2,double v3);
    //
    
};




#endif /* defined(__Graphics_Final_Project__PhysicsEngine__) */
