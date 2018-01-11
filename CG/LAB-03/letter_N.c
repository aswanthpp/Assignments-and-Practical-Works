#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<math.h>

void init(){
	glClearColor(0.1,0.3,0.2,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D( 0.0,400.0,0.0,400.0);	//Viewport, i.e., camera position.
}
void disp(){
	
	 glColor3f (0.0, 0.0, 0.0);
 
 
 
 glBegin(GL_POLYGON);
 
   glLineWidth (3.0);
   glVertex2f(50.0, 50.0); 
   glVertex2f(50.0, 325.0);
   glColor3f (1.0, 0.0, 0.0);
   glVertex2f(50.0, 50.0); 
   glVertex2f(85.0, 50.0);
   glColor3f (2.0, 0.0, 0.0);
   glVertex2f(85.0, 50.0); 
   glVertex2f(85.0, 135.0);
   glColor3f (3.0, 0.0, 0.0);
   glVertex2f(85.0, 135.0); 
   glVertex2f(50.0, 325.0);
   glColor3f (4.0, 0.0, 0.0);
 
 glEnd();
 
 glColor3f (0.0, 0.0, 0.0);
 glBegin(GL_POLYGON);
 
   glVertex2f(100.0, 50.0); 
   glVertex2f(50.0, 325.0);
   glColor3f (1.0, 0.0, 0.0);
   glVertex2f(50.0, 325.0);
   glVertex2f(145.0, 50.0);
   glColor3f (2.0, 0.0, 0.0);
   glVertex2f(145.0, 50.0);
   glVertex2f(100.0, 50.0);
 
 glEnd(); 
 
  glColor3f (0.0, 0.0, 0.0);
  glBegin(GL_POLYGON);
 
   glVertex2f(145.0, 50.0); 
   glVertex2f(145.0, 325.0); 
   glColor3f (3.0, 0.0, 0.0);
   glVertex2f(145.0, 325.0); 
   glVertex2f(145.0, 325.0); 
   glColor3f (2.0, 0.0, 0.0);
   glVertex2f(145.0, 325.0); 
   glVertex2f(105.0, 166.0); 
   glColor3f (1.0, 0.0, 0.0);
   glVertex2f(105.0, 166.0); 
   glVertex2f(145.0, 50.0);
 glEnd();
 
 glFlush ();
}
void main(int argc,char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
   	glutInitWindowSize (700, 400); 
   glutInitWindowPosition (100, 100);
	glutCreateWindow("Sierpenski Gasket Algorithm");
	init();
	glutDisplayFunc(disp);
	glutMainLoop();

}
