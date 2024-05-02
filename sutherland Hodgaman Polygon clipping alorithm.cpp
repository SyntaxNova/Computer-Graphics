#include<stdio.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<math.h>

typedef struct{
    float x;
    float y;
}PT;

int n;

int i,j;

PT p1,p2,p[20],pp[20];

void left(){
    i=0;j=0;
    for(i=0;i<n;i++){
        if(p[i].x<p1.x && p[i+1].x>=p1.x){
            if(p[i+1].x-p[i].x!=0){
                pp[j].y=(p[i+1].y-p[i].y)/(p[i+1].x-p[i].x)*(p1.x-p[i].x)+p[i].y;
            }
            else{
                pp[j].y=p[i].y;
            }
            pp[j].x=p1.x;
            j++;
            pp[j].x=p[i+1].x;
            pp[j].y=p[i+1].y;
            j++;
        }

        if(p[i].x>=p1.x && p[i+1].x>=p1.x){
            pp[j].y=p[i+1].y;
            pp[j].x=p[i+1].x;
            j++;
        }

        if(p[i].x>=p1.x && p[i+1].x<p1.x){
            if(p[i+1].x-p[i].x!=0){
                pp[j].y=(p[i+1].y-p[i].y)/(p[i+1].x-p[i].x)*(p1.x-p[i].x)+p[i].y;
            }
            else{
                pp[j].y=p[i].y;
            }
            pp[j].x=p1.x;
            j++;
        }
    }

    for(i=0;i<j;i++){
        p[i].x=pp[i].x;
        p[i].y=pp[i].y;
    }

    p[i].x=pp[0].x;
    p[i].y=pp[0].y;
    n=j;
}

void right(){
    i=0;j=0;

    for(i=0;i<n;i++){
        if(p[i].x>p2.x && p[i+1].x<=p2.x){
            if(p[i+1].x-p[i].x!=0){
                pp[j].y=(p[i+1].y-p[i].y)/(p[i+1].x-p[i].x)*(p2.x-p[i].x)+p[i].y;
            }
            else{
                pp[j].y=p[i].y;
            }
            pp[j].x=p2.x;
            j++;
            pp[j].x=p[i+1].x;
            pp[j].y=p[i+1].y;
            j++;
        }

        if(p[i].x<=p2.x && p[i+1].x<=p2.x){
            pp[j].y=p[i+1].y;
            pp[j].x=p[i+1].x;
            j++;
        }

        if(p[i].x<=p2.x && p[i+1].x>p2.x){
            if(p[i+1].x-p[i].x!=0){
                pp[j].y=(p[i+1].y-p[i].y)/(p[i+1].x-p[i].x)*(p2.x-p[i].x)+p[i].y;
            }
            else{
                pp[j].y=p[i].y;
            }
            pp[j].x=p2.x;
            j++;
        }
    }

    for(i=0;i<j;i++){
        p[i].x=pp[i].x;
        p[i].y=pp[i].y;
    }
    p[i].x=pp[0].x;
    p[i].y=pp[0].y;
}

void top(){
    i=0;j=0;

    for(i=0;i<n;i++){
        if(p[i].y>p2.y && p[i+1].y<=p2.y){
            if(p[i+1].y-p[i].y!=0){
                pp[j].x=(p[i+1].x-p[i].x)/(p[i+1].y-p[i].y)*(p2.y-p[i].y)+p[i].x;
            }
            else{
                pp[j].x=p[i].x;
            }
            pp[j].y=p2.y;
            j++;
            pp[j].x=p[i+1].x;
            pp[j].y=p[i+1].y;
            j++;
        }

        if(p[i].y<=p2.y && p[i+1].y<=p2.y){
            pp[j].y=p[i+1].y;
            pp[j].x=p[i+1].x;
            j++;
        }

        if(p[i].y<=p2.y && p[i+1].y>p2.y){
            if(p[i+1].y-p[i].y!=0){
                pp[j].x=(p[i+1].x-p[i].x)/(p[i+1].y-p[i].y)*(p2.y-p[i].y)+p[i].x;
            }
            else{
                pp[j].x=p[i].x;
            }
            pp[j].y=p2.y;
            j++;
        }
    }

    for(i=0;i<j;i++){
        p[i].x=pp[i].x;
        p[i].y=pp[i].y;
    }
    p[i].x=pp[0].x;
    p[i].y=pp[0].y;
    n=j;
}


void bottom(){
    i=0;j=0;

    for(i=0;i<n;i++){
        if(p[i].y<p1.y && p[i+1].y>=p1.y){
            if(p[i+1].y-p[i].y!=0){
                pp[j].x=(p[i+1].x-p[i].x)/(p[i+1].y-p[i].y)*(p1.y-p[i].y)+p[i].x;
            }
            else{
                pp[j].x=p[i].x;
            }
            pp[j].y=p1.y;
            j++;
            pp[j].x=p[i+1].x;
            pp[j].y=p[i+1].y;
            j++;
        }

        if(p[i].y>=p1.y && p[i+1].y>=p1.y){
            pp[j].x=p[i+1].x;
            pp[j].y=p[i+1].y;
            j++;
        }

        if(p[i].y>=p1.y && p[i+1].y<p1.y){
            if(p[i+1].y-p[i].y!=0){
                pp[j].x=(p[i+1].x-p[i].x)/(p[i+1].y-p[i].y)*(p1.y-p[i].y)+p[i].x;
            }
            else{
                pp[j].x=p[i].x;
            }
            pp[j].y=p1.y;
            j++;
        }
    }

    for(i=0;i<j;i++){
        p[i].x=pp[i].x;
        p[i].y=pp[i].y;
    }
    p[i].x=pp[0].x;
    p[i].y=pp[0].y;
    n=j;
}

void drawpolygon(){
    glColor3f(0.0,1.0,1.0);
    for(i=0;i<n-1;i++){
        glBegin(GL_LINES);
        glVertex2d(p[i].x,p[i].y);
        glVertex2d(p[i+1].x,p[i+1].y);
        glEnd();
    }
    glBegin(GL_LINES);
    glVertex2d(p[i].x,p[i].y);
    glVertex2d(p[0].x,p[0].y);
    glEnd();
}

void myMouse(int button, int state, int x, int y){
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_LINE_LOOP);
        glVertex2f(p1.x,p1.y);
        glVertex2f(p2.x,p1.y);
        glVertex2f(p2.x,p2.y);
        glVertex2f(p1.x,p2.y);
        glEnd();
        left();
        right();
        top();
        bottom();
        drawpolygon();
    }
    glFlush();
}


void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.4,0.0,1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(p1.x, p1.y);
    glVertex2f(p2.x,p1.y);
    glVertex2f(p2.x,p2.y);
    glVertex2f(p1.x,p2.y);
    glEnd();
    drawpolygon();
    glFlush();
}

void init(void){
    glClearColor(0.0,0.0,0.0,0.0);
    gluOrtho2D(0,500,0,500);
}

int main(int argc, char**argv){
    printf("Enter Window Coordinates:\n");
    printf("Please Enter two Points:\n");
    printf("Enter P1(x,y):\n");
    scanf("%f", &p1.x);
    scanf("%f", &p1.y);

    printf("Enter P2(x,y):\n");
    scanf("%f", &p2.x);
    scanf("%f", &p2.y);

    printf("\nEnter the no. of vertices:");
    scanf("%d", &n);

    for(i=0;i<n;i++){
    printf("\nEnter V%d(x%d,y%d):\n" , i+1, i+1, i+1);
    scanf("%f", &p[i].x);
    scanf("%f", &p[i].y);
    }

    p[i].x=p[0].x;
    p[i].y=p[0].y;

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Sutherland Hodgman Polygon Clipping Algorithm ");
    init();

    glutDisplayFunc(display);
    glutMouseFunc(myMouse);
    glFlush();
    glutMainLoop();
    return 0;
}

