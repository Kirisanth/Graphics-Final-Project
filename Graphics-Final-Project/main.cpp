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
#include "PhysicsEngine.h"
#include "Particle.h"
#include "Texture.h"
#include <math.h>
#include "ray.h"
#include "Texture.h"
#include "Points.h"

ray newRay;
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
PhysicsEngine game;
Texture textureObeject;
bool cameraParticlePosition = false;
bool startStop = true;
bool lightswitch = true;
bool gameOver = false;

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

///* rayCast - takes a mouse x,y, coordinate, and casts a ray through that point
// *   for subsequent intersection tests with objects.
// */
void rayCast(float x, float y)
{
    bool groundPlane = true;//check if hit on plane
    GLdouble pNear[3];//depth for z
    GLdouble pFar[3]; //depth for z
    float inter[3];//stores object intersection
    //count through number of objects to perform tests on each one
    //count through number of planes of each object to perform test on each one
    for (int count1 = 0; count1 < game.ActiveObjects.size(); count1++){
        for(int count2 = 0; count2 < 6; count2++){
        
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
            
            newRay.normalizeDirection();
            
            groundPlane = newRay.rayPlaneTest(count1, count2, game.ActiveObjects);
            //update the position of the object to the intersection point
            if ( groundPlane == true){
                //check if object is hit between min and max bounds
                if ((game.ActiveObjects.at(count1).min + game.ActiveObjects.at(count1).translateX < newRay.inter[0] && newRay.inter[0] < game.ActiveObjects.at(count1).max + game.ActiveObjects.at(count1).translateX && game.ActiveObjects.at(count1).min + game.ActiveObjects.at(count1).translateZ < newRay.inter[2] && newRay.inter[2] < game.ActiveObjects.at(count1).max + game.ActiveObjects.at(count1).translateZ && inter[1] < game.ActiveObjects.at(count1).max + game.ActiveObjects.at(count1).translateY && game.ActiveObjects.at(count1).min + game.ActiveObjects.at(count1).translateY < newRay.inter[1])){
                    
                    game.ActiveObjects.at(count1).hit = true;
                    //check to see right click to delete object
                    break;
                }
                //return false hit else wise
                else{
                    game.ActiveObjects.at(count1).hit = false;
                }
            }
        }   //break out of cycle of object
        if(game.ActiveObjects.at(count1).hit == true){
            for(int z = 0; z < game.ActiveObjects.size(); z++){
                if(z != count1){
                    game.ActiveObjects.at(z).hit = false;
                }
            }
            break;
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

void light()
{
    GLfloat position[] = { static_cast<GLfloat>(game.ball.posX), static_cast<GLfloat>(game.ball.posX), static_cast<GLfloat>(game.ball.posX), 1.0 };
//  float amb[4] = {1.0, 1, 1, 1};
//	float diff[4] = {1,0,0, 1};
	float spec[4] = {0,0,1, 1};
    
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, diff);
//	glLightfv(GL_LIGHT0, GL_AMBIENT, amb);
	glLightfv(GL_LIGHT0, GL_SPECULAR, spec);
    glLightfv (GL_LIGHT0, GL_POSITION, position);
    
    
    GLfloat position2[] = {0,4.5,0,1.0};
    float amb2[4] = {0,1,1,1};
	float diff2[4] = {0,0,0,1};
	float spec2[4] = {0,0,0,0};
    
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diff2);
	glLightfv(GL_LIGHT1, GL_AMBIENT, amb2);
	glLightfv(GL_LIGHT1, GL_SPECULAR, spec2);
    glLightfv (GL_LIGHT1, GL_POSITION, position2);
    
    float m_amb[] = {0.33, 0.22, 0.03, 1.0};
	float m_dif[] = {0.78, 0.57, 0.11, 1.0};
	float m_spec[] = {0.99, 0.91, 0.81, 1.0};
	float shiny = 27; //10, 100
    
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, m_amb);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, m_dif);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, m_spec);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shiny);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(camera[0], camera[1], camera[2], 0, 0, 0, orientation[0], orientation[1], orientation[2]);
        
    textureObeject.drawPlane();
    
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    glPushMatrix();
    
    //for first person camera
    if (cameraParticlePosition == true){
        glRotatef(45, 1, 0, 0);
        glTranslatef(-game.ball.posX, 12.5 - game.ball.posY, -game.ball.posZ);
        angY = 9*sin(1.05);
        camera[0] = 0;
        camera[1] = 9;
        camera[2] = 9;
    }
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
    
    for (int x = 0; x < 5; x++){
        game.ActiveObjects.at(x).drawObjects();
        
    }
    game.points.dispalyPoints();
    light();
    game.ball.drawSphere();
    
    if (flip1 == true || flip2 == true){//Check to see if user pressed flipper button a or s

            if(flip1 == true && flip2 == true)//check if both buttons have been pressed a and s
            {
                game.flipperStruct.movFlip1 = moveY;
                game.flipperStruct.movFlip2 = moveY;
                game.flipperStruct.CalculateNormal();
                pinballStruct(moveY,moveY,drawWall1First);//make both flippers move
            }
            else if (flip1 == true)//check if s is pressed
            {
                game.flipperStruct.movFlip1 = moveY;
                game.flipperStruct.CalculateNormal();

                pinballStruct(moveY,-2,drawWall1First);//make s flipper move
            }
            else//else a is pressed
            {
                game.flipperStruct.setUpdatedYValue1(moveY);
                game.flipperStruct.CalculateNormal();
                pinballStruct(-2,moveY,drawWall1First);//make a flipper move
            }
    }
    else{
        pinballStruct(-2,-2,drawWall1First);
    }
    glPopMatrix();
    
    if(gameOver == true){
        game.points.gameOver();
    }
    
    glFlush();
    glutSwapBuffers();
    glutPostRedisplay();
}

