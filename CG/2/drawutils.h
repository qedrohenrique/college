#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

float rotationX(float x, float y, float xr, float yr, float angle){
    return xr + ((x - xr) * cos(angle)) - ((y-yr)*sin(angle));
}

float rotationY(float x, float y, float xr, float yr, float angle){
    return yr + ((x - xr) * sin(angle)) + ((y-yr)*cos(angle));
}

void drawCircle(float r, float x, float y) {
        float i = 0.0f;

        glBegin(GL_TRIANGLE_FAN);

        glVertex2f(x, y); // Center
        for(i = 0.0f; i <= 360; i++)
                glVertex2f(r*cos(M_PI * i / 180.0) + x, r*sin(M_PI * i / 180.0) + y);

        glEnd();
}
void drawSemiUpperCircle(float r, float x, float y) {
        float i = 0.0f;

        glBegin(GL_TRIANGLE_FAN);

        glVertex2f(x, y); // Center
        for(i = 0.0f; i <= 180; i++)
                glVertex2f(r*cos(M_PI * i / 180.0) + x, r*sin(M_PI * i / 180.0) + y);

        glEnd();
}

void drawHitbox(float x, float y, float range, float angle){
    glColor3f(0.75, 0.25, 0.25);
    float xpos, ypos;
    glBegin(GL_QUADS);
        xpos = rotationX(x-range, y-range, x, y, angle); ypos = rotationY(x-range, y-range, x, y, angle);
        glVertex2f(xpos, ypos);
        xpos = rotationX(x+range, y-range, x, y, angle); ypos = rotationY(x+range, y-range, x, y, angle);
        glVertex2f(xpos, ypos);
        xpos = rotationX(x+range, y+range, x, y, angle); ypos = rotationY(x+range, y+range, x, y, angle);
        glVertex2f(xpos, ypos);
        xpos = rotationX(x-range, y+range, x, y, angle); ypos = rotationY(x-range, y+range, x, y, angle);
        glVertex2f(xpos, ypos);
    glEnd();
    glPointSize(10);
    glColor3f(0,1,0);
    glBegin(GL_POINTS);
        xpos = rotationX(x+range, y, x, y, angle); ypos = rotationY(x+range, y, x, y, angle);
        glVertex2f(xpos, ypos);
    glEnd();
}

