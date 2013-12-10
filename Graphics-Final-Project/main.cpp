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
#include "ray.h"


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
double camera[3] = {9,9,9};//declares camera at position


ray newRay;
GLdouble newPoint [3];//creates new point
GLdouble pNear[3];//depth for z
GLdouble pFar[3]; //depth for z
float objectPos[3];//stores object position
float inter[3];//stores object intersection
bool groundPlane = true;//check if hit on plane
double platformNormal[2][3] ={{-1,0,0},{1,0,0}};
double platformPoints[2][3] = {{-2.5,-0.7,2.5}, {2.5,4.7,0}};
float minX = -2.500000, maxX = 2.500000, minY = -0.7, maxY = 4.7, minZ = 0, maxZ = 2.5;
bool hit1, hit2;





void Get3DPos(int x, int y, float winz, GLdouble point[3])
{
	GLint viewport[4];
	GLdouble modelview[16];
	GLdouble projection[16];
	
	//get the matrices
	glGetDoublev( GL_MODELVIEW_MATRIX, modelview );
	glGetDoublev( GL_PROJECTION_MATRIX, projection );
	glGetIntegerv( GL_VIEWPORT, viewport );
    
	//"un-project" the 2D point giving the 3D position corresponding to the provided depth (winz)
	gluUnProject( (float)x, (float)(viewport[3]-y), winz, modelview, projection, viewport, &point[0], &point[1], &point[2]);
    
}

double distance(int i){
    return -1 * (platformPoints[i][0]*platformNormal[i][0] + platformPoints[i][1]*platformNormal[i][1] + platformPoints[i][2]*platformNormal[i][2]);
    
}

float normalMultiplyDirection(int i){
    return (platformNormal[i][0] *  newRay.norm[0] + platformNormal[i][1] * newRay.norm[1] + platformNormal[i][2] * newRay.norm[2]);
}

float normalMultiplyOrgin(int i, float t){
    return  (-1* (platformNormal[i][0] * newRay.org[0] + platformNormal[i][1] * newRay.org[1] + platformNormal[i][2] * newRay.org[2] + distance(i)))/t;
}

////Function performs a ray plan test to check if ray intersected object other then sphere
bool rayPlaneTest(int i){
    float t = 0;
    normalMultiplyDirection(i);
    t = (platformNormal[i][0] *  newRay.norm[0] + platformNormal[i][1] * newRay.norm[1] + platformNormal[i][2] * newRay.norm[2]);
    if (t != 0){
        t = normalMultiplyOrgin(i, t);
        //store instesection points if it did
        inter[0] = newRay.org[0] + t*newRay.norm[0];
        inter[1] = newRay.org[1] + t*newRay.norm[1];
        inter[2] = newRay.org[2] + t*newRay.norm[2];

        return true;
    }
    else {
        return false;
    }
    
}

//
///* rayCast - takes a mouse x,y, coordinate, and casts a ray through that point
// *   for subsequent intersection tests with objects.
// */
void rayCast(float x, float y)

{
    //count through number of objects to perform tests on each one
        //count through number of planes of each object to perform test on each one
        for (int i = 0; i < 2; i++){
            
            
            Get3DPos(x, y, 0.0, pNear);
            Get3DPos(x, y, 1.0, pFar);
            
            //store ray orgin
            newRay.org[0] = camera[0];
            newRay.org[1] = camera[1];
            newRay.org[2] = camera[2];
            
            //ray direction is the vector (pFar - pNear)
            newRay.dir[0] = pFar[0] - pNear[0];
            newRay.dir[1] = pFar[1] - pNear[1];
            newRay.dir[2] = pFar[2] - pNear[2];
            
            //normalize direction vector
            newRay.normalizeDirection();
            
            //undergoe ray plane test
            groundPlane = rayPlaneTest(i);
            
            //update the position of the object to the intersection point
            if ( groundPlane == true){
                objectPos[0] = inter[0];
                objectPos[1] = inter[1];
                objectPos[2] = inter[2];
                
                printf("x = %f\n",objectPos[0]);
                printf("y = %f\n",objectPos[1]);
                printf("z = %f\n",objectPos[2]);
                
                //check if object is hit between min and max bounds
                if ((minZ < objectPos[2] && objectPos[2] < maxZ && objectPos[1] <= maxY && minY <= objectPos[1]) && maxX == objectPos[0]){
                    hit1 = true;
                    break;
                }
                else if (( minZ < objectPos[2] && objectPos[2] < maxZ && objectPos[1] <= maxY && minY <= objectPos[1]) && minX == objectPos[0]){
                    hit2 = true;
                    break;
                }
                else{
                    hit1 = false;
                    hit2 = false;
    
                }
     
                
            }
        }  
}
            
            
            
                                                                                                                              



