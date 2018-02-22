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
/*
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}*/
void drawTriangle(int x0,int y0,int x1,int y1,int x2,int y2){
    	/*if(y2<y1&&y2){
		swap(&x0,&x1);
		swap(&y0,&y1);
	}
	else if(y2<y0){
		swap(&x2,&x0);
		swap(&y2,&y0);
	}*/
	bresenham(x0,y0,x1,y1);
    	bresenham(x1,y1,x2,y2);
    	bresenham(x0,y0,x2,y2);
}
int main()
{
    int gd = DETECT, gm;
    initgraph (&gd, &gm, "");  
drawTriangle(50,10,350,10,200,320);
	getchar();
    return 0;
} 
