//
//  Particle.cpp
//  GC3AssignmentTwo
//
//  Created by Meraj Patel on 11/8/2013.
//  Copyright (c) 2013 Meraj Patel. All rights reserved.
//

#include "Particle.h"

//intialize particles to 0 values if object of class is created
Particle::Particle()
{
    point2D particlePoint;
    color particleColor;
    particleSize = 0;
    velY = 10;
    velX = 0;
    velZ = 0;
    posX = 0;
    posZ = 0.5;
    posY = 4.2;
    rotationX = 0;
    rotationY = 0;
    rotationZ = 0;
    accX = 0;
    accY = -9.8;
    accY = -1;
    age = 200;
    friction = 1;
    
};


void Particle::drawSphere(){
    glPushMatrix();
    glTranslatef(posX, posY, posZ);
    glColor3f(1,1,1);
    glutSolidSphere(0.1, 10, 10);
    glPopMatrix();
}

//Resposible for handeling movement of particles in terms of velocity and acceleration
void Particle::updatePosition(){
    posX = posX + (velX *speed) + (accY * speed*speed) *0.5;//standard physics equation for determing new position at X
    posY = posY + (velY *speed) + (accY * speed*speed) *0.5;//standard physics equation for determing new position at Y
    posZ = posZ + (velZ *speed) + (accY * speed*speed) *0.5;//standard physics equation for determing new position at Z
    velY = velY + (accY *speed);//Calculate new velocity speed for Y component
    particleManipulation();//call to allow particle manipulation
    
}

//responsible for handling wind turbine feature; changing velocity of particle if it comes in contact
void Particle::windFan(){
    
    if (posX == -1.7 && posY < 2 && posY > 1 && posZ < 2.5 && posZ > 1.9){//change velocity to 10 for x if it comes in that direction
        velX = 10;
    }
    if (velY <= 1 && posX > -2.3 && posX < -1.7 && posZ > 1.9 && posZ < 2.5){//change velocity to 10 for y if it comes in that direction
        velY = 10;
    }
    if (posX <= -1.7 && posX > -2.3 && posY < 2 && posY > 1 && posZ <= 1.9){//change velocity to -10 for z if it comes in that direction
        velZ = -10;
    }
    
    
}

//Responsible for particle manipulation; bounce, friction, making a call to wind turbine
void Particle::particleManipulation(){
    
    if(normalMode == true) {//check if user selected normal mode
        windFan();//turn on turbine effect
        if (posY < 0){//check if it hits the floor
            velY = -velY * friction;//cause bounce if so with friciton
            
            if(posX < 1.4 && posX > 0.6 && posZ < 1.4 && posZ > 0.6){//check to see if on black hole
                velY = -velY;//cause particle to fall through it
                velX = 0;
                velZ = 0;
            }
            else if (posX > 2.8 || posX < -2.8 || posZ > 2.8 || posZ < -2.8){//check to see if outsife platform
                velY = -velY;//cause particle to fall
            }
        }
        if (posY <= -1 ){//reset particle position if falls past -1
            resetParticlePosition();
        }
    }
    else if (rainMode == true){//check if user selected rain mode
        if (posY <= 0 ){//reset particle position if rain touches platform
            rainParticles();
        }
    }
    else if (snowMode == true){//check if user selected snow mode
        if (posY <= 0 ){//reset particle position if snow touches platform
            snowParticles();
        }
    }
    
}