/*
 Section is used to update the new particle position. Update is called constantly as per idle function.
 With this it constatly redraws it giving it a smooth animation.
 */

void pinballStruct(){
    

    glBegin(GL_QUADS);
    //platform
    
    glEnable(GL_BLEND); //Enable blending.
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //Set blending function.
    glColor3f(0.3, 0, 1);
    glVertex3f(-2.5,4.7,2.5);
    glVertex3f(2.5,4.7,2.5);
    glVertex3f(2.5,4.7,0);
    glVertex3f(-2.5,4.7,0);
    
    glColor4f(1, 0, 0.3,0.55);
    glVertex3f(2.5,-0.7,2.5);
    glVertex3f(2.5,4.7,2.5);
    glVertex3f(2.5,4.7,0);
    glVertex3f(2.5,-0.7,0);
    
    glColor4f(1, 0, 0.3,0.55);
    glVertex3f(-2.5,-0.7,2.5);
    glVertex3f(-2.5,4.7,2.5);
    glVertex3f(-2.5,4.7,0);
    glVertex3f(-2.5,-0.7,0);
    
    //flippers
    
    
    glColor3f(0.3, 0, 1);
    glVertex3f(0.4,-2,2.5);
    glVertex3f(2.5,-0.7,2.5);
    glVertex3f(2.5,-0.7,0);
    glVertex3f(0.4,-2,0);
    
    glColor3f(0.3, 0, 1);
    glVertex3f(-0.4,-2,2.5);
    glVertex3f(-2.5,-0.7,2.5);
    glVertex3f(-2.5,-0.7,0);
    glVertex3f(-0.4,-2,0);
    
    //back
    
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(2.5,-0.7,0);
    glVertex3f(2.5,4.7,0);
    glVertex3f(-2.5,4.7,0);
    glVertex3f(-2.5,-0.7,0);
    
    
    
    
	glEnd();
    
    
}

/* drawAxis() -- draws an axis at the origin of the coordinate system
 *   red = +X axis, green = +Y axis, blue = +Z axis
 */
void drawAxis()
{
	glBegin(GL_LINES);
    glColor3f(1, 0, 0);
    glVertex3f(0,0,0);
    glVertex3f(50,0,0);
    
    glColor3f(0,1,0);
    glVertex3f(0,0,0);
    glVertex3f(0,50,0);
    
    glColor3f(0,0,1);
    glVertex3f(0,0,0);
    glVertex3f(0,0,50);
	glEnd();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    drawAxis();
    glLoadIdentity();
    gluLookAt(camera[0], camera[1], camera[2], 0, 0, 0, 0, 1, 0);
    glPointSize(10);
    glBegin(GL_POINTS);
    glVertex3f(objectPos[0],objectPos[1],objectPos[2]);//draw point
    glEnd();
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    if (hit1 == true || hit2 == true){
    glutSolidTeapot(1);
    }
    
    glPushMatrix();
    glRotatef(angY, 1, 0, 0);//rotate scene around x axis
    glRotatef(angX, 0, 1, 0);//rotate scene around y axis
    pinballStruct();

    glPopMatrix();
    
    glFlush();
    glutSwapBuffers();
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

}

void processSpecialKeys(int key, int x, int y) {
    
    //Responsible for camera movement, press right to turn right, left for left, up for up and down for down
    switch(key) {
		case GLUT_KEY_UP:
            camera[1] +=+ 0.5;
            break;
		case GLUT_KEY_DOWN :
            camera[1] -= 0.5;
            break;
        case GLUT_KEY_LEFT:
            camera[0] -= 0.5;
            break;
        case GLUT_KEY_RIGHT:
            camera[0] += 0.5;
            break;
	}
    
}
void idle()
{
    if (startStop == true){

        particleSpin++;//increment angle so particles can rotate
	}
    glutPostRedisplay();
}

void mouse(int btn, int state, int x, int y)
{
    //ray cast is pressed
	if(btn == GLUT_LEFT_BUTTON)
	{
        rayCast(x, y);
	}
    //delete if pressed
	if(btn == GLUT_RIGHT_BUTTON)
	{
	}
    
	glFlush();
    glutSwapBuffers();
}


/*  Initialize alpha blending function.  */
static void init(void)
{
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glShadeModel (GL_FLAT);
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
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65, 1, 1, 100);
    
	glMatrixMode(GL_MODELVIEW);
    glutMouseFunc(mouse);
    
    glFrontFace(GL_CCW);
    glCullFace(GL_BACK);
    init();
    
	glRotatef(10, 1, 0, 0);
    glutDisplayFunc(display);
	glutMainLoop();
	return(0);
}