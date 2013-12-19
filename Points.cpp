//
//  Points.cpp
//  Graphics-Final-Project
//
//  Created by Meraj Patel on 12/19/2013.
//  Copyright (c) 2013 Kirisanth Subramaniam. All rights reserved.
//

#include "Points.h"

Points::Points(){
    //static int points = 0;
};

void Points::setPoints(int x){
    points = points +x;
}

void dispalyPoints(){
    char *a= "Points: ";
    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos3f( 2.0f , -1.0f ,4.0f );
    for(int i = 0; a[i] != '\0'; i++)
        glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18 , a[i]);
    
    std::string s = std::to_string(4000);
    char const *pchar = s.c_str();
    for (int count = 0; pchar[count] != '\0'; count++){
        glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18 , pchar[count]);
    }
}

