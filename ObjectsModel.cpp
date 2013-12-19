//
//  ObjectsModel.cpp
//  Graphics-Final-Project
//
//  Created by Kirisanth Subramaniam on 2013-12-17.
//  Copyright (c) 2013 Kirisanth Subramaniam. All rights reserved.
//

#include "ObjectsModel.h"

ObjectsModel::ObjectsModel()
{
//    point2D particlePoint;
//    color objectColor;
    

        r = (rand() % (100 - 1) + 1);
        r = r/100;
        g = (rand() % (100 - 1) + 1);
        g = r/100;
        b = (rand() % (100 - 1) + 1);
        b = r/100;
    
    translateX = (rand() % (400 - 1) + 1);//randomize position between 2.5 - -2.5
    translateX = (translateX - 250)/100;
    translateY = (rand() % (420 - 1) + 1);//randomize position between -0.3 - 0.3
    translateY = (translateY)/100;
    translateZ = (rand() % (200 - 1) + 1);//randomize velocity between -1.5 - 1.5
    translateZ = (translateZ)/100 + 0.3;
    
    scale = (rand() % (10 - 1) + 1);//randomize velocity between -1.5 - 1.5
    scale = scale/100 ;
    min = min - scale/2;
    max = max + scale/2;
    
    objectType = (rand() % 4);//randomize velocity between -1.5 - 1.5
    
    normal[0][0] = 0;
    normal[0][1] = 0;
    normal[0][2] = 1;
    pointsForNormal[0][0] = (0.25 + translateX);
    pointsForNormal[0][1] = (-0.25 + translateY) ;
    pointsForNormal[0][2] = (0.25 + translateZ) ;
    
    normal[1][0] = 0;
    normal[1][1] = 0;
    normal[1][2] = -1;
    pointsForNormal[1][0] = (-0.25 + translateX) ;
    pointsForNormal[1][1] = (-0.25 + translateY) ;
    pointsForNormal[1][2] = (-0.25 + translateZ);
    
    normal[2][0] = 1;
    normal[2][1] = 0;
    normal[2][2] = 0;
    pointsForNormal[2][0] = (0.25 + translateX) ;
    pointsForNormal[2][1] = (-0.25 + translateY) ;
    pointsForNormal[2][2] = (-0.25 + translateZ) ;
    
    normal[3][0] = -1;
    normal[3][1] = 0;
    normal[3][2] = 0;
    pointsForNormal[3][0] = (-0.25 + translateX) ;
    pointsForNormal[3][1] = (-0.25 + translateY);
    pointsForNormal[3][2] = (-0.25 + translateZ) ;
    
    normal[4][0] = 0;
    normal[4][1] = 1;
    normal[4][2] = 0;
    pointsForNormal[4][0] = (0.25 + translateX) ;
    pointsForNormal[4][1] = (0.25 + translateY) ;
    pointsForNormal[4][2] = (0.25 + translateZ) ;
    
    normal[5][0] = 0;
    normal[5][1] = 1;
    normal[5][2] = 0;
    pointsForNormal[5][0] = (-0.25 + translateX) ;
    pointsForNormal[5][1] = (-0.25 + translateY) ;
    pointsForNormal[5][2] = (-0.25 + translateZ) ;

    objectSize = 0;
    
};

void ObjectsModel::objectTranslateX(double x){
    translateX = translateX + x;
}

void ObjectsModel::objectTranslateY(double y){
    translateY = translateY + y;
}

void ObjectsModel::objectTranslateZ(double z){
    translateZ = translateZ + z;
}

void ObjectsModel::drawObjects(){
    
    glColor3f(r, g, b);
    glPushMatrix();
    glTranslatef(translateX, translateY, translateZ);
    if (objectType == 1){
        glutSolidCube(0.5 + scale);
    }
    else if (objectType == 2){
        glutSolidSphere(0.3 + scale, 15, 15);
    }
    else if (objectType == 3){
        glutSolidTorus(0.1 + scale, 0.2 + scale, 10, 10);
    }
    if (hit == true){
        glutWireCube(0.7 + scale);
    }
    glPopMatrix();
}



