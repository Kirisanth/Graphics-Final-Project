//
//  Texture.cpp
//  Graphics-Final-Project
//
//  Created by Kirisanth Subramaniam on 2013-12-18.
//  Copyright (c) 2013 Kirisanth Subramaniam. All rights reserved.
//

#include "Texture.h"


#include <stdio.h>
#include <stdlib.h>

Texture::Texture(){
    
};

GLubyte* Texture::LoadPPM(const char* file, int* width, int* height, int* max){
    GLubyte* img;
	FILE *fd;
	int n, m;
	int  k, size;
	char c;
	int i;
	char b[100];
	float s;
	int red, green, blue;
    
	//open the file in read mode
	fd = fopen(file, "r");
    
	//scan everything up to newline
	fscanf(fd,"%[^\n] ",b);
    
	//check if the first two characters are not P3, if not, it's not an ASCII PPM file
	if(b[0]!='P'|| b[1] != '3')
	{
		printf("%s is not a PPM file!\n",file);
		exit(0);
	}
    
	printf("%s is a PPM file\n", file);
    
	//read past the file comments: scan for lines that begin
	//  with #, and keep going until you find no more
	fscanf(fd, "%c",&c);
	while(c == '#')
	{
		fscanf(fd, "%[^\n] ", b);
		printf("%s\n",b);
		fscanf(fd, "%c",&c);
	}
    
	//rewind the read pointer one character, or we'll lose the size
	ungetc(c,fd);
    
	//read the rows, columns and max colour values
	fscanf(fd, "%d %d %d", &n, &m, &k);
    
	printf("%d rows  %d columns  max value= %d\n",n,m,k);
    
	//number of pixels is rows * columns
	size = n*m;
    
	//allocate memory to store 3 GLuints for every pixel
	img =  (GLubyte *)malloc(3*sizeof(GLuint)*size);
    
	//scale the colour in case maxCol is not 255
	s=255.0/k;
    
	//start reading pixel colour data
	for(i=0;i<size;i++)
	{
		fscanf(fd,"%d %d %d",&red, &green, &blue );
		img[3*size-3*i-3]=red*s;
		img[3*size-3*i-2]=green*s;
		img[3*size-3*i-1]=blue*s;
	}
    
	*width = n;
	*height = m;
	*max = k;
    
	return img;
}



void Texture::loadTexture()
{
    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &textures);
    
    image = LoadPPM("feep.ppm", &width, &height, &max);
    
	glBindTexture(GL_TEXTURE_2D, textures);
	
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    
}

void Texture::drawPlane(){
    
    glEnable(GL_TEXTURE_2D);
    
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, textures);
    
    glColor3f(0.2,0.4,0.7);
    glBegin(GL_QUADS);
    glNormal3d(0,1,0);
    glTexCoord2f(1,0);
    glVertex3f(-20, -2, 20);
    glTexCoord2f(0,0);
    glVertex3f(20, -2, 20);
    glTexCoord2f(0,1);
    glVertex3f(20, -2, -20);
    glTexCoord2f(1,1);
    glVertex3f(-20, -2, -20);
    glEnd();
    
    glColor4f(1, 1, 1, 1);
    
    glDisable(GL_COLOR_MATERIAL);
    glPopMatrix();
    
    glDisable(GL_TEXTURE_2D);
    
}
