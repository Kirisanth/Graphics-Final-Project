//
//  Points.cpp
//  Graphics-Final-Project
//
//  Created by Meraj Patel on 12/19/2013.
//  Copyright (c) 2013 Kirisanth Subramaniam. All rights reserved.
//

#include "Points.h"

Points::Points(){
    points = 0;
};

void Points::setPoints(int x){
    points = points +x;
}

void Points::dispalyPoints(){
    
    glPushMatrix();
    char *b= "3GC3 Pinball 3D";
    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos3f( -2.0f , 6.0f ,0 );
    for(int i = 0; b[i] != '\0'; i++)
        glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18 , b[i]);
    glPopMatrix();
    
    glPushMatrix();
    char *a= "Points: ";
    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos3f( 2.0f , -1.0f ,4.0f );
    for(int i = 0; a[i] != '\0'; i++)
        glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18 , a[i]);
    
    
    std::string s = std::to_string(points);
    char const *pchar = s.c_str();
    for (int count = 0; pchar[count] != '\0'; count++){
        glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18 , pchar[count]);
    }
    glPopMatrix();
}

void Points::gameOver(){
    char *c= "GAME OVER - PLEASE PRESS R TO TRY AGAIN";
    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos3f( -3.0f , 2.0f ,4.0f );
    for(int i = 0; c[i] != '\0'; i++)
        glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18 , c[i]);
}




