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
    //std::vector<Particle> * ActiveObjects;
    //movement gravity
    //constructor
    PhysicsEngine();

    //methods
    void addObject();
//    void moveParticle(Particle ball);
    void moveParticle();
    //collision detection
//    void collision(std::vector<Particle>& ball, std::vector<ObjectsModel>& vector);
    void collision(Particle ball, std::vector<ObjectsModel>& currentObjects, std::vector<ObjectsModel>& wall, std::vector<ObjectsModel>& flippers);
    //
    
};




#endif /* defined(__Graphics_Final_Project__PhysicsEngine__) */
