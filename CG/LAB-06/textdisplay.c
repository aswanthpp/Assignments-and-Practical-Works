#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<math.h>
#include<string.h>
int w=600;
void init(){
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,600,0,600);
}
void text(char *name,int x,int y)
{
	int l=strlen(name);
	glRasterPos2f(x,y);
	for(int i=0;i<l;i++){
		glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24 ,name[i]);	
	}
	
}
void display(int x,int y){
	y=w-y;
	glColor3f(0,1,0);
	glClear(GL_COLOR_BUFFER_BIT);
	text("COMPUTER",x,y);	
	glFlush();
	
}
void disp(){
	glFlush();
	
}
void mouse(int button,int state,int x,int y){
		if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
			display(x,y);
		}
}
void keyboard(unsigned char k,int x,int y){
}
void main(int argc,char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(0,0);
	glutCreateWindow("test Program");
	init();
	glutDisplayFunc(disp);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);	
	glutMainLoop();

}
