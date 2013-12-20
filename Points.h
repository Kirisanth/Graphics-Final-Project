//
//  Points.h
//  Graphics-Final-Project
//
//  Created by Meraj Patel on 12/19/2013.
//  Copyright (c) 2013 Kirisanth Subramaniam. All rights reserved.
//

#ifndef __Graphics_Final_Project__Points__
#define __Graphics_Final_Project__Points__

#include <iostream>
#include <stdlib.h>
#include <GLUT/glut.h>

class Points{
    public:
    Points();
    int points;
    void setPoints(int x);
    void dispalyPoints();
    void gameOver();
};

#endif /* defined(__Graphics_Final_Project__Points__) */
