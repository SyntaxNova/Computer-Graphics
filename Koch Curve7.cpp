#include <GL/glut.h>
#include <iostream>

int windowWidth = 800;
int windowHeight = 600;

int menuID;
int submenuID;

// Variables for Koch curve
int kochLevel = 0;

// Variables for Bezier curve
int numControlPoints = 0;
GLfloat controlPoints[10][2];

void drawKochCurve(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, int level) {
    if (level == 0) {
        glBegin(GL_LINES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glEnd();
    } else {
        GLfloat deltaX = x2 - x1;
        GLfloat deltaY = y2 - y1;
        GLfloat x3 = x1 + deltaX / 3;
        GLfloat y3 = y1 + deltaY / 3;
        GLfloat x4 = x1 + 2 * deltaX / 3;
        GLfloat y4 = y1 + 2 * deltaY / 3;
        GLfloat x5 = x3 + (x4 - x3) * 0.5 - (y4 - y3) * 0.866;
        GLfloat y5 = y3 + (y4 - y3) * 0.5 + (x4 - x3) * 0.866;

        drawKochCurve(x1, y1, x3, y3, level - 1);
        drawKochCurve(x3, y3, x5, y5, level - 1);
        drawKochCurve(x5, y5, x4, y4, level - 1);
        drawKochCurve(x4, y4, x2, y2, level - 1);
    }
}

void drawBezierCurve() {
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= numControlPoints; ++i) {
        glVertex2f(controlPoints[i][0], controlPoints[i][1]);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw Koch curve
    glColor3f(1.0f, 0.0f, 0.0f);
    drawKochCurve(-0.8f, -0.5f, 0.8f, -0.5f, kochLevel);

    // Draw Bezier curve
    glColor3f(0.0f, 0.0f, 1.0f);
    drawBezierCurve();

    glFlush();
}

void processMenuEvents(int option) {
    switch (option) {
        case 1:
            kochLevel++;
            break;
        case 2:
            kochLevel--;
            if (kochLevel < 0) {
                kochLevel = 0;
            }
            break;
        case 3:
            std::cout << "Enter the number of control points (2-10): ";
            std::cin >> numControlPoints;
            if (numControlPoints < 2) {
                numControlPoints = 2;
            } else if (numControlPoints > 10) {
                numControlPoints = 10;
            }
            std::cout << "Enter the control points (x y):" << std::endl;
            for (int i = 0; i < numControlPoints; ++i) {
                std::cin >> controlPoints[i][0] >> controlPoints[i][1];
            }
            break;
        case 4:
            numControlPoints = 0;
            break;
        case 5:
            exit(0);
    }
    glutPostRedisplay();
}

void createMenu() {
    submenuID = glutCreateMenu(processMenuEvents);
    glutAddMenuEntry("Increase Level", 1);
    glutAddMenuEntry("Decrease Level", 2);

    menuID = glutCreateMenu(processMenuEvents);
    glutAddSubMenu("Koch Curve", submenuID);
    glutAddMenuEntry("Set Bezier Control Points", 3);
    glutAddMenuEntry("Clear Bezier Control Points", 4);
    glutAddMenuEntry("Exit", 5);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Koch & Bezier Curves");

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    createMenu();

    glutMainLoop();

    return 0;
}

