#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>
void init(void);
void display(void);
void keyboard(unsigned char, int, int);
void resize(int, int);
void mouseMove(int x, int y);
void mouseButton(int button, int state, int x, int y);
using namespace std;
float xrot = 0;
float yrot = 0;
float xdiff = 0;
float ydiff = 0;
bool mousedown = false;
int is_depth;
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(40, 40);
    glutCreateWindow("City University of Hong Kong");
    init();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouseButton);
    glutMotionFunc(mouseMove);
    glutReshapeFunc(resize);
    glutMainLoop();
    return 0;
}
void init(void)
{
    glClearColor(0.4, 0.7, 1.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    //glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(20.0);
    glLineWidth(6.0f);

}

void display(void)
{
    if (is_depth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
        glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(xrot, 1, 0, 0);
    glRotatef(yrot, 0, 1, 0);

    glBegin(GL_POLYGON);//alas
    glColor3f(0.8, 0.6, 0.6);
    glVertex3f(-400, 0, -250);
    glColor3f(0.6, 0.4, 0.4);
    glVertex3f(-400, 0, 200);
    glColor3f(0.8, 0.6, 0.6);
    glVertex3f(400, 0, 200);
    glColor3f(0.6, 0.4, 0.4);
    glVertex3f(400, 0, -250);
    glEnd();
    glBegin(GL_LINE_LOOP);//garis alas
    glColor3f(0, 0, 0);
    glVertex3f(-400, 0, -250);
    glVertex3f(-400, 0, 200);
    glVertex3f(400, 0, 200);
    glVertex3f(400, 0, -250);
    glEnd();

    glBegin(GL_POLYGON);//fondasi 1 kanan
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-340, 0, 140);
    glVertex3f(-340, 0, 120);
    glVertex3f(-340, 20, 120);
    glVertex3f(-340, 20, 140);
    glEnd();
    glBegin(GL_POLYGON);//fondasi 1 kiri
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-320, 0, 140);
    glVertex3f(-320, 0, 120);
    glVertex3f(-320, 20, 120);
    glVertex3f(-320, 20, 140);
    glEnd();
    glBegin(GL_POLYGON);//fondasi 1 depan
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-320, 0, 140);
    glVertex3f(-340, 0, 140);
    glVertex3f(-340, 20, 140);
    glVertex3f(-320, 20, 140);
    glEnd();
    glBegin(GL_POLYGON);//fondasi 1 belakang
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-320, 0, 120);
    glVertex3f(-340, 0, 120);
    glVertex3f(-340, 20, 120);
    glVertex3f(-320, 20, 120);
    glEnd();
    glBegin(GL_POLYGON);//fondasi 1.2 depan
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-320, 20, 140);
    glVertex3f(-340, 20, 140);
    glVertex3f(-355, 50, 140);
    glVertex3f(-335, 50, 140);
    glEnd();
    glBegin(GL_POLYGON);//fondasi 1.2 belakang
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-320, 20, 120);
    glVertex3f(-340, 20, 120);
    glVertex3f(-355, 50, 120);
    glVertex3f(-335, 50, 120);
    glEnd();
    glBegin(GL_POLYGON);//fondasi 1.2 kanan
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-340, 20, 120);
    glVertex3f(-340, 20, 140);
    glVertex3f(-355, 50, 140);
    glVertex3f(-355, 50, 120);
    glEnd();
    glBegin(GL_POLYGON);//fondasi 1.2 kiri
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-320, 20, 120);
    glVertex3f(-320, 20, 140);
    glVertex3f(-335, 50, 140);
    glVertex3f(-335, 50, 120);
    glEnd();
    glBegin(GL_POLYGON);//fondasi 1.3 depan
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-340, 20, 140);
    glVertex3f(-320, 20, 140);
    glVertex3f(-305, 50, 140);
    glVertex3f(-325, 50, 140);
    glEnd();
    glBegin(GL_POLYGON);//fondasi 1.3 belakang
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-340, 20, 120);
    glVertex3f(-320, 20, 120);
    glVertex3f(-305, 50, 120);
    glVertex3f(-325, 50, 120);
    glEnd();
    glBegin(GL_POLYGON);//fondasi 1.3 kanan
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-340, 20, 120);
    glVertex3f(-340, 20, 140);
    glVertex3f(-325, 50, 140);
    glVertex3f(-325, 50, 120);
    glEnd();
    glBegin(GL_POLYGON);//fondasi 1.3 kiri
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-320, 20, 120);
    glVertex3f(-320, 20, 140);
    glVertex3f(-305, 50, 140);
    glVertex3f(-305, 50, 120);
    glEnd();

    glBegin(GL_POLYGON);//fondasi 2 kanan
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-340, 0, -140);
    glVertex3f(-340, 0, -120);
    glVertex3f(-340, 20, -120);
    glVertex3f(-340, 20, -140);
    glEnd();
    glBegin(GL_POLYGON);//fondasi 2 kiri
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-320, 0, -140);
    glVertex3f(-320, 0, -120);
    glVertex3f(-320, 20, -120);
    glVertex3f(-320, 20, -140);
    glEnd();
    glBegin(GL_POLYGON);//fondasi 2 depan
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-320, 0, -140);
    glVertex3f(-340, 0, -140);
    glVertex3f(-340, 20, -140);
    glVertex3f(-320, 20, -140);
    glEnd();
    glBegin(GL_POLYGON);//fondasi 2 belakang
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-320, 0, -120);
    glVertex3f(-340, 0, -120);
    glVertex3f(-340, 20, -120);
    glVertex3f(-320, 20, -120);
    glEnd();
    glBegin(GL_POLYGON);//fondasi 2.2 depan
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-320, 20, -140);
    glVertex3f(-340, 20, -140);
    glVertex3f(-355, 50, -140);
    glVertex3f(-335, 50, -140);
    glEnd();
    glBegin(GL_POLYGON);//fondasi 2.2 belakang
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-320, 20, -120);
    glVertex3f(-340, 20, -120);
    glVertex3f(-355, 50, -120);
    glVertex3f(-335, 50, -120);
    glEnd();
    glBegin(GL_POLYGON);//fondasi 2.2 kanan
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-340, 20, -120);
    glVertex3f(-340, 20, -140);
    glVertex3f(-355, 50, -140);
    glVertex3f(-355, 50, -120);
    glEnd();
    glBegin(GL_POLYGON);//fondasi 2.2 kiri
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-320, 20, -120);
    glVertex3f(-320, 20, -140);
    glVertex3f(-335, 50, -140);
    glVertex3f(-335, 50, -120);
    glEnd();
    glBegin(GL_POLYGON);//fondasi 2.3 depan
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-340, 20, -140);
    glVertex3f(-320, 20, -140);
    glVertex3f(-305, 50, -140);
    glVertex3f(-325, 50, -140);
    glEnd();
    glBegin(GL_POLYGON);//fondasi 2.3 belakang
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-340, 20, -120);
    glVertex3f(-320, 20, -120);
    glVertex3f(-305, 50, -120);
    glVertex3f(-325, 50, -120);
    glEnd();
    glBegin(GL_POLYGON);//fondasi 2.3 kanan
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-340, 20, -120);
    glVertex3f(-340, 20, -140);
    glVertex3f(-325, 50, -140);
    glVertex3f(-325, 50, -120);
    glEnd();
    glBegin(GL_POLYGON);//fondasi 2.3 kiri
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-320, 20, -120);
    glVertex3f(-320, 20, -140);
    glVertex3f(-305, 50, -140);
    glVertex3f(-305, 50, -120);
    glEnd();

    glBegin(GL_POLYGON);//fondasi 3 kanan
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-140, 0, -140);
    glVertex3f(-140, 0, -120);
    glVertex3f(-140, 20, -120);
    glVertex3f(-140, 20, -140);
    glEnd();
    glBegin(GL_POLYGON);//fondasi 3 kiri
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-120, 0, -140);
    glVertex3f(-120, 0, -120);
    glVertex3f(-120, 20, -120);
    glVertex3f(-120, 20, -140);
    glEnd();
    glBegin(GL_POLYGON);//fondasi 3 depan
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-120, 0, -140);
    glVertex3f(-140, 0, -140);
    glVertex3f(-140, 20, -140);
    glVertex3f(-120, 20, -140);
    glEnd();
    glBegin(GL_POLYGON);//fondasi 3 belakang
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-120, 0, -120);
    glVertex3f(-140, 0, -120);
    glVertex3f(-140, 20, -120);
    glVertex3f(-120, 20, -120);
    glEnd();
    glBegin(GL_POLYGON);//fondasi 3.1 kanan
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-140, 20, -140);
    glVertex3f(-140, 20, -120);
    glVertex3f(-140, 50, -120);
    glVertex3f(-140, 50, -140);
    glEnd();
    glBegin(GL_POLYGON);//fondasi 3.1 kiri
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-120, 20, -140);
    glVertex3f(-120, 20, -120);
    glVertex3f(-120, 50, -120);
    glVertex3f(-120, 50, -140);
    glEnd();
    glBegin(GL_POLYGON);//fondasi 3.1 depan
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-120, 20, -140);
    glVertex3f(-140, 20, -140);
    glVertex3f(-140, 50, -140);
    glVertex3f(-120, 50, -140);
    glEnd();
    glBegin(GL_POLYGON);//fondasi 3.1 belakang
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-120, 20, -120);
    glVertex3f(-140, 20, -120);
    glVertex3f(-140, 50, -120);
    glVertex3f(-120, 50, -120);
    glEnd();

    glBegin(GL_POLYGON);//fondasi 4 kanan
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-140, 0, 140);
    glVertex3f(-140, 0, 120);
    glVertex3f(-140, 20, 120);
    glVertex3f(-140, 20, 140);
    glEnd();
    glBegin(GL_POLYGON);//fondasi 4 kiri
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-120, 0, 140);
    glVertex3f(-120, 0, 120);
    glVertex3f(-120, 20, 120);
    glVertex3f(-120, 20, 140);
    glEnd();
    glBegin(GL_POLYGON);//fondasi 4 depan
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-120, 0, 140);
    glVertex3f(-140, 0, 140);
    glVertex3f(-140, 20, 140);
    glVertex3f(-120, 20, 140);
    glEnd();
    glBegin(GL_POLYGON);//fondasi 4 belakang
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-120, 0, 120);
    glVertex3f(-140, 0, 120);
    glVertex3f(-140, 20, 120);
    glVertex3f(-120, 20, 120);
    glEnd();
    glBegin(GL_POLYGON);//fondasi 4.1 kanan
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-140, 20, 140);
    glVertex3f(-140, 20, 120);
    glVertex3f(-140, 50, 120);
    glVertex3f(-140, 50, 140);
    glEnd();
    glBegin(GL_POLYGON);//fondasi 4.1 kiri
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-120, 20, 140);
    glVertex3f(-120, 20, 120);
    glVertex3f(-120, 50, 120);
    glVertex3f(-120, 50, 140);
    glEnd();
    glBegin(GL_POLYGON);//fondasi 4.1 depan
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-120, 20, 140);
    glVertex3f(-140, 20, 140);
    glVertex3f(-140, 50, 140);
    glVertex3f(-120, 50, 140);
    glEnd();
    glBegin(GL_POLYGON);//fondasi 4.1 belakang
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-120, 20, 120);
    glVertex3f(-140, 20, 120);
    glVertex3f(-140, 50, 120);
    glVertex3f(-120, 50, 120);
    glEnd();

    glBegin(GL_LINE_LOOP);//bangunan bawah1 garis alas
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-360, 50, 160);
    glVertex3f(-360, 50, -160);
    glVertex3f(-40, 50, -160);
    glVertex3f(-40, 50, 160);
    glEnd();
    glBegin(GL_POLYGON);//bangunan bawah1 kiri miring1
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-360, 50, 160);
    glVertex3f(-360, 50, -160);
    glVertex3f(-390, 250, -160);
    glVertex3f(-390, 250, 160);
    glEnd();
    glBegin(GL_POLYGON);//bangunan bawah1 kiri miring2
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-390, 250, 160);
    glVertex3f(-390, 250, -160);
    glVertex3f(-360, 270, -160);
    glVertex3f(-360, 270, 160);
    glEnd();
    glBegin(GL_LINES);//bangunan bawah1 kiri garis depan1
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-360, 50, 160);
    glVertex3f(-390, 250, 160);
    glEnd();
    glBegin(GL_LINES);//bangunan bawah1 kiri garis depan2
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-390, 250, 160);
    glVertex3f(-360, 270, 160);
    glEnd();
    glBegin(GL_LINES);//bangunan bawah1 kiri garis belakang1
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-360, 50, -160);
    glVertex3f(-390, 250, -160);
    glEnd();
    glBegin(GL_LINES);//bangunan bawah1 kiri garis belakang2
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-390, 250, -160);
    glVertex3f(-360, 270, -160);
    glEnd();
    glBegin(GL_POLYGON);//bangunan bawah1 atas merah
    glColor3f(0.8, 0.6, 0.6);
    glVertex3f(-360, 270, 160);
    glVertex3f(-360, 270, -160);
    glVertex3f(-280, 270, -160);
    glVertex3f(-280, 270, 160);
    glEnd();
    glBegin(GL_POLYGON);//bangunan bawah1 atas abu"
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-280, 270, 160);
    glVertex3f(-280, 270, -160);
    glVertex3f(-280, 250, -160);
    glVertex3f(-280, 250, 160);
    glEnd();
    glBegin(GL_POLYGON);//bangunan bawah1 atas ijo1
    glColor3f(0.2, 0.4, 0.2);
    glVertex3f(-280, 270, -160);
    glVertex3f(-280, 270, -80);
    glVertex3f(-40, 270, -80);
    glVertex3f(-40, 270, -160);
    glEnd();
    glBegin(GL_POLYGON);//bangunan bawah1 atas ijo1 tutup
    glColor3f(0.2, 0.3, 0.2);
    glVertex3f(-280, 270, -80);
    glVertex3f(-280, 250, -80);
    glVertex3f(-40, 250, -80);
    glVertex3f(-40, 270, -80);
    glEnd();
    glBegin(GL_POLYGON);//bangunan bawah atas ijo1 tutup kanan
    glColor3f(0.2, 0.3, 0.2);
    glVertex3f(-40, 250, -160);
    glVertex3f(-40, 250, -80);
    glVertex3f(-40, 270, -80);
    glVertex3f(-40, 270, -160);
    glEnd();
    glBegin(GL_POLYGON);//bangunan bawah1 atas ijo2 lapangan
    glColor3f(0.3, 0.5, 0.3);
    glVertex3f(-280, 250, -80);
    glVertex3f(-170, 250, -80);
    glVertex3f(-170, 250, 120);
    glVertex3f(-280, 250, 120);
    glEnd();
    glBegin(GL_LINES);//garis ijo2 lapangan
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-280, 250, -20);
    glVertex3f(-230, 250, 0);
    glEnd();
    glBegin(GL_LINES);//garis ijo2 lapangan
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-230, 250, 0);
    glVertex3f(-230, 250, 50);
    glEnd();
    glBegin(GL_LINES);//garis ijo2 lapangan
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-230, 250, 50);
    glVertex3f(-170, 250, 70);
    glEnd();
    glBegin(GL_POLYGON);//bangunan bawah1 atas coklat
    glColor3f(0.5, 0.4, 0.4);
    glVertex3f(-40, 250, -80);
    glVertex3f(-170, 250, -80);
    glVertex3f(-170, 250, 120);
    glVertex3f(-40, 250, 120);
    glEnd();
    glBegin(GL_POLYGON);//bangunan bawah1 atas ijo3
    glColor3f(0.2, 0.4, 0.2);
    glVertex3f(-280, 270, 160);
    glVertex3f(-280, 270, 120);
    glVertex3f(-40, 270, 120);
    glVertex3f(-40, 270, 160);
    glEnd();
    glBegin(GL_POLYGON);//bangunan bawah1 atas ijo3 tutup
    glColor3f(0.2, 0.3, 0.2);
    glVertex3f(-280, 270, 120);
    glVertex3f(-280, 250, 120);
    glVertex3f(-40, 250, 120);
    glVertex3f(-40, 270, 120);
    glEnd();
    glBegin(GL_POLYGON);//bangunan bawah atas ijo3 tutup kanan
    glColor3f(0.2, 0.3, 0.2);
    glVertex3f(-40, 250, 120);
    glVertex3f(-40, 250, 160);
    glVertex3f(-40, 270, 160);
    glVertex3f(-40, 270, 120);
    glEnd();
    glBegin(GL_LINES);//bangunan bawah1 garis atas1
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-360, 270, 160);
    glVertex3f(-360, 270, -160);
    glEnd();
    glBegin(GL_LINES);//bangunan bawah1 garis atas2
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-360, 270, -160);
    glVertex3f(360, 270, -160);
    glEnd();
    glBegin(GL_LINES);//bangunan bawah1 garis atas3c
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-360, 270, 160);
    glVertex3f(360, 270, 160);
    glEnd();
    glBegin(GL_LINES);//bangunan bawah1 garis atas4
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(360, 270, 160);
    glVertex3f(360, 270, -160);
    glEnd();
    glBegin(GL_POLYGON);//bangunan bawah1 depan putih1
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-360, 51, 160);
    glVertex3f(-40, 51, 160);
    glVertex3f(-40, 250, 160);
    glVertex3f(-390, 250, 160);
    glEnd();
    glBegin(GL_POLYGON);//bangunan bawah1 depan putih2
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-390, 250, 160);
    glVertex3f(-40, 250, 160);
    glVertex3f(-40, 269, 160);
    glVertex3f(-360, 269, 160);
    glEnd();
    glBegin(GL_POLYGON);//bangunan bawah1 belakang putih1
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-360, 51, -160);
    glVertex3f(-40, 51, -160);
    glVertex3f(-40, 250, -160);
    glVertex3f(-390, 250, -160);
    glEnd();
    glBegin(GL_POLYGON);//bangunan bawah1 belakang putih2
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-390, 250, -160);
    glVertex3f(-40, 250, -160);
    glVertex3f(-40, 269, -160);
    glVertex3f(-360, 269, -160);
    glEnd();
    glBegin(GL_POLYGON);//bangunan bawah alas
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-360, 51, 160);
    glVertex3f(360, 51, 160);
    glVertex3f(360, 51, -160);
    glVertex3f(-360, 51, -160);
    glEnd();
    glBegin(GL_POLYGON);//bangunan bawah atas tutup
    glColor3f(0.5, 0.4, 0.4);
    glVertex3f(-40, 250, 160);
    glVertex3f(360, 250, 160);
    glVertex3f(360, 250, -160);
    glVertex3f(-40, 250, -160);
    glEnd();

    glBegin(GL_POLYGON);//bangunan bawah1.5 depan hitam
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-40, 50, 160);
    glVertex3f(30, 50, 160);
    glVertex3f(15, 270, 160);
    glVertex3f(-40, 270, 160);
    glEnd();
    glBegin(GL_POLYGON);//bangunan bawah1.5 belakang hitam
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-40, 50, -160);
    glVertex3f(30, 50, -160);
    glVertex3f(15, 270, -160);
    glVertex3f(-40, 270, -160);
    glEnd();

    glBegin(GL_POLYGON);//bangunan bawah2 fondasi atas
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(80, 50, 150);
    glVertex3f(350, 50, 150);
    glVertex3f(350, 50, -150);
    glVertex3f(80, 50, -150);
    glEnd();
    glBegin(GL_POLYGON);//bangunan bawah2 fondasi depan
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(80, 0, 150);
    glVertex3f(350, 0, 150);
    glVertex3f(350, 50, 150);
    glVertex3f(80, 50, 150);
    glEnd();
    glBegin(GL_POLYGON);//bangunan bawah2 fondasi belakang
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(80, 0, -150);
    glVertex3f(350, 0, -150);
    glVertex3f(350, 50, -150);
    glVertex3f(80, 50, -150);
    glEnd();
    glBegin(GL_POLYGON);//bangunan bawah2 fondasi kanan
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(350, 0, 150);
    glVertex3f(350, 0, -150);
    glVertex3f(350, 50, -150);
    glVertex3f(350, 50, 150);
    glEnd();
    glBegin(GL_POLYGON);//bangunan bawah2 fondasi kiri
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(80, 0, 150);
    glVertex3f(80, 0, -150);
    glVertex3f(80, 49, -150);
    glVertex3f(80, 49, 150);
    glEnd();
    glBegin(GL_LINE_LOOP);//bangunan bawah2 garis alas
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(30, 50, 160);
    glVertex3f(360, 50, 160);
    glVertex3f(360, 50, -160);
    glVertex3f(30, 50, -160);
    glEnd();
    glBegin(GL_POLYGON);//bangunan bawah2 depan putih
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(30, 51, 160);
    glVertex3f(360, 51, 160);
    glVertex3f(360, 270, 160);
    glVertex3f(15, 270, 160);
    glEnd();
    glBegin(GL_POLYGON);//bangunan bawah2 belakang putih
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(30, 51, -160);
    glVertex3f(360, 51, -160);
    glVertex3f(360, 270, -160);
    glVertex3f(15, 270, -160);
    glEnd();
    glBegin(GL_POLYGON);//bangunan bawah2 kanan putih
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(360, 51, 160);
    glVertex3f(360, 51, -160);
    glVertex3f(360, 270, -160);
    glVertex3f(360, 270, 160);
    glEnd();
    glBegin(GL_LINES);//bangunan bawah2 kanan garis depan
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(360, 50, 160);
    glVertex3f(360, 270, 160);
    glEnd();
    glBegin(GL_LINES);//bangunan bawah2 kanan garis belakang
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(360, 50, -160);
    glVertex3f(360, 270, -160);
    glEnd();

    glBegin(GL_POLYGON);//fondasi atas 1 kiri
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-120, 270, 150);
    glVertex3f(-120, 270, 130);
    glVertex3f(-120, 340, 130);
    glVertex3f(-120, 340, 150);
    glEnd();
    glBegin(GL_POLYGON);//fondasi atas 1 kanan
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-100, 270, 150);
    glVertex3f(-100, 270, 130);
    glVertex3f(-100, 340, 130);
    glVertex3f(-100, 340, 150);
    glEnd();
    glBegin(GL_POLYGON);//fondasi atas 1 depan
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-100, 270, 150);
    glVertex3f(-120, 270, 150);
    glVertex3f(-120, 340, 150);
    glVertex3f(-100, 340, 150);
    glEnd();
    glBegin(GL_POLYGON);//fondasi atas 1 belakang
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-100, 270, 130);
    glVertex3f(-120, 270, 130);
    glVertex3f(-120, 340, 130);
    glVertex3f(-100, 340, 130);
    glEnd();

    glBegin(GL_POLYGON);//fondasi atas 2 kiri
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(0, 250, 150);
    glVertex3f(0, 250, 130);
    glVertex3f(0, 340, 130);
    glVertex3f(0, 340, 150);
    glEnd();
    glBegin(GL_POLYGON);//fondasi atas 2 kanan
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(20, 250, 150);
    glVertex3f(20, 250, 130);
    glVertex3f(20, 340, 130);
    glVertex3f(20, 340, 150);
    glEnd();
    glBegin(GL_POLYGON);//fondasi atas 2 depan
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(20, 250, 150);
    glVertex3f(0, 250, 150);
    glVertex3f(0, 340, 150);
    glVertex3f(20, 340, 150);
    glEnd();
    glBegin(GL_POLYGON);//fondasi atas 2 belakang
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(20, 250, 130);
    glVertex3f(0, 250, 130);
    glVertex3f(0, 340, 130);
    glVertex3f(20, 340, 130);
    glEnd();

    glBegin(GL_POLYGON);//fondasi atas 3 kiri
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(120, 250, 150);
    glVertex3f(120, 250, 130);
    glVertex3f(120, 340, 130);
    glVertex3f(120, 340, 150);
    glEnd();
    glBegin(GL_POLYGON);//fondasi atas 3 kanan
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(140, 250, 150);
    glVertex3f(140, 250, 130);
    glVertex3f(140, 340, 130);
    glVertex3f(140, 340, 150);
    glEnd();
    glBegin(GL_POLYGON);//fondasi atas 3 depan
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(140, 250, 150);
    glVertex3f(120, 250, 150);
    glVertex3f(120, 340, 150);
    glVertex3f(140, 340, 150);
    glEnd();
    glBegin(GL_POLYGON);//fondasi atas 3 belakang
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(140, 250, 130);
    glVertex3f(120, 250, 130);
    glVertex3f(120, 340, 130);
    glVertex3f(140, 340, 130);
    glEnd();

    glBegin(GL_POLYGON);//fondasi atas 4 kiri
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(240, 250, 150);
    glVertex3f(240, 250, 130);
    glVertex3f(240, 340, 130);
    glVertex3f(240, 340, 150);
    glEnd();
    glBegin(GL_POLYGON);//fondasi atas 4 kanan
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(260, 250, 150);
    glVertex3f(260, 250, 130);
    glVertex3f(260, 340, 130);
    glVertex3f(260, 340, 150);
    glEnd();
    glBegin(GL_POLYGON);//fondasi atas 4 depan
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(260, 250, 150);
    glVertex3f(240, 250, 150);
    glVertex3f(240, 340, 150);
    glVertex3f(260, 340, 150);
    glEnd();
    glBegin(GL_POLYGON);//fondasi atas 4 belakang
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(260, 250, 130);
    glVertex3f(240, 250, 130);
    glVertex3f(240, 340, 130);
    glVertex3f(260, 340, 130);
    glEnd();

    glBegin(GL_POLYGON);//gedung tinggi 1 alas
    glColor3f(0.6, 0.7, 0.6);
    glVertex3f(-150, 340, 170);
    glVertex3f(300, 340, 170);
    glVertex3f(300, 340, -30);
    glVertex3f(-150, 340, -30);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 1 kiri miring bawah
    glColor3f(0.812, 0.812, 0.812);
    glVertex3f(-150, 340, 170);
    glVertex3f(-150, 340, -30);
    glColor3f(0.612, 0.612, 0.612);
    glVertex3f(-130, 550, -30);
    glVertex3f(-130, 550, 170);
    glEnd();
    int k = -130;
    for (float i = 550; i > 340; i -= 50) {
        glBegin(GL_LINES);//gedung tinggi 1 kiri trap bawah aksen
        glColor3f(0.389, 0.389, 0.389);
        glVertex3f(k - 0.5, i, 170);
        glVertex3f(k - 0.5, i, -30);
        glEnd();
        k = k - 5;
    }
    glBegin(GL_POLYGON);//gedung tinggi 1 kanan trapesium bawah
    glColor3f(0.812, 0.812, 0.812);
    glVertex3f(300, 340, 170);
    glVertex3f(300, 340, -30);
    glColor3f(0.612, 0.612, 0.612);
    glVertex3f(300, 550, -30);
    glVertex3f(300, 550, 170);
    glEnd();
    for (float i = 550; i > 340; i -= 50) {
        glBegin(GL_LINES);//gedung tinggi 1 kanan trap bawah aksen
        glColor3f(0.389, 0.389, 0.389);
        glVertex3f(300.1, i, 170);
        glVertex3f(300.1, i, -30);
        glEnd();
    }
    glBegin(GL_POLYGON);//gedung tinggi 1 depan trapesium bawah
    glColor3f(0.812, 0.812, 0.812);
    glVertex3f(-150, 340, 170);
    glVertex3f(300, 340, 170);
    glColor3f(0.612, 0.612, 0.612);
    glVertex3f(300, 550, 170);
    glVertex3f(-130, 550, 170);
    glEnd();
    k = -130;
    for (float i = 550; i > 340; i -= 50) {
        glBegin(GL_LINES);//gedung tinggi 1 depan trap bawah aksen
        glColor3f(0.389, 0.389, 0.389);
        glVertex3f(k, i, 170.1);
        glVertex3f(300, i, 170.1);
        glEnd();
        k = k - 4;
    }
    glBegin(GL_POLYGON);//gedung tinggi 1 belakang trapesium bawah
    glColor3f(0.812, 0.812, 0.812);
    glVertex3f(-150, 340, -30);
    glVertex3f(300, 340, -30);
    glColor3f(0.612, 0.612, 0.612);
    glVertex3f(300, 550, -30);
    glVertex3f(-130, 550, -30);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 1 kiri atas
    glColor3f(0.612, 0.612, 0.612);
    glVertex3f(-130, 550, 170);
    glVertex3f(-130, 550, -30);
    glColor3f(0.812, 0.812, 0.812);
    glVertex3f(-130, 950, -30);
    glVertex3f(-130, 950, 170);
    glEnd();
    for (float i = 580; i < 950; i += 50) {
        glBegin(GL_LINES);//gedung tinggi 1 kiri atas aksen
        glColor3f(0.389, 0.389, 0.389);
        glVertex3f(-130.1, i, 170);
        glVertex3f(-130.1, i, -30);
        glEnd();
    }
    glBegin(GL_POLYGON);//gedung tinggi 1 kanan atas
    glColor3f(0.612, 0.612, 0.612);
    glVertex3f(300, 550, 170);
    glVertex3f(300, 550, -30);
    glColor3f(0.812, 0.812, 0.812);
    glVertex3f(300, 950, -30);
    glVertex3f(300, 950, 170);
    glEnd();
    for (float i = 580; i < 950; i += 50) {
        glBegin(GL_LINES);//gedung tinggi 1 kanan atas aksen
        glColor3f(0.389, 0.389, 0.389);
        glVertex3f(300.1, i, 170);
        glVertex3f(300.1, i, -30);
        glEnd();
    }
    glBegin(GL_POLYGON);//gedung tinggi 1 depan atas
    glColor3f(0.612, 0.612, 0.612);
    glVertex3f(-130, 550, 170);
    glVertex3f(300, 550, 170);
    glColor3f(0.812, 0.812, 0.812);
    glVertex3f(300, 950, 170);
    glVertex3f(-130, 950, 170);
    glEnd();
    for (float i = 580; i < 950; i += 50) {
        glBegin(GL_LINES);//gedung tinggi 1 depan atas aksen
        glColor3f(0.389, 0.389, 0.389);
        glVertex3f(-130, i, 170.1);
        glVertex3f(300, i, 170.1);
        glEnd();
    }
    glLineWidth(6.0f);
    glBegin(GL_POLYGON);//gedung tinggi 1 belakang atas
    glColor3f(0.612, 0.612, 0.612);
    glVertex3f(-130, 550, -30);
    glVertex3f(300, 550, -30);
    glColor3f(0.812, 0.812, 0.812);
    glVertex3f(300, 950, -30);
    glVertex3f(-130, 950, -30);
    glEnd();
    glBegin(GL_LINES);//gedung tinggi 1 garis miring bawah abu
    glColor3f(0.867, 0.867, 0.867);
    glVertex3f(130, 340, 171);
    glVertex3f(200, 550, 171);
    glEnd();
    glBegin(GL_LINES);//gedung tinggi 1 garis miring atas abu
    glColor3f(0.867, 0.867, 0.867);
    glVertex3f(200, 550, 171);
    glVertex3f(180, 950, 171);
    glEnd();
    glBegin(GL_LINES);//gedung tinggi 1 garis aksen 1 putih
    glColor3f(1, 1, 1);
    glVertex3f(197, 540, 171);
    glVertex3f(300, 540, 171);
    glEnd();
    glBegin(GL_LINES);//gedung tinggi 1 garis aksen 2 putih
    glColor3f(1, 1, 1);
    glVertex3f(195, 680, 171);
    glVertex3f(300, 680, 171);
    glEnd();
    glBegin(GL_LINES);//gedung tinggi 1 garis aksen 2 putih
    glColor3f(1, 1, 1);
    glVertex3f(188, 820, 171);
    glVertex3f(300, 820, 171);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 1 atap
    glColor3f(0.6, 0.7, 0.6);
    glVertex3f(-130, 950, 170);
    glVertex3f(300, 950, 170);
    glVertex3f(300, 950, -30);
    glVertex3f(-130, 950, -30);
    glEnd();

    glBegin(GL_POLYGON);//gedung tinggi 1 atap pagar putih depan1
    glColor3f(0.95, 0.95, 0.95);
    glVertex3f(-130, 950, 170);
    glVertex3f(180, 950, 170);
    glVertex3f(165, 990, 170);
    glVertex3f(-130, 990, 170);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 1 atap pagar putih depan2
    glColor3f(0.95, 0.95, 0.95);
    glVertex3f(-130, 950, 160);
    glVertex3f(180, 950, 160);
    glVertex3f(165, 990, 160);
    glVertex3f(-130, 990, 160);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 1 atap pagar putih depan3
    glColor3f(0.95, 0.95, 0.95);
    glVertex3f(180, 950, 170);
    glVertex3f(180, 950, 160);
    glVertex3f(165, 990, 160);
    glVertex3f(165, 990, 170);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 1 atap pagar putih depan atas
    glColor3f(0.95, 0.95, 0.95);
    glVertex3f(-130, 990, 160);
    glVertex3f(165, 990, 160);
    glVertex3f(165, 990, 170);
    glVertex3f(-130, 990, 170);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 1 atap pagar putih belakang1
    glColor3f(0.95, 0.95, 0.95);
    glVertex3f(-130, 950, -20);
    glVertex3f(-100, 950, -20);
    glVertex3f(-100, 990, -20);
    glVertex3f(-130, 990, -20);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 1 atap pagar putih belakang2
    glColor3f(0.95, 0.95, 0.95);
    glVertex3f(-130, 950, -30);
    glVertex3f(-100, 950, -30);
    glVertex3f(-100, 990, -30);
    glVertex3f(-130, 990, -30);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 1 atap pagar putih belakang3
    glColor3f(0.95, 0.95, 0.95);
    glVertex3f(-100, 950, -30);
    glVertex3f(-100, 950, -20);
    glVertex3f(-100, 990, -20);
    glVertex3f(-100, 990, -30);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 1 atap pagar putih belakang atas
    glColor3f(0.95, 0.95, 0.95);
    glVertex3f(-130, 990, -30);
    glVertex3f(-100, 990, -30);
    glVertex3f(-100, 990, -20);
    glVertex3f(-130, 990, -20);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 1 atap pagar putih kiri1
    glColor3f(0.95, 0.95, 0.95);
    glVertex3f(-130, 950, -30);
    glVertex3f(-130, 990, -30);
    glVertex3f(-130, 990, 170);
    glVertex3f(-130, 950, 170);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 1 atap pagar putih kiri2
    glColor3f(0.95, 0.95, 0.95);
    glVertex3f(-120, 950, -30);
    glVertex3f(-120, 990, -30);
    glVertex3f(-120, 990, 170);
    glVertex3f(-120, 950, 170);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 1 atap pagar putih kiri atas
    glColor3f(0.95, 0.95, 0.95);
    glVertex3f(-120, 990, -30);
    glVertex3f(-130, 990, -30);
    glVertex3f(-130, 990, 170);
    glVertex3f(-120, 990, 170);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 1 atap pagar putih depan kecil1
    glColor3f(0.95, 0.95, 0.95);
    glVertex3f(170, 950, 170);
    glVertex3f(300, 950, 170);
    glVertex3f(300, 965, 170);
    glVertex3f(170, 965, 170);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 1 atap pagar putih depan kecil2
    glColor3f(0.95, 0.95, 0.95);
    glVertex3f(170, 950, 160);
    glVertex3f(300, 950, 160);
    glVertex3f(300, 965, 160);
    glVertex3f(170, 965, 160);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 1 atap pagar putih depan kecil atas
    glColor3f(0.95, 0.95, 0.95);
    glVertex3f(170, 965, 160);
    glVertex3f(300, 965, 160);
    glVertex3f(300, 965, 170);
    glVertex3f(170, 965, 170);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 1 atap pagar putih kanan1
    glColor3f(0.95, 0.95, 0.95);
    glVertex3f(300, 950, -30);
    glVertex3f(300, 950, 170);
    glVertex3f(300, 965, 170);
    glVertex3f(300, 965, -30);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 1 atap pagar putih kanan2
    glColor3f(0.95, 0.95, 0.95);
    glVertex3f(290, 950, -30);
    glVertex3f(290, 950, 170);
    glVertex3f(290, 965, 170);
    glVertex3f(290, 965, -30);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 1 atap pagar putih kanan atas
    glColor3f(0.95, 0.95, 0.95);
    glVertex3f(300, 965, -30);
    glVertex3f(300, 965, 170);
    glVertex3f(290, 965, 170);
    glVertex3f(290, 965, -30);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 1 atap pagar putih belakang kecil1
    glColor3f(0.95, 0.95, 0.95);
    glVertex3f(220, 950, -20);
    glVertex3f(300, 950, -20);
    glVertex3f(300, 965, -20);
    glVertex3f(220, 965, -20);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 1 atap pagar putih belakang kecil2
    glColor3f(0.95, 0.95, 0.95);
    glVertex3f(220, 950, -30);
    glVertex3f(300, 950, -30);
    glVertex3f(300, 965, -30);
    glVertex3f(220, 965, -30);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 1 atap pagar putih belakang kecil3
    glColor3f(0.95, 0.95, 0.95);
    glVertex3f(220, 950, -30);
    glVertex3f(220, 950, -20);
    glVertex3f(220, 965, -20);
    glVertex3f(220, 965, -30);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 1 atap pagar putih belakang kecil atas
    glColor3f(0.95, 0.95, 0.95);
    glVertex3f(300, 965, -30);
    glVertex3f(300, 965, -20);
    glVertex3f(220, 965, -20);
    glVertex3f(220, 965, -30);
    glEnd();

    //ruang kubus abu di atas gedung tinggi 1

    glBegin(GL_POLYGON);//ruang kubus abu di atas gedung tinggi 1 kiri1
    glColor3f(0.678, 0.678, 0.678);
    glVertex3f(-20, 950, -57);
    glVertex3f(-20, 950, 80);
    glVertex3f(-20, 1070, 80);
    glVertex3f(-20, 1070, -57);
    glEnd();
    glBegin(GL_POLYGON);//ruang kubus abu di atas gedung tinggi 1 kiri2
    glColor3f(0.678, 0.678, 0.678);
    glVertex3f(-10, 950, -57);
    glVertex3f(-10, 950, 80);
    glVertex3f(-10, 1070, 80);
    glVertex3f(-10, 1070, -57);
    glEnd();
    glBegin(GL_POLYGON);//ruang kubus abu di atas gedung tinggi 1 kiri atas
    glColor3f(0.778, 0.778, 0.778);
    glVertex3f(-10, 1070, -57);
    glVertex3f(-20, 1070, -57);
    glVertex3f(-20, 1070, 80);
    glVertex3f(-10, 1070, 80);
    glEnd();
    glBegin(GL_POLYGON);//ruang kubus abu di atas gedung tinggi 1 kanan1
    glColor3f(0.678, 0.678, 0.678);
    glVertex3f(220, 950, -57);
    glVertex3f(220, 950, 80);
    glVertex3f(220, 1070, 80);
    glVertex3f(220, 1070, -57);
    glEnd();
    glBegin(GL_POLYGON);//ruang kubus abu di atas gedung tinggi 1 kanan2
    glColor3f(0.678, 0.678, 0.678);
    glVertex3f(210, 950, -57);
    glVertex3f(210, 950, 80);
    glVertex3f(210, 1070, 80);
    glVertex3f(210, 1070, -57);
    glEnd();
    glBegin(GL_POLYGON);//ruang kubus abu di atas gedung tinggi 1 kanan atas
    glColor3f(0.778, 0.778, 0.778);
    glVertex3f(210, 1070, -57);
    glVertex3f(220, 1070, -57);
    glVertex3f(220, 1070, 80);
    glVertex3f(210, 1070, 80);
    glEnd();
    glBegin(GL_POLYGON);//ruang kubus abu di atas gedung tinggi 1 depan1
    glColor3f(0.678, 0.678, 0.678);
    glVertex3f(-20, 950, 80);
    glVertex3f(220, 950, 80);
    glVertex3f(220, 1070, 80);
    glVertex3f(-20, 1070, 80);
    glEnd();
    glBegin(GL_POLYGON);//ruang kubus abu di atas gedung tinggi 1 depan2
    glColor3f(0.678, 0.678, 0.678);
    glVertex3f(-20, 950, 70);
    glVertex3f(220, 950, 70);
    glVertex3f(220, 1070, 70);
    glVertex3f(-20, 1070, 70);
    glEnd();
    glBegin(GL_POLYGON);//ruang kubus abu di atas gedung tinggi 1 depan atas
    glColor3f(0.778, 0.778, 0.778);
    glVertex3f(-20, 1070, 70);
    glVertex3f(220, 1070, 70);
    glVertex3f(220, 1070, 80);
    glVertex3f(-20, 1070, 80);
    glEnd();
    glBegin(GL_POLYGON);//ruang kubus abu di atas gedung tinggi 1 belakang1
    glColor3f(0.678, 0.678, 0.678);
    glVertex3f(-20, 950, -57);
    glVertex3f(220, 950, -57);
    glVertex3f(220, 1070, -57);
    glVertex3f(-20, 1070, -57);
    glEnd();
    glBegin(GL_POLYGON);//ruang kubus abu di atas gedung tinggi 1 belakang2
    glColor3f(0.678, 0.678, 0.678);
    glVertex3f(-20, 950, -47);
    glVertex3f(220, 950, -47);
    glVertex3f(220, 1070, -47);
    glVertex3f(-20, 1070, -47);
    glEnd();
    glBegin(GL_POLYGON);//ruang kubus abu di atas gedung tinggi 1 belakang atas
    glColor3f(0.778, 0.778, 0.778);
    glVertex3f(-20, 1070, -47);
    glVertex3f(220, 1070, -47);
    glVertex3f(220, 1070, -57);
    glVertex3f(-20, 1070, -57);
    glEnd();
    glBegin(GL_POLYGON);//ruang kubus abu di atas gedung tinggi 1 atap
    glColor3f(0.878, 0.878, 0.878);
    glVertex3f(-10, 1060, -47);
    glVertex3f(210, 1060, -47);
    glVertex3f(210, 1060, 70);
    glVertex3f(-10, 1060, 70);
    glEnd();

    glBegin(GL_POLYGON);//gedung tinggi 2 bawah belakang1
    glColor3f(0.93, 0.93, 0.93);
    glVertex3f(-150, 0, -240);
    glVertex3f(350, 0, -240);
    glVertex3f(350, 320, -240);
    glVertex3f(-150, 320, -240);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 2 bawah belakang2
    glColor3f(0.93, 0.93, 0.93);
    glVertex3f(-150, 0, -180);
    glVertex3f(350, 0, -180);
    glVertex3f(350, 300, -180);
    glVertex3f(-150, 300, -180);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 2 bawah depan
    glColor3f(0.93, 0.93, 0.93);
    glVertex3f(-150, 300, -240);
    glVertex3f(350, 300, -240);
    glVertex3f(350, 320, -240);
    glVertex3f(-150, 320, -240);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 2 bawah atas1
    glColor3f(0.88, 0.78, 0.78);
    glVertex3f(-150, 320, -240);
    glVertex3f(-150, 320, -40);
    glVertex3f(350, 320, -40);
    glVertex3f(350, 320, -240);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 2 bawah atas2
    glColor3f(0.93, 0.93, 0.93);
    glVertex3f(-150, 300, -180);
    glVertex3f(-150, 300, -40);
    glVertex3f(350, 300, -40);
    glVertex3f(350, 300, -180);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 2 bawah kiri1
    glColor3f(0.88, 0.78, 0.78);
    glVertex3f(-150, 0, -240);
    glVertex3f(-150, 0, -180);
    glVertex3f(-150, 320, -180);
    glVertex3f(-150, 320, -240);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 2 bawah kiri2
    glColor3f(0.88, 0.78, 0.78);
    glVertex3f(-150, 300, -240);
    glVertex3f(-150, 300, -40);
    glVertex3f(-150, 320, -40);
    glVertex3f(-150, 320, -240);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 2 bawah kanan1
    glColor3f(0.88, 0.78, 0.78);
    glVertex3f(350, 0, -240);
    glVertex3f(350, 0, -180);
    glVertex3f(350, 320, -180);
    glVertex3f(350, 320, -240);
    glEnd();
    int j = 0;
    for (float i = 395; i > 349; i -= 5) {
        glBegin(GL_POLYGON);//gedung tinggi 2 bawah kanan1 tangga alas atas
        glColor3f(0.9, 0.9, 0.9);
        glVertex3f(350, j, -180);
        glVertex3f(350, j, -240);
        glVertex3f(i, j, -240);
        glVertex3f(i, j, -180);
        glEnd();
        j += 5;
        glBegin(GL_POLYGON);//gedung tinggi 2 bawah kanan1 tangga alas atas
        glColor3f(0.9, 0.9, 0.9);
        glVertex3f(350, j, -180);
        glVertex3f(350, j, -240);
        glVertex3f(i, j, -240);
        glVertex3f(i, j, -180);
        glEnd();
        //i=i-4;

    }
    j = 395;
    for (float i = 0; i < 44; i += 5) {
        glBegin(GL_POLYGON);//gedung tinggi 2 bawah kanan1 tangga alas depan
        glColor3f(0.6, 0.6, 0.6);
        glVertex3f(j, i, -180);
        glVertex3f(j, i, -240);
        glVertex3f(j, i + 5, -240);
        glVertex3f(j, i + 5, -180);
        glEnd();
        //i=i-4;
        j -= 5;
    }
    j = 0;
    for (float i = 395; i > 349; i -= 5) {
        glBegin(GL_POLYGON);//gedung tinggi 2 bawah kanan1 tangga alas kanan
        glColor3f(0.2, 0.2, 0.2);
        glVertex3f(350, j, -240);
        glVertex3f(i, j, -240);
        glVertex3f(i, j + 5, -240);
        glVertex3f(350, j + 5, -240);
        glEnd();
        //i=i-4;
        j += 5;
    }
    j = 0;
    for (float i = 395; i > 349; i -= 5) {
        glBegin(GL_POLYGON);//gedung tinggi 2 bawah kanan1 tangga alas kiri
        glColor3f(0.2, 0.2, 0.2);
        glVertex3f(350, j, -180);
        glVertex3f(i, j, -180);
        glVertex3f(i, j + 5, -180);
        glVertex3f(350, j + 5, -180);
        glEnd();
        //i=i-4;
        j += 5;
    }
    glPushMatrix();//gedung tinggi 2 bawah kanan1 pintu
    glColor3ub(102, 51, 0);
    glTranslatef(350, 45, -180);
    glRotatef(90, 0, 1, 0);
    glScalef(50, 100, 5);
    glTranslatef(0.6, 0.5, -0.1);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();//gedung tinggi 2 bawah kanan1 pintu kunci
    glColor3ub(26, 38, 45);
    glTranslatef(350, 45, -180);
    glRotatef(90, 0, 1, 0);
    glTranslatef(10, 45, -0.5);
    glutSolidSphere(4, 32, 32);
    glPopMatrix();

    glBegin(GL_POLYGON);//gedung tinggi 2 lantai belakang pintu
    glColor3f(0.88, 0.78, 0.78);
    glVertex3f(350, 45, -240);
    glVertex3f(350, 45, -180);
    glVertex3f(-150, 45, -180);
    glVertex3f(-150, 45, -240);
    glEnd();


    glBegin(GL_POLYGON);//gedung tinggi 2 bawah kanan2
    glColor3f(0.88, 0.78, 0.78);
    glVertex3f(350, 300, -240);
    glVertex3f(350, 300, -40);
    glVertex3f(350, 320, -40);
    glVertex3f(350, 320, -240);
    glEnd();

    glBegin(GL_POLYGON);//gedung tinggi 2 bawah fondasi atas
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-130, 340, -220);
    glVertex3f(-130, 340, -60);
    glVertex3f(280, 340, -60);
    glVertex3f(280, 340, -220);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 2 bawah fondasi belakang
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-130, 320, -220);
    glVertex3f(-130, 340, -220);
    glVertex3f(280, 340, -220);
    glVertex3f(280, 320, -220);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 2 bawah fondasi depan
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-130, 320, -60);
    glVertex3f(-130, 340, -60);
    glVertex3f(280, 340, -60);
    glVertex3f(280, 320, -60);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 2 bawah fondasi kiri
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-130, 320, -220);
    glVertex3f(-130, 340, -220);
    glVertex3f(-130, 340, -60);
    glVertex3f(-130, 320, -60);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 2 bawah fondasi kanan
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(280, 320, -220);
    glVertex3f(280, 340, -220);
    glVertex3f(280, 340, -60);
    glVertex3f(280, 320, -60);
    glEnd();

    glBegin(GL_POLYGON);//gedung tinggi 2 atas alas
    glColor3f(0.93, 0.93, 0.93);
    glVertex3f(-150, 340, -240);
    glVertex3f(-150, 340, -60);
    glVertex3f(300, 340, -60);
    glVertex3f(300, 340, -240);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 2 atas atap ijo
    glColor3f(0.2, 0.7, 0.2);
    glVertex3f(-150, 1050, -240);
    glVertex3f(-150, 1050, -60);
    glVertex3f(300, 1050, -60);
    glVertex3f(300, 1050, -240);
    glEnd();
    glBegin(GL_LINES);//gedung tinggi 2 atas atap garis depan
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(-150, 1050, -60);
    glVertex3f(300, 1050, -60);
    glEnd();
    glBegin(GL_LINES);//gedung tinggi 2 atas atap garis belakang
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(-150, 1050, -240);
    glVertex3f(300, 1050, -240);
    glEnd();
    glBegin(GL_LINES);//gedung tinggi 2 atas atap garis kiri
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(-150, 1050, -60);
    glVertex3f(-150, 1050, -240);
    glEnd();
    glBegin(GL_LINES);//gedung tinggi 2 atas atap garis kiri
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(300, 1050, -60);
    glVertex3f(300, 1050, -240);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 2 atas atap kotak putih
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-100, 1050.1, -100);
    glVertex3f(-100, 1050.1, -60.1);
    glVertex3f(300, 1050.1, -60.1);
    glVertex3f(300, 1050.1, -100);
    glEnd();
    glBegin(GL_LINES);//gedung tinggi 2 atas atap garis putih1
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(0, 1050.2, -75);
    glVertex3f(0, 1050.2, -100);
    glEnd();
    glBegin(GL_LINES);//gedung tinggi 2 atas atap garis putih2
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(100, 1050.2, -75);
    glVertex3f(100, 1050.2, -100);
    glEnd();
    glBegin(GL_LINES);//gedung tinggi 2 atas atap garis putih3
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(200, 1050.2, -75);
    glVertex3f(200, 1050.2, -100);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 2 atas atap kotak abu1
    glColor3f(0.65, 0.65, 0.65);
    glVertex3f(-90, 1050.2, -95);
    glVertex3f(-90, 1050.2, -75);
    glVertex3f(290, 1050.2, -75);
    glVertex3f(290, 1050.2, -95);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 2 atas depan
    glColor3f(0.93, 0.93, 0.93);
    glVertex3f(-150, 340, -60);
    glVertex3f(300, 340, -60);
    glVertex3f(300, 1050, -60);
    glVertex3f(-150, 1050, -60);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 2 atas belakang1
    glColor3f(0.93, 0.93, 0.93);
    glVertex3f(-150, 340, -240);
    glVertex3f(300, 340, -240);
    glVertex3f(300, 730, -240);
    glVertex3f(-150, 730, -240);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 2 atas belakang2
    glColor3f(0.93, 0.93, 0.93);
    glVertex3f(-50, 730, -240);
    glVertex3f(300, 730, -240);
    glVertex3f(300, 850, -240);
    glVertex3f(-50, 850, -240);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 2 atas belakang3
    glColor3f(0.93, 0.93, 0.93);
    glVertex3f(-150, 850, -240);
    glVertex3f(300, 850, -240);
    glVertex3f(300, 1050, -240);
    glVertex3f(-150, 1050, -240);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 2 atas kiri1
    glColor3f(0.93, 0.93, 0.93);
    glVertex3f(-150, 340, -240);
    glVertex3f(-150, 340, -60);
    glVertex3f(-150, 730, -60);
    glVertex3f(-150, 730, -240);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 2 atas kiri2
    glColor3f(0.93, 0.93, 0.93);
    glVertex3f(-150, 730, -140);
    glVertex3f(-150, 730, -60);
    glVertex3f(-150, 850, -60);
    glVertex3f(-150, 850, -140);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 2 atas kiri3
    glColor3f(0.93, 0.93, 0.93);
    glVertex3f(-150, 850, -240);
    glVertex3f(-150, 850, -60);
    glVertex3f(-150, 1050, -60);
    glVertex3f(-150, 1050, -240);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 2 ruang kotak belakang
    glColor3f(0.45, 0.45, 0.9);
    glVertex3f(-50, 730, -230);
    glVertex3f(-140, 730, -230);
    glVertex3f(-140, 850, -230);
    glVertex3f(-50, 850, -230);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 2 ruang kotak depan
    glColor3f(0.45, 0.45, 0.9);
    glVertex3f(-50, 730, -140);
    glVertex3f(-140, 730, -140);
    glVertex3f(-140, 850, -140);
    glVertex3f(-50, 850, -140);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 2 ruang kotak kanan
    glColor3f(0.45, 0.45, 0.9);
    glVertex3f(-50, 730, -230);
    glVertex3f(-50, 730, -140);
    glVertex3f(-50, 850, -140);
    glVertex3f(-50, 850, -230);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 2 ruang kotak kiri
    glColor3f(0.45, 0.45, 0.9);
    glVertex3f(-140, 730, -230);
    glVertex3f(-140, 730, -140);
    glVertex3f(-140, 850, -140);
    glVertex3f(-140, 850, -230);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 2 ruang kotak tutup kanan
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(-50, 730, -240);
    glVertex3f(-50, 730, -230);
    glVertex3f(-50, 850, -230);
    glVertex3f(-50, 850, -240);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 2 ruang kotak tutup belakang bawah
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(-50, 730, -240);
    glVertex3f(-50, 730, -230);
    glVertex3f(-150, 730, -230);
    glVertex3f(-150, 730, -240);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 2 ruang kotak tutup belakang atas
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(-50, 850, -240);
    glVertex3f(-50, 850, -230);
    glVertex3f(-150, 850, -230);
    glVertex3f(-150, 850, -240);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 2 ruang kotak tutup kiri bawah
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(-140, 730, -240);
    glVertex3f(-140, 730, -140);
    glVertex3f(-150, 730, -140);
    glVertex3f(-150, 730, -240);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 2 ruang kotak tutup kiri atas
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(-140, 850, -240);
    glVertex3f(-140, 850, -140);
    glVertex3f(-150, 850, -140);
    glVertex3f(-150, 850, -240);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 2 ruang kotak tutup depan
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(-140, 730, -140);
    glVertex3f(-140, 850, -140);
    glVertex3f(-150, 850, -140);
    glVertex3f(-150, 730, -140);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 2 atas kanan
    glColor3f(0.93, 0.93, 0.93);
    glVertex3f(300, 340, -240);
    glVertex3f(300, 340, -60);
    glVertex3f(300, 1050, -60);
    glVertex3f(300, 1050, -240);
    glEnd();

    glBegin(GL_POLYGON);//gedung tinggi tengah biru kiri
    glColor3f(0.2, 0.2, 0.4);
    glVertex3f(-130, 360, -30);
    glVertex3f(-130, 360, -60);
    glVertex3f(-130, 950, -60);
    glVertex3f(-130, 950, -30);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi tengah biru kanan
    glColor3f(0.2, 0.2, 0.4);
    glVertex3f(280, 360, -30);
    glVertex3f(280, 360, -60);
    glVertex3f(280, 950, -60);
    glVertex3f(280, 950, -30);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi tengah biru atas
    glColor3f(0.2, 0.2, 0.4);
    glVertex3f(-130, 950, -30);
    glVertex3f(-130, 950, -60);
    glVertex3f(280, 950, -60);
    glVertex3f(280, 950, -30);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi tengah biru bawah
    glColor3f(0.2, 0.2, 0.4);
    glVertex3f(-130, 360, -30);
    glVertex3f(-130, 360, -60);
    glVertex3f(280, 360, -60);
    glVertex3f(280, 360, -30);
    glEnd();
    glBegin(GL_LINES);//garis gedung biru
    glColor3f(0.978, 0.978, 0.978);
    glVertex3f(-131, 462, -60);
    glVertex3f(-131, 462, -30);
    glEnd();
    glBegin(GL_LINES);//garis gedung biru
    glColor3f(0.978, 0.978, 0.978);
    glVertex3f(-131, 584, -60);
    glVertex3f(-131, 584, -30);
    glEnd();
    glBegin(GL_LINES);//garis gedung biru
    glColor3f(0.978, 0.978, 0.978);
    glVertex3f(-131, 706, -60);
    glVertex3f(-131, 706, -30);
    glEnd();
    glBegin(GL_LINES);//garis gedung biru
    glColor3f(0.978, 0.978, 0.978);
    glVertex3f(-131, 828, -60);
    glVertex3f(-131, 828, -30);
    glEnd();

    //lantai gedung tinggi 1
    glBegin(GL_POLYGON);//gedung tinggi 1 lantai 2
    glColor3f(0.345, 0.345, 0.345);
    glVertex3f(-138.3, 462, 170);
    glVertex3f(300, 462, 170);
    glVertex3f(300, 462, -30);
    glVertex3f(-138.3, 462, -30);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 1 lantai 3
    glColor3f(0.345, 0.345, 0.345);
    glVertex3f(-130, 584, 170);
    glVertex3f(300, 584, 170);
    glVertex3f(300, 584, -30);
    glVertex3f(-130, 584, -30);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 1 lantai 4
    glColor3f(0.345, 0.345, 0.345);
    glVertex3f(-130, 706, 170);
    glVertex3f(300, 706, 170);
    glVertex3f(300, 706, -30);
    glVertex3f(-130, 706, -30);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 1 lantai 5
    glColor3f(0.345, 0.345, 0.345);
    glVertex3f(-130, 828, 170);
    glVertex3f(300, 828, 170);
    glVertex3f(300, 828, -30);
    glVertex3f(-130, 828, -30);
    glEnd();

    //lantai gedung tinggi 2 atas
    glBegin(GL_POLYGON);//gedung tinggi 2 atas lantai 2
    glColor3f(0.321, 0.321, 0.321);
    glVertex3f(-150, 462, -240);
    glVertex3f(-150, 462, -60);
    glVertex3f(300, 462, -60);
    glVertex3f(300, 462, -240);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 2 atas lantai 3
    glColor3f(0.321, 0.321, 0.321);
    glVertex3f(-150, 584, -240);
    glVertex3f(-150, 584, -60);
    glVertex3f(300, 584, -60);
    glVertex3f(300, 584, -240);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 2 atas lantai 4
    glColor3f(0.321, 0.321, 0.321);
    glVertex3f(-150, 706, -240);
    glVertex3f(-150, 706, -60);
    glVertex3f(300, 706, -60);
    glVertex3f(300, 706, -240);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 2 atas lantai 5.1
    glColor3f(0.321, 0.321, 0.321);
    glVertex3f(-50, 828, -240);
    glVertex3f(-50, 828, -60);
    glVertex3f(300, 828, -60);
    glVertex3f(300, 828, -240);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 2 atas lantai 5.2
    glColor3f(0.321, 0.321, 0.321);
    glVertex3f(-50, 828, -140);
    glVertex3f(-50, 828, -60);
    glVertex3f(-150, 828, -60);
    glVertex3f(-150, 828, -140);
    glEnd();
    glBegin(GL_POLYGON);//gedung tinggi 2 atas lantai 6
    glColor3f(0.321, 0.321, 0.321);
    glVertex3f(-150, 950, -240);
    glVertex3f(-150, 950, -60);
    glVertex3f(300, 950, -60);
    glVertex3f(300, 950, -240);
    glEnd();

    //hiasan atau aksen gedung tinggi 2
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 2 1
    glColor3f(0.356, 0.356, 0.356);
    glVertex3f(260, 950, -240.1);
    glVertex3f(280, 950, -240.1);
    glVertex3f(280, 1050, -240.1);
    glVertex3f(260, 1050, -240.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 2 2
    glColor3f(0.356, 0.356, 0.356);
    glVertex3f(200, 950, -240.1);
    glVertex3f(220, 950, -240.1);
    glVertex3f(220, 1050, -240.1);
    glVertex3f(200, 1050, -240.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 2 3
    glColor3f(0.556, 0.556, 0.556);
    glVertex3f(170, 950, -240.1);
    glVertex3f(190, 950, -240.1);
    glVertex3f(190, 1050, -240.1);
    glVertex3f(170, 1050, -240.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 2 4
    glColor3f(0.356, 0.356, 0.356);
    glVertex3f(80, 950, -240.1);
    glVertex3f(90, 950, -240.1);
    glVertex3f(90, 1050, -240.1);
    glVertex3f(80, 1050, -240.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 2 5
    glColor3f(0.556, 0.556, 0.556);
    glVertex3f(60, 950, -240.1);
    glVertex3f(75, 950, -240.1);
    glVertex3f(75, 1050, -240.1);
    glVertex3f(60, 1050, -240.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 2 6
    glColor3f(0.356, 0.356, 0.356);
    glVertex3f(10, 950, -240.1);
    glVertex3f(30, 950, -240.1);
    glVertex3f(30, 1050, -240.1);
    glVertex3f(10, 1050, -240.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 2 7
    glColor3f(0.356, 0.356, 0.356);
    glVertex3f(-20, 950, -240.1);
    glVertex3f(-5, 950, -240.1);
    glVertex3f(-5, 1050, -240.1);
    glVertex3f(-20, 1050, -240.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 2 8
    glColor3f(0.556, 0.556, 0.556);
    glVertex3f(-60, 950, -240.1);
    glVertex3f(-45, 950, -240.1);
    glVertex3f(-45, 1050, -240.1);
    glVertex3f(-60, 1050, -240.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 2 9
    glColor3f(0.556, 0.556, 0.556);
    glVertex3f(-80, 950, -240.1);
    glVertex3f(-65, 950, -240.1);
    glVertex3f(-65, 1050, -240.1);
    glVertex3f(-80, 1050, -240.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 2 10
    glColor3f(0.356, 0.356, 0.356);
    glVertex3f(-130, 950, -240.1);
    glVertex3f(-115, 950, -240.1);
    glVertex3f(-115, 1050, -240.1);
    glVertex3f(-130, 1050, -240.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 3 1
    glColor3f(0.356, 0.356, 0.356);
    glVertex3f(260, 730, -240.1);
    glVertex3f(280, 730, -240.1);
    glVertex3f(280, 940, -240.1);
    glVertex3f(260, 940, -240.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 3 2
    glColor3f(0.356, 0.356, 0.356);
    glVertex3f(200, 730, -240.1);
    glVertex3f(210, 730, -240.1);
    glVertex3f(210, 940, -240.1);
    glVertex3f(200, 940, -240.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 3 3
    glColor3f(0.556, 0.556, 0.556);
    glVertex3f(170, 730, -240.1);
    glVertex3f(190, 730, -240.1);
    glVertex3f(190, 940, -240.1);
    glVertex3f(170, 940, -240.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 3 4
    glColor3f(0.556, 0.556, 0.556);
    glVertex3f(130, 730, -240.1);
    glVertex3f(150, 730, -240.1);
    glVertex3f(150, 940, -240.1);
    glVertex3f(130, 940, -240.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 3 5
    glColor3f(0.356, 0.356, 0.356);
    glVertex3f(90, 730, -240.1);
    glVertex3f(110, 730, -240.1);
    glVertex3f(110, 940, -240.1);
    glVertex3f(90, 940, -240.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 3 6
    glColor3f(0.556, 0.556, 0.556);
    glVertex3f(40, 730, -240.1);
    glVertex3f(70, 730, -240.1);
    glVertex3f(70, 940, -240.1);
    glVertex3f(40, 940, -240.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 3 7
    glColor3f(0.356, 0.356, 0.356);
    glVertex3f(0, 730, -240.1);
    glVertex3f(20, 730, -240.1);
    glVertex3f(20, 940, -240.1);
    glVertex3f(0, 940, -240.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 3 7
    glColor3f(0.556, 0.556, 0.556);
    glVertex3f(-40, 730, -240.1);
    glVertex3f(-20, 730, -240.1);
    glVertex3f(-20, 940, -240.1);
    glVertex3f(-40, 940, -240.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 3 8
    glColor3f(0.356, 0.356, 0.356);
    glVertex3f(-80, 850, -240.1);
    glVertex3f(-65, 850, -240.1);
    glVertex3f(-65, 940, -240.1);
    glVertex3f(-80, 940, -240.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 3 9
    glColor3f(0.556, 0.556, 0.556);
    glVertex3f(-120, 850, -240.1);
    glVertex3f(-95, 850, -240.1);
    glVertex3f(-95, 940, -240.1);
    glVertex3f(-120, 940, -240.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 3 10
    glColor3f(0.356, 0.356, 0.356);
    glVertex3f(-150, 850, -240.1);
    glVertex3f(-130, 850, -240.1);
    glVertex3f(-130, 940, -240.1);
    glVertex3f(-150, 940, -240.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 4 1
    glColor3f(0.556, 0.556, 0.556);
    glVertex3f(250, 540, -240.1);
    glVertex3f(270, 540, -240.1);
    glVertex3f(270, 720, -240.1);
    glVertex3f(250, 720, -240.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 4 2
    glColor3f(0.356, 0.356, 0.356);
    glVertex3f(200, 540, -240.1);
    glVertex3f(220, 540, -240.1);
    glVertex3f(220, 720, -240.1);
    glVertex3f(200, 720, -240.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 4 3
    glColor3f(0.356, 0.356, 0.356);
    glVertex3f(150, 540, -240.1);
    glVertex3f(170, 540, -240.1);
    glVertex3f(170, 720, -240.1);
    glVertex3f(150, 720, -240.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 4 4
    glColor3f(0.556, 0.556, 0.556);
    glVertex3f(80, 540, -240.1);
    glVertex3f(100, 540, -240.1);
    glVertex3f(100, 720, -240.1);
    glVertex3f(80, 720, -240.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 4 5
    glColor3f(0.556, 0.556, 0.556);
    glVertex3f(40, 540, -240.1);
    glVertex3f(60, 540, -240.1);
    glVertex3f(60, 720, -240.1);
    glVertex3f(40, 720, -240.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 4 6
    glColor3f(0.356, 0.356, 0.356);
    glVertex3f(-30, 540, -240.1);
    glVertex3f(0, 540, -240.1);
    glVertex3f(0, 720, -240.1);
    glVertex3f(-30, 720, -240.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 4 7
    glColor3f(0.556, 0.556, 0.556);
    glVertex3f(-100, 540, -240.1);
    glVertex3f(-80, 540, -240.1);
    glVertex3f(-80, 720, -240.1);
    glVertex3f(-100, 720, -240.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 5 1
    glColor3f(0.356, 0.356, 0.356);
    glVertex3f(260, 340, -240.1);
    glVertex3f(280, 340, -240.1);
    glVertex3f(280, 530, -240.1);
    glVertex3f(260, 530, -240.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 5 2
    glColor3f(0.556, 0.556, 0.556);
    glVertex3f(200, 340, -240.1);
    glVertex3f(220, 340, -240.1);
    glVertex3f(220, 530, -240.1);
    glVertex3f(200, 530, -240.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 5 3
    glColor3f(0.356, 0.356, 0.356);
    glVertex3f(150, 340, -240.1);
    glVertex3f(170, 340, -240.1);
    glVertex3f(170, 530, -240.1);
    glVertex3f(150, 530, -240.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 5 4
    glColor3f(0.356, 0.356, 0.356);
    glVertex3f(100, 340, -240.1);
    glVertex3f(120, 340, -240.1);
    glVertex3f(120, 530, -240.1);
    glVertex3f(100, 530, -240.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 5 5
    glColor3f(0.356, 0.356, 0.356);
    glVertex3f(20, 340, -240.1);
    glVertex3f(40, 340, -240.1);
    glVertex3f(40, 530, -240.1);
    glVertex3f(20, 530, -240.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 5 6
    glColor3f(0.556, 0.556, 0.556);
    glVertex3f(-20, 340, -240.1);
    glVertex3f(0, 340, -240.1);
    glVertex3f(0, 530, -240.1);
    glVertex3f(-20, 530, -240.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 5 7
    glColor3f(0.556, 0.556, 0.556);
    glVertex3f(-70, 340, -240.1);
    glVertex3f(-50, 340, -240.1);
    glVertex3f(-50, 530, -240.1);
    glVertex3f(-70, 530, -240.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 5 8
    glColor3f(0.356, 0.356, 0.356);
    glVertex3f(-120, 340, -240.1);
    glVertex3f(-100, 340, -240.1);
    glVertex3f(-100, 530, -240.1);
    glVertex3f(-120, 530, -240.1);
    glEnd();

    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 6 1
    glColor3f(0.356, 0.356, 0.356);
    glVertex3f(320, 150, -240.1);
    glVertex3f(340, 150, -240.1);
    glVertex3f(340, 320, -240.1);
    glVertex3f(320, 320, -240.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 6 2
    glColor3f(0.556, 0.556, 0.556);
    glVertex3f(280, 150, -240.1);
    glVertex3f(300, 150, -240.1);
    glVertex3f(300, 320, -240.1);
    glVertex3f(280, 320, -240.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 6 3
    glColor3f(0.556, 0.556, 0.556);
    glVertex3f(220, 150, -240.1);
    glVertex3f(250, 150, -240.1);
    glVertex3f(250, 320, -240.1);
    glVertex3f(220, 320, -240.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 6 4
    glColor3f(0.356, 0.356, 0.356);
    glVertex3f(140, 150, -240.1);
    glVertex3f(160, 150, -240.1);
    glVertex3f(160, 320, -240.1);
    glVertex3f(140, 320, -240.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 6 5
    glColor3f(0.556, 0.556, 0.556);
    glVertex3f(50, 150, -240.1);
    glVertex3f(70, 150, -240.1);
    glVertex3f(70, 320, -240.1);
    glVertex3f(50, 320, -240.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 6 6
    glColor3f(0.556, 0.556, 0.556);
    glVertex3f(0, 150, -240.1);
    glVertex3f(20, 150, -240.1);
    glVertex3f(20, 320, -240.1);
    glVertex3f(0, 320, -240.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 6 7
    glColor3f(0.356, 0.356, 0.356);
    glVertex3f(-40, 150, -240.1);
    glVertex3f(-20, 150, -240.1);
    glVertex3f(-20, 320, -240.1);
    glVertex3f(-40, 320, -240.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 6 8
    glColor3f(0.356, 0.356, 0.356);
    glVertex3f(-100, 150, -240.1);
    glVertex3f(-80, 150, -240.1);
    glVertex3f(-80, 320, -240.1);
    glVertex3f(-100, 320, -240.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 7 1
    glColor3f(0.356, 0.356, 0.356);
    glVertex3f(300, 10, -240.1);
    glVertex3f(320, 10, -240.1);
    glVertex3f(320, 140, -240.1);
    glVertex3f(300, 140, -240.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 7 2
    glColor3f(0.356, 0.356, 0.356);
    glVertex3f(260, 10, -240.1);
    glVertex3f(280, 10, -240.1);
    glVertex3f(280, 140, -240.1);
    glVertex3f(260, 140, -240.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 7 3
    glColor3f(0.556, 0.556, 0.556);
    glVertex3f(180, 10, -240.1);
    glVertex3f(200, 10, -240.1);
    glVertex3f(200, 140, -240.1);
    glVertex3f(180, 140, -240.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 7 4
    glColor3f(0.556, 0.556, 0.556);
    glVertex3f(90, 10, -240.1);
    glVertex3f(120, 10, -240.1);
    glVertex3f(120, 140, -240.1);
    glVertex3f(90, 140, -240.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 7 5
    glColor3f(0.356, 0.356, 0.356);
    glVertex3f(40, 10, -240.1);
    glVertex3f(70, 10, -240.1);
    glVertex3f(70, 140, -240.1);
    glVertex3f(40, 140, -240.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 7 6
    glColor3f(0.356, 0.356, 0.356);
    glVertex3f(0, 10, -240.1);
    glVertex3f(20, 10, -240.1);
    glVertex3f(20, 140, -240.1);
    glVertex3f(0, 140, -240.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 7 7
    glColor3f(0.356, 0.356, 0.356);
    glVertex3f(-70, 10, -240.1);
    glVertex3f(-50, 10, -240.1);
    glVertex3f(-50, 140, -240.1);
    glVertex3f(-70, 140, -240.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 7 8
    glColor3f(0.556, 0.556, 0.556);
    glVertex3f(-130, 10, -240.1);
    glVertex3f(-110, 10, -240.1);
    glVertex3f(-110, 140, -240.1);
    glVertex3f(-130, 140, -240.1);
    glEnd();

    //hiasan atau aksen gedung tinggi 2 samping 1 tanpa biru

    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 8 1
    glColor3f(0.356, 0.356, 0.356);
    glVertex3f(300.1, 950, -210.1);
    glVertex3f(300.1, 950, -230.1);
    glVertex3f(300.1, 1050, -230.1);
    glVertex3f(300.1, 1050, -210.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 8 2
    glColor3f(0.556, 0.556, 0.556);
    glVertex3f(300.1, 950, -170.1);
    glVertex3f(300.1, 950, -190.1);
    glVertex3f(300.1, 1050, -190.1);
    glVertex3f(300.1, 1050, -170.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 8 3
    glColor3f(0.356, 0.356, 0.356);
    glVertex3f(300.1, 950, -140.1);
    glVertex3f(300.1, 950, -155.1);
    glVertex3f(300.1, 1050, -155.1);
    glVertex3f(300.1, 1050, -140.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 8 4
    glColor3f(0.356, 0.356, 0.356);
    glVertex3f(300.1, 950, -90.1);
    glVertex3f(300.1, 950, -120.1);
    glVertex3f(300.1, 1050, -120.1);
    glVertex3f(300.1, 1050, -90.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 9 1
    glColor3f(0.556, 0.556, 0.556);
    glVertex3f(300.1, 730, -215.1);
    glVertex3f(300.1, 730, -235.1);
    glVertex3f(300.1, 940, -235.1);
    glVertex3f(300.1, 940, -215.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 9 2
    glColor3f(0.556, 0.556, 0.556);
    glVertex3f(300.1, 730, -170.1);
    glVertex3f(300.1, 730, -195.1);
    glVertex3f(300.1, 940, -195.1);
    glVertex3f(300.1, 940, -170.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 9 3
    glColor3f(0.356, 0.356, 0.356);
    glVertex3f(300.1, 730, -130.1);
    glVertex3f(300.1, 730, -155.1);
    glVertex3f(300.1, 940, -155.1);
    glVertex3f(300.1, 940, -130.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 9 4
    glColor3f(0.356, 0.356, 0.356);
    glVertex3f(300.1, 730, -75.1);
    glVertex3f(300.1, 730, -105.1);
    glVertex3f(300.1, 940, -105.1);
    glVertex3f(300.1, 940, -75.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 10 1
    glColor3f(0.556, 0.556, 0.556);
    glVertex3f(300.1, 540, -205.1);
    glVertex3f(300.1, 540, -230.1);
    glVertex3f(300.1, 720, -230.1);
    glVertex3f(300.1, 720, -205.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 10 2
    glColor3f(0.356, 0.356, 0.356);
    glVertex3f(300.1, 540, -160.1);
    glVertex3f(300.1, 540, -185.1);
    glVertex3f(300.1, 720, -185.1);
    glVertex3f(300.1, 720, -160.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 10 3
    glColor3f(0.556, 0.556, 0.556);
    glVertex3f(300.1, 540, -120.1);
    glVertex3f(300.1, 540, -140.1);
    glVertex3f(300.1, 720, -140.1);
    glVertex3f(300.1, 720, -120.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 10 4
    glColor3f(0.556, 0.556, 0.556);
    glVertex3f(300.1, 540, -70.1);
    glVertex3f(300.1, 540, -100.1);
    glVertex3f(300.1, 720, -100.1);
    glVertex3f(300.1, 720, -70.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 11 1
    glColor3f(0.356, 0.356, 0.356);
    glVertex3f(300.1, 340, -210.1);
    glVertex3f(300.1, 340, -238.1);
    glVertex3f(300.1, 530, -238.1);
    glVertex3f(300.1, 530, -210.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 11 2
    glColor3f(0.356, 0.356, 0.356);
    glVertex3f(300.1, 340, -175.1);
    glVertex3f(300.1, 340, -193.1);
    glVertex3f(300.1, 530, -193.1);
    glVertex3f(300.1, 530, -175.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 11 3
    glColor3f(0.556, 0.556, 0.556);
    glVertex3f(300.1, 340, -130.1);
    glVertex3f(300.1, 340, -155.1);
    glVertex3f(300.1, 530, -155.1);
    glVertex3f(300.1, 530, -130.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 11 4
    glColor3f(0.356, 0.356, 0.356);
    glVertex3f(300.1, 340, -80.1);
    glVertex3f(300.1, 340, -105.1);
    glVertex3f(300.1, 530, -105.1);
    glVertex3f(300.1, 530, -80.1);
    glEnd();

    //hiasan atau aksen gedung tinggi 2 samping 1 ada biru

    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 12 1
    glColor3f(0.556, 0.556, 0.556);
    glVertex3f(-150.1, 950, -208.1);
    glVertex3f(-150.1, 950, -235.1);
    glVertex3f(-150.1, 1050, -235.1);
    glVertex3f(-150.1, 1050, -208.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 12 2
    glColor3f(0.556, 0.556, 0.556);
    glVertex3f(-150.1, 950, -165.1);
    glVertex3f(-150.1, 950, -188.1);
    glVertex3f(-150.1, 1050, -188.1);
    glVertex3f(-150.1, 1050, -165.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 12 3
    glColor3f(0.356, 0.356, 0.356);
    glVertex3f(-150.1, 950, -100.1);
    glVertex3f(-150.1, 950, -130.1);
    glVertex3f(-150.1, 1050, -130.1);
    glVertex3f(-150.1, 1050, -100.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 12 4
    glColor3f(0.556, 0.556, 0.556);
    glVertex3f(-150.1, 730, -103.1);
    glVertex3f(-150.1, 730, -130.1);
    glVertex3f(-150.1, 940, -130.1);
    glVertex3f(-150.1, 940, -103.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 12 5
    glColor3f(0.356, 0.356, 0.356);
    glVertex3f(-150.1, 730, -70.1);
    glVertex3f(-150.1, 730, -90.1);
    glVertex3f(-150.1, 940, -90.1);
    glVertex3f(-150.1, 940, -70.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 13 1
    glColor3f(0.556, 0.556, 0.556);
    glVertex3f(-150.1, 540, -190.1);
    glVertex3f(-150.1, 540, -220.1);
    glVertex3f(-150.1, 720, -220.1);
    glVertex3f(-150.1, 720, -190.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 13 2
    glColor3f(0.356, 0.356, 0.356);
    glVertex3f(-150.1, 540, -140.1);
    glVertex3f(-150.1, 540, -170.1);
    glVertex3f(-150.1, 720, -170.1);
    glVertex3f(-150.1, 720, -140.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 13 3
    glColor3f(0.356, 0.356, 0.356);
    glVertex3f(-150.1, 540, -97.1);
    glVertex3f(-150.1, 540, -120.1);
    glVertex3f(-150.1, 720, -120.1);
    glVertex3f(-150.1, 720, -97.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 13 4
    glColor3f(0.556, 0.556, 0.556);
    glVertex3f(-150.1, 540, -60.1);
    glVertex3f(-150.1, 540, -80.1);
    glVertex3f(-150.1, 720, -80.1);
    glVertex3f(-150.1, 720, -60.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 13 5
    glColor3f(0.556, 0.556, 0.556);
    glVertex3f(-150.1, 540, -220);
    glVertex3f(-150.1, 540, -240);
    glVertex3f(-150.1, 720, -240);
    glVertex3f(-150.1, 720, -220);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 14 1
    glColor3f(0.356, 0.356, 0.356);
    glVertex3f(-150.1, 340, -200.1);
    glVertex3f(-150.1, 340, -230.1);
    glVertex3f(-150.1, 530, -230.1);
    glVertex3f(-150.1, 530, -200.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 14 2
    glColor3f(0.556, 0.556, 0.556);
    glVertex3f(-150.1, 340, -150.1);
    glVertex3f(-150.1, 340, -182.1);
    glVertex3f(-150.1, 530, -182.1);
    glVertex3f(-150.1, 530, -150.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 14 3
    glColor3f(0.356, 0.356, 0.356);
    glVertex3f(-150.1, 340, -100.1);
    glVertex3f(-150.1, 340, -130.1);
    glVertex3f(-150.1, 530, -130.1);
    glVertex3f(-150.1, 530, -100.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasan atau aksen gedung tinggi 14 4
    glColor3f(0.556, 0.556, 0.556);
    glVertex3f(-150.1, 340, -65.1);
    glVertex3f(-150.1, 340, -90.1);
    glVertex3f(-150.1, 530, -90.1);
    glVertex3f(-150.1, 530, -65.1);
    glEnd();

    //hiasan atau aksen bangunan bawah

    glBegin(GL_POLYGON);//garis horizontal tengah bangunan bawah2
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(23.558, 145, 160.1);
    glVertex3f(360, 145, 160.1);
    glVertex3f(360, 155, 160.1);
    glVertex3f(22.8, 155, 160.1);
    glEnd();
    glBegin(GL_POLYGON);//garis horizontal atas bangunan bawah2
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(15.6, 260, 160.1);
    glVertex3f(360, 260, 160.1);
    glVertex3f(360, 270, 160.1);
    glVertex3f(15, 270, 160.1);
    glEnd();
    glBegin(GL_POLYGON);//garis horizontal bawah bangunan bawah2
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(30, 51, 160.1);
    glVertex3f(360, 51, 160.1);
    glVertex3f(360, 61, 160.1);
    glVertex3f(29.3, 61, 160.1);
    glEnd();
    glBegin(GL_POLYGON);//garis lantai atas kiri bangunan bawah2
    glColor3f(1, 1, 1);
    glVertex3f(30, 150, 160.2);
    glVertex3f(45, 150, 160.2);
    glVertex3f(45, 270, 160.2);
    glVertex3f(30, 270, 160.2);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(65, 150, 160.2);
    glVertex3f(80, 150, 160.2);
    glVertex3f(80, 270, 160.2);
    glVertex3f(65, 270, 160.2);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(110, 150, 160.2);
    glVertex3f(130, 150, 160.2);
    glVertex3f(130, 270, 160.2);
    glVertex3f(110, 270, 160.2);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(145, 150, 160.2);
    glVertex3f(160, 150, 160.2);
    glVertex3f(160, 270, 160.2);
    glVertex3f(145, 270, 160.2);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(190, 150, 160.2);
    glVertex3f(200, 150, 160.2);
    glVertex3f(200, 270, 160.2);
    glVertex3f(190, 270, 160.2);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(225, 150, 160.2);
    glVertex3f(245, 150, 160.2);
    glVertex3f(245, 270, 160.2);
    glVertex3f(225, 270, 160.2);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(270, 150, 160.2);
    glVertex3f(285, 150, 160.2);
    glVertex3f(285, 270, 160.2);
    glVertex3f(270, 270, 160.2);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(305, 150, 160.2);
    glVertex3f(320, 150, 160.2);
    glVertex3f(320, 270, 160.2);
    glVertex3f(305, 270, 160.2);
    glEnd();
    glBegin(GL_POLYGON);//garis lantai atas kanan bangunan bawah2
    glColor3f(1, 1, 1);
    glVertex3f(345, 150, 160.2);
    glVertex3f(360, 150, 160.2);
    glVertex3f(360, 270, 160.2);
    glVertex3f(345, 270, 160.2);
    glEnd();
    glBegin(GL_POLYGON);//garis lantai bawah kiri bangunan bawah2
    glColor3f(1, 1, 1);
    glVertex3f(30, 51, 160.2);
    glVertex3f(45, 51, 160.2);
    glVertex3f(45, 150, 160.2);
    glVertex3f(30, 150, 160.2);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(80, 51, 160.2);
    glVertex3f(95, 51, 160.2);
    glVertex3f(95, 150, 160.2);
    glVertex3f(80, 150, 160.2);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(110, 51, 160.2);
    glVertex3f(130, 51, 160.2);
    glVertex3f(130, 150, 160.2);
    glVertex3f(110, 150, 160.2);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(160, 51, 160.2);
    glVertex3f(180, 51, 160.2);
    glVertex3f(180, 150, 160.2);
    glVertex3f(160, 150, 160.2);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(200, 51, 160.2);
    glVertex3f(215, 51, 160.2);
    glVertex3f(215, 150, 160.2);
    glVertex3f(200, 150, 160.2);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(245, 51, 160.2);
    glVertex3f(260, 51, 160.2);
    glVertex3f(260, 150, 160.2);
    glVertex3f(245, 150, 160.2);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(280, 51, 160.2);
    glVertex3f(295, 51, 160.2);
    glVertex3f(295, 150, 160.2);
    glVertex3f(280, 150, 160.2);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(320, 51, 160.2);
    glVertex3f(335, 51, 160.2);
    glVertex3f(335, 150, 160.2);
    glVertex3f(320, 150, 160.2);
    glEnd();
    glBegin(GL_POLYGON);//garis lantai bawah kanan bangunan bawah2
    glColor3f(1, 1, 1);
    glVertex3f(345, 51, 160.2);
    glVertex3f(360, 51, 160.2);
    glVertex3f(360, 150, 160.2);
    glVertex3f(345, 150, 160.2);
    glEnd();

    glBegin(GL_POLYGON);//garis horizontal belakang tengah bangunan bawah2
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(23.558, 145, -160.1);
    glVertex3f(360, 145, -160.1);
    glVertex3f(360, 155, -160.1);
    glVertex3f(22.8, 155, -160.1);
    glEnd();
    glBegin(GL_POLYGON);//garis horizontal belakang atas bangunan bawah2
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(15.6, 260, -160.1);
    glVertex3f(360, 260, -160.1);
    glVertex3f(360, 270, -160.1);
    glVertex3f(15, 270, -160.1);
    glEnd();
    glBegin(GL_POLYGON);//garis horizontal belakang bawah bangunan bawah2
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(30, 51, -160.1);
    glVertex3f(360, 51, -160.1);
    glVertex3f(360, 61, -160.1);
    glVertex3f(29.3, 61, -160.1);
    glEnd();
    glBegin(GL_POLYGON);//garis lantai atas kiri bangunan bawah2
    glColor3f(1, 1, 1);
    glVertex3f(30, 150, -160.2);
    glVertex3f(45, 150, -160.2);
    glVertex3f(45, 270, -160.2);
    glVertex3f(30, 270, -160.2);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(65, 150, -160.2);
    glVertex3f(80, 150, -160.2);
    glVertex3f(80, 270, -160.2);
    glVertex3f(65, 270, -160.2);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(110, 150, -160.2);
    glVertex3f(130, 150, -160.2);
    glVertex3f(130, 270, -160.2);
    glVertex3f(110, 270, -160.2);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(145, 150, -160.2);
    glVertex3f(160, 150, -160.2);
    glVertex3f(160, 270, -160.2);
    glVertex3f(145, 270, -160.2);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(190, 150, -160.2);
    glVertex3f(200, 150, -160.2);
    glVertex3f(200, 270, -160.2);
    glVertex3f(190, 270, -160.2);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(225, 150, -160.2);
    glVertex3f(245, 150, -160.2);
    glVertex3f(245, 270, -160.2);
    glVertex3f(225, 270, -160.2);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(270, 150, -160.2);
    glVertex3f(285, 150, -160.2);
    glVertex3f(285, 270, -160.2);
    glVertex3f(270, 270, -160.2);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(305, 150, -160.2);
    glVertex3f(320, 150, -160.2);
    glVertex3f(320, 270, -160.2);
    glVertex3f(305, 270, -160.2);
    glEnd();
    glBegin(GL_POLYGON);//garis lantai atas kanan bangunan bawah2
    glColor3f(1, 1, 1);
    glVertex3f(345, 150, -160.2);
    glVertex3f(360, 150, -160.2);
    glVertex3f(360, 270, -160.2);
    glVertex3f(345, 270, -160.2);
    glEnd();
    glBegin(GL_POLYGON);//garis lantai bawah kiri bangunan bawah2
    glColor3f(1, 1, 1);
    glVertex3f(30, 51, -160.2);
    glVertex3f(45, 51, -160.2);
    glVertex3f(45, 150, -160.2);
    glVertex3f(30, 150, -160.2);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(80, 51, -160.2);
    glVertex3f(95, 51, -160.2);
    glVertex3f(95, 150, -160.2);
    glVertex3f(80, 150, -160.2);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(110, 51, -160.2);
    glVertex3f(130, 51, -160.2);
    glVertex3f(130, 150, -160.2);
    glVertex3f(110, 150, -160.2);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(160, 51, -160.2);
    glVertex3f(180, 51, -160.2);
    glVertex3f(180, 150, -160.2);
    glVertex3f(160, 150, -160.2);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(200, 51, -160.2);
    glVertex3f(215, 51, -160.2);
    glVertex3f(215, 150, -160.2);
    glVertex3f(200, 150, -160.2);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(245, 51, -160.2);
    glVertex3f(260, 51, -160.2);
    glVertex3f(260, 150, -160.2);
    glVertex3f(245, 150, -160.2);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(280, 51, -160.2);
    glVertex3f(295, 51, -160.2);
    glVertex3f(295, 150, -160.2);
    glVertex3f(280, 150, -160.2);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(320, 51, -160.2);
    glVertex3f(335, 51, -160.2);
    glVertex3f(335, 150, -160.2);
    glVertex3f(320, 150, -160.2);
    glEnd();
    glBegin(GL_POLYGON);//garis lantai bawah kanan bangunan bawah2
    glColor3f(1, 1, 1);
    glVertex3f(345, 51, -160.2);
    glVertex3f(360, 51, -160.2);
    glVertex3f(360, 150, -160.2);
    glVertex3f(345, 150, -160.2);
    glEnd();

    glBegin(GL_POLYGON);//garis horizontal kanan tengah bangunan bawah2
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(360.1, 145, 160);
    glVertex3f(360.1, 145, -160);
    glVertex3f(360.1, 155, -160);
    glVertex3f(360.1, 155, 160);
    glEnd();
    glBegin(GL_POLYGON);//garis horizontal kanan bawah bangunan bawah2
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(360.1, 51, 160);
    glVertex3f(360.1, 51, -160);
    glVertex3f(360.1, 61, -160);
    glVertex3f(360.1, 61, 160);
    glEnd();
    glBegin(GL_POLYGON);//garis horizontal kanan atas bangunan bawah2
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(360.1, 260, 160);
    glVertex3f(360.1, 260, -160);
    glVertex3f(360.1, 270, -160);
    glVertex3f(360.1, 270, 160);
    glEnd();
    glBegin(GL_POLYGON);//garis lantai atas kiri bangunan bawah2
    glColor3f(1, 1, 1);
    glVertex3f(360.2, 150, 160);
    glVertex3f(360.2, 150, 145);
    glVertex3f(360.2, 270, 145);
    glVertex3f(360.2, 270, 160);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(360.2, 150, 125);
    glVertex3f(360.2, 150, 110);
    glVertex3f(360.2, 270, 110);
    glVertex3f(360.2, 270, 125);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(360.2, 150, 80);
    glVertex3f(360.2, 150, 60);
    glVertex3f(360.2, 270, 60);
    glVertex3f(360.2, 270, 80);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(360.2, 150, 40);
    glVertex3f(360.2, 150, 30);
    glVertex3f(360.2, 270, 30);
    glVertex3f(360.2, 270, 40);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(360.2, 150, 0);
    glVertex3f(360.2, 150, -15);
    glVertex3f(360.2, 270, -15);
    glVertex3f(360.2, 270, 0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(360.2, 150, -35);
    glVertex3f(360.2, 150, -50);
    glVertex3f(360.2, 270, -50);
    glVertex3f(360.2, 270, -35);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(360.2, 150, -80);
    glVertex3f(360.2, 150, -95);
    glVertex3f(360.2, 270, -95);
    glVertex3f(360.2, 270, -80);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(360.2, 150, -115);
    glVertex3f(360.2, 150, -130);
    glVertex3f(360.2, 270, -130);
    glVertex3f(360.2, 270, -115);
    glEnd();
    glBegin(GL_POLYGON);//garis lantai atas kanan bangunan bawah2
    glColor3f(1, 1, 1);
    glVertex3f(360.2, 150, -150);
    glVertex3f(360.2, 150, -160);
    glVertex3f(360.2, 270, -160);
    glVertex3f(360.2, 270, -150);
    glEnd();
    glBegin(GL_POLYGON);//garis lantai atas kiri bangunan bawah2
    glColor3f(1, 1, 1);
    glVertex3f(360.2, 51, 160);
    glVertex3f(360.2, 51, 145);
    glVertex3f(360.2, 150, 145);
    glVertex3f(360.2, 150, 160);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(360.2, 51, 110);
    glVertex3f(360.2, 51, 100);
    glVertex3f(360.2, 150, 100);
    glVertex3f(360.2, 150, 110);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(360.2, 51, 80);
    glVertex3f(360.2, 51, 55);
    glVertex3f(360.2, 150, 55);
    glVertex3f(360.2, 150, 80);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(360.2, 51, 30);
    glVertex3f(360.2, 51, 10);
    glVertex3f(360.2, 150, 10);
    glVertex3f(360.2, 150, 30);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(360.2, 51, -5);
    glVertex3f(360.2, 51, -25);
    glVertex3f(360.2, 150, -25);
    glVertex3f(360.2, 150, -5);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(360.2, 51, -35);
    glVertex3f(360.2, 51, -50);
    glVertex3f(360.2, 150, -50);
    glVertex3f(360.2, 150, -35);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(360.2, 51, -60);
    glVertex3f(360.2, 51, -80);
    glVertex3f(360.2, 150, -80);
    glVertex3f(360.2, 150, -60);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(360.2, 51, -100);
    glVertex3f(360.2, 51, -115);
    glVertex3f(360.2, 150, -115);
    glVertex3f(360.2, 150, -100);
    glEnd();
    glBegin(GL_POLYGON);//garis lantai atas kanan bangunan bawah2
    glColor3f(1, 1, 1);
    glVertex3f(360.2, 51, -150);
    glVertex3f(360.2, 51, -160);
    glVertex3f(360.2, 150, -160);
    glVertex3f(360.2, 150, -150);
    glEnd();

    glBegin(GL_POLYGON);//hiasasn hitam depan atas 1
    //sumbu z tetap = 160.1
    glColor3f(1, 1, 1);
    glVertex3f(-60, 150, 160.1);
    glVertex3f(-40, 150, 160.1);
    glVertex3f(-40, 250, 160.1);
    glVertex3f(-60, 250, 160.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasasn hitam depan bawah 1
   //sumbu z tetap = 160.1
    glColor3f(1, 1, 1);
    glVertex3f(-80, 50, 160.1);
    glVertex3f(-60, 50, 160.1);
    glVertex3f(-60, 150, 160.1);
    glVertex3f(-80, 150, 160.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasasn hitam depan atas 2
    //sumbu z tetap = 160.1
    glColor3f(1, 1, 1);
    glVertex3f(-100, 150, 160.1);
    glVertex3f(-80, 150, 160.1);
    glVertex3f(-80, 250, 160.1);
    glVertex3f(-100, 250, 160.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasasn hitam depan bawah 2
    //sumbu z tetap = 160.1
    glColor3f(1, 1, 1);
    glVertex3f(-120, 50, 160.1);
    glVertex3f(-100, 50, 160.1);
    glVertex3f(-100, 150, 160.1);
    glVertex3f(-120, 150, 160.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasasn hitam depan atas 3
    //sumbu z tetap = 160.1
    glColor3f(1, 1, 1);
    glVertex3f(-140, 150, 160.1);
    glVertex3f(-120, 150, 160.1);
    glVertex3f(-120, 250, 160.1);
    glVertex3f(-140, 250, 160.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasasn hitam depan bawah 3
    //sumbu z tetap = 160.1
    glColor3f(1, 1, 1);
    glVertex3f(-160, 50, 160.1);
    glVertex3f(-140, 50, 160.1);
    glVertex3f(-140, 150, 160.1);
    glVertex3f(-160, 150, 160.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasasn hitam depan atas 4
    //sumbu z tetap = 160.1
    glColor3f(1, 1, 1);
    glVertex3f(-180, 150, 160.1);
    glVertex3f(-160, 150, 160.1);
    glVertex3f(-160, 250, 160.1);
    glVertex3f(-180, 250, 160.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasasn hitam depan bawah 4
    //sumbu z tetap = 160.1
    glColor3f(1, 1, 1);
    glVertex3f(-200, 50, 160.1);
    glVertex3f(-180, 50, 160.1);
    glVertex3f(-180, 150, 160.1);
    glVertex3f(-200, 150, 160.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasasn hitam depan atas 5
    //sumbu z tetap = 160.1
    glColor3f(1, 1, 1);
    glVertex3f(-220, 150, 160.1);
    glVertex3f(-200, 150, 160.1);
    glVertex3f(-200, 250, 160.1);
    glVertex3f(-220, 250, 160.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasasn hitam depan bawah 5
    //sumbu z tetap = 160.1
    glColor3f(1, 1, 1);
    glVertex3f(-240, 50, 160.1);
    glVertex3f(-220, 50, 160.1);
    glVertex3f(-220, 150, 160.1);
    glVertex3f(-240, 150, 160.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasasn hitam depan atas 6
    //sumbu z tetap = 160.1
    glColor3f(1, 1, 1);
    glVertex3f(-260, 150, 160.1);
    glVertex3f(-240, 150, 160.1);
    glVertex3f(-240, 250, 160.1);
    glVertex3f(-260, 250, 160.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasasn hitam depan bawah 6
    //sumbu z tetap = 160.1
    glColor3f(1, 1, 1);
    glVertex3f(-280, 50, 160.1);
    glVertex3f(-260, 50, 160.1);
    glVertex3f(-260, 150, 160.1);
    glVertex3f(-280, 150, 160.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasasn hitam depan atas 7
    //sumbu z tetap = 160.1
    glColor3f(1, 1, 1);
    glVertex3f(-300, 150, 160.1);
    glVertex3f(-280, 150, 160.1);
    glVertex3f(-280, 250, 160.1);
    glVertex3f(-300, 250, 160.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasasn hitam depan bawah 7
    //sumbu z tetap = 160.1
    glColor3f(1, 1, 1);
    glVertex3f(-320, 50, 160.1);
    glVertex3f(-300, 50, 160.1);
    glVertex3f(-300, 150, 160.1);
    glVertex3f(-320, 150, 160.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasasn hitam depan atas 8
    //sumbu z tetap = 160.1
    glColor3f(1, 1, 1);
    glVertex3f(-340, 150, 160.1);
    glVertex3f(-320, 150, 160.1);
    glVertex3f(-320, 250, 160.1);
    glVertex3f(-340, 250, 160.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasasn hitam depan bawah 8
    //sumbu z tetap = 160.1
    glColor3f(1, 1, 1);
    glVertex3f(-360, 50, 160.1);
    glVertex3f(-340, 50, 160.1);
    glVertex3f(-340, 150, 160.1);
    glVertex3f(-360, 150, 160.1);
    glEnd();

    glBegin(GL_POLYGON);//hiasasn hitam belakang atas 1
    //sumbu z tetap = 160.1
    glColor3f(1, 1, 1);
    glVertex3f(-60, 150, -160.1);
    glVertex3f(-40, 150, -160.1);
    glVertex3f(-40, 250, -160.1);
    glVertex3f(-60, 250, -160.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasasn hitam belakang bawah 1
   //sumbu z tetap = 160.1
    glColor3f(1, 1, 1);
    glVertex3f(-80, 50, -160.1);
    glVertex3f(-60, 50, -160.1);
    glVertex3f(-60, 150, -160.1);
    glVertex3f(-80, 150, -160.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasasn hitam belakang atas 2
    //sumbu z tetap = 160.1
    glColor3f(1, 1, 1);
    glVertex3f(-100, 150, -160.1);
    glVertex3f(-80, 150, -160.1);
    glVertex3f(-80, 250, -160.1);
    glVertex3f(-100, 250, -160.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasasn hitam belakang bawah 2
    //sumbu z tetap = 160.1
    glColor3f(1, 1, 1);
    glVertex3f(-120, 50, -160.1);
    glVertex3f(-100, 50, -160.1);
    glVertex3f(-100, 150, -160.1);
    glVertex3f(-120, 150, -160.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasasn hitam belakang atas 3
    //sumbu z tetap = 160.1
    glColor3f(1, 1, 1);
    glVertex3f(-140, 150, -160.1);
    glVertex3f(-120, 150, -160.1);
    glVertex3f(-120, 250, -160.1);
    glVertex3f(-140, 250, -160.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasasn hitam belakang bawah 3
    //sumbu z tetap = 160.1
    glColor3f(1, 1, 1);
    glVertex3f(-160, 50, -160.1);
    glVertex3f(-140, 50, -160.1);
    glVertex3f(-140, 150, -160.1);
    glVertex3f(-160, 150, -160.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasasn hitam belakang atas 4
    //sumbu z tetap = 160.1
    glColor3f(1, 1, 1);
    glVertex3f(-180, 150, -160.1);
    glVertex3f(-160, 150, -160.1);
    glVertex3f(-160, 250, -160.1);
    glVertex3f(-180, 250, -160.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasasn hitam belakang bawah 4
    //sumbu z tetap = 160.1
    glColor3f(1, 1, 1);
    glVertex3f(-200, 50, -160.1);
    glVertex3f(-180, 50, -160.1);
    glVertex3f(-180, 150, -160.1);
    glVertex3f(-200, 150, -160.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasasn hitam belakang atas 5
    //sumbu z tetap = 160.1
    glColor3f(1, 1, 1);
    glVertex3f(-220, 150, -160.1);
    glVertex3f(-200, 150, -160.1);
    glVertex3f(-200, 250, -160.1);
    glVertex3f(-220, 250, -160.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasasn hitam belakang bawah 5
    //sumbu z tetap = 160.1
    glColor3f(1, 1, 1);
    glVertex3f(-240, 50, -160.1);
    glVertex3f(-220, 50, -160.1);
    glVertex3f(-220, 150, -160.1);
    glVertex3f(-240, 150, -160.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasasn hitam belakang atas 6
    //sumbu z tetap = 160.1
    glColor3f(1, 1, 1);
    glVertex3f(-260, 150, -160.1);
    glVertex3f(-240, 150, -160.1);
    glVertex3f(-240, 250, -160.1);
    glVertex3f(-260, 250, -160.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasasn hitam belakang bawah 6
    //sumbu z tetap = 160.1
    glColor3f(1, 1, 1);
    glVertex3f(-280, 50, -160.1);
    glVertex3f(-260, 50, -160.1);
    glVertex3f(-260, 150, -160.1);
    glVertex3f(-280, 150, -160.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasasn hitam belakang atas 7
    //sumbu z tetap = 160.1
    glColor3f(1, 1, 1);
    glVertex3f(-300, 150, -160.1);
    glVertex3f(-280, 150, -160.1);
    glVertex3f(-280, 250, -160.1);
    glVertex3f(-300, 250, -160.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasasn hitam belakang bawah 7
    //sumbu z tetap = 160.1
    glColor3f(1, 1, 1);
    glVertex3f(-320, 50, -160.1);
    glVertex3f(-300, 50, -160.1);
    glVertex3f(-300, 150, -160.1);
    glVertex3f(-320, 150, -160.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasasn hitam belakang atas 8
    //sumbu z tetap = 160.1
    glColor3f(1, 1, 1);
    glVertex3f(-340, 150, -160.1);
    glVertex3f(-320, 150, -160.1);
    glVertex3f(-320, 250, -160.1);
    glVertex3f(-340, 250, -160.1);
    glEnd();
    glBegin(GL_POLYGON);//hiasasn hitam belakang bawah 8
    //sumbu z tetap = 160.1
    glColor3f(1, 1, 1);
    glVertex3f(-360, 50, -160.1);
    glVertex3f(-340, 50, -160.1);
    glVertex3f(-340, 150, -160.1);
    glVertex3f(-360, 150, -160.1);
    glEnd();

    //isi dalam bangunan bawah

    //karpet merah
    glBegin(GL_POLYGON);//karpet merah 1
    glColor3f(0.8, 0, 0);
    glVertex3f(-300, 51.1, 60);
    glVertex3f(-80, 51.1, 60);
    glVertex3f(-80, 51.1, -60);
    glVertex3f(-300, 51.1, -60);
    glEnd();
    glBegin(GL_POLYGON);//karpet merah 2
    glColor3f(0.8, 0, 0);
    glVertex3f(300, 51.1, 60);
    glVertex3f(80, 51.1, 60);
    glVertex3f(80, 51.1, -60);
    glVertex3f(300, 51.1, -60);
    glEnd();

    //mount tv
    glBegin(GL_POLYGON);//mount tv 1
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(-300, 249.9, -10);
    glVertex3f(-290, 249.9, -10);
    glVertex3f(-290, 249.9, 0);
    glVertex3f(-300, 249.9, 0);
    glEnd();
    glBegin(GL_POLYGON);//mount tv 2
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(-300, 180, -10);
    glVertex3f(-270, 180, -10);
    glVertex3f(-270, 180, 0);
    glVertex3f(-300, 180, 0);
    glEnd();
    glBegin(GL_POLYGON);//mount tv 3
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(-300, 249.9, -10);
    glVertex3f(-300, 180, -10);
    glVertex3f(-300, 180, 0);
    glVertex3f(-300, 249.9, 0);
    glEnd();
    glBegin(GL_POLYGON);//mount tv 4
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(-290, 249.9, -10);
    glVertex3f(-290, 180, -10);
    glVertex3f(-290, 180, 0);
    glVertex3f(-290, 249.9, 0);
    glEnd();
    glBegin(GL_POLYGON);//mount tv 5
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(-290, 249.9, -10);
    glVertex3f(-300, 180, -10);
    glVertex3f(-300, 180, -10);
    glVertex3f(-290, 249.9, -10);
    glEnd();
    glBegin(GL_POLYGON);//mount tv 6
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(-290, 249.9, 0);
    glVertex3f(-300, 180, 0);
    glVertex3f(-300, 180, 0);
    glVertex3f(-290, 249.9, 0);
    glEnd();
    glBegin(GL_POLYGON);//mount tv 7
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(-300, 190, -10);
    glVertex3f(-270, 190, -10);
    glVertex3f(-270, 190, 0);
    glVertex3f(-300, 190, 0);
    glEnd();
    glBegin(GL_POLYGON);//mount tv 8
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(-300, 180, 0);
    glVertex3f(-270, 180, 0);
    glVertex3f(-270, 190, 0);
    glVertex3f(-300, 190, 0);
    glEnd();
    glBegin(GL_POLYGON);//mount tv 9
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(-300, 180, -10);
    glVertex3f(-270, 180, -10);
    glVertex3f(-270, 190, -10);
    glVertex3f(-300, 190, -10);
    glEnd();

    //tv
    glBegin(GL_POLYGON);//tv 1
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(-270, 140, -40);
    glVertex3f(-270, 140, 30);
    glVertex3f(-270, 200, 30);
    glVertex3f(-270, 200, -40);
    glEnd();
    glBegin(GL_POLYGON);//tv 2
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(-268, 140, -40);
    glVertex3f(-268, 140, 30);
    glVertex3f(-268, 200, 30);
    glVertex3f(-268, 200, -40);
    glEnd();
    glBegin(GL_POLYGON);//tv 3
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(-268, 140, 30);
    glVertex3f(-270, 140, 30);
    glVertex3f(-270, 200, 30);
    glVertex3f(-268, 200, 30);
    glEnd();
    glBegin(GL_POLYGON);//tv 4
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(-268, 140, -40);
    glVertex3f(-270, 140, -40);
    glVertex3f(-270, 200, -40);
    glVertex3f(-268, 200, -40);
    glEnd();
    glBegin(GL_POLYGON);//layar tv biru
    glColor3f(0, 0, 0.7);
    glVertex3f(-268.1, 142, -38);
    glVertex3f(-268.1, 142, 28);
    glVertex3f(-268.1, 198, 28);
    glVertex3f(-268.1, 198, -38);
    glEnd();

    //rak buku1
    glBegin(GL_POLYGON);//rak buku1 1
    glColor3f(0.3, 0.2, 0.2);
    glVertex3f(-230, 51.1, -130);
    glVertex3f(-170, 51.1, -130);
    glVertex3f(-170, 51.1, -159);
    glVertex3f(-230, 51.1, -159);
    glEnd();
    glBegin(GL_POLYGON);//rak buku1 2
    glColor3f(0.3, 0.2, 0.2);
    glVertex3f(-230, 150, -130);
    glVertex3f(-170, 150, -130);
    glVertex3f(-170, 150, -159);
    glVertex3f(-230, 150, -159);
    glEnd();
    glBegin(GL_POLYGON);//rak buku1 3
    glColor3f(0.3, 0.2, 0.2);
    glVertex3f(-230, 150, -130);
    glVertex3f(-230, 51.1, -130);
    glVertex3f(-230, 51.1, -159);
    glVertex3f(-230, 150, -159);
    glEnd();
    glBegin(GL_POLYGON);//rak buku1 4
    glColor3f(0.3, 0.2, 0.2);
    glVertex3f(-170, 150, -130);
    glVertex3f(-170, 51.1, -130);
    glVertex3f(-170, 51.1, -159);
    glVertex3f(-170, 150, -159);
    glEnd();
    glBegin(GL_POLYGON);//rak buku1 5
    glColor3f(0.488, 0.388, 0.388);
    glVertex3f(-230, 150, -159);
    glVertex3f(-230, 51.1, -159);
    glVertex3f(-170, 51.1, -159);
    glVertex3f(-170, 150, -159);
    glEnd();
    glBegin(GL_POLYGON);//rak buku1 lantai 2
    glColor3f(0.3, 0.2, 0.2);
    glVertex3f(-230, 75, -130);
    glVertex3f(-170, 75, -130);
    glVertex3f(-170, 75, -159);
    glVertex3f(-230, 75, -159);
    glEnd();
    glBegin(GL_POLYGON);//rak buku1 lantai 3
    glColor3f(0.3, 0.2, 0.2);
    glVertex3f(-230, 100, -130);
    glVertex3f(-170, 100, -130);
    glVertex3f(-170, 100, -159);
    glVertex3f(-230, 100, -159);
    glEnd();
    glBegin(GL_POLYGON);//rak buku1 lantai 4
    glColor3f(0.3, 0.2, 0.2);
    glVertex3f(-230, 125, -130);
    glVertex3f(-170, 125, -130);
    glVertex3f(-170, 125, -159);
    glVertex3f(-230, 125, -159);
    glEnd();

    //rak buku2
    glBegin(GL_POLYGON);//rak buku2 1
    glColor3f(0.3, 0.2, 0.2);
    glVertex3f(230, 51.1, -130);
    glVertex3f(170, 51.1, -130);
    glVertex3f(170, 51.1, -159);
    glVertex3f(230, 51.1, -159);
    glEnd();
    glBegin(GL_POLYGON);//rak buku2 2
    glColor3f(0.3, 0.2, 0.2);
    glVertex3f(230, 150, -130);
    glVertex3f(170, 150, -130);
    glVertex3f(170, 150, -159);
    glVertex3f(230, 150, -159);
    glEnd();
    glBegin(GL_POLYGON);//rak buku2 3
    glColor3f(0.3, 0.2, 0.2);
    glVertex3f(230, 150, -130);
    glVertex3f(230, 51.1, -130);
    glVertex3f(230, 51.1, -159);
    glVertex3f(230, 150, -159);
    glEnd();
    glBegin(GL_POLYGON);//rak buku2 4
    glColor3f(0.3, 0.2, 0.2);
    glVertex3f(170, 150, -130);
    glVertex3f(170, 51.1, -130);
    glVertex3f(170, 51.1, -159);
    glVertex3f(170, 150, -159);
    glEnd();
    glBegin(GL_POLYGON);//rak buku2 5
    glColor3f(0.488, 0.388, 0.388);
    glVertex3f(230, 150, -159);
    glVertex3f(230, 51.1, -159);
    glVertex3f(170, 51.1, -159);
    glVertex3f(170, 150, -159);
    glEnd();
    glBegin(GL_POLYGON);//rak buku2 lantai 2
    glColor3f(0.3, 0.2, 0.2);
    glVertex3f(230, 75, -130);
    glVertex3f(170, 75, -130);
    glVertex3f(170, 75, -159);
    glVertex3f(230, 75, -159);
    glEnd();
    glBegin(GL_POLYGON);//rak buku2 lantai 3
    glColor3f(0.3, 0.2, 0.2);
    glVertex3f(230, 100, -130);
    glVertex3f(170, 100, -130);
    glVertex3f(170, 100, -159);
    glVertex3f(230, 100, -159);
    glEnd();
    glBegin(GL_POLYGON);//rak buku2 lantai 4
    glColor3f(0.3, 0.2, 0.2);
    glVertex3f(230, 125, -130);
    glVertex3f(170, 125, -130);
    glVertex3f(170, 125, -159);
    glVertex3f(230, 125, -159);
    glEnd();

    //tempat sampah

    glBegin(GL_POLYGON);//tempat sampah 1
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(150, 51.1, -125);
    glVertex3f(130, 51.1, -125);
    glVertex3f(130, 51.1, -155);
    glVertex3f(150, 51.1, -155);
    glEnd();
    glBegin(GL_POLYGON);//tempat sampah 2
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(125, 80, -125);
    glVertex3f(130, 51.1, -125);
    glVertex3f(130, 51.1, -155);
    glVertex3f(125, 80, -155);
    glEnd();
    glBegin(GL_POLYGON);//tempat sampah 3
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(155, 80, -125);
    glVertex3f(150, 51.1, -125);
    glVertex3f(150, 51.1, -155);
    glVertex3f(155, 80, -155);
    glEnd();
    glBegin(GL_POLYGON);//tempat sampah 4
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(125, 80, -155);
    glVertex3f(130, 51.1, -155);
    glVertex3f(150, 51.1, -155);
    glVertex3f(155, 80, -155);
    glEnd();
    glBegin(GL_POLYGON);//tempat sampah 4
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(125, 80, -125);
    glVertex3f(130, 51.1, -125);
    glVertex3f(150, 51.1, -125);
    glVertex3f(155, 80, -125);
    glEnd();

    //meja

    //meja1
    glBegin(GL_POLYGON);//meja1 1
    glColor3f(0.3, 0.2, 0.2);
    glVertex3f(-210, 51.1, 5);
    glVertex3f(-210, 80, 5);
    glVertex3f(-210, 80, -5);
    glVertex3f(-210, 51.1, -5);
    glEnd();
    glBegin(GL_POLYGON);//meja1 2
    glColor3f(0.3, 0.2, 0.2);
    glVertex3f(-200, 51.1, 5);
    glVertex3f(-200, 80, 5);
    glVertex3f(-200, 80, -5);
    glVertex3f(-200, 51.1, -5);
    glEnd();
    glBegin(GL_POLYGON);//meja1 3
    glColor3f(0.3, 0.2, 0.2);
    glVertex3f(-200, 51.1, 5);
    glVertex3f(-200, 80, 5);
    glVertex3f(-210, 80, 5);
    glVertex3f(-210, 51.1, 5);
    glEnd();
    glBegin(GL_POLYGON);//meja1 4
    glColor3f(0.3, 0.2, 0.2);
    glVertex3f(-200, 51.1, -5);
    glVertex3f(-200, 80, -5);
    glVertex3f(-210, 80, -5);
    glVertex3f(-210, 51.1, -5);
    glEnd();

    glBegin(GL_POLYGON);//meja1 5
    glColor3f(0.3, 0.2, 0.2);
    glVertex3f(-150, 80, 30);
    glVertex3f(-150, 80, -30);
    glVertex3f(-260, 80, -30);
    glVertex3f(-260, 80, 30);
    glEnd();
    glBegin(GL_POLYGON);//meja1 6
    glColor3f(0.3, 0.2, 0.2);
    glVertex3f(-150, 90, 30);
    glVertex3f(-150, 90, -30);
    glVertex3f(-260, 90, -30);
    glVertex3f(-260, 90, 30);
    glEnd();
    glBegin(GL_POLYGON);//meja1 7
    glColor3f(0.3, 0.2, 0.2);
    glVertex3f(-150, 80, 30);
    glVertex3f(-150, 80, -30);
    glVertex3f(-150, 90, -30);
    glVertex3f(-150, 90, 30);
    glEnd();
    glBegin(GL_POLYGON);//meja1 8
    glColor3f(0.3, 0.2, 0.2);
    glVertex3f(-260, 80, 30);
    glVertex3f(-260, 80, -30);
    glVertex3f(-260, 90, -30);
    glVertex3f(-260, 90, 30);
    glEnd();
    glBegin(GL_POLYGON);//meja1 9
    glColor3f(0.3, 0.2, 0.2);
    glVertex3f(-260, 80, -30);
    glVertex3f(-150, 80, -30);
    glVertex3f(-150, 90, -30);
    glVertex3f(-260, 90, -30);
    glEnd();
    glBegin(GL_POLYGON);//meja1 10
    glColor3f(0.3, 0.2, 0.2);
    glVertex3f(-260, 80, 30);
    glVertex3f(-150, 80, 30);
    glVertex3f(-150, 90, 30);
    glVertex3f(-260, 90, 30);
    glEnd();


    glPopMatrix();
    glutSwapBuffers();
}

void mouseMove(int x, int y) {
    if (mousedown) {
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}

void mouseButton(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        mousedown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else {
        mousedown = false;
    }
    glutPostRedisplay();
}
/*
Cara penggunaan :
+++++++++++++++++++++----------------------------------------------------+++++++++++++
untuk penggunaan mouse langsung klik rumah dan arahkan
+++++++++++++++++++++----------------------------------------------------+++++++++++++
tombol pada keyboard:
"a": ke kiri
"d": ke kanan
"w": ke depan
"s": ke belakang
"z" : ke atas
"x" : ke bawah
"i" : rotasi ke bawah terhadap sumbu X
"k" : rotasi ke atas terhadap sumbu X
"j" : rotasi ke kiri terhadap sumbu Y
"l" : rotasi ke kanan terhadap sumbu Y
"m" : rotasi ke kiri terhadap sumbu Z
"n" : rotasi ke kanan terhadap sumbu Z
"5" : transparankan rumah
*/
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'a':
    case 'A':
        glTranslatef(15.0, 0.0, 0.0);
        break;
    case 'd':
    case 'D':
        glTranslatef(-15.0, 0.0, 0.0);
        break;
    case 'z':
    case 'Z':
        glTranslatef(0.0, 15.0, 0.0);
        break;
    case 'x':
    case 'X':
        glTranslatef(0.0, -15.0, 0.0);
        break;
    case 'w':
    case 'W':
        glTranslatef(0.0, 0.0, 15.0);
        break;
    case 's':
    case 'S':
        glTranslatef(0.0, 0.0, -15.0);
        break;
    case 'i':
    case 'I':
        glRotatef(3.0, 1.0, 0.0, 0.0);
        break;
    case 'k':
    case 'K':
        glRotatef(-3.0, 1.0, 0.0, 0.0);
        break;
    case 'j':
    case 'J':
        glRotatef(3.0, 0.0, 1.0, 0.0);
        break;
    case 'l':
    case 'L':
        glRotatef(-3.0, 0.0, 1.0, 0.0);
        break;
    case 'm':
    case 'M':
        glRotatef(3.0, 0.0, 0.0, 1.0);
        break;
    case 'n':
    case 'N':
        glRotatef(-3.0, 0.0, 0.0, 1.0);
        break;
    case '5':
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    display();
}
void resize(int width, int height)
{
    if (height == 0) height = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, width / height, 30.0, 2000.0);
    glTranslatef(0.0, -500.0, -1500.0);
    glMatrixMode(GL_MODELVIEW);
}
