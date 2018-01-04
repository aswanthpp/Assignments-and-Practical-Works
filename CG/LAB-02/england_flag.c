#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
void init(){
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,100,0,100);
}
void disp(){
	glColor3f(1,1,1);
	glBegin(GL_POLYGON);
	glVertex2f(10,10);
	glVertex2f(70,10);
	glVertex2f(70,50);
	glVertex2f(10,50);
	glEnd();

	glColor3f(1,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(35,10);
	glVertex2f(45,10);
	glVertex2f(45,50);
	glVertex2f(35,50);
	glEnd();

        glColor3f(1,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(10,25);
	glVertex2f(70,25);
	glVertex2f(70,35);
	glVertex2f(10,35);
	glEnd();

	glColor3f(0,1,1);
	glBegin(GL_POLYGON);
	glVertex2f(9,0);
	glVertex2f(10,0);
	glVertex2f(10,50);
	glVertex2f(9,50);
	glEnd();
	
	
//glVertex2f(10,10);
	
	glFlush();
}
void main(int argc,char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(0,0);
	glutCreateWindow("test Program");
	init();
	glutDisplayFunc(disp);
	glutMainLoop();

}
