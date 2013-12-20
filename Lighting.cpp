//
//  Lighting.cpp
//  Graphics-Final-Project
//
//  Created by Kirisanth Subramaniam on 2013-12-20.
//  Copyright (c) 2013 Kirisanth Subramaniam. All rights reserved.
//

#include "Lighting.h"

Lighting::Lighting()
{
//    GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
//    GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
//    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
//    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
//    float origin[] = {0,0,0,1};
    light_ambient[0] = 0.33;
    light_ambient[1] = 0.22;
    light_ambient[2] = 0.03;
    light_ambient[3] = 1.0;
    
    light_diffuse[0] = 0.78;
    light_diffuse[1] = 0.57;
    light_diffuse[2] = 0.11;
    light_diffuse[3] = 1.0;
    
	light_specular[1] = 0.99;
    light_specular[1] = 0.91;
    light_specular[1] = 0.81;
    light_specular[1] = 1.0;
//	shiny = 27;
    
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
//    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}


void Lighting::lightBall()
{
    GLfloat lightpos[] = {.5, 1., 1., 0.};
    glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
}
void Lighting::lightObject()
{
    
}
void Lighting::setLightLocation()
{
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
}