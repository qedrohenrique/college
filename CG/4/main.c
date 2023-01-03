#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>


#define TORSO 0
#define COTOVELO_DIR 1
#define COTOVELO_ESQ 2
#define OMBRO_DIR 3
#define OMBRO_ESQ 4
#define PULSO_DIR 5
#define PULSO_ESQ 6
#define QUADRIL_DIR 7
#define QUADRIL_ESQ 8
#define JOELHO_DIR 9
#define JOELHO_ESQ 10
#define CALCANHAR_DIR 11
#define CALCANHAR_ESQ 12


int angx = 30, angy = 0, angz = 0;
float zoom = 0.75;
int menuParteCorpo = 0;

int ombroX_esq = 0, ombroY_esq = 0, ombroZ_esq = 0,
    cotoveloX_esq = 0, cotoveloY_esq = 0, cotoveloZ_esq = 0,
    pulsoX_esq = 0, pulsoY_esq = 0, pulsoZ_esq = 0;
int ombroX_dir = 0, ombroY_dir= 0, ombroZ_dir = 0,
    cotoveloX_dir = 0, cotoveloY_dir = 0, cotoveloZ_dir = 0,
    pulsoX_dir = 0, pulsoY_dir = 0, pulsoZ_dir = 0;
int quadrilX_dir = 0,  quadrilY_dir = 0,  quadrilZ_dir = 0,
    joelhoX_dir = 0,  joelhoY_dir = 0,  joelhoZ_dir = 0,
    calcanharX_dir = 0,  calcanharY_dir = 0,  calcanharZ_dir = 0;
int quadrilX_esq = 0,  quadrilY_esq = 0,  quadrilZ_esq = 0,
    joelhoX_esq = 0,  joelhoY_esq = 0,  joelhoZ_esq = 0,
    calcanharX_esq = 0,  calcanharY_esq = 0,  calcanharZ_esq = 0;
int abdomemY = 0;
int torsoX = 0, torsoY = 0, torsoZ = 0;
int win = 800;

float translateHumanX = 0, translateHumanY = 0, translateHumanZ = 0;

int flag_animPernaDir = 0,flag_animPernaEsq = 0;
int flag_andar = 1, must_walk = 1, stop_walk = 0;
int flag_ballReached = 0;
int flag_centerReached = 0;
int flag_pegaPeso = 0;
int flag_treinaBraco = 0;
int flag_guardaPeso = 0;
int flag_rotBracoEsq = 0;
int flag_rotBracoDir = 0;

GLfloat fAspect, angle = 45.0;
GLfloat ctrlpoints1[7][3] = {
    {-1.0, 0, 0.0}, {-0.5, 0.75, 0.0}, {0.0, 1.0, 0.0}, {0.0, 1.0, 0.0}, {0.5, 0.75, 0.0}, {1.0, 0.0, 0.0}
};

GLuint texture_id_grama;

typedef struct BMPIMG {
    int width;
    int height;
    char *data;
}BMPIMG;


// aux draw

void resetMovements(){
    angx = 0;
    angy = 0;
    angz = 0;
    zoom = 0.75;
    menuParteCorpo = 0;

    ombroX_esq = 0;ombroY_esq = 0;ombroZ_esq = 0,
    cotoveloX_esq = 0;cotoveloY_esq = 0;cotoveloZ_esq = 0,
    pulsoX_esq = 0;pulsoY_esq = 0;pulsoZ_esq = 0;
    ombroX_dir = 0;ombroY_dir= 0;ombroZ_dir = 0,
    cotoveloX_dir = 0;cotoveloY_dir = 0;cotoveloZ_dir = 0,
    pulsoX_dir = 0;pulsoY_dir = 0;pulsoZ_dir = 0;
    quadrilX_dir = 0; quadrilY_dir = 0; quadrilZ_dir = 0,
    joelhoX_dir = 0; joelhoY_dir = 0; joelhoZ_dir = 0,
    calcanharX_dir = 0; calcanharY_dir = 0; calcanharZ_dir = 0;
    quadrilX_esq = 0; quadrilY_esq = 0; quadrilZ_esq = 0,
    joelhoX_esq = 0; joelhoY_esq = 0; joelhoZ_esq = 0,
    calcanharX_esq = 0; calcanharY_esq = 0; calcanharZ_esq = 0;
    abdomemY = 0;
    torsoX = 0;torsoY = 0;torsoZ = 0;

    translateHumanX = 0;translateHumanY = 0;translateHumanZ = 0;

    flag_animPernaDir = 0,flag_animPernaEsq = 0;
    flag_andar = 1;must_walk = 1;stop_walk = 0;
    flag_ballReached = 0;
    flag_centerReached = 0;
    flag_pegaPeso = 0;
    flag_treinaBraco = 0;
    flag_guardaPeso = 0;
    flag_rotBracoEsq = 0;
    flag_rotBracoDir = 0;
}

void drawHalfSphere(int scaley, int scalex, GLfloat r) {
   int i, j;
   GLfloat v[scalex*scaley][3];

   for (i=0; i<scalex; ++i) {
     for (j=0; j<scaley; ++j) {
       v[i*scaley+j][0]=r*cos(j*2*M_PI/scaley)*cos(i*M_PI/(2*scalex));
       v[i*scaley+j][1]=r*sin(i*M_PI/(2*scalex));
       v[i*scaley+j][2]=r*sin(j*2*M_PI/scaley)*cos(i*M_PI/(2*scalex));
     }
   }

   glBegin(GL_QUADS);
     for (i=0; i<scalex-1; ++i) {
       for (j=0; j<scaley; ++j) {
         glVertex3fv(v[i*scaley+j]);
         glVertex3fv(v[i*scaley+(j+1)%scaley]);
         glVertex3fv(v[(i+1)*scaley+(j+1)%scaley]);
         glVertex3fv(v[(i+1)*scaley+j]);
       }
     }
   glEnd();
 }

// Personagem

void drawTorso(){

    // TORAX
    glPushMatrix();
        glColor3f(0.670, 0.289, 0.194);

        // Frente/Tras

        glBegin(GL_POLYGON);
            glVertex3f(0.1, 0, 0.1);
            glVertex3f(-0.1, 0, 0.1);
            glVertex3f(-0.15, 0.2, 0.1);
            glVertex3f(-0.05, 0.15, 0.15);
            glVertex3f(0.05, 0.15, 0.15);
            glVertex3f(0.15, 0.2, 0.1);
        glEnd();

        glBegin(GL_POLYGON);
            glVertex3f(0.15, 0.2, 0.1);
            glVertex3f(0.05, 0.15, 0.15);
            glVertex3f(-0.05, 0.15, 0.15);
            glVertex3f(-0.15, 0.2, 0.10);
            glVertex3f(-0.1, 0.25, 0.05);
            glVertex3f(0.1, 0.25, 0.05);
        glEnd();

            //

        glBegin(GL_POLYGON);
            glVertex3f(0.10, 0, -0.1);
            glVertex3f(-0.10, 0, -0.1);
            glVertex3f(-0.15, 0.22, -0.12);
            glVertex3f(0.15, 0.22, -0.12);
        glEnd();

        glBegin(GL_POLYGON);
            glVertex3f(0.15, 0.22, -0.12);
            glVertex3f(-0.15, 0.22, -0.12);
            glVertex3f(-0.15, 0.25, -0.1);
            glVertex3f(0.15, 0.25, -0.1);
        glEnd();

        //Lados

        glBegin(GL_POLYGON);
            glVertex3f(0.1, 0, -0.1);
            glVertex3f(0.1, 0, 0.1);
            glVertex3f(0.15, 0.22, -0.12);
        glEnd();

        glBegin(GL_POLYGON);
            glVertex3f(0.1, 0, 0.1);
            glVertex3f(0.15, 0.2, 0.1);
            glVertex3f(0.15, 0.22, -0.12);
        glEnd();

        glBegin(GL_POLYGON);
            glVertex3f(0.15, 0.22, -0.12);
            glVertex3f(0.15, 0.25, -0.1);
            glVertex3f(0.1, 0.25, 0.05);
            glVertex3f(0.15, 0.2, 0.1);
        glEnd();

        //

        glBegin(GL_POLYGON);
            glVertex3f(-0.10, 0, -0.1);
            glVertex3f(-0.10, 0, 0.1);
            glVertex3f(-0.15, 0.22, -0.12);
        glEnd();

        glBegin(GL_POLYGON);
            glVertex3f(-0.1, 0, 0.1);
            glVertex3f(-0.15, 0.2, 0.1);
            glVertex3f(-0.15, 0.22, -0.12);
        glEnd();

        glBegin(GL_POLYGON);
            glVertex3f(-0.15, 0.22, -0.12);
            glVertex3f(-0.15, 0.25, -0.10);
            glVertex3f(-0.1, 0.25, 0.05);
            glVertex3f(-0.15, 0.2, 0.1);
        glEnd();

        // Baixo

        glBegin(GL_POLYGON);
            glVertex3f(0.1, 0, 0.1);
            glVertex3f(-0.1, 0, 0.1);
            glVertex3f(-0.1, 0, -0.1);
            glVertex3f(0.1, 0, -0.1);
        glEnd();

        // Cima

        glBegin(GL_POLYGON);
            glVertex3f(0.15, 0.25, -0.1);
            glVertex3f(-0.15, 0.25, -0.1);
            glVertex3f(-0.1, 0.25, 0.05);
            glVertex3f(0.1, 0.25, 0.05);
        glEnd();

    glPopMatrix();
}

void drawAbdomen(){
    //ABDOMEN
    glPushMatrix();
        glColor3f(0.670, 0.289, 0.194);
        glutSolidSphere(0.1, 50, 10);
    glPopMatrix();
}

void drawQuadril(){
//QUADRIL
    glPushMatrix();
        // Frente/Tras
        glColor3f(0.670, 0.289, 0.194);

        glBegin(GL_POLYGON);
            glVertex3f(0.1, -0.02, 0.08);
            glVertex3f(-0.1, -0.02, 0.08);
            glVertex3f(-0.15, -0.25, 0.1);
            glVertex3f(0.15, -0.25, 0.1);
        glEnd();

        //

        glBegin(GL_POLYGON);
            glVertex3f(0.1, -0.02, -0.08);
            glVertex3f(-0.1, -0.02, -0.08);
            glVertex3f(-0.15, -0.25, -0.1);
            glVertex3f(0.15, -0.25, -0.1);
        glEnd();

        //Lados

        glBegin(GL_POLYGON);
            glVertex3f(0.1, -0.02, -0.08);
            glVertex3f(0.1, -0.02, 0.08);
            glVertex3f(0.15, -0.25, 0.1);
            glVertex3f(0.15, -0.25, -0.1);
        glEnd();

        //

        glBegin(GL_POLYGON);
            glVertex3f(-0.1, -0.02, -0.08);
            glVertex3f(-0.1, -0.02, 0.08);
            glVertex3f(-0.15, -0.25, 0.1);
            glVertex3f(-0.15, -0.25, -0.1);
        glEnd();

        //baixo

        glBegin(GL_POLYGON);
            glVertex3f(0.15, -0.25, 0.1);
            glVertex3f(-0.15, -0.25, 0.1);
            glVertex3f(-0.15, -0.25, -0.1);
            glVertex3f(0.15, -0.25, -0.1);
        glEnd();

        //cima

        glBegin(GL_POLYGON);
            glVertex3f(0.1, -0.02, -0.08);
            glVertex3f(-0.1, -0.02, -0.08);
            glVertex3f(-0.1, -0.02, 0.08);
            glVertex3f(0.1, -0.02, 0.08);
        glEnd();

    glPopMatrix();}

void drawArm(
             int ombroX, int ombroY, int ombroZ,
             int cotoveloX, int cotoveloY, int cotoveloZ,
             int pulsoX, int pulsoY, int pulsoZ,
             int lado
             ){

    float radius = 0.05;
    float braco_heigth = 0.23;
    float antebraco_height = 0.18;
    float hand_quarter_size = 0.05;

    glPushMatrix();
        glColor4f(0, 0, 0, 0.7);

        glRotatef(ombroX, 1, 0, 0);
        glRotatef(ombroY, 0, 1, 0);
        glRotatef(ombroZ, 0, 0, 1);

        //ombro
        glPushMatrix();
            glColor3f(0.670, 0.289, 0.194);
            glutSolidSphere(radius+0.005, 50, 10);
        glPopMatrix();

        //braco
        glPushMatrix();
            glColor3f(0.670, 0.289, 0.194);
            glRotatef(90, 1, 0, 0);
            glutSolidCylinder(radius, braco_heigth, 10, 10);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0, -braco_heigth, 0);

            //cotovelo
            glRotatef(cotoveloX, 1, 0, 0);
            glRotatef(cotoveloY, 0, 1, 0);
            glRotatef(cotoveloZ, 0, 0, 1);

            glPushMatrix();
                glColor3f(0.670, 0.289, 0.194);
                glutSolidSphere(radius, 50, 10);
            glPopMatrix();

            //antebraco
            glPushMatrix();
                glColor3f(0.910, 0.867, 0.792);
                glRotatef(90, 1, 0, 0);
                glutSolidCylinder(radius-0.005, antebraco_height, 10, 10);
            glPopMatrix();

            //pulso
            glTranslatef(0, -antebraco_height, 0);

            glRotatef(pulsoX, 1, 0, 0);
            glRotatef(pulsoY, 0, 1, 0);
            glRotatef(pulsoZ, 0, 0, 1);

            glPushMatrix();
                glColor3f(0.910, 0.867, 0.792);
                glutSolidSphere(radius-0.005, 50, 10);
            glPopMatrix();

            //Mão

            if(flag_pegaPeso == 2 && lado == -1){
                glPushMatrix();
                    glTranslatef(radius/2*lado + 0.05, -radius, -hand_quarter_size + 0.05);
                    drawPeso();
                glPopMatrix();
            }

            glPushMatrix();
                glColor3f(0.910, 0.867, 0.792);
                glTranslatef(radius/2*lado, -radius/2, 0);
                glScaled(1, 2, 1.5);
                glutSolidCube(hand_quarter_size);
            glPopMatrix();

            glPushMatrix();
                glRotatef(30, 1, 0, 0);
                glTranslatef(radius/2*lado, -radius/2, hand_quarter_size*1.1);
                glScaled(0.5, 0.5, 0.75);
                glutSolidCube(hand_quarter_size);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(radius/2*lado, -radius*1.5, 0);
                glScaled(1, 1.15, 1.35);
                glutSolidCube(hand_quarter_size);
            glPopMatrix();

        glPopMatrix();
    glPopMatrix();
}

