#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
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
    glutCreateWindow("Ivan Sukma Hanindria - 672018048");
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
    glClearColor(0.0, 1.0, 0.906, 0.0);
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
    glVertex3f(-400, 0, -200);
    glColor3f(0.6, 0.4, 0.4);
    glVertex3f(-400, 0, 200);
    glColor3f(0.8, 0.6, 0.6);
    glVertex3f(400, 0, 200);
    glColor3f(0.6, 0.4, 0.4);
    glVertex3f(400, 0, -200);
    glEnd();
    glBegin(GL_LINE_LOOP);//garis alas
    glColor3f(0, 0, 0);
    glVertex3f(-400, 0, -200);
    glVertex3f(-400, 0, 200);
    glVertex3f(400, 0, 200);
    glVertex3f(400, 0, -200);
    glEnd();

    glBegin(GL_POLYGON);//fondasi 1 alas
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-340, 0, 140);
    glVertex3f(-340, 0, 120);
    glVertex3f(-320, 0, 120);
    glVertex3f(-320, 0, 140);
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

    glBegin(GL_POLYGON);//fondasi 2 alas
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-340, 0, -140);
    glVertex3f(-340, 0, -120);
    glVertex3f(-320, 0, -120);
    glVertex3f(-320, 0, -140);
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

    glBegin(GL_POLYGON);//fondasi 3 alas
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-140, 0, -140);
    glVertex3f(-140, 0, -120);
    glVertex3f(-120, 0, -120);
    glVertex3f(-120, 0, -140);
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

    glBegin(GL_POLYGON);//fondasi 4 alas
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-140, 0, 140);
    glVertex3f(-140, 0, 120);
    glVertex3f(-120, 0, 120);
    glVertex3f(-120, 0, 140);
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
    glVertex3f(-40, 270, -160);
    glEnd();
    glBegin(GL_LINES);//bangunan bawah1 garis atas3
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-360, 270, 160);
    glVertex3f(-40, 270, 160);
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
    glVertex3f(90, 50, 160);
    glVertex3f(360, 50, 160);
    glVertex3f(360, 50, -160);
    glVertex3f(90, 50, -160);
    glEnd();
    glBegin(GL_POLYGON);//bangunan bawah2 fondasi depan
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(90, 0, 160);
    glVertex3f(360, 0, 160);
    glVertex3f(360, 50, 160);
    glVertex3f(90, 50, 160);
    glEnd();
    glBegin(GL_POLYGON);//bangunan bawah2 fondasi belakang
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(90, 0, -160);
    glVertex3f(360, 0, -160);
    glVertex3f(360, 50, -160);
    glVertex3f(90, 50, -160);
    glEnd();
    glBegin(GL_POLYGON);//bangunan bawah2 fondasi kanan
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(360, 0, 160);
    glVertex3f(360, 0, -160);
    glVertex3f(360, 50, -160);
    glVertex3f(360, 50, 160);
    glEnd();
    glBegin(GL_POLYGON);//bangunan bawah2 fondasi kiri
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(90, 0, 160);
    glVertex3f(90, 0, -160);
    glVertex3f(90, 50, -160);
    glVertex3f(90, 50, 160);
    glEnd();
    glBegin(GL_POLYGON);//bangunan bawah2 depan putih1
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(30, 51, 160);
    glVertex3f(360, 51, 160);
    glVertex3f(360, 270, 160);
    glVertex3f(15, 270, 160);
    glEnd();
    glBegin(GL_POLYGON);//bangunan bawah2 belakang putih1
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(30, 51, -160);
    glVertex3f(360, 51, -160);
    glVertex3f(360, 270, -160);
    glVertex3f(15, 270, -160);
    glEnd();
    glBegin(GL_POLYGON);//bangunan kanan putih
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(360, 51, 160);
    glVertex3f(360, 51, -160);
    glVertex3f(360, 270, -160);
    glVertex3f(360, 270, 160);
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
        glTranslatef(10.0, 0.0, 0.0);
        break;
    case 'd':
    case 'D':
        glTranslatef(-10.0, 0.0, 0.0);
        break;
    case 'z':
    case 'Z':
        glTranslatef(0.0, 10.0, 0.0);
        break;
    case 'x':
    case 'X':
        glTranslatef(0.0, -10.0, 0.0);
        break;
    case 'w':
    case 'W':
        glTranslatef(0.0, 0.0, 10.0);
        break;
    case 's':
    case 'S':
        glTranslatef(0.0, 0.0, -10.0);
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