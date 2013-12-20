//
//  PhysicsEngine.cpp
//  Graphics-Final-Project
//
//  Created by Kirisanth Subramaniam on 2013-12-18.
//  Copyright (c) 2013 Kirisanth Subramaniam. All rights reserved.
//

#include "PhysicsEngine.h"
#include "ray.h"

//Physics Engine Constructor
PhysicsEngine::PhysicsEngine()
{
    time = 0.0002;
}


//Used to uppdate points by applying kinematic equation
void PhysicsEngine::moveParticle()
{
    ball.posX += (ball.velX * time) + (0.5 * (ball.accX * (time * time)));
    ball.velX = ball.velX + (ball.accX * time);
    ball.posY += (ball.velY * time) + (0.5 * (ball.accY * (time * time)));
    ball.velX = ball.velX + (ball.accX * time);
    ball.posZ += (ball.velZ * time) + (0.5 * (ball.accZ * (time * time)));
    ball.velX = ball.velX + (ball.accX * time);
    collisionTest();
};

//Calculates new vector after bounce
//implementation taken from:
//http://stackoverflow.com/questions/573084/how-to-calculate-bounce-angle
Vec3D PhysicsEngine::CalculateBounceVector(double nX,double nY,double nZ,double vX,double vY,double vZ)
{
    //initialization
    Math3dhelpers Math;
    Vec3D ballMotionVector = Vec3D(vX, vY, vZ);
    Vec3D normal = Vec3D(nX, nY, nZ);
    Vec3D newVector;
    
    //Step 1 - Vector Projection
    double tmpValue = Math.dot(ballMotionVector, normal) / Math.dot(normal, normal);
    Vec3D uVector = Math.scalarVectorMultiply(tmpValue, nX, nY, nZ);
    
    //Step 2 - Vector Subtraction
    Vec3D wVector = Math.vectorSubtract(ballMotionVector, uVector);
    
    //Step 3 - Vector Subtraction
    newVector = Math.vectorSubtract(wVector, uVector);
    
    return newVector;
};

