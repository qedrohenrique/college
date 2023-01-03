#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

#define MAX_OBJ 1000
#define WIDTH 600.0
#define HEIGHT 600.0
#define DRAW_CIRCLE 1
#define DRAW_LINE 0
#define DRAW_RECTANGLE 2
#define PI 3.141592654

float xpos[MAX_OBJ], ypos[MAX_OBJ];
float xpos_cache, ypos_cache;
float red[MAX_OBJ], green[MAX_OBJ], blue[MAX_OBJ];
float r, g, b;
float lineWidth[MAX_OBJ];
float _lineWidth;

int countClicks;
int drawType;
int drawControl;
int drawTypeGlBegin[MAX_OBJ];
int numbersMode;
int colorControl;

void initializeGlobalVariables(){
    xpos[0] = 0.0; ypos[0] = 0.0;
    xpos[1] = 0.0; ypos[1] = 0.0;
    xpos_cache = 0.0; ypos_cache = 0.0;
    red[0] = 0.0; green[0] = 0.0; blue[0] = 1.0;
    r = 0.0; g = 0.0; b = 0.0;
    lineWidth[0] = 1.0;
    _lineWidth = 1.0;

    countClicks = 1;
    drawType = DRAW_LINE;
    drawControl = 0;
    drawTypeGlBegin[0] = GL_LINES;
    drawTypeGlBegin[1] = GL_LINES;
    numbersMode = 0;
    colorControl = 0;
}

float convertFloatToIntegerX(int x){
    return 2*(x / WIDTH)-1;
}

float convertFloatToIntegerY(int y){
    return (2*(y/ HEIGHT)-1)*(-1);
}

float convertIntegerToFloatX(int x){
    return x * WIDTH;
}

float convertIntegerToFloatY(int y){
    return y * HEIGHT;
}

void draw(){
    glClearColor(1.0, 1.0, 1.0, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    for(int i = 0; i < countClicks; i += 2){
        if(drawTypeGlBegin[i] == GL_LINES){
            glLineWidth(lineWidth[i]);
            glBegin(GL_LINES);
                glLineWidth(lineWidth[i]);
                glColor3f(red[i], green[i], blue[i]);
                glVertex2f(xpos[i], ypos[i]);
                glVertex2f(xpos[i+1], ypos[i+1]);
            glEnd();
        }
    }

    for(int i = 0; i < countClicks; i += 2){
        if(drawTypeGlBegin[i] == GL_LINE_LOOP){
            glLineWidth(lineWidth[i]);
            glBegin(GL_LINE_LOOP);
                glColor3f(red[i], green[i], blue[i]);
                float angle, radius;
                for (int j = 0;j <= 1000; j++) {
                    angle = 2 * PI * j / 1000.0;
                    radius = sqrt(pow(xpos[i]-xpos[1+i], 2) + pow(ypos[i]-ypos[1+i], 2));
                    glVertex2f(radius * cos(angle) +  xpos[i], radius * sin(angle) + ypos[i]);
                }
            glEnd();
        }
    }

    for(int i = 0; i < countClicks; i += 2){
        if(drawTypeGlBegin[i] == GL_QUADS){
            glLineWidth(lineWidth[i]);
            glBegin(GL_LINE_LOOP);
                glColor3f(red[i], green[i], blue[i]);
                glVertex2f(xpos[i], ypos[i]);
                glVertex2f(xpos[i], ypos[i+1]);
                glVertex2f(xpos[i+1], ypos[i+1]);
                glVertex2f(xpos[i+1], ypos[i]);
            glEnd();
        }
    }



    glFlush();
}

void onMouseAction (int button, int state, int x, int y) {
    switch(button){
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN){
                if(countClicks % 2 == 1){
                    xpos_cache = convertFloatToIntegerX(x);
                    ypos_cache = convertFloatToIntegerY(y);
                }else{
                    xpos[countClicks] = xpos_cache;
                    ypos[countClicks] = ypos_cache;
                    xpos[countClicks+1] = convertFloatToIntegerX(x);
                    ypos[countClicks+1] = convertFloatToIntegerY(y);

                    if(drawControl == DRAW_LINE){
                        drawType = DRAW_LINE;
                        drawTypeGlBegin[countClicks] = GL_LINES;
                        drawTypeGlBegin[countClicks+1] = GL_LINES;
                        red[countClicks] = r; red[countClicks+1] = r;
                        green[countClicks] = g; green[countClicks+1] = g;
                        blue[countClicks] = b; blue[countClicks+1] = b;
                        lineWidth[countClicks] = _lineWidth; lineWidth[countClicks+1] = _lineWidth;
                    }else if(drawControl == DRAW_CIRCLE){
                        drawType = DRAW_CIRCLE;
                        drawTypeGlBegin[countClicks] = GL_LINE_LOOP;
                        drawTypeGlBegin[countClicks+1] = GL_LINE_LOOP;
                        red[countClicks] = r; red[countClicks+1] = r;
                        green[countClicks] = g; green[countClicks+1] = g;
                        blue[countClicks] = b; blue[countClicks+1] = b;
                        lineWidth[countClicks] = _lineWidth; lineWidth[countClicks+1] = _lineWidth;

                    }else{
                        drawType = DRAW_RECTANGLE;
                        drawTypeGlBegin[countClicks] = GL_QUADS;
                        drawTypeGlBegin[countClicks+1] = GL_QUADS;
                        red[countClicks] = r; red[countClicks+1] = r;
                        green[countClicks] = g; green[countClicks+1] = g;
                        blue[countClicks] = b; blue[countClicks+1] = b;
                        lineWidth[countClicks] = _lineWidth; lineWidth[countClicks+1] = _lineWidth;
                    }
                }
                countClicks++;
            }
            break;
    }
    glutPostRedisplay();
}

void onKeyboardAction(unsigned char key, int x, int y){
    switch(key){
        case '0':
            if(numbersMode == 0){ r = 0.0; g = 0.0; b = 1.0; }
            else _lineWidth = 10.0;
            break;
        case '1':
            if(numbersMode == 0){ r = 0.0; g = 1.0; b = 1.0; }
            else _lineWidth = 1.0;
            break;
        case '2':
            if(numbersMode == 0){ r = 1.0; g = 0.0; b = 1.0; }
            else _lineWidth = 2.0;
            break;
        case '3':
            if(numbersMode == 0){ r = 0.0; g = 0.0; b = 0.0; }
            else _lineWidth = 3.0;
            break;
        case '4':
            if(numbersMode == 0){ r = 0.5; g = 0.5; b = 0.5; }
            else _lineWidth = 4.0;
            break;
        case '5':
            if(numbersMode == 0){r = 0.5; g = 0.0; b = 1.0; }
            else _lineWidth = 5.0;
            break;
        case '6':
            if(numbersMode == 0){ r = 0.0; g = 0.5; b = 1.0; }
            else _lineWidth = 6.0;
            break;
        case '7':
            if(numbersMode == 0){ r = 1.0; g = 0.5; b = 0.0; }
            else _lineWidth = 7.0;
            break;
        case '8':
            if(numbersMode == 0){ r = 0.5; g = 0.25; b = 1.0; }
            else _lineWidth = 8.0;
            break;
        case '9':
            if(numbersMode == 0){ r = 0.0; g = 0.0; b = 0.0; }
            else _lineWidth = 9.0;
            break;
        case 'c':
        case 'C':
            drawControl = DRAW_CIRCLE;
            break;
        case 'r':
        case 'R':
            drawControl = DRAW_LINE;
            break;
        case 'b':
        case 'B':
            drawControl = DRAW_RECTANGLE;
            break;
        case 'e':
        case 'E':
            numbersMode = 1;
            break;
        case 'k':
        case'K':
            numbersMode = 0;
            break;
        case 'l':
        case 'L':
            initializeGlobalVariables();
            break;

    }
    glutPostRedisplay();
}

int main(int argc, char *argv[ ] ) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50,100);
    glutInitWindowSize(WIDTH,HEIGHT);
    glutCreateWindow("Computação Gráfica");

    //Auxiliar function
    initializeGlobalVariables();

    glutDisplayFunc(draw);
    glutKeyboardFunc(onKeyboardAction);
    glutMouseFunc(onMouseAction);

    glutMainLoop ();
    return 0;
}
