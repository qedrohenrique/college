#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
int it = 1;

void vicsekRecursive(float a,float b,float len,float m){

    if(m == 0)
        glRectd(a,b,a+len,b+len);
    else{
        vicsekRecursive(a+len/3,b+len/3,len/3,m-1);
        vicsekRecursive(a,b,len/3,m-1);
        vicsekRecursive(a+(len*2)/3,b,len/3,m-1);
        vicsekRecursive(a+(len*2)/3,b+(len*2)/3,len/3,m-1);
        vicsekRecursive(a,b+(len*2)/3,len/3,m-1);
    }
}


void draw(){
    glClearColor (1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0,0.0,0.0);
    vicsekRecursive(-2,-2,4,it);
    glEnd();

    glFlush();
}


int main(int argc, char **argv){

    printf("Digite o numero de iteracoes desejado: \nOBS: o numero maximo eh 7.\n");
    scanf("%d", &it);

    while(it > 7 || it < 0){
        printf("Digite um valor valido.\n");
        scanf("%d", &it);
    }

    if(it == 0) it = 1;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Computação Gráfica - Vicsek");

    glutDisplayFunc(draw);

    gluOrtho2D(-2.0, 2.0, -2.0, 2.0);

    glutMainLoop();
}
