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
#include <GLUT/glut.h>



class Texture {
    int time;
    
public:
    Texture();
        //    Texture();
    GLubyte* LoadPPM(char* file, int* width, int* height, int* max);
//    void LoadPPM(char* file, int* width, int* height, int* max);
    

};


#endif /* defined(__Graphics_Final_Project__Texture__) */