void drawLeg(
             int quadrilX, int quadrilY, int quadrilZ,
             int joelhoX, int joelhoY, int joelhoZ,
             int calcanharX, int calcanharY, int calcanharZ
             ){

    float radius = 0.06;
    float coxa_height = 0.25;
    float canela_hight = 0.18;
    float foot_height = 0.1;

    glPushMatrix();
        glColor4f(0, 0, 0, 0.7);

        glRotatef(quadrilX, 1, 0, 0);
        glRotatef(quadrilY, 0, 1, 0);
        glRotatef(quadrilZ, 0, 0, 1);

        //quadril
        glPushMatrix();
            glColor3f(0.165, 0.173, 0.190);
            glutSolidSphere(radius, 50, 10);
        glPopMatrix();

        //coxa
        glPushMatrix();
            glColor3f(0.165, 0.173, 0.190);
            glRotatef(90, 1, 0, 0);
            glutSolidCylinder(radius, coxa_height, 10, 10);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0, -coxa_height, 0);

            //joelho
            glRotatef(joelhoX, 1, 0, 0);
            glRotatef(joelhoY, 0, 1, 0);
            glRotatef(joelhoZ, 0, 0, 1);

            glPushMatrix();
                glColor3f(0.165, 0.173, 0.190);
                glutSolidSphere(radius, 50, 10);
            glPopMatrix();

            //canela
            glPushMatrix();
                glColor3f(0.910, 0.867, 0.792);
                glRotatef(90, 1, 0, 0);
                glutSolidCylinder(radius-0.008, canela_hight, 10, 10);
            glPopMatrix();

            //calcanhar
            glTranslatef(0, -canela_hight, 0);

            glRotatef(calcanharX, 1, 0, 0);
            glRotatef(calcanharY, 0, 1, 0);
            glRotatef(calcanharZ, 0, 0, 1);

            glPushMatrix();
                glColor3f(0.910, 0.867, 0.792);
                glutSolidSphere(radius-0.008, 50, 10);
            glPopMatrix();

            glTranslatef(0, -radius, 0);
            glPushMatrix();
                glColor3f(0, 0, 0);
                glutSolidCube(foot_height);

                glTranslatef(0, 0, foot_height/2);
                glutSolidSphere(foot_height/2, 50, 10);

                glPushMatrix();
                    glTranslatef(foot_height/4, -foot_height/4, foot_height/4);
                    glutSolidCube(foot_height/2);
                    glTranslatef(0, 0, foot_height/4);
                    glutSolidCube(foot_height/2);
                    glTranslatef(0, 0, foot_height/4);
                    glutSolidCube(foot_height/2);
                glPopMatrix();

                glPushMatrix();
                    glTranslatef(-foot_height/4, -foot_height/4, foot_height/4);
                    glutSolidCube(foot_height/2);
                    glTranslatef(0, 0, foot_height/4);
                    glutSolidCube(foot_height/2);
                    glTranslatef(0, 0, foot_height/4);
                    glutSolidCube(foot_height/2);
                glPopMatrix();

            glPopMatrix();
        glPopMatrix();

    glPopMatrix();
}

void drawHead(){
    glPushMatrix();
        glPushMatrix();
            glColor3f(0.910, 0.867, 0.792);
            glRotatef(90, 1, 0, 0);
            glutSolidCylinder(0.04, 0.04, 20, 20);
        glPopMatrix();

        glTranslatef(0, 0.08, 0);
        glPushMatrix();
            glScaled(1, 1.3, 1);
            glutSolidSphere(0.08, 20, 20);
        glPopMatrix();
    glPopMatrix();
}

// Cena

void drawPeso(){
    glPushMatrix();
        glColor3f(1, 0, 0);
        glTranslatef(0, 0, -0.075);
        glutSolidCylinder(0.025, 0.15, 10, 10);
        glutSolidSphere(0.05, 10, 10);
        glTranslatef(0, 0, 0.15);
        glutSolidSphere(0.05, 10, 10);

    glPopMatrix();
}

void drawChao(){
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glPushMatrix();
        glTranslatef(0, -0.8, 0);
        glScaled(300, 2, 300);
        glColor3f(0.36, 0.36, 0);
        glBindTexture(GL_TEXTURE_2D, texture_id_grama);

        glutSolidCube(0.05);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void drawMesa(){
    glPushMatrix();
        glColor3f(0.1, 0.05, 0);

        glPushMatrix();
            glTranslatef(0.75, -0.25, 0.0);
            glScaled(2.5, 1, 5);
            glutSolidCube(0.1);
        glPopMatrix();


        glPushMatrix();
            glTranslatef(0.85, -0.5, 0.2);
            glScaled(1, 10, 1);
            glutSolidCube(0.05);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0.85, -0.5, -0.2);
            glScaled(1, 10, 1);
            glutSolidCube(0.05);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0.65, -0.5, 0.2);
            glScaled(1, 10, 1);
            glutSolidCube(0.05);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0.65, -0.5, -0.2);
            glScaled(1, 10, 1);
            glutSolidCube(0.05);
        glPopMatrix();

    glPopMatrix();
}

void drawArvoreTipo1(){
    glPushMatrix();
        glTranslatef(0, 0, -3);

    glPushMatrix();
        glColor3d(0.0, 0.50, 0.50);
        glTranslated(0, 0.3, 0);
        glScaled(0.3, 0.3, 0.3);
        glutSolidDodecahedron();
    glPopMatrix();

    glPushMatrix();
        glColor3d(0.91, 0.59, 0.48);
        glTranslated(0, -0.4, 0);
        glScaled(2, 8, 2);
        glutSolidCube(0.1);
    glPopMatrix();

    glPopMatrix();
}

void drawArvoreTipo2(){
    glPushMatrix();
        glTranslatef(0, 0, -3);

    glPushMatrix();
        glColor3d(0.830, 0.596, 0.0498);
        glTranslated(0, 0.4, 0);
        glScaled(0.4, 0.4, 0.4);
        glutSolidDodecahedron();
    glPopMatrix();

    glPushMatrix();
        glColor3d(0.860, 0.846, 0.808);
        glTranslated(0, -0.3, 0);
        glScaled(2, 10, 2);
        glutSolidCube(0.1);
    glPopMatrix();

    glPopMatrix();
}

void drawArvoreTipo3(){
        glPushMatrix();
        glTranslatef(0, 0, -3);

    glPushMatrix();
        glColor3d(0.314, 0.430, 0.355);
        glTranslated(0, 0.5, 0);
        glScaled(0.35, 0.35, 0.35);
        glutSolidDodecahedron();
    glPopMatrix();

    glPushMatrix();
        glColor3d(0.290, 0.236, 0.191);
        glTranslated(0, -0.075, 0);
        glScaled(2, 15, 2);
        glutSolidCube(0.1);
    glPopMatrix();

    glPopMatrix();
}

void drawMontanhaTipo1(GLfloat size){
    drawHalfSphere(64, 64, size);
}

void drawMontanhaTipo2(){
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 6, &ctrlpoints1[0][0]);
    glEnable(GL_MAP1_VERTEX_3);

    for (int i = 0; i < 1000; i++){
        glPushMatrix();
            glTranslated(0, 0, 0.001*i);
            glScaled(1, 1-0.0001*i, 1);
            glBegin(GL_POLYGON);
            for (int i = 0; i <= 100; i++)
                glEvalCoord1f((GLfloat) i/100.0);
            glEnd();
        glPopMatrix();
    }

    glFlush();
}

void drawArbusto(){
    glColor3d(0, 0.5, 0.3);
    glPushMatrix();
        glScaled(0.2, 0.2, 0.2);
        glutSolidDodecahedron();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-0.3, -0.1, 0);
        glScaled(0.15, 0.15, 0.15);
        glutSolidDodecahedron();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.3, -0.1, 0);
        glScaled(0.15, 0.15, 0.15);
        glutSolidDodecahedron();
    glPopMatrix();
}

void drawPath(){
    glColor3d(0.640, 0.582, 0.506);
    glPushMatrix();
        glTranslatef(0, -0.76, 0);
        glScaled(1, 0.01, 1);
        glutSolidSphere(2, 30, 30);
    glPopMatrix();

    glPushMatrix();
        glPushMatrix();
            glTranslatef(0, -0.795, 2);
            glScaled(1, 0.1, 5);
            glutSolidCube(1);
        glPopMatrix();
    glPopMatrix();


}

// display

void draw(){
    glClearColor(0.1,0.3,0.45,0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION) ;
    glLoadIdentity() ;
    gluPerspective(80, fAspect, 0.1, 100.0);
    glOrtho(-win, win, -win, win, win, win);
    gluLookAt(0, 0, 3.5, 0, 0, 0, 0, 1, 0);

    glMatrixMode(GL_MODELVIEW) ;
    glLoadIdentity();




    glPushMatrix();

        glTranslatef(0, 0, 1);

        glRotated(angx, 1, 0, 0);
        glRotated(angy, 0, 1, 0);
        glRotated(angz, 0, 0, 1);

        glScalef(zoom, zoom, zoom);

        if(flag_pegaPeso != 2){
            glPushMatrix();
                glTranslatef(0.75, -0.15, 0);
                drawPeso();
            glPopMatrix();
        }

        // Personagem
        glPushMatrix();

            glTranslatef(translateHumanX, translateHumanY, translateHumanZ);

            glRotated(abdomemY, 0, 1, 0);
            drawAbdomen();

            glPushMatrix();
                glPushMatrix();

                    //Torso
                    glRotated(torsoX, 1, 0, 0);
                    glRotated(torsoY, 0, 1, 0);
                    glRotated(torsoZ, 0, 0, 1);
                    drawTorso();

                    //Bracos
                    glPushMatrix();
                        glTranslatef(0.185, 0.2, 0);
                        drawArm(ombroX_esq, ombroY_esq, ombroZ_esq, cotoveloX_esq, cotoveloY_esq, cotoveloZ_esq, pulsoX_esq, pulsoY_esq, pulsoZ_esq, 1);
                        glTranslatef(-0.37, 0, 0);
                        drawArm(ombroX_dir, ombroY_dir, ombroZ_dir, cotoveloX_dir, cotoveloY_dir, cotoveloZ_dir, pulsoX_dir, pulsoY_dir, pulsoZ_dir, -1);
                    glPopMatrix();

                    //cabeca
                    glPushMatrix();
                        glTranslatef(0, 0.28, 0);
                        drawHead();
                    glPopMatrix();

                glPopMatrix();

                drawQuadril();

                glPushMatrix();
                    glTranslatef(-0.075, -0.2, 0);
                    drawLeg(quadrilX_esq,  quadrilY_esq,  quadrilZ_esq, joelhoX_esq,  joelhoY_esq,  joelhoZ_esq, calcanharX_esq,  calcanharY_esq,  calcanharZ_esq);
                    glTranslatef(0.15, 0, 0);
                    drawLeg(quadrilX_dir,  quadrilY_dir,  quadrilZ_dir, joelhoX_dir,  joelhoY_dir,  joelhoZ_dir, calcanharX_dir,  calcanharY_dir,  calcanharZ_dir);
                glPopMatrix();

            glPopMatrix();

        glPopMatrix();

         // Cena
        glPushMatrix();
            glPushMatrix();
                drawMesa();
            glPopMatrix();

            int x, z;
            for(x = -10; x <= 10; x++){
                for(z = -3; z <= 1; z++){
                    glPushMatrix();
                        if((x % 3 == 0 && z % 3 == 2) || (x % 3 == 0 && z % 3 == -2)) {
                            glTranslatef(0.4*x, 0, 0.3*z);
                            drawArvoreTipo1();
                        }
                        if((x % 3 == 1 && z % 3 == 1) || (x % 3 == -1 && z % 3 == -1)) {
                            glTranslatef(0.4*x, 0, 0.3*z);
                            drawArvoreTipo2();
                        }
                        if((x % 3 == 2 && z % 3 == 0) || (x % 3 == -2 && z % 3 == 0)) {
                            glTranslatef(0.4*x, 0, 0.3*z);
                            drawArvoreTipo3();
                        }
                    glPopMatrix();
                }
            }

            glPushMatrix();
                glColor3d(0.230, 0.206, 0.161);
                glTranslatef(-3.5, -0.8, 1);
                drawMontanhaTipo1(1.5);
                glColor3d(0.370, 0.304, 0.218);
                glTranslatef(0.5, 0, -1);
                drawMontanhaTipo1(1);
                glColor3d(0.230, 0.198, 0.156);
                glTranslatef(-2, 0, -1);
                drawMontanhaTipo1(2);
            glPopMatrix();

            glPushMatrix();
                glColor3d(0.75, 0.5, 0.25);
                glTranslatef(0, -0.8, -5);
                glScaled(1, 2, 1);
                drawMontanhaTipo2();
            glPopMatrix();

            glPushMatrix();
                glColor3d(0.3, 0.15, 0.1);
                glTranslatef(1.85, -0.8, -5);
                glScaled(1, 2, 1);
                drawMontanhaTipo2();
            glPopMatrix();

            glPushMatrix();
                glRotated(90, 0, 1, 0);
                glPushMatrix();
                    glTranslatef(0.0, -0.5, 3);
                    drawArbusto();
                    for(int i = -3; i <= 1; i++){
                        glTranslatef(0.4 * i, 0, 0);
                        drawArbusto();
                    }
                    glTranslatef(0.0, 0, 0.7);
                    for(int i = -3; i <= 6; i++){
                        glTranslatef(0.3 * i, 0, 0);
                        drawArbusto();
                    }
                    glTranslatef(0.0, 0, 0.5);
                    for(int i = -3; i <= 4; i++){
                        glTranslatef(0.35 * i, 0, 0);
                        drawArbusto();
                    }
                glPopMatrix();
            glPopMatrix();


            glPushMatrix();
                drawPath();
            glPopMatrix();

            drawChao();

        glPopMatrix();

    glPopMatrix();



    glutSwapBuffers();
}

// Animações

void animDuasPernas(int extra) {
    if(flag_animPernaDir == 0){
        if(quadrilX_dir != -90){
            quadrilX_dir -= 5;
        }
        if(joelhoX_dir != 90){
            joelhoX_dir += 5;
        }
        if(joelhoX_dir == 90 && quadrilX_dir == -90 && quadrilZ_dir != 90){
            quadrilZ_dir += 5;
        }
        if(quadrilZ_dir == 90) flag_animPernaDir = 1;
    }

    if(flag_animPernaDir == 1){
        if(joelhoX_dir != 0){
            joelhoX_dir -= 5;
        }
        if(quadrilY_dir != 90){
            quadrilY_dir += 5;
        }
        if(quadrilY_dir == 90)flag_animPernaDir = 2;
    }

    if(flag_animPernaDir == 2){
        quadrilZ_dir = 0;
        quadrilX_dir = 0;
        flag_animPernaDir = 3;
    }

    if(flag_animPernaDir == 3){
        if(quadrilY_dir != 0){
            quadrilY_dir -= 5;
        }
        if(quadrilY_dir == 0) flag_animPernaDir = -1;
    }

    glutPostRedisplay();

    if(flag_animPernaDir != -1){
        glutTimerFunc(30,animDuasPernas,0);
    }else{
        animPernaEsq(0);
        flag_animPernaDir = 0;
    }
}

void animPernaDir(int extra) {
    if(flag_animPernaDir == 0){
        if(quadrilX_dir != -90){
            quadrilX_dir -= 5;
        }
        if(joelhoX_dir != 90){
            joelhoX_dir += 5;
        }
        if(joelhoX_dir == 90 && quadrilX_dir == -90 && quadrilZ_dir != 90){
            quadrilZ_dir += 5;
        }
        if(quadrilZ_dir == 90) flag_animPernaDir = 1;
    }

    if(flag_animPernaDir == 1){
        if(joelhoX_dir != 0){
            joelhoX_dir -= 5;
        }
        if(quadrilY_dir != 90){
            quadrilY_dir += 5;
        }
        if(quadrilY_dir == 90)flag_animPernaDir = 2;
    }

    if(flag_animPernaDir == 2){
        quadrilZ_dir = 0;
        quadrilX_dir = 0;
        flag_animPernaDir = 3;
    }

    if(flag_animPernaDir == 3){
        if(quadrilY_dir != 0){
            quadrilY_dir -= 5;
        }
        if(quadrilY_dir == 0) flag_animPernaDir = -1;
    }

    glutPostRedisplay();

    if(flag_animPernaDir != -1){
        glutTimerFunc(30,animPernaDir,0);
    }else{
        flag_animPernaDir = 0;
    }
}

void animPernaEsq(int extra){

    if(flag_animPernaEsq == 0){
        if(quadrilX_esq != -90){
            quadrilX_esq -= 5;
        }
        if(joelhoX_esq != 90){
            joelhoX_esq += 5;
        }
        if(joelhoX_esq == 90 && quadrilX_esq == -90 && quadrilZ_esq != -90){
            quadrilZ_esq -= 5;
        }
        if(quadrilZ_esq == -90) flag_animPernaEsq = 1;
    }

    if(flag_animPernaEsq == 1){
        if(joelhoX_esq != 0){
            joelhoX_esq -= 5;
        }
        if(quadrilY_esq != -90){
            quadrilY_esq -= 5 ;
        }
        if(quadrilY_esq == -90 )flag_animPernaEsq = 2;
    }

    if(flag_animPernaEsq == 2){
        quadrilZ_esq = 0;
        quadrilX_esq = 0;
        flag_animPernaEsq = 3;
    }

    if(flag_animPernaEsq == 3){
        if(quadrilY_esq != 0){
            quadrilY_esq += 5;
        }
        if(quadrilY_esq == 0) flag_animPernaEsq = -1;
    }

    glutPostRedisplay();

    if(flag_animPernaEsq != -1){
        glutTimerFunc(30,animPernaEsq,0);
    }else{
        flag_animPernaEsq = 0;
    }
}

void andar(int extra){
    quadrilX_dir += 5 * flag_andar;
    quadrilX_esq += 5 * (-flag_andar);

    ombroX_dir += 5 * (-flag_andar);
    ombroX_esq += 5 * flag_andar;

    if(quadrilX_dir == 30 || quadrilX_dir == -30) flag_andar = -flag_andar;

    glutPostRedisplay();
    if(stop_walk){
        ombroX_esq = 0;
        ombroX_dir = 0;
        quadrilX_esq = 0;
        quadrilX_dir = 0;
    }
    if(!stop_walk) glutTimerFunc(30,andar,0);
    else stop_walk = 0;
}

void alignToBall(int extra){
    if(abdomemY != 90) abdomemY += 5;

    glutPostRedisplay();
    if(abdomemY != 90) glutTimerFunc(30,alignToBall,0);
}

void alignToFront(int extra){
    if(abdomemY < -10 || abdomemY > 10){
        if(abdomemY < -10) abdomemY += 3;
        if(abdomemY > 10) abdomemY -= 3;
    }else{
        abdomemY = 0;
    }

    glutPostRedisplay();
    if(abdomemY != 0) glutTimerFunc(30,alignToFront,0);
}

void goToCenter(int extra){
   if(flag_pegaPeso == 2) printf("Por favor guarde o peso antes de voltar!\n");
   else{
     if(abdomemY != -90) abdomemY -= 5;
    else{
        if(must_walk == 1){
                glutTimerFunc(30, andar, 0);
                must_walk = 0;
            }
            translateHumanX -= 0.01;
            if(translateHumanX < 0){
                flag_centerReached = 1;
                stop_walk = 1;
            }
        }

        glutPostRedisplay();
        if(!flag_centerReached){
            glutTimerFunc(30,goToCenter,0);
        }else{
            must_walk = 1;
            flag_ballReached = 0;
        }
   }
}

void goToBall(int extra){
    if(abdomemY != 90) abdomemY += 5;
    else{
        if(must_walk == 1){
            glutTimerFunc(30, andar, 0);
            must_walk = 0;
        }
        translateHumanX += 0.01;
        if(translateHumanX > 0.4){
            flag_ballReached = 1;
            stop_walk = 1;
        }
    }

    glutPostRedisplay();
    if(!flag_ballReached){
        glutTimerFunc(30,goToBall,0);
    }else{
        must_walk = 1;
        flag_centerReached = 0;
    }
}

void pegaPeso(int extra){

    if(flag_pegaPeso == 0){
        if(cotoveloX_dir != -60){
            cotoveloX_dir -= 5;
        }

        if(ombroX_dir != -15){
            ombroX_dir -= 5;
        }

        if(ombroX_dir == -15 && cotoveloX_dir == -60){
            flag_pegaPeso = 1;
        }
    }

    if(flag_pegaPeso == 1){
        if(cotoveloX_dir != 0){
            cotoveloX_dir += 5;
        }

        if(ombroX_dir != -45){
            ombroX_dir -= 5;
        }

        if(cotoveloX_dir == 0 && ombroX_dir == -45){
            flag_pegaPeso = 2;
        }
    }

    glutPostRedisplay();
    if(flag_pegaPeso != 2) glutTimerFunc(30,pegaPeso,0);
}

void goToAndPickPeso(int extra){
    if(abdomemY != 90) abdomemY += 5;
    else{
        if(must_walk == 1){
            glutTimerFunc(30, andar, 0);
            must_walk = 0;
        }
        translateHumanX += 0.01;
        if(translateHumanX > 0.4){
            flag_ballReached = 1;
            stop_walk = 1;
        }
    }

    glutPostRedisplay();
    if(!flag_ballReached){
        glutTimerFunc(30,goToAndPickPeso,0);
    }else{
        must_walk = 1;
        flag_centerReached = 0;
    }
    if(flag_ballReached == 1) pegaPeso(1);
}

void treinaBraco(int extra){

    if(flag_treinaBraco == 0){
        if(cotoveloX_dir != -50) cotoveloX_dir -= 5;
        else flag_treinaBraco = 1;
    }

    if(flag_treinaBraco == 1){
        if(cotoveloX_dir != 0) cotoveloX_dir += 5;
        else flag_treinaBraco = 2;
    }

    glutPostRedisplay();
    if(flag_treinaBraco != 2) glutTimerFunc(30,treinaBraco,0);
    else flag_treinaBraco = 0;
}

void guardaPeso(int extra){

    if(flag_guardaPeso == 0){
        if(abdomemY < 95 && abdomemY > 85){
            abdomemY = 90;
        }else{
            if(abdomemY > 95) abdomemY -= 3;
            if(abdomemY < 85) abdomemY += 3;
        }

        if(abdomemY == 90) flag_guardaPeso = 1;
    }


    if(flag_guardaPeso == 1){

        flag_pegaPeso = 0;

        if(ombroX_dir != 0){
            ombroX_dir += 5;
        }

        if(ombroX_dir == 0) flag_guardaPeso = 2;
    }

    glutPostRedisplay();
    if(flag_guardaPeso != 2) glutTimerFunc(30,guardaPeso,0);
}

void rotacaoBracoEsqFrente(int extra){

    if(flag_rotBracoEsq == 0){
        if(ombroZ_esq < 15) ombroZ_esq += 5;
        if(cotoveloY_esq != 90) cotoveloY_esq += 5;
        if(ombroX_esq != -360) ombroX_esq -= 5;

        if(ombroX_esq == -360) flag_rotBracoEsq = 1;
    }

    if(flag_rotBracoEsq == 1){
        if(ombroZ_esq > 3) ombroZ_esq -= 5;
        if(cotoveloY_esq != 0) cotoveloY_esq -= 5;
        if(ombroZ_esq < 3 && cotoveloY_esq == 0) {
            flag_rotBracoEsq = 2;
            ombroX_esq = 0;
            ombroZ_esq = 0;
        }
    }

    glutPostRedisplay();
    if(flag_rotBracoEsq != 2) glutTimerFunc(30, rotacaoBracoEsqFrente, 0);
}

void rotacaoBracoDirFrente(int extra){

    if(flag_rotBracoDir == 0){
        if(ombroZ_dir > -15) ombroZ_dir -= 5;
        if(ombroX_dir != -360) ombroX_dir -= 5;
        if(cotoveloY_dir != -90) cotoveloY_dir -= 5;
        if(ombroX_dir == -360) flag_rotBracoDir = 1;
    }

    if(flag_rotBracoDir == 1){
        if(ombroZ_dir < -3) ombroZ_dir += 5;
        if(cotoveloY_dir != 0) cotoveloY_dir += 5;
        if(ombroZ_dir > -3 && cotoveloY_dir == 0) {
            flag_rotBracoDir = 2;
            ombroX_dir = 0;
            ombroZ_dir = 0;
        }
    }

    glutPostRedisplay();
    if(flag_rotBracoDir != 2) glutTimerFunc(30, rotacaoBracoDirFrente, 0);
}

// Controles

void keyboard(unsigned char key, int x, int y){
    switch(key){
        case 27:
            exit(0);
            break;
        case 'a': // Rotaciona apenas o personagem, cuidado pois pode dar problema com as animacoes, prefira por rotacionar a cena inteira
            abdomemY += 5;
            abdomemY = abdomemY % 360;
            break;
        case 'z':
            angy += 5;
            angy = angy % 360;
            break;
        case 'x':
            angx += 5;
            angx = angx % 360;
            break;
        case 'c':
            angz += 5;
            angz = angz % 360;
            break;
        case 'A': // Rotaciona apenas o personagem, cuidado pois pode dar problema com as animacoes, prefira por rotacionar a cena inteira
            abdomemY -= 5;
            abdomemY = abdomemY % 360;
            break;
        case 'Z':
            angy -= 5;
            angy = angy % 360;
            break;
        case 'X':
            angx -= 5;
            angx = angx % 360;
            break;
        case 'C':
            angz -= 5;
            angz = angz % 360;
            break;
        case 's': // ZOOM IN
            if(zoom < 1.3) zoom += 0.05;
            break;
        case 'd': // ZOOM OUT
            if(zoom > 0.4) zoom -= 0.05;
            break;
    }
    glutPostRedisplay();
}

void specialKeyboard(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_LEFT: // X NEGATIVO
            switch(menuParteCorpo){
                case COTOVELO_DIR:
                    if(cotoveloX_dir < 0) cotoveloX_dir += 5;
                    break;
                case COTOVELO_ESQ:
                    if(cotoveloX_esq >= -140) cotoveloX_esq -= 5;
                    break;
                case OMBRO_DIR:
                    ombroX_dir -= 5;
                    ombroX_dir = ombroX_dir % 360;
                    break;
                case OMBRO_ESQ:
                    ombroX_esq -= 5;
                    ombroX_esq = ombroX_esq % 360;
                    break;
                case TORSO:
                     if(torsoX > -45) torsoX -= 5;
                    break;
                case QUADRIL_DIR:
                    if(quadrilX_dir < 80) quadrilX_dir += 5;
                    break;
                case QUADRIL_ESQ:
                    if(quadrilX_esq < 80) quadrilX_esq += 5;
                    break;
                case JOELHO_DIR:
                    if(joelhoX_dir < 140) joelhoX_dir += 5;
                    break;
                case JOELHO_ESQ:
                    if(joelhoX_esq < 140) joelhoX_esq += 5;
                    break;
                case CALCANHAR_DIR:
                    if(calcanharX_dir < 0) calcanharX_dir += 5;
                    break;
                case CALCANHAR_ESQ:
                    if(calcanharX_esq < 0) calcanharX_esq += 5;
                    break;
                default:
                    printf("Não rodo neste eixo! \n");
                    break;
            }
            break;
        case GLUT_KEY_RIGHT: // X POSITIVO
            switch(menuParteCorpo){
                case COTOVELO_DIR:
                    if(cotoveloX_dir >= -140) cotoveloX_dir -= 5;
                    break;
                case COTOVELO_ESQ:
                    if(cotoveloX_esq >= -140) cotoveloX_esq -= 5;
                    break;
                case OMBRO_DIR:
                    ombroX_dir += 5;
                    ombroX_dir = ombroX_dir % 360;
                    break;
                case OMBRO_ESQ:
                    ombroX_esq += 5;
                    ombroX_esq = ombroX_esq % 360;
                    break;
                case TORSO:
                     if(torsoX < 45) torsoX += 5;
                    break;
                case QUADRIL_DIR:
                    if(quadrilX_dir > -80) quadrilX_dir -= 5;
                    break;
                case QUADRIL_ESQ:
                    if(quadrilX_esq > -80) quadrilX_esq -= 5;
                    break;
                case JOELHO_DIR:
                    if(joelhoX_dir > 0) joelhoX_dir -= 5;
                    break;
                case JOELHO_ESQ:
                    if(joelhoX_esq > 0) joelhoX_esq -= 5;
                    break;
                case CALCANHAR_DIR:
                    if(calcanharX_dir > -30) calcanharX_dir -= 5;
                    break;
                case CALCANHAR_ESQ:
                    if(calcanharX_esq > -30) calcanharX_esq -= 5;
                    break;
                default:
                    printf("Não rodo neste eixo! \n");
                    break;
            }
            break;
        case GLUT_KEY_UP: // Y NEGATIVO
            switch(menuParteCorpo){
                case COTOVELO_DIR:
                    if(cotoveloY_dir > -90) cotoveloY_dir -= 5;
                    break;
                case COTOVELO_ESQ:
                    if(cotoveloY_esq > -90) cotoveloY_esq -= 5;
                    break;
                case OMBRO_DIR:
                    if(ombroY_dir > -180) ombroY_dir -= 5;
                    break;
                case OMBRO_ESQ:
                    if(ombroY_esq > -180) ombroY_esq -= 5;
                    break;
                case TORSO:
                    if(torsoY > -90) torsoY -= 5;
                    break;
                case QUADRIL_DIR:
                    if(quadrilY_dir < 45) quadrilY_dir += 5;
                    break;
                case QUADRIL_ESQ:
                    if(quadrilY_esq < 45) quadrilY_esq += 5;
                    break;
                case JOELHO_DIR:
                    if(joelhoY_dir < 35) joelhoY_dir += 5;
                    break;
                case JOELHO_ESQ:
                    if(joelhoY_esq < 35) joelhoY_esq += 5;
                    break;
                default:
                    printf("Não rodo neste eixo! \n");
                    break;
            }
            break;
        case GLUT_KEY_DOWN: // Y POSITIVO
            switch(menuParteCorpo){
                case COTOVELO_DIR:
                    if(cotoveloY_dir < 90) cotoveloY_dir += 5;
                    break;
                case COTOVELO_ESQ:
                    if(cotoveloY_esq < 90) cotoveloY_esq += 5;
                    break;
                case OMBRO_DIR:
                    if(ombroY_dir < 180) ombroY_dir += 5;
                    break;
                case OMBRO_ESQ:
                    if(ombroY_esq < 180) ombroY_esq += 5;
                    break;
                case TORSO:
                    if(torsoY < 90) torsoY += 5;
                    break;
                case QUADRIL_DIR:
                    if(quadrilY_dir > -45) quadrilY_dir -= 5;
                    break;
                case QUADRIL_ESQ:
                    if(quadrilY_dir > -45) quadrilY_dir -= 5;
                    break;
                case JOELHO_DIR:
                    if(joelhoY_dir > -35) joelhoY_dir -= 5;
                    break;
                case JOELHO_ESQ:
                    if(joelhoY_esq > -35) joelhoY_esq -= 5;
                    break;
                default:
                    printf("Não rodo neste eixo! \n");
                    break;
            }
            break;
        case GLUT_KEY_F1: // Z NEGATIVO
            switch(menuParteCorpo){
                case OMBRO_DIR:
                    if(ombroZ_dir > -120) ombroZ_dir -= 5;
                    break;
                case OMBRO_ESQ:
                    if(ombroZ_esq < 120) ombroZ_esq += 5;
                    break;
                case PULSO_DIR:
                    if(pulsoZ_dir > -90) pulsoZ_dir -= 5;
                    break;
                case PULSO_ESQ:
                    if(pulsoZ_esq < 90) pulsoZ_esq += 5;
                    break;
                case TORSO:
                    if(torsoZ > -30) torsoZ -= 5;
                    break;
               case QUADRIL_DIR:
                    if(quadrilZ_dir < 0) quadrilZ_dir += 5;
                    break;
                case QUADRIL_ESQ:
                    if(quadrilZ_esq > 0) quadrilZ_esq -= 5;
                    break;
                default:
                    printf("Não rodo neste eixo! \n");
                    break;
            }
            break;
        case GLUT_KEY_F2: // Z POSITIVO
            switch(menuParteCorpo){
                case OMBRO_DIR:
                    if(ombroZ_dir < 0) ombroZ_dir += 5;
                    break;
                case OMBRO_ESQ:
                    if(ombroZ_esq > 0) ombroZ_esq -= 5;
                    break;
                case PULSO_DIR:
                    if(pulsoZ_dir < 90) pulsoZ_dir += 5;
                    break;
                case PULSO_ESQ:
                    if(pulsoZ_esq > -90) pulsoZ_esq -= 5;
                    break;
                case TORSO:
                    if(torsoZ < 30) torsoZ += 5;
                    break;
                case QUADRIL_DIR:
                    if(quadrilZ_dir > -45) quadrilZ_dir -= 5;
                    break;
                case QUADRIL_ESQ:
                    if(quadrilZ_esq < 45) quadrilZ_esq += 5;
                    break;
                default:
                    printf("Não rodo neste eixo! \n");
                    break;
            }
            break;

    }
    glutPostRedisplay();
}

void optionMenu(GLint op){
    switch(op){
    case -1:
        exit(0);
        break;
    case 1:
        menuParteCorpo = TORSO;
        break;
    case 2:
        menuParteCorpo = COTOVELO_DIR;
        break;
    case 3:
        menuParteCorpo = COTOVELO_ESQ;
        break;
    case 4:
        menuParteCorpo = OMBRO_DIR;
        break;
    case 5:
        menuParteCorpo = OMBRO_ESQ;
        break;
    case 6:
        menuParteCorpo = PULSO_DIR;
        break;
    case 7:
        menuParteCorpo = PULSO_ESQ;
        break;
    case 8:
        menuParteCorpo = QUADRIL_DIR;
        break;
    case 9:
        menuParteCorpo = QUADRIL_ESQ;
        break;
    case 10:
        menuParteCorpo = JOELHO_DIR;
        break;
    case 11:
        menuParteCorpo = JOELHO_ESQ;
        break;
    case 12:
        menuParteCorpo = CALCANHAR_DIR;
        break;
    case 13:
        menuParteCorpo = CALCANHAR_ESQ;
        break;
    case 14:
        glutTimerFunc(30,goToAndPickPeso,0);
        break;
    case 15:
        glutTimerFunc(30, treinaBraco, 0);
        break;
    case 16:
        glutTimerFunc(30, alignToFront, 0);
        break;
    case 17:
        glutTimerFunc(30, guardaPeso, 0);
        break;
    case 18:
        glutTimerFunc(30, goToCenter, 0);
        break;
    case 19:
        glutTimerFunc(30, animPernaEsq, 0); //Sim, está invertido
        break;
    case 20:
        glutTimerFunc(30, animPernaDir, 0); //Sim, está invertido
        break;
    case 21:
        glutTimerFunc(30, animDuasPernas, 0);
        break;
    case 22:
        glutTimerFunc(30, rotacaoBracoDirFrente, 0);
        break;
    case 23:
        glutTimerFunc(30, rotacaoBracoEsqFrente, 0);
        break;
    case 24:
        resetMovements();
        glutPostRedisplay();
        break;
    }
}

//Reshape + Texturas + Iluminacao

void reshape(int w, int h){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (w > h)
        glViewport(0, 0, (GLsizei)h, (GLsizei)h);
    if (w < h){
        glViewport(0, 0, (GLsizei)w, (GLsizei)w);
    }

    if(w == h)
        glViewport(0, 0, (GLsizei)w, (GLsizei)h);

    initialize(w, h);
}

void initialize(int w, int h){
    fAspect = (GLfloat)w/(GLfloat)h;

    glMatrixMode(GL_PROJECTION) ;
    glLoadIdentity() ;
    gluPerspective(80, fAspect, 0.1, 100.0);
    glOrtho(-win, win, -win, win, win, win);
    gluLookAt(0, 2, 5, 0, 0, 0, 0, 1, 0);

    glMatrixMode(GL_MODELVIEW) ;
    glLoadIdentity();

    glEnable(GL_DEPTH_TEST);
}

void shine(){
    GLfloat luzAmbiente[]  = {0.5, 0.5, 0.5, 1.0};
    GLfloat luzDifusa[]  = {1.0, 1.0, 1.0, 1.0};
    GLfloat luzEspecular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat luzPosition[] = {0.0, 2.0, 1.0, 0.0};

    GLfloat mat_ambiente[] = {0.7, 0.7, 0.7, 1.0};
    GLfloat mat_difuso[] = {0.8, 0.8, 0.8, 1.0};
    GLfloat mat_especular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat brilho[] = {90.0f};

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
    glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
    glLightfv(GL_LIGHT0, GL_POSITION, luzPosition);

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambiente);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_difuso);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_especular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, brilho);
}

void get_bitmap_image_data(char *pFileName, BMPIMG *pImage ){
    FILE *pFile = NULL;
    unsigned short nNumPlanes;
    unsigned short nNumBPP;
	int i;

    if((pFile = fopen(pFileName, "rb")) == NULL)
		printf("ERROR: getBitmapImageData - %s not found.\n", pFileName);

    fseek(pFile, 18, SEEK_CUR);

    if((i = fread(&pImage->width, 4, 1, pFile)) != 1)
		printf("ERROR: getBitmapImageData - Couldn't read width from %s.\n ", pFileName);

    if((i = fread(&pImage->height, 4, 1, pFile)) != 1)
		printf("ERROR: getBitmapImageData - Couldn't read height from %s.\n ", pFileName);

    if((fread(&nNumPlanes, 2, 1, pFile)) != 1)
		printf("ERROR: getBitmapImageData - Couldn't read plane count from %s.\n", pFileName);

    if(nNumPlanes != 1)
		printf("ERROR: getBitmapImageData - Plane count from %s.\n ", pFileName);

    if((i = fread(&nNumBPP, 2, 1, pFile)) != 1)
		printf( "ERROR: getBitmapImageData - Couldn't read BPP from %s.\n ", pFileName);

    if(nNumBPP != 24)
		printf("ERROR: getBitmapImageData - BPP from %s - %d.\n ", pFileName, nNumBPP);

    fseek(pFile, 24, SEEK_CUR);

    int nTotalImagesize = (pImage->width * pImage->height) * 3;

    pImage->data = (char*) malloc( nTotalImagesize );

    if((i = fread(pImage->data, nTotalImagesize, 1, pFile)) != 1)
		printf("ERROR: getBitmapImageData - Couldn't read image data from %s.\n ", pFileName);

	char charTemp;
    for(i = 0; i < nTotalImagesize; i += 3){
		charTemp = pImage->data[i];
		pImage->data[i] = pImage->data[i+2];
		pImage->data[i+2] = charTemp;
    }
}

void loadTextureGrama(){
    BMPIMG textura;
    char nome[15] = "grass2.bmp";
    get_bitmap_image_data(nome, &textura);

    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);
    glGenTextures(1, &texture_id_grama);
    glBindTexture(GL_TEXTURE_2D, texture_id_grama);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, textura.width, textura.height, 0, GL_RGB, GL_UNSIGNED_BYTE, textura.data);


    /*Define modo de preenchimento se textura for menor ou maior*/
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

}


// Main

int main(int argc, char *argv[ ] ) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(50,100);
    glutInitWindowSize(800,800);
    glutCreateWindow("Computação Gráfica");

    shine();

    glutDisplayFunc(draw);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeyboard);
    glutReshapeFunc(reshape);

    loadTextureGrama();


    glutCreateMenu(optionMenu);
        glutAddMenuEntry("Rotacionar Torso", 1);
        glutAddMenuEntry("Rotacionar Cotovelo Direito", 2);
        glutAddMenuEntry("Rotacionar Cotovelo Esquerdo", 3);
        glutAddMenuEntry("Rotacionar Ombro Direito", 4);
        glutAddMenuEntry("Rotacionar Ombro Esquerdo", 5);
        glutAddMenuEntry("Rotacionar Pulso Direito", 6);
        glutAddMenuEntry("Rotacionar Pulso Esquerdo", 7);

        glutAddMenuEntry("Rotacionar Quadril Esquerdo", 8);
        glutAddMenuEntry("Rotacionar Quadril Direito", 9);
        glutAddMenuEntry("Rotacionar Joelho Esquerdo", 10);
        glutAddMenuEntry("Rotacionar Joelho Direito", 11);
        glutAddMenuEntry("Rotacionar Calcanhar Esquerdo", 12);
        glutAddMenuEntry("Rotacionar Calcanhar Direito", 13);

        glutAddMenuEntry("Reiniciar movimentos", 24);

        glutAddMenuEntry("Pegar Peso", 14);
        glutAddMenuEntry("Treinar Braco", 15);
        glutAddMenuEntry("Olhar para Frente", 16);
        glutAddMenuEntry("Guardar Peso", 17);

        glutAddMenuEntry("Ir para o Centro", 18);

        glutAddMenuEntry("Exercitar Perna Direita", 19);
        glutAddMenuEntry("Exercitar Perna Esquerda", 20);
        glutAddMenuEntry("Exercitar as duas Pernas", 21);

        glutAddMenuEntry("Exercitar Braco Direito", 22);
        glutAddMenuEntry("Exercitar Braco Esquerdo", 23);

        glutAddMenuEntry("Sair", -1);

    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop ();
    return 0;
}
