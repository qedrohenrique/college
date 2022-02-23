#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "drawutils.h"
#include "fila.h"

#define MAX_OBJ 1000
#define WIDTH 600.0
#define HEIGHT 600.0

struct cords {
  float x, y;
} typedef Coords;

float catHitboxRange = 0.2;
float angle;
float lastAngle;

int setAngle = 1;

Coords catFront;
Coords catPos;

struct Node* dotsHead;

void initVariables(){
    catPos.x = 0;
    catPos.y = 0;
    catFront.x = catHitboxRange;
    catFront.y = 0;
    lastAngle = 3.14*2;
    dotsHead = createNode(0.0, 0.0);
}

float integerToFloatX(int x){
    return 2*(x / WIDTH)-1;
}

float integerToFloatY(int y){
    return (2*(y/ HEIGHT)-1)*(-1);
}

void Timer(int extra) {
    glutPostRedisplay();
    glutTimerFunc(30,Timer,0);
}

float distance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0);
}

float calcAngle(float x, float y, float xx, float yy){
    return atan2(yy-y, xx-x);
}

void draw(){
    glClearColor(1.0, 1.0, 1.0, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    Node* currentNode = dotsHead->next;

    if(len(dotsHead) == 0){
        angle = lastAngle;
    }else{
        if(setAngle){
            angle = calcAngle(catPos.x , catPos.y, currentNode->x, currentNode->y);
            lastAngle = angle;
        }
    }

    drawCat(catPos.x, catPos.y, catHitboxRange, lastAngle);


    if(0){
        drawHitbox(catPos.x, catPos.y, catHitboxRange, lastAngle);
        setAngle = 0;
    }else{
        setAngle = 1;
        drawCat(catPos.x, catPos.y, catHitboxRange, lastAngle);
        if(len(dotsHead) != 0){
            if(currentNode->x > catPos.x - catHitboxRange && currentNode->y > catPos.y - catHitboxRange && currentNode->x < catPos.x + catHitboxRange && currentNode->y < catPos.y+catHitboxRange){
                dotsHead = popHead(dotsHead);
            }else{
                if(catPos.x + catHitboxRange > 1 || catPos.x - catHitboxRange < -1){
                    if(currentNode->y - catPos.y > 0) catPos.y += 0.01;
                    else catPos.y -= 0.01;
                    if(catPos.x + catHitboxRange > 1) catPos.x -= 0.001;
                    else catPos.x += 0.001;
                }else if(catPos.y + catHitboxRange > 1 || catPos.y - catHitboxRange < -1){
                    if(currentNode->x - catPos.x > 0) catPos.x += 0.01;
                    else catPos.x -= 0.01;
                    if(catPos.y + catHitboxRange > 1) catPos.y -= 0.001;
                    else catPos.y += 0.001;
                }else{
                    if(currentNode->x - catPos.x > 0) catPos.x += 0.01;
                    else catPos.x -= 0.01;

                    if(currentNode->y - catPos.y > 0) catPos.y +=  0.01;
                    else catPos.y -= 0.01;
                }
            }
        }
    }




    glColor3f(0.0, 1.0, 1.0);
    glPointSize(10.0);
    glBegin(GL_POINTS);
        while(currentNode != NULL){
            glVertex2f(currentNode->x, currentNode->y);
            currentNode = currentNode->next;
        }
    glEnd();

    glutSwapBuffers();
}

void onClickDraw(int button, int state, int x, int y){
    switch (button) {
        case GLUT_LEFT_BUTTON:
            break;
        case GLUT_RIGHT_BUTTON:
            if (state == GLUT_DOWN){
                Node *dot = createNode(integerToFloatX(x), integerToFloatY(y));
                insertNode(dotsHead, dot);
            }
            break;
        default:
            break;
    }
}

void onKeyboardAction(unsigned char key, int x, int y){
    switch(key){
        case '-':
            if(catHitboxRange > 0.1){
                catHitboxRange-=0.01;
            }
            break;
        case '+':
            if(catHitboxRange < 0.5 && catPos.x + catHitboxRange < 1 && catPos.x - catHitboxRange > -1 && catPos.y + catHitboxRange < 1 && catPos.y - catHitboxRange > -1){
                catHitboxRange+=0.01;
            }
            break;
    }
    glutPostRedisplay();
}


int main(int argc, char *argv[ ] ) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(50,100);
    glutInitWindowSize(WIDTH,HEIGHT);
    glutCreateWindow("Computação Gráfica");

    //Auxiliar function
    initVariables();

    glutDisplayFunc(draw);
    glutMouseFunc(onClickDraw);
    glutKeyboardFunc(onKeyboardAction);
    glutTimerFunc(0,Timer,0);

    glutMainLoop ();
    return 0;
}
