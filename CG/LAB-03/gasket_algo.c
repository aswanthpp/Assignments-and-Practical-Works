#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<math.h>

void init(){
	glClearColor(0.1,0.3,0.2,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,100,0,100);
}
void disp(){
	
	float xy[3][2]={10,10,70,10,40,52.3}; // vertices of triangle
	float px=40; // cordinate centre of triagle
	float py=24.1; 

	glColor3f(0.8,0.5,0.3);
	glBegin(GL_LINES);
	glVertex2f(xy[0][0],xy[0][1]);
	glVertex2f(xy[1][0],xy[1][1]);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(xy[1][0],xy[1][1]);
	glVertex2f(xy[2][0],xy[2][1]);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(xy[2][0],xy[2][1]);
	glVertex2f(xy[0][0],xy[0][1]);
	glEnd();	
	
	int j;
	for(int i=0;i<32767;i++){
		j=rand()%3;
		px=(px+xy[j][0])/2;
		py=(py+xy[j][1])/2;
		glBegin(GL_POINTS);
		glVertex2f(px,py);
		glEnd();
			
	}	
	glFlush();
}
void main(int argc,char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Sierpenski Gasket Algorithm");
	init();
	glutDisplayFunc(disp);
	glutMainLoop();

}