//Keyboard handler function
void kbd(unsigned char key, int x, int y)
{
    y = 500 - y;
    
    if(key == 'q' || key == 27)
	{
		exit(0);
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
    if (key == '1'){
        for (int count = 0; count < game.ActiveObjects.size();count++){
            if (game.ActiveObjects.at(count).hit == true){
                game.ActiveObjects.at(count).objectType = 1;
            }
        }
        printf("Cube selected\n");
    }
    if (key == '2'){
        for (int count = 0; count < game.ActiveObjects.size();count++){
            if (game.ActiveObjects.at(count).hit == true){
                game.ActiveObjects.at(count).objectType = 2;
            }
        }
        printf("Sphere selected\n");
        
    }
    if (key == '3'){
        for (int count = 0; count < game.ActiveObjects.size();count++){
            if (game.ActiveObjects.at(count).hit == true){
                game.ActiveObjects.at(count).objectType = 3;
            }
        }
        printf("Ring selected\n");
    }
    if (key == '8'){
        cameraParticlePosition = true;
        printf("Pinball Perspective\n");
    }
    if (key == '9'){
        cameraParticlePosition = false;
        printf("Regular Perspective\n");
    }
    if (key == 'x'){
        for (int count = 0; count < game.ActiveObjects.size();count++){
            if (game.ActiveObjects.at(count).hit == true){
                game.ActiveObjects.at(count).objectTranslateX(0.1);
            }
        }
    }
    if (key == 'X'){
        for (int count = 0; count < game.ActiveObjects.size();count++){
            if (game.ActiveObjects.at(count).hit == true){
                game.ActiveObjects.at(count).objectTranslateX(-0.1);
            }
        }
    }
    
    if (key == 'y'){
        for (int count = 0; count < game.ActiveObjects.size();count++){
            if (game.ActiveObjects.at(count).hit == true){
                game.ActiveObjects.at(count).objectTranslateY(0.1);
            }
        }
    }
    if (key == 'Y'){
        for (int count = 0; count < game.ActiveObjects.size();count++){
            if (game.ActiveObjects.at(count).hit == true){
                game.ActiveObjects.at(count).objectTranslateY(-0.1);
            }
        }
    }
    
    if (key == 'z'){
        for (int count = 0; count < game.ActiveObjects.size();count++){
            if (game.ActiveObjects.at(count).hit == true){
                game.ActiveObjects.at(count).objectTranslateZ(0.1);
            }
        }
    }
    if (key == 'Z'){
        for (int count = 0; count < game.ActiveObjects.size();count++){
            if (game.ActiveObjects.at(count).hit == true){
                game.ActiveObjects.at(count).objectTranslateZ(-0.1);
            }
        }
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
    if (key == 'r'){
        //check to see if on, is so turn off and vice versa
        game.ball = Particle();
        game.points = Points();
        gameOver = false;
        printf("Restart\n");
    }
    
    if (key == 'l')
    {
        if(lightswitch == true)
        {
            lightswitch = false;
            glEnable(GL_LIGHTING);
            printf("Light Enabled\n");
        }
        else
        {
            lightswitch = true;
            glDisable(GL_LIGHTING);
            printf("Light Disabled\n");
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


void update(int value){
    if (startStop == true){
	game.moveParticle();
    
    if (flip1 == true || flip2 == true){
        x++;//x is used to iterate over moving the flipper up then back down
        if (x < 13){//increment by 0.1 to move flipper up. When x reaches 12, it'll reach its maximum which is -0.4
            moveY = moveY + 0.1;
            game.flipperStruct.movFlip1 = moveY;
        }
        else{//decrease by 0.1 to move flipper down
            moveY = moveY - 0.1;
            //                game.flipperStruct.movFlip1 = moveY;
            //                game.flipperStruct.movFlip2 = moveY;
        }
    if(x >= 25){//if x = 25, flipper is at orginal position
        flip1 = false;
        flip2 = false;
        x = -1;
    }
    }
        if(game.ball.posY < -4){
            gameOver = true;
        }
    }
	glutTimerFunc(10,update,0);
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
	glFlush();
    glutSwapBuffers();
}


/*  Initialize alpha blending function.  */
static void init(void)
{
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glShadeModel (GL_FLAT);
    
    textureObeject.loadTexture();
    
    for (int x = 0; x < 5; x++){
        ObjectsModel newObject;
        game.ActiveObjects.push_back(newObject);
    }
    
    printf("Welcome to 3GC3 Pinball \n \n How to play:\n Press 'a' and 's' to move the left and right paddle to hit the ball. The object of the game is to score as many points as possible by hitting objects before the ball falls.\n You can change the view by rotating the camera around the y axis to see the objects in it's z space. As well, press 8 to change over to pinball perspective and 9 to change back to regular perspective.\n\nThere are many more commands down below to enhance the 3D pinball expierence! \n \n Functions: \n \n a - move left flipper \n s - move right flipper \n arrow keys - move camera around y axis and x \n 8 - change camera to Pinball's perspective \n 9 - change camera to regular perspective \n mouse click - click on a object to select it \n 1 - change object to cube (object must be selected) \n 2 - change object to sphere (object must be selected) \n 3 - change object to ring (object must be selected) \n x and shift x - translate object along x axis (must be selected) \n y and shift y - translate object along y axis (must be selected) \n z and shift z - translate object along z axis (must be selected) \n space - start/stop animation \n r - restart game \n l - turn off/on lighting \n q or esc - quit program\n\n");
    
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutCreateWindow("3GC3 Pinball");
    
	glutKeyboardUpFunc(kbd);
    glutSpecialFunc(processSpecialKeys);
	glutIdleFunc(idle);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
	glLoadIdentity();
	gluPerspective(90, 1, 1, 100);

	glMatrixMode(GL_MODELVIEW);
    glutMouseFunc(mouse);
    
    glFrontFace(GL_CCW);
    glCullFace(GL_BACK);
    init();
    glutDisplayFunc(display);
    glutTimerFunc(10,update,0);
	glutMainLoop();
//    Particle ball;
//    PhysicsEngine test;
//    test.moveParticle(ball);
	return(0);
}