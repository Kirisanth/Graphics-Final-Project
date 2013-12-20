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
    //    float origin[] = {0,0,0,1};
    //    light_ambient[0] = 0.33;
    //    light_ambient[1] = 0.22;
    //    light_ambient[2] = 0.03;
    //    light_ambient[3] = 1.0;
    //
    //    light_diffuse[0] = 0.78;
    //    light_diffuse[1] = 0.57;
    //    light_diffuse[2] = 0.11;
    //    light_diffuse[3] = 1.0;
    //
    //	light_specular[1] = 0.99;
    //    light_specular[1] = 0.91;
    //    light_specular[1] = 0.81;
    //    light_specular[1] = 1.0;
    //	shiny = 27;

    
    
}

void Lighting::initialize()
{
//    glEnable(GL_LIGHTING);
//    glEnable(GL_LIGHT0);
//    glClearColor (0.0, 0.0, 0.0, 0.0);
//    glShadeModel (GL_SMOOTH);
//    glEnable(GL_LIGHTING);
//    glEnable(GL_LIGHT0);
//    glEnable(GL_DEPTH_TEST);
    
    //    std::cout << light_ambient;
    
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    
    //    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    
    
}

void Lighting::lightBall()
{
    GLfloat lightpos[] = {0, 0, 0, 0.};
    glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
    
//    GLfloat light_position[] = { 0.0, 0.0, 1.5, 1.0 };

//    glPushMatrix();
//    gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
//    glPushMatrix();
//    glRotated(spin, 1.0, 0.0, 0.0);
//    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
//    glPopMatrix();
//    glutSolidTorus (0.275, 0.85, 8, 15);
//    glPopMatrix();
    
    
}
void Lighting::lightObject()
{
    
}
void Lighting::setLightLocation()
{
    //    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
}