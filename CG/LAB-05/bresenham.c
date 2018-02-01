#include<stdio.h>
#include<graphics.h>
#include<math.h>
void bresenham(int X0,int Y0,int X1,int Y1){
	int dx = X1 - X0;
	int dy = Y1 - Y0;
	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
	float Xinc = dx / (float) steps;
        float Yinc = dy / (float) steps;
	float X = X0;
    	float Y = Y0;
	int pk=2*dy;
	for(int i=0;i<steps;i++){
		
		if(pk<0){
			putpixel(X+Xinc,Y,RED);
			pk=pk+2*dy;
			X=X+Xinc;			
		}
		else{
			putpixel(X+Xinc,Y+Yinc,RED);
			pk=pk+2*dy-dx;
			X=X+Xinc;
			Y=Y+Yinc;					
		}
		delay(3);	
	}
}
int main()
{
    int gd = DETECT, gm;
    initgraph (&gd, &gm, "");   
    bresenham(0,0,640,480);
    bresenham(320,0,320,480);
    bresenham(640,0,0,480);
    bresenham(640,240,0,240);    
    getchar();
    return 0;
} 