void drawCat(float x, float y, float range, float angle){
    glColor3f(0.25, 0.25, 0.25);
    range *= 1.15;

    float xpos, ypos;

    glBegin(GL_QUADS);
        //body
        xpos = rotationX(x-range/2, y-range/4, x, y, angle); ypos = rotationY(x-range/2, y-range/4, x, y, angle);
        glVertex2f(xpos, ypos);
        xpos = rotationX(x+range/2,  y-range/4, x, y, angle); ypos = rotationY(x+range/2,  y-range/4, x, y, angle);
        glVertex2f(xpos, ypos);
        xpos = rotationX(x+range/2, y+range/4, x, y, angle); ypos = rotationY(x+range/2, y+range/4, x, y, angle);
        glVertex2f(xpos, ypos);
        xpos = rotationX(x-range/2, y+range/4, x, y, angle); ypos = rotationY(x-range/2, y+range/4, x, y, angle);
        glVertex2f(xpos, ypos);

        //legs
        xpos = rotationX(x-range/2, y-range/4, x, y, angle); ypos = rotationY(x-range/2, y-range/4, x, y, angle);
        glVertex2f(xpos, ypos);
        xpos = rotationX(x-range/2.5, y-range/4, x, y, angle); ypos = rotationY(x-range/2.5, y-range/4, x, y, angle);
        glVertex2f(xpos, ypos);
        xpos = rotationX(x-range/2.5, y-range/2, x, y, angle); ypos = rotationY(x-range/2.5, y-range/2, x, y, angle);
        glVertex2f(xpos, ypos);
        xpos = rotationX(x-range/2, y-range/2, x, y, angle); ypos = rotationY(x-range/2, y-range/2, x, y, angle);
        glVertex2f(xpos, ypos);

        xpos = rotationX(x-range/2 + range/6, y-range/4, x, y, angle); ypos = rotationY(x-range/2 + range/6, y-range/4, x, y, angle);
        glVertex2f(xpos, ypos);
        xpos = rotationX(x-range/2.5 + range/6, y-range/4, x, y, angle); ypos = rotationY(x-range/2.5 + range/6, y-range/4, x, y, angle);
        glVertex2f(xpos, ypos);
        xpos = rotationX(x-range/2.5 + range/6, y-range/2, x, y, angle); ypos = rotationY(x-range/2.5 + range/6, y-range/2, x, y, angle);
        glVertex2f(xpos, ypos);
        xpos = rotationX(x-range/2 + range/6, y-range/2, x, y, angle); ypos = rotationY(x-range/2 + range/6, y-range/2, x, y, angle);
        glVertex2f(xpos, ypos);

        xpos = rotationX(x+range/2, y-range/4, x, y, angle); ypos = rotationY(x+range/2, y-range/4, x, y, angle);
        glVertex2f(xpos, ypos);
        xpos = rotationX(x+range/2.5, y-range/4, x, y, angle); ypos = rotationY(x+range/2.5, y-range/4, x, y, angle);
        glVertex2f(xpos, ypos);
        xpos = rotationX(x+range/2.5, y-range/2, x, y, angle); ypos = rotationY(x+range/2.5, y-range/2, x, y, angle);
        glVertex2f(xpos, ypos);
        xpos = rotationX(x+range/2, y-range/2, x, y, angle); ypos = rotationY(x+range/2, y-range/2, x, y, angle);
        glVertex2f(xpos, ypos);

        xpos = rotationX(x+range/2 - range/6, y-range/4, x, y, angle); ypos = rotationY(x+range/2 - range/6, y-range/4, x, y, angle);
        glVertex2f(xpos, ypos);
        xpos = rotationX(x+range/2.5 - range/6, y-range/4, x, y, angle); ypos = rotationY(x+range/2.5 - range/6, y-range/4, x, y, angle);
        glVertex2f(xpos, ypos);
        xpos = rotationX(x+range/2.5 - range/6, y-range/2, x, y, angle); ypos = rotationY(x+range/2.5 - range/6, y-range/2, x, y, angle);
        glVertex2f(xpos, ypos);
        xpos = rotationX(x+range/2 - range/6, y-range/2, x, y, angle); ypos = rotationY(x+range/2 - range/6, y-range/2, x, y, angle);
        glVertex2f(xpos, ypos);

        //head
        xpos = rotationX(x+range/2, y+range/4, x, y, angle); ypos = rotationY(x+range/2, y+range/4, x, y, angle);
        glVertex2f(xpos, ypos);
        xpos = rotationX(x+range/1.1, y+range/4, x, y, angle); ypos = rotationY(x+range/1.1, y+range/4, x, y, angle);
        glVertex2f(xpos, ypos);
        xpos = rotationX(x+range/1.1, y+range/1.6, x, y, angle); ypos = rotationY(x+range/1.1, y+range/1.6, x, y, angle);
        glVertex2f(xpos, ypos);
        xpos = rotationX(x+range/2, y+range/1.6, x, y, angle); ypos = rotationY(x+range/2, y+range/1.6, x, y, angle);
        glVertex2f(xpos, ypos);

        //ears;
        xpos = rotationX(x+range/0.93 - range/6, y+range/1.6, x, y, angle); ypos = rotationY(x+range/0.93 - range/6, y+range/1.6, x, y, angle);
        glVertex2f(xpos, ypos);
        xpos = rotationX(x+range/0.93 - range/6, y+range/1.4, x, y, angle); ypos = rotationY(x+range/0.93 - range/6, y+range/1.4, x, y, angle);
        glVertex2f(xpos, ypos);
        xpos = rotationX(x+range/1.03 - range/6, y+range/1.4, x, y, angle); ypos = rotationY(x+range/1.03 - range/6, y+range/1.4, x, y, angle);
        glVertex2f(xpos, ypos);
        xpos = rotationX(x+range/1.03 - range/6, y+range/1.6, x, y, angle); ypos = rotationY(x+range/1.03 - range/6, y+range/1.6, x, y, angle);
        glVertex2f(xpos, ypos);

        xpos = rotationX(x+range/1.5 - range/6, y+range/1.6, x, y, angle); ypos = rotationY(x+range/1.5 - range/6, y+range/1.6, x, y, angle);
        glVertex2f(xpos, ypos);
        xpos = rotationX(x+range/1.5 - range/6, y+range/1.4, x, y, angle); ypos = rotationY(x+range/1.5 - range/6, y+range/1.4, x, y, angle);
        glVertex2f(xpos, ypos);
        xpos = rotationX(x+range/1.3 - range/6, y+range/1.4, x, y, angle); ypos = rotationY(x+range/1.3 - range/6, y+range/1.4, x, y, angle);
        glVertex2f(xpos, ypos);
        xpos = rotationX(x+range/1.3 - range/6, y+range/1.6, x, y, angle); ypos = rotationY(x+range/1.3 - range/6, y+range/1.6, x, y, angle);
        glVertex2f(xpos, ypos);


        //tail
        xpos = rotationX(x-range/2.2, y+range/4.5, x, y, angle); ypos = rotationY(x-range/2.2, y+range/4.5, x, y, angle);
        glVertex2f(xpos, ypos);
        xpos = rotationX(x-range/2.2, y+range/3.1, x, y, angle); ypos = rotationY(x-range/2.2, y+range/3.1, x, y, angle);
        glVertex2f(xpos, ypos);
        xpos = rotationX(x-range/1.3, y+range/3.1, x, y, angle); ypos = rotationY(x-range/1.3, y+range/3.1, x, y, angle);
        glVertex2f(xpos, ypos);
        xpos = rotationX(x-range/1.3, y+range/4.5, x, y, angle); ypos = rotationY(x-range/1.3, y+range/4.5, x, y, angle);
        glVertex2f(xpos, ypos);
    glEnd();

    glPointSize(30*range);
    glBegin(GL_POINTS);
        //tail
        glColor3f(0.75,0.75,0.75);
        xpos = rotationX(x-range/1.3, y+range/3.1, x, y, angle); ypos = rotationY(x-range/1.3, y+range/3.1, x, y, angle);
        glVertex2f(xpos, ypos);

        //nose
        glColor3f(0.9,0.5,0.45);
        xpos = rotationX(x+range/1.35, y+range/2.5, x, y, angle); ypos = rotationY(x+range/1.35, y+range/2.5, x, y, angle);
        glVertex2f(xpos, ypos);
    glEnd();

    glLineWidth(10*range);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        //left mustache
        xpos = rotationX(x+range/1.35, y+range/2.5, x, y, angle); ypos = rotationY(x+range/1.35, y+range/2.5, x, y, angle);
        glVertex2f(xpos, ypos);
        xpos = rotationX(x+range/1.75, y+range/2.5, x, y, angle); ypos = rotationY(x+range/1.75, y+range/2.5, x, y, angle);
        glVertex2f(xpos, ypos);

        xpos = rotationX(x+range/1.35, y+range/2.5, x, y, angle); ypos = rotationY(x+range/1.35, y+range/2.5, x, y, angle);
        glVertex2f(xpos, ypos);
        xpos = rotationX(x+range/1.75, y+range/2.1, x, y, angle); ypos = rotationY(x+range/1.75, y+range/2.1, x, y, angle);
        glVertex2f(xpos, ypos);

        xpos = rotationX(x+range/1.35, y+range/2.5, x, y, angle); ypos = rotationY(x+range/1.35, y+range/2.5, x, y, angle);
        glVertex2f(xpos, ypos);
        xpos = rotationX(x+range/1.75, y+range/2.9, x, y, angle); ypos = rotationY(x+range/1.75, y+range/2.9, x, y, angle);
        glVertex2f(xpos, ypos);

        //right mustache
        xpos = rotationX(x+range/1.35, y+range/2.5, x, y, angle); ypos = rotationY(x+range/1.35, y+range/2.5, x, y, angle);
        glVertex2f(xpos, ypos);
        xpos = rotationX(x+range/1.15, y+range/2.5, x, y, angle); ypos = rotationY(x+range/1.15, y+range/2.5, x, y, angle);
        glVertex2f(xpos, ypos);

        xpos = rotationX(x+range/1.35, y+range/2.5, x, y, angle); ypos = rotationY(x+range/1.35, y+range/2.5, x, y, angle);
        glVertex2f(xpos, ypos);
        xpos = rotationX(x+range/1.15, y+range/2.1, x, y, angle); ypos = rotationY(x+range/1.15, y+range/2.1, x, y, angle);
        glVertex2f(xpos, ypos);

        xpos = rotationX(x+range/1.35, y+range/2.5, x, y, angle); ypos = rotationY(x+range/1.35, y+range/2.5, x, y, angle);
        glVertex2f(xpos, ypos);
        xpos = rotationX(x+range/1.15, y+range/2.9, x, y, angle); ypos = rotationY(x+range/1.15, y+range/2.9, x, y, angle);
        glVertex2f(xpos, ypos);

    glEnd();




    }

