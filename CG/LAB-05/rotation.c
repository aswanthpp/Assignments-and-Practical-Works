#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<math.h>
#include<stdio.h>
float th=0;
float x,y;
int n=1;

void init(){
	glClearColor(1,1,1,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-100,100,-100,100);
	
}
void draw(){
	 
	glBegin(GL_POLYGON);
	glColor3f(1,0,0);	
	glVertex2f(x,y);
	glColor3f(0,1,0);	
	glVertex2f(-y,x);
	glColor3f(0,0,1);	
	glVertex2f(-x,-y);
	glColor3f(0.6,0.4,0.2);	
	glVertex2f(y,-x);
	glEnd();
	glFlush();

}
void idle(){
	th=th+2;
	if(th>360)
		th=th-360;
	x=10*cos(th/6.28);
	y=10*sin(th/6.28);
	glutPostRedisplay();
}
void timer(int v){
	glutPostRedisplay();
	glutTimerFunc(1000/v,timer,v);	
		
}
void mouse(int button,int state,int x,int y){
	if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN){
		glutIdleFunc(NULL);			
	}
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
		glutIdleFunc(idle);
	}
}
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	draw();
	glutSwapBuffers();
	
}

void main(int argc,char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Mouse Keyboard Interaction");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutTimerFunc(1000,timer,n);
	//glutSpecialFunc(special);
	//glutKeyboardFunc(keyboard);
	glutIdleFunc(idle);	
	glutMainLoop();

}
