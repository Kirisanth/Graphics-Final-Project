//
//  ray.h
//  Graphics-Final-Project
//
//  Created by Meraj Patel on 12/4/2013.
//  Copyright (c) 2013 Kirisanth Subramaniam. All rights reserved.
//

#ifndef __Graphics_Final_Project__ray__
#define __Graphics_Final_Project__ray__

#include <iostream>

class ray{
public:
    double org[3];
    double dir[3];
    double norm[3];
    ray();
    void normalizeDirection();
    void findDistance(int i);
    void normalMultiplyDirection(int i);
    
};

#endif /* defined(__Graphics_Final_Project__ray__) */
