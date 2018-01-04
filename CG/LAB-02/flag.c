#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<math.h>
void init(){
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,100,0,100);
}
void disp(){
	glColor3f(0,1,0);
	glBegin(GL_POLYGON);
	glVertex2f(10,10);
	glVertex2f(70,10);
	glVertex2f(70,23);
	glVertex2f(10,23);
	glEnd();

	glColor3f(1,1,1);
	glBegin(GL_POLYGON);
	glVertex2f(10,23);
	glVertex2f(70,23);
	glVertex2f(70,36);
	glVertex2f(10,36);
	glEnd();

        glColor3f(1,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(10,36);
	glVertex2f(70,36);
	glVertex2f(70,49);
	glVertex2f(10,49);
	glEnd();
	
	 glColor3f(0,0,0);
	glBegin(GL_POINTS);
 	for(int i=0;i<1000;++i)
  	{
  		glVertex3f(40+5*cos(2*3.14159*i/1000.0),30+5*sin(2*3.14159*i/1000.0),0);
  	}
 	glEnd();

	glColor3f(0,0,0);
	for(int i=0;i<24;i++){

		glBegin(GL_LINES);
    		glVertex2f(40,30);
    		glVertex2f(40+5*cos(2*3.14159*i*15),30+5*sin(2*3.14159*i*15));
		glEnd();
	}
	
	
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
