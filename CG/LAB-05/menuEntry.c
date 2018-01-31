#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<math.h>
#include<stdio.h>

int window,menu_id,submenu_id,value = 0;

void init(){
	glClearColor(1,1,1,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,30,0,30);
	
}
void menu(int num){
  if(num == 1){
    glutDestroyWindow(window);
    exit(0);
  }else{
    value = num;
  }
  glutPostRedisplay();
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
void createMenu(void){     
    submenu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Squre", 2);
    glutAddMenuEntry("Triangle", 3);     
    menu_id = glutCreateMenu(menu);
    glutAddSubMenu("Draw", submenu_id);
    glutAddMenuEntry("Clear", 0);
    glutAddMenuEntry("Quit", 1);     
    glutAttachMenu(GLUT_RIGHT_BUTTON);
} 
void display(void){
  glClear(GL_COLOR_BUFFER_BIT);
  if(value == 0){
    return; 
  }
  else if(value == 2){
    drawSqure();
  }else if(value == 3){
    drawTriangle();
  }
 
} 
void main(int argc,char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Menu Entry ");
	init();
	createMenu();
	glutDisplayFunc(display);
	glutMainLoop();

}