//Used to test for collisions
//iterates through all objects and find if ball is close to objects
void PhysicsEngine::collisionTest()
{
    Math3dhelpers Math;//Math Helper
    
    //store ray orgin
    collision.org[0] = ball.posX;
    collision.org[1] = ball.posY;
    collision.org[2] = ball.posZ;
    
    //ray direction is the vector (pFar - pNear)
    collision.dir[0] = ball.velX;
    collision.dir[1] = ball.velY;
    collision.dir[2] = ball.velZ;
    
    //iteration through objects
    for (int x=0; x < ActiveObjects.size(); x++) {
        //iteration through object's normals
        for(int y = 0; y < 6; y++){
        
            //normalize direction vector
            collision.normalizeDirection();
            
            //undergoes ray plane test
            groundPlane = collision.rayPlaneTest(x, y, ActiveObjects);
            
            //update the position of the object to the intersection point
            if ( groundPlane == true){
                collision.objectPos[0] = collision.inter[0];
                collision.objectPos[1] = collision.inter[1];
                collision.objectPos[2] = collision.inter[2];
                //check if object is hit between min and max bounds
                float t1 = collision.inter[0] - ball.posX;
                float t2 = collision.inter[1] - ball.posY;
                float t3 = collision.inter[2] - ball.posZ;
                Vec3D v = Vec3D(t1, t2, t3);
                double distanceFromCenter = Math.distance3D(v);
                if (distanceFromCenter < 0.25 && distanceFromCenter > 0){
                    if ((ActiveObjects.at(x).min + ActiveObjects.at(x).translateX < collision.inter[0] && collision.inter[0] < ActiveObjects.at(x).max + ActiveObjects.at(x).translateX && ActiveObjects.at(x).min + ActiveObjects.at(x).translateZ < collision.inter[2] && collision.inter[2] < ActiveObjects.at(x).max + ActiveObjects.at(x).translateZ && collision.inter[1] < ActiveObjects.at(x).max + ActiveObjects.at(x).translateY && ActiveObjects.at(x).min + ActiveObjects.at(x).translateY < collision.inter[1])){
                    
                        double normal[] = {ActiveObjects.at(x).normal[y][0],ActiveObjects.at(x).normal[y][1],ActiveObjects.at(x).normal[y][2]};

                        Vec3D bounceVector = CalculateBounceVector(normal[0], normal[1], normal[2], ball.velX, ball.velY, ball.velZ);
                        ball.velX = bounceVector.xComponent;
                        ball.velY = bounceVector.yComponent;
                        ball.velZ = bounceVector.zComponent;
                        points.setPoints(10);
                        break;
                    }
                }
            }
        }
    }
    
    //iteration through platform/game machine/walls
    for (int count = 0; count < 5; count++){
        //normalize direction vector
        collision.normalizeDirection();
        
        //undergoes ray plane test
        groundPlane = collision.rayPlaneTest(count, pinballStruct);
        //update the position of the object to the intersection point
        if ( groundPlane == true){
            collision.objectPos[0] = collision.inter[0];
            collision.objectPos[1] = collision.inter[1];
            collision.objectPos[2] = collision.inter[2];
            //check if object is hit between min and max bounds
            float t1 = collision.inter[0] - ball.posX;
            float t2 = collision.inter[1] - ball.posY;
            float t3 = collision.inter[2] - ball.posZ;
            Vec3D v = Vec3D(t1, t2, t3);
            double distanceFromCenter = Math.distance3D(v);
            if (distanceFromCenter < 0.25){
                if(collision.inter[1] > -1.9 && collision.inter[1] < 4.9 && collision.inter[2] > 0 && collision.inter[2] <= 2.5){
                
                    double normal[] = {pinballStruct.platformNormal[count][0],pinballStruct.platformNormal[count][1],pinballStruct.platformNormal[count][2]};
                    
                    Vec3D bounceVector = CalculateBounceVector(normal[0], normal[1], normal[2], ball.velX, ball.velY, ball.velZ);
                    ball.velX = bounceVector.xComponent;
                    ball.velY = bounceVector.yComponent;
                    ball.velZ = bounceVector.zComponent;
                    //call calculate bounce vector
                    break;
                }
            }
        }

    }
    
    //iteration through flippers
    for (int count = 0; count < 2; count++){
        //normalize direction vector
        collision.normalizeDirection();
        //flipperStruct.CalculateNormal();
        //undergoes ray plane test
        groundPlane = collision.rayPlaneTest(count, flipperStruct);

        //update the position of the object to the intersection point
        if ( groundPlane == true){
            collision.objectPos[0] = collision.inter[0];
            collision.objectPos[1] = collision.inter[1];
            collision.objectPos[2] = collision.inter[2];
            
            //check if object is hit between min and max bounds
            float t1 = collision.inter[0] - ball.posX;
            float t2 = collision.inter[1] - ball.posY;
            float t3 = collision.inter[2] - ball.posZ;
            Vec3D v = Vec3D(t1, t2, t3);
            
            double distanceFromCenter = Math.distance3D(v);
            if (distanceFromCenter < 0.25){
                if (count == 0){
                    
                    if(collision.inter[0] > 0.4 && collision.inter[0] < 2.5 && collision.inter[2] > 0 && collision.inter[2] < 2.5){
                    
                        double normal[] = {flipperStruct.flipperNormal[count][0],flipperStruct.flipperNormal[count][1],flipperStruct.flipperNormal[count][2]};
                        
                        Vec3D bounceVector = CalculateBounceVector(normal[0], normal[1], normal[2], ball.velX, ball.velY, ball.velZ);
                        ball.velX = bounceVector.xComponent;
                        ball.velY = bounceVector.yComponent;
                        ball.velZ = bounceVector.zComponent;
                        //call calculate bounce vector
                        break;
                    }
                }
                else if(count == 1){
                    if(collision.inter[0] > -2.5 && collision.inter[0] < -0.4 && collision.inter[2] > 0 && collision.inter[2] < 2.5){
                        
                        double normal[] = {flipperStruct.flipperNormal[count][0],flipperStruct.flipperNormal[count][1],flipperStruct.flipperNormal[count][2]};
                        
                        Vec3D bounceVector = CalculateBounceVector(normal[0], normal[1], normal[2], ball.velX, ball.velY, ball.velZ);
                        ball.velX = bounceVector.xComponent;
                        ball.velY = bounceVector.yComponent;
                        ball.velZ = bounceVector.zComponent;
                        //call calculate bounce vector
                        break;
                    }
                }
            }
        }
        
    }
};