#include<stdio.h>
#include<graphics.h>
#include<math.h>

void DDA(int X0, int Y0, int X1, int Y1)
{

    int dx = X1 - X0;
    int dy = Y1 - Y0;
 

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
 

    float Xinc = dx / (float) steps;
    float Yinc = dy / (float) steps;
 
    float X = X0;
    float Y = Y0;
    for (int i = 0; i <= steps; i++)
    {
        putpixel (X,Y,GREEN); 
        X += Xinc;           
        Y += Yinc;
	delay(2);                
    }
}
void drawCircle(int x,int y,int r){
	for(int i=0;i<360;i++){
		int a=r*cos(i/6.28)+x;
		int b=r*sin(i/6.28)+y;
		putpixel(a,b,RED);
		delay(1);	
	}
}
int main()
{
    int gd = DETECT, gm;
    initgraph (&gd, &gm, "");      
	drawCircle(120,60,30);
	drawCircle(440,60,30);
	DDA(280,70,260,150);
	DDA(280,70,300,150);
	DDA(260,150,300,150);
	
    getchar();
    return 0;
} 
