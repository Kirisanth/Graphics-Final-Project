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
double transparentWall1 = 1;
double transparentWall2 = 1;
int orientation[3] = {0,1,0};
bool flip1, flip2;
float moveY = -2;
float angY = 9*sin(1.05);//roation around Y
double camera[3] = {0,9,9};//declares camera at position
double bounceY = 0;
int x = -1;


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
                
                //check if object is hit between min and max bounds
                if ((minZ <= objectPos[2] && objectPos[2] <= maxZ && objectPos[1] <= maxY && minY <= objectPos[1]) && maxX == objectPos[0]){
                    hit1 = true;
                    break;
                }
                if (( minZ < objectPos[2] && objectPos[2] < maxZ && objectPos[1] <= maxY && minY <= objectPos[1]) && minX == objectPos[0]){
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

void drawWall1(){
    glBegin(GL_QUADS);
    glColor4f(1, 0, 0.3,transparentWall1);
    glVertex3f(-2.5,-0.7,2.5);
    glVertex3f(-2.5,4.7,2.5);
    glVertex3f(-2.5,4.7,0);
    glVertex3f(-2.5,-0.7,0);
    glEnd();
}

void drawWall2(){
    glBegin(GL_QUADS);
    glColor4f(1, 0, 0.3,transparentWall2);
    glVertex3f(2.5,-0.7,2.5);
    glVertex3f(2.5,4.7,2.5);
    glVertex3f(2.5,4.7,0);
    glVertex3f(2.5,-0.7,0);
    glEnd();
}


/*
 Section is used to update the new particle position. Update is called constantly as per idle function.
 With this it constatly redraws it giving it a smooth animation.
 */

void pinballStruct(float movFlip1, float movFlip2, bool drawWall1First){
    

    glBegin(GL_QUADS);
    
    glEnable(GL_BLEND); //Enable blending.
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //Set blending function.
    

    //platform
    glColor3f(0.3, 0, 1);
    glVertex3f(-2.5,4.7,2.5);
    glVertex3f(2.5,4.7,2.5);
    glVertex3f(2.5,4.7,0);
    glVertex3f(-2.5,4.7,0);
    
    //flippers
    glColor3f(0.3, 0, 1);
    glVertex3f(0.4,movFlip1,2.5);
    glVertex3f(2.5,-0.7,2.5);
    glVertex3f(2.5,-0.7,0);
    glVertex3f(0.4,movFlip1,0);
    
    glColor3f(0.3, 0, 1);
    glVertex3f(-0.4,movFlip2,2.5);
    glVertex3f(-2.5,-0.7,2.5);
    glVertex3f(-2.5,-0.7,0);
    glVertex3f(-0.4,movFlip2,0);
    
    //back
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(2.5,-0.7,0);
    glVertex3f(2.5,4.7,0);
    glVertex3f(-2.5,4.7,0);
    glVertex3f(-2.5,-0.7,0);
    
    
    if(drawWall1First == true){//Created to make sure wall 1 is seen if wall 2 is transparent
        drawWall1();
        drawWall2();
    }
    else{
        drawWall2();
        drawWall1();
    }

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

void Points(){
    //char dig = (char)(((int)'0')+10);
    char *a= "Points: ";
    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos3f( 2.0f , -1.0f ,4.0f );
    for(int i = 0; a[i] != '\0'; i++)
        glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18 , a[i]);
    
    std::string s = std::to_string(4000);
    char const *pchar = s.c_str();
    for (int count = 0; pchar[count] != '\0'; count++){
        glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18 , pchar[count]);
    }
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(camera[0], camera[1], camera[2], 0, 0, 0, orientation[0], orientation[1], orientation[2]);
    
    //intersection point for ray casting
    /*
    glPointSize(10);
    glBegin(GL_POINTS);
    glVertex3f(objectPos[0],objectPos[1],objectPos[2]);//draw point
    glEnd();
    */
    
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    Points();
    glPushMatrix();
    
    //for first person camera 
    //glRotatef(45, 1, 0, 0);
    //glTranslatef(-1, 7.1 + bounceY, -.5);
    
    //drawAxis();
    bool drawWall1First;
    if ((-9<camera[0] && camera[0] < -6) || hit2 == true){
        transparentWall1 = 0.2;
        drawWall1First = false;
    }
    
    else if ((9>camera[0] && camera[0] > 6) || hit1 == true){
        transparentWall2 = 0.2;
        drawWall1First = true;
    }
    else{
        transparentWall1 = 1;
        transparentWall2 = 1;
    }
    
    
    
    if (flip1 == true || flip2 == true){//Check to see if user pressed flipper button a or s
            //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            x++;//x is used to iterate over moving the flipper up then back down
            if (x < 13)//increment by 0.1 to move flipper up. When x reaches 12, it'll reach its maximum which is -0.4
                moveY = moveY + 0.1;
            else//decrease by 0.1 to move flipper down
                moveY = moveY - 0.1;
            if(flip1 == true && flip2 == true)//check if both buttons have been pressed a and s
                pinballStruct(moveY,moveY,drawWall1First);//make both flippers move
            else if (flip1 == true)//check if s is pressed
                pinballStruct(moveY,-2,drawWall1First);//make s flipper move
            else//else a is pressed
                pinballStruct(-2,moveY,drawWall1First);//make a flipper move
            //glutSwapBuffers();
        //}
        if(x >= 25){//if x = 25, flipper is at orginal position
            flip1 =false;
            flip2 = false;
            x = -1;
        }
    }
    else{
        pinballStruct(-2,-2,drawWall1First);
    }
    
    //For first person camera
    /*
    glPushMatrix();
    if (bounceY >= 4.7)
        bounceY = 0;
    else if(bounceY >= 0)
        bounceY = bounceY + 0.1;
    glTranslatef(0, bounceY,0);
    glutSolidCube(0.5);
    glPopMatrix();
    */
    
    glPopMatrix();
    glFlush();
    glutSwapBuffers();
    glutPostRedisplay();
}

void kbd(unsigned char key, int x, int y)
{
    y = 500 - y;
    
    if(key == 'q' || key == 27)
	{
		exit(0);
	}
    //resets particles to normal mode
    if(key == 'r'){
        
    }

    if(key == 's'){
        flip1 = true;
    }
    if(key == 'a'){
        flip2 = true;
    }
    if(key == 's' && key == 'a'){
        flip1 = true;
        flip2 = true;
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
            angY = angY + 0.05;
            camera[0]=9*cos(angY);
            camera[2]=9*sin(angY);
            
            break;
        case GLUT_KEY_RIGHT:
            angY = angY - 0.05;
            camera[0]=9*cos(angY);
            camera[2]=9*sin(angY);
            break;
	}
    
}


void idle()
{
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
    
	glutKeyboardUpFunc(kbd);
    glutSpecialFunc(processSpecialKeys);
	glutIdleFunc(idle);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90, 1, 1, 100);

	glMatrixMode(GL_MODELVIEW);
    glutMouseFunc(mouse);
    
    glFrontFace(GL_CCW);
    glCullFace(GL_BACK);
    init();
    
	//glRotatef(10, 1, 0, 0);
    glutDisplayFunc(display);
	glutMainLoop();
	return(0);
}