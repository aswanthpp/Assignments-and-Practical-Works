#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<math.h>
#include<stdio.h>

int width=600;

void init(){
	glClearColor(1,1,1,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-100,100,-100,100);
	
}
void drawSqure(){
	 
	glBegin(GL_POLYGON);
	glColor3f(1,0,0);	
	glVertex2f(10,10);
	glColor3f(0,1,0);	
	glVertex2f(20,10);
	glColor3f(0,0,1);	
	glVertex2f(20,20);
	glColor3f(0.6,0.4,0.2);	
	glVertex2f(10,20);
	glEnd();
	glFlush();

}
void drawTriangle(){
	 
	glBegin(GL_POLYGON);
	glColor3f(1,0,0);	
	glVertex2f(10,10);
	glColor3f(0,1,0);	
	glVertex2f(20,10);
	glColor3f(0,0,1);	
	glVertex2f(15,20);
	glEnd();
	glFlush();

}
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	//draw();
	
}
void menu(){
}
void createWindow(){
	int menu1=glutCreateMenu(menu);
	glutAddMenuEntry("aa",1);
	glutAddMenuEntry("bb",2);
}
void mouse(int button,int state,int x,int y){
	if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN){
		createWindow();			
	}
}
void keyboard(unsigned char k,int x,int y){
	switch(k){
	case '+' :	//glTranslated(-x,-y,0); 
			glScaled(2,2,2);
			//glTranslated(x,y,0);
			glutPostRedisplay();break;
	case '-' : glScaled(0.5,0.5,0.5);
			glutPostRedisplay();break;	
	}
}
void special(int k,int x,int y){
	switch(k){
	case GLUT_KEY_UP:
		glTranslated(0,2,0);
		glutPostRedisplay();break;	
	case GLUT_KEY_DOWN :
		glTranslated(0,-2,0);
		glutPostRedisplay();break;
	case GLUT_KEY_RIGHT :
		glTranslated(2,0,0);
		glutPostRedisplay();break; 
	case GLUT_KEY_LEFT :
		glTranslated(-2,0,0);
		glutPostRedisplay();break;
	}
}
void main(int argc,char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Mouse Keyboard Interaction");
	init();
	glutDisplayFunc(display);
	//glutMouseFunc(mouse);
	glutSpecialFunc(special);
	glutKeyboardFunc(keyboard);
	glutMainLoop();

}
