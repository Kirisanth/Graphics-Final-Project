//
//  Lighting.h
//  Graphics-Final-Project
//
//  Created by Kirisanth Subramaniam on 2013-12-20.
//  Copyright (c) 2013 Kirisanth Subramaniam. All rights reserved.
//

#ifndef __Graphics_Final_Project__Lighting__
#define __Graphics_Final_Project__Lighting__

#include <iostream>
#include <GLUT/glut.h>

class Lighting {
    
public:
    //fields
//    GLfloat light_ambient[4];
//    GLfloat light_diffuse[4];
//    GLfloat light_specular[4];
//    GLfloat light_position[4];
    
    GLfloat light_ambient[4] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light_diffuse[4] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_specular[4] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_position[4] = { 1.0, 1.0, 1.0, 0.0 };
    //constructor
    //instantiated on the stack
    Lighting();
    //methods
    void initialize();
    void lightBall();
    void lightObject();
    void setLightLocation();
//    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
};


#endif /* defined(__Graphics_Final_Project__Lighting__) */