//Responsible for reseting normal particle position
void Particle::resetParticlePosition() {
    
    float size = rand() % (20 - 10) + 4;//randomize size
    
    //randomize color
    int r = 0;
    int g = 0;
    int b = 0;
    while (r == 0 & b == 0 & g ==0){
        r = rand() % 2;
        g = rand() % 2;
        b = rand() % 2;
    }
    float newPosX = (rand() % (60 - 1) + 1);//randomize position between -0.3 - 0.3
    newPosX = (newPosX - 30)/100;
    float newPosZ = (rand() % (60 - 1) + 1);//randomize position between -0.3 - 0.3
    newPosZ = (newPosZ - 30)/100;
    double newVelX = (rand() % (30 - 1) + 1);//randomize velocity between -1.5 - 1.5
    newVelX = (newVelX - 15)/10 ;
    double newVelZ = (rand() % (30 - 1) + 1);//randomize velcoity between -1.5 - 1.5
    newVelZ = (newVelZ - 15)/10 ;
    double newVelY = (rand() % (9 - 3) + 3);//randomize velocity between 9 - 3
    int newAge = (rand() % (10 - 3) + 3);//randomize age between 10 - 3
    newAge = newAge * 50;//add life to particle
    
    //setting randomize properties to assigned variables
    color newParticleColor(r,g,b);
    particleColor = newParticleColor;
    particleSize = size;
    velY = newVelY;
    velX = newVelX;
    velZ = newVelZ;
    posX = newPosX;
    posZ = newPosZ;
    posY = 0.5;
    accY = -9.8;
    age = newAge;
    rotationX = rand() % 2;
    rotationY = rand() % 2;
    rotationZ = rand() % 2;
}

//set particle properties to simplest or primary values
void Particle::resetParticleProperties(){
    point2D particlePoint;
    color particleColor;
    particleSize = 0;
    velY = 0;
    velX = 0;
    velZ = 0;
    posX = 0;
    posZ = 0;
    posY = 0;
    rotationX = 0;
    rotationY = 0;
    rotationZ = 0;
    accY = -9.8;
    age = 200;
    friction = 1;
    speed = 0.015;
    
}

//Responsible for reseting rain particle position
void Particle::rainParticles(){
    float newPosX = (rand() % (400 - 1) + 1);//randomize position between -2 - 2
    newPosX = (newPosX - 200)/100;
    float newPosZ = (rand() % (400 - 1) + 1);//randomize position between -2 - 2
    newPosZ = (newPosZ - 200)/100;
    int newAge = (rand() % (10 - 3) + 3);//randomize age between 10 - 3
    newAge = newAge * 50;//add life to particle
    double newVelY = (rand() % (9 - 3) + 3);//randomize velocity between 9 - 3
    
    //setting randomize properties to assigned variables
    color newParticleColor(0,0,1);
    particleColor = newParticleColor;
    particleSize = 5;
    velY = newVelY;
    velX = 0;
    velZ = 0;
    posX = newPosX;
    posZ = newPosZ;
    posY = 6;
    accY = -9.8;
    age = newAge;
    speed = 0.015;
    
}

//Responsible for reseting rain particle position
void Particle::snowParticles(){
    float newPosX = (rand() % (60 - 1) + 1);//randomize position between -0.3 - 0.3
    newPosX = (newPosX - 30)/100;
    float newPosZ = (rand() % (60 - 1) + 1);//randomize position between -0.3 - 0.3
    newPosZ = (newPosZ - 30)/100;
    double newVelX = (rand() % (30 - 1) + 1);//randomize velocity between -1.5 - 1.5
    newVelX = (newVelX - 15)/10 ;
    double newVelZ = (rand() % (30 - 1) + 1);//randomize velocity between -1.5 - 1.5
    newVelZ = (newVelZ - 15)/10 ;
    double newVelY = (rand() % (9 - 3) + 3);//randomize velocity between 9 - 3
    int newAge = (rand() % (2 - 1) + 3);//randomize age between 10 - 3
    newAge = newAge * 10000;//add life to particle
    
    
    color newParticleColor(1,1,1);
    particleColor = newParticleColor;
    particleSize = 6;
    velY = newVelY;
    velX = newVelX;
    velZ = newVelZ;
    posX = newPosX;
    posZ = newPosZ;
    posY = 6;
    accY = -4.8;
    age = newAge;
    speed = 0.01;
}
