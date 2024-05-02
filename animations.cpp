#include <iostream>
#include <cmath>
#include <math.h>
#include <GL/glut.h>
using namespace std;

void Timer(int);
void calc();

struct Point
{
    double x;
    double y;
};

Point p1 = {400, 600};
Point p2 = {400, 600};
Point p3 = {400, 600};
Point p4 = {400, 600};

double time1 = 0;
double time2 = 0;
double time3 = 0;
double time4 = 0;

void calc()
{
    time1 += 0.1;
    time2 += 0.1;
    time3 += 0.1;
    time4 += 0.1;

    p1.y = (-0.5 * 9.8) * (time1 * time1) + 0 + 600;
    p2.y = (-0.5 * 2.8) * (time2 * time2) + 0 + 600;
    p3.y = (-0.5 * 1.8) * (time3 * time3) + 0 + 600;
    p4.y = (-0.5 * 6.8) * (time4 * time4) + 0 + 600;

    if (p1.y < 0)
    {
        p1.y = 600;
        time1 = 0;
    }
    if (p2.y < 0)
    {
        p2.y = 600;
        time2 = 0;
    }
    if (p3.y < 0)
    {
        p3.y = 600;
        time3 = 0;
    }
    if (p4.y < 0)
    {
        p4.y = 600;
        time4 = 0;
    }
}

void Timer(int value)
{
    glutTimerFunc(1000 / 60, Timer, value);
    glutPostRedisplay();
}

void init()
{
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glPointSize(10);
    gluOrtho2D(-800, 800, -600, 600);
}

void display()
{
    calc();
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2d(p1.x, p1.y);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2d(p2.x, p2.y);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2d(p3.x, p3.y);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2d(p4.x, p4.y);
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Training animation !");
    init();
    Timer(0);
    glutDisplayFunc(display);
    glutMainLoop();
}
