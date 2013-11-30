//
//  main.m
//  GC3AssignmentTwo
//
//  Created by Meraj Patel on 11/8/2013.
//  Copyright (c) 2013 Meraj Patel. All rights reserved.
//

#include <stdlib.h>
#include <GLUT/glut.h>
#include "MathLibrary.h"
#include "Particle.h"
#include <math.h>


static int numOfParticles = 0;//count num of particles
static Particle particles[5000];//store particles
int particleChoice = 1;//choose particle tep
float angY = 0;//roation around Y
float angX = 0;//rotation around X
float particleSpin = 0;//rotating particles
int age = 1;//age of particles
bool startStop = true;//start stop animation
bool frictionOnOff = false;//turn friction on and off
bool wind = false;//turn wind on and off
bool rainMode = false, snowMode = false, normalMode = true;//allocating modes for desired effects


/*
 Used to draw the cannon resposible for shooting out the particles
 */
void drawCanon(){
    
    glBegin(GL_QUADS);
    
    //platform
    glColor3f(1, 0.3, 1);
    glVertex3f(-0.6,0.5,0.6);
    glVertex3f(0.6,0.5,0.6);
    glVertex3f(0.6,0.5,-0.6);
    glVertex3f(-0.6,0.5,-0.6);
    
    //front
  	glColor3f(1, 1, 1);
    glVertex3f(-0.6, 0, 0.6);
    glVertex3f(0.6, 0, 0.6);
    glVertex3f(0.6, 0.5, 0.6);
    glVertex3f(-0.6, 0.5, 0.6);
    
    //left side
    glColor3f(1, 1, 1);
    glVertex3f(-0.6,0.5,0.6);
    glVertex3f(-0.6,0,0.6);
    glVertex3f(-0.6,0,-0.6);
    glVertex3f(-0.6,0.5,-0.6);
    
    //right side
    glColor3f(1, 1, 1);
    glVertex3f(0.6,0.5,0.6);
    glVertex3f(0.6,0,0.6);
    glVertex3f(0.6,0,-0.6);
    glVertex3f(0.6,0.5,-0.6);
    
    //back side
    glColor3f(1, 1, 1);
    glVertex3f(-0.6,0.5,-0.6);
    glVertex3f(-0.6,0,-0.6);
    glVertex3f(0.6,0,-0.6);
    glVertex3f(0.6,0.5,-0.6);
    
	glEnd();
    
}

/*
 Used to draw actual platform where particles will held and manipulated with
 */

void drawPlatform()
{
    
	glBegin(GL_QUADS);
    
    //platform
    glColor3f(1, 0, 0.3);
    glVertex3f(-2.8,0,2.8);
    glVertex3f(2.8,0,2.8);
    glVertex3f(2.8,0,-2.8);
    glVertex3f(-2.8,0,-2.8);
    
    //bottom
    glColor3f(1, 0, 0.3);
    glVertex3f(-2.8,-0.3,2.8);
    glVertex3f(2.8,-0.3,2.8);
    glVertex3f(2.8,-0.3,-2.8);
    glVertex3f(-2.8,-0.3,-2.8);
    
    //front
  	glColor3f(1, 0, 0.3);
    glVertex3f(-2.8, -0.3, 2.8);
    glVertex3f(2.8, -0.3, 2.8);
    glVertex3f(2.8, 0, 2.8);
    glVertex3f(-2.8, 0, 2.8);
    
    //left side
    glColor3f(1, 0, 0.3);
    glVertex3f(-2.8,0,2.8);
    glVertex3f(-2.8,-0.3,2.8);
    glVertex3f(-2.8,-0.3,-2.8);
    glVertex3f(-2.8,0,-2.8);
    
    //right side
    glColor3f(1, 0, 0.3);
    glVertex3f(2.8,0,2.8);
    glVertex3f(2.8,-0.3,2.8);
    glVertex3f(2.8,-0.3,-2.8);
    glVertex3f(2.8,0,-2.8);
    
    //back side
    glColor3f(1, 0, 0.3);
    glVertex3f(-2.8,0,-2.8);
    glVertex3f(-2.8,-0.3,-2.8);
    glVertex3f(2.8,-0.3,-2.8);
    glVertex3f(2.8,0,-2.8);
    
	glEnd();
    
    //Section used to draw a black hole within the platform, one of the extra features
    glPushMatrix();
    
    glTranslated(1, 0, 1);
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(-0.4,0,0.4);
    glVertex3f(0.4,0,0.4);
    glVertex3f(0.4,0,-0.4);
    glVertex3f(-0.4,0,-0.4);
    glEnd();
    
    glPopMatrix();
    
}

/*
 Section is used for drawing the wind turbine. As white rectangular box floating above the platform
 */
void drawTurbine() {
    
    //particle cannon
    glPushMatrix();
    glTranslated(-2, 1, 2.2);
    
    glBegin(GL_QUADS);
    
    
    //top
    glColor3f(1, 1, 1);
    glVertex3f(-0.3,1,0.3);
    glVertex3f(0.3,1,0.3);
    glVertex3f(0.3,1,-0.3);
    glVertex3f(-0.3,1,-0.3);
    
    //front
  	glColor3f(1, 1, 1);
    glVertex3f(-0.3, 0, 0.3);
    glVertex3f(0.3, 0, 0.3);
    glVertex3f(0.3, 1, 0.3);
    glVertex3f(-0.3, 1, 0.3);
    
    //left side
    glColor3f(1, 1, 1);
    glVertex3f(-0.3,1,0.3);
    glVertex3f(-0.3,0,0.3);
    glVertex3f(-0.3,0,-0.3);
    glVertex3f(-0.3,1,-0.3);
    
    //right side
    glColor3f(1, 1, 1);
    glVertex3f(0.3,1,0.3);
    glVertex3f(0.3,0,0.3);
    glVertex3f(0.3,0,-0.3);
    glVertex3f(0.3,1,-0.3);
    
    
    //back side
    glColor3f(1, 1, 1);
    glVertex3f(-0.3,1,-0.3);
    glVertex3f(-0.3,0,-0.3);
    glVertex3f(0.3,0,-0.3);
    glVertex3f(0.3,1,-0.3);
    
    glEnd();
    glPopMatrix();
    
    
}


/*
 Section used to actual draw each particle out
 */
void drawParticles(){
    for (int i = 0; i < numOfParticles; i++){
        glPushMatrix();
        glTranslated(particles[i].posX,particles[i].posY,particles[i].posZ);//translate particle as per speciation in particle class
        glRotatef(particleSpin, particles[i].rotationX, particles[i].rotationY, particles[i].rotationZ);//add rotation per specification of particle class
        glColor3f(particles[i].particleColor.r, particles[i].particleColor.g, particles[i].particleColor.b);//add color per specification of particle class
        
        /*
         Series of if statements used to depict what kind of particle will be drawn
         That is; WireSphere, WireCube or a vertex
         */
        if (particleChoice == 1){
            glutWireSphere(0.1,15,15);//draw sphere
        }
        else if (particleChoice == 2){
            glutWireCube(0.2);//draw cube
        }
        else {
            glEnable( GL_POINT_SMOOTH );
            glEnable( GL_BLEND );
            glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
            glPointSize(particles[i].particleSize);
			glBegin(GL_POINTS);
			glVertex3f(0,0,0);//draw point
			glEnd();
        }
        glPopMatrix();
    }
}

/*
 Section is used to update the new particle position. Update is called constantly as per idle function.
 With this it constatly redraws it giving it a smooth animation.
 */
void changeParticlePosition(){
    age++;//increment ag counter
	for (int i = 0; i < numOfParticles; i++){
        //check if users wanted friction on or off
        if (frictionOnOff == true) {
            particles[i].friction = 0.8;
        }
        else {
            particles[i].friction = 1;
        }
        //check if user wanted wind on or off
        if (wind == true){
            particles[i].velX = 5;
        }
        //check if particle reached its life span, by seeing if age of particle is divisible by age counter
        //if so, reset the postion
        if( age % particles[i].age == 0 && age >= 100){
            //Check which mode was clicked by the user
            //that is; normal, rain or snow mode
            if(normalMode == true){
                particles[i].resetParticlePosition();
            }
            else if (rainMode == true){
                particles[i].rainParticles();
            }
            else if (snowMode == true){
                particles[i].snowParticles();
            }
            particles[i].age += age;
        }
        particles[i].updatePosition();//apply changes
	}
	glutPostRedisplay();
}


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glRotatef(angY, 1, 0, 0);//rotate scene around x axis
    glRotatef(angX, 0, 1, 0);//rotate scene around y axis
    drawPlatform();//draw platform
    drawCanon();//draw canon
    drawParticles();//draw particles
    drawTurbine();//draw turbine
    glPopMatrix();
    glFlush();
    glutSwapBuffers();
}

/*
 Section used for spawning random normal particle features
 */
void spawnRandomParticles (){
    for (int count = 0; count < 50; count++){
        numOfParticles++;
        particles[numOfParticles].resetParticlePosition();//respawn to normal features
        //turn off other modes, select normal
        particles[numOfParticles].rainMode = false;
        particles[numOfParticles].snowMode = false;
        particles[numOfParticles].normalMode = true;
    }
}

/*
 Section used for spawning rain particle features
 */
void spawnRainParticles (){
    for(int i=0;i<50;i++){
        numOfParticles++;
        particles[numOfParticles].rainParticles();//respawn to rain features
        //turn off other modes, select normal
        particles[numOfParticles].rainMode = true;
        particles[numOfParticles].snowMode = false;
        particles[numOfParticles].normalMode = false;
    }
}

/*
 Section used for spawning snow particle features
 */

void spawnSnowParticles (){
    for(int i=0;i<50;i++){
        numOfParticles++;
        particles[numOfParticles].snowParticles();//respawn to snow features
        //turn off other modes, select normal
        particles[numOfParticles].rainMode = false;
        particles[numOfParticles].snowMode = true;
        particles[numOfParticles].normalMode = false;
    }
}

void kbd(unsigned char key, int x, int y)
{
    y = 500 - y;
    
    if(key == 'q' || key == 27)
	{
		exit(0);
	}
    if ( key == '1'){
        particleChoice = 1;//user wants spheres
        printf("Particle are now spheres\n");
    }
    else if (key == '2'){
        particleChoice = 2;//user wants cubes
        printf("Particle are now cubes\n");
    }
    else if (key == '3'){
        particleChoice = 3;//user wants verticies
        printf("Particle are now vetrticies\n");
    }
    if (key == ' '){
        //check to see if on, is so turn off and vice versa
        if (startStop == true){
            startStop = false;
            printf("stoped animation\n");
        }
        else if (startStop == false){
            startStop = true;
            printf("started animation\n");
        }
    }
    //resets particles to normal mode
    if(key == 'r' || key == '7'){
        for(int i=0;i<numOfParticles;i++){
            particles[numOfParticles].resetParticleProperties();
        }
        numOfParticles = 0;
        spawnRandomParticles();
        //turn of modes and turn on normal
        rainMode = false, snowMode = false, normalMode = true;
        printf("Change setting to normal mode/reset particles \n");
    }
    //turn on/off friction mode
    if(key == 'f'){
        if (frictionOnOff == true){
            frictionOnOff = false;
            printf("Friction off\n");
        }
        else if (frictionOnOff == false){
            frictionOnOff = true;
            printf("Friction on\n");
        }
    }
    //turn on/off wind mode
    if(key == 'w'){
        if (wind == true){
            wind = false;
            printf("Wind off\n");
        }
        else if (wind == false){
            wind = true;
            printf("Wind on\n");
        }
    }
    //turns on rain mode
    if(key == '8'){
        for(int i=0;i<numOfParticles;i++){
            particles[numOfParticles].resetParticleProperties();
        }
        numOfParticles = 0;
        spawnRainParticles();
        rainMode = true, snowMode = false, normalMode = false;
        printf("Reset setting to rain mode\n");
        
    }
    //turn on snow mode
    if(key == '9'){
        for(int i=0;i<numOfParticles;i++){
            particles[numOfParticles].resetParticleProperties();
        }
        numOfParticles = 0;
        spawnSnowParticles();
        rainMode = false, snowMode = true, normalMode = false;
        printf("Reset setting to snow mode\n");
    }
}

void processSpecialKeys(int key, int x, int y) {
    
    //Responsible for camera movement, press right to turn right, left for left, up for up and down for down
    switch(key) {
		case GLUT_KEY_UP:
            angY = angY +1;
            break;
		case GLUT_KEY_DOWN :
            angY = angY -1;
            break;
        case GLUT_KEY_LEFT:
            angX = angX + 1;
            break;
        case GLUT_KEY_RIGHT:
            angX = angX - 1;
            break;
	}
    
}


void idle()
{
    if (startStop == true){
        changeParticlePosition();//update particle position
        particleSpin++;//increment angle so particles can rotate
	}
    glutPostRedisplay();
}

void printCommands(){
    printf("Welcome to Meraj's Particle Fountain!! \n\n");
    printf("Basic Commands: \n");
    printf(" 1) F - friction mode \n 2) Space - stop/start simulation \n 3) Arrow Keys - Scene Rotation \n 4) R - Rest particles \n 5) Esc - Quit Program");
    printf("\n\nExtra Commands: \n\n");
    printf(" 1) 1 - change particle to wire sphere \n 2) 2 - change particle to wire cube (change to this view to see rotation) \n 3) 3 - change particle to vertex \n 4) W - wind mode (blows to the right side) \n 5) 7 - changes setting to normal mode \n 6) 8 - Changes setting to rain mode \n 7) 9 - Changes setting to snow mode \n 8) Particle life - there is not key to activate this, note that the particle life is randowm for all particles");
    printf("\n\nExtra Features: \n\n");
    printf("1) Wind Fan - The white rectangular box hovering over the platform is a wind turbine. Every time a particle comes in proxmity or croses its path (along z axis), i'll be blown away. Note that the particle must be in it's view. \n");
    printf("2) Floor Hole - A black hole is placed on the platform. If particles roll over it or bounce into it, it will fall through into abyss\n\n\n\n\n");
    
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Particle Fountain");
    
	glutKeyboardFunc(kbd);
    glutSpecialFunc(processSpecialKeys);
	glutIdleFunc(idle);
    
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-3.5, 3.5, -3.5, 3.5, -3.5, 3.5);//set view to close up
    
	glMatrixMode(GL_MODELVIEW);
    
    glFrontFace(GL_CCW);
    glCullFace(GL_BACK);
    
	glRotatef(10, 1, 0, 0);
    printCommands();
    spawnRandomParticles();//spawn particles as soon as program starts
    glutDisplayFunc(display);
	glutMainLoop();
	return(0);
}