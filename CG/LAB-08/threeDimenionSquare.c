#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<math.h>
#include<stdio.h>
float th=0;
float x=0,y=1,z=0;
int n=1;
int a[8][3]={ 	0,0,0,
		0,10,0,
		10,10,0,
		10,0,0,
		10,0,10,
		10,10,10,
		0,10,10,
		0,0,10
  	};
float color[ ][3]={	0,0,0,
			0,1,0,
			0,0,1,
			1,1,0,
			0,1,1,
			1,0,1
		};

void init(){
	glClearColor(1,1,1,0);
	glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glOrtho(-30,30,-30,30,-30,30);
	
}
void draw(){
	 

            //1
	glBegin(GL_POLYGON);
	glColor3fv(color[0]);
	glVertex3f(a[0][0],a[0][1],a[0][2]);
	glVertex3f(a[1][0],a[1][1],a[1][2]);
	glVertex3f(a[2][0],a[2][1],a[2][2]);
	glVertex3f(a[3][0],a[3][1],a[3][2]);
	glEnd();
	glFlush();
	
	//2
	glBegin(GL_POLYGON);
	glColor3fv(color[1]);
	glVertex3f(a[3][0],a[3][1],a[3][2]);
	glVertex3f(a[2][0],a[2][1],a[2][2]);
	glVertex3f(a[5][0],a[5][1],a[5][2]);
	glVertex3f(a[4][0],a[4][1],a[4][2]);
	glEnd();
	glFlush();
	//3
	glBegin(GL_POLYGON);
	glColor3fv(color[2]);
	glVertex3f(a[4][0],a[4][1],a[4][2]);
	glVertex3f(a[5][0],a[5][1],a[5][2]);
	glVertex3f(a[6][0],a[6][1],a[6][2]);
	glVertex3f(a[7][0],a[7][1],a[7][2]);
	glEnd();
	glFlush();
	//6
glBegin(GL_POLYGON);
	glColor3fv(color[5]);
	glVertex3f(a[0][0],a[0][1],a[0][2]);
	glVertex3f(a[3][0],a[3][1],a[3][2]);
	glVertex3f(a[4][0],a[4][1],a[4][2]);
	glVertex3f(a[7][0],a[7][1],a[7][2]);
	glEnd();
	glFlush();
		
	//4
	glBegin(GL_POLYGON);
	glColor3fv(color[3]);
	glVertex3f(a[7][0],a[7][1],a[7][2]);
	glVertex3f(a[6][0],a[6][1],a[6][2]);
	glVertex3f(a[1][0],a[1][1],a[1][2]);
	glVertex3f(a[0][0],a[0][1],a[0][2]);
	glEnd();
	glFlush();
//5
	glBegin(GL_POLYGON);
	glColor3fv(color[4]);
	glVertex3f(a[6][0],a[6][1],a[6][2]);
	glVertex3f(a[5][0],a[5][1],a[5][2]);
	glVertex3f(a[2][0],a[2][1],a[2][2]);
	glVertex3f(a[1][0],a[1][1],a[1][2]);
	glEnd();
	glFlush();
		


}
void idle(){
	th=2;
	if(th>360)
		th=th-360;
	
	glutPostRedisplay();
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
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glRotatef(th,x,y,z);
	draw();
	glutSwapBuffers();
	
}
void keyboard(unsigned char k,int x,int y){
	switch(k){
		case 'x' :	x=1;
				y=0;
				z=0;
				break;
		case 'y' :	x=0;
				y=1;
				z=0;
			
				break;
		case 'z' : 	x=0;
				y=0;
				z=1;
				break;
				
	}
}
void main(int argc,char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(0,0);
	glutCreateWindow("3d rotation");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutIdleFunc(idle);	
	glutMainLoop();

}
