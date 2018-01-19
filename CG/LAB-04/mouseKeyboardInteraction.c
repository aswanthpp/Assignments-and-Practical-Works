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
	gluOrtho2D(0,600,0,600);
	
}
void disp(int x,int y){
	
	y=width-y;
	
	glBegin(GL_POLYGON);
	glVertex2f(x-3,y-3);
	glVertex2f(x+3,y-3);
	glVertex2f(x+3,y+3);
	glVertex2f(x-3,y+3);
	glEnd();
	glFlush();
}
void display(){
	glColor3f(1,0,0);
	glFlush();
	
}
void mouse(int button,int state,int x,int y){
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
		disp(x,y);
		
	}
}
void keyboard(unsigned char k,int x,int y){
	switch(k){
		case 'r' :glColor3f(1,0,0);
			
				break;
		case 'g' :	glColor3f(0,1,0);
			
				break;
		case 'b' : glColor3f(0,0,1);
				
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
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutMainLoop();

}
