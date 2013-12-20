//
//  Texture.h
//  Graphics-Final-Project
//
//  Created by Kirisanth Subramaniam on 2013-12-18.
//  Copyright (c) 2013 Kirisanth Subramaniam. All rights reserved.
//

#ifndef __Graphics_Final_Project__Texture__
#define __Graphics_Final_Project__Texture__

#include <iostream>
#include <stdlib.h>
#include <GLUT/glut.h>
class Texture{
    public:
        Texture();
        GLuint textures[4];
        GLubyte* image[4];
        int width[4]; int
        height[4];
        int maxNum[4];
        GLubyte* LoadPPM(const char* file, int* width, int* height, int* max);
        void loadTexture();
        void drawPlane();
    
};

#endif /* defined(__Graphics_Final_Project__Texture__) */
