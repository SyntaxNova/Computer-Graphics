#include<iostream>
#include<GL/glut.h>
using namespace std;

void myInit() {
	glClearColor(1.0, 1.0, 1.0, 0);
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 640, 0, 480);
}

void boundaryFill(float x, float y, float* b, float* n) {
	float color[3];
	glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, color);
	if((color[0] != b[0] || color[1] != b[1] || color[2] != b[2]) && (color[0] != n[0] || color[1] != n[1] || color[2] != n[2])) {
		glColor3f(n[0], n[1], n[2]);
		glBegin(GL_POINTS);
			glVertex2d(x, y);
		glEnd();
		glFlush();
		boundaryFill(x + 1, y, b, n);
		boundaryFill(x - 2, y, b, n);
		boundaryFill(x, y + 1, b, n);
		boundaryFill(x, y - 2, b, n);
		boundaryFill(x + 1, y + 1, b, n);
		boundaryFill(x + 1, y - 1, b, n);
		boundaryFill(x - 1, y + 1, b, n);
		boundaryFill(x - 1, y - 1, b, n);
	}
}

void floodFill(float x, float y, float *b, float *n) {
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2d(40, 440);
	glVertex2d(600, 440);
	glColor3f(0.0, 1.0, 1.0);
	glVertex2d(600, 40);
	glVertex2d(40, 40);
	glEnd();
	float color[3];
	glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, color);
	if(color[0] == b[0] && color[1] == b[1] && color[2] == b[2]) {
		glColor3f(n[0], n[1], n[2]);
		glBegin(GL_POINTS);
			glVertex2d(x, y);
		glEnd();
		glFlush();
		floodFill(x + 1, y, b, n);
		floodFill(x - 2, y, b, n);
		floodFill(x, y + 1, b, n);
		floodFill(x, y - 2, b, n);
		floodFill(x + 1, y + 1, b, n);
		floodFill(x + 1, y - 1, b, n);
		floodFill(x - 1, y + 1, b, n);
		floodFill(x - 1, y - 1, b, n);
	}
}

void myDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLineWidth(3);
	glPointSize(2);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2d(40, 440);
	glVertex2d(600, 440);
	glVertex2d(600, 40);
	glVertex2d(40, 40);
	glEnd();
	glFlush();
}

void mouse(int btn, int state, int x, int y) {
	y = 480 - y;
	if(btn == GLUT_LEFT_BUTTON) {
		if(state == GLUT_DOWN) {
			float b[] = {0, 0, 0};
			float n[] = {1, 0, 0};
			boundaryFill(x, y, b, n);
		}
	} else if(btn == GLUT_RIGHT_BUTTON) {
		if(state == GLUT_DOWN) {
			float b[3];
			glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, b);
			cout << b[0] << b[1] << b[2];
			float n[] = {1, 0, 0};
			floodFill(x, y, b, n);
		}
	}
}

int main(int argc, char ** argv) {
	cout << ("Left Mouse Button: Boundary Fill Right Mouse Button: Flood Fill");
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Filling");
	myInit();
	glutMouseFunc(mouse);
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}

