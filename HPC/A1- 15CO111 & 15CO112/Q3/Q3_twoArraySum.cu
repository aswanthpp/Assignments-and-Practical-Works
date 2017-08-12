#include<stdio.h>
#include<math.h>
__global__  void add(int *c,const int *a,const int *b){

	int i=threadIdx.x;
	c[i]=a[i]+b[i];
	}
/*__global__ void input(const int * a){
	int i=threadIdx.x+blockDim.x*blockIdx.x;
	curand_init(1234,i,0,&a[i]);
	}*/
int main(){
int arraySize;
int a[100000],b[100000],c[100000];
printf("\nEnter Size of Arryay :");
scanf("%d",&arraySize);
for(int i=0;i<arraySize;i++){
a[i]=10*sin(i);
b[i]=10*cos(i);
}
printf("Array-1:  \n");
for(int i=0;i<arraySize;i++){
printf("%d ",a[i]);
}	
printf("\nArray-2 \n");
for(int i=0;i<arraySize;i++){
printf("%d ",b[i]);
}
	int *a_in=0;
	int *b_in=0;
	int *c_out=0;
/*	int arraySize;
	printf("\nEnter ArraySize : ");
	scanf("%d",&arraySize);
	cudaMalloc((void **)&a_in,arraySize*sizeof(int));
	input<<<1,arraySize>>>(a_in);
*/	
	cudaMalloc((void **)&a_in,arraySize*sizeof(int));
	cudaMemcpy(a_in,a,arraySize*sizeof(int),cudaMemcpyHostToDevice);
	cudaMalloc((void **)&b_in,arraySize*sizeof(int));
	cudaMemcpy(b_in,b,arraySize*sizeof(int),cudaMemcpyHostToDevice);
	cudaMalloc((void **)&c_out,arraySize*sizeof(int));
	cudaMemcpy(c_out,c,arraySize*sizeof(int),cudaMemcpyHostToDevice);
	add<<<1,arraySize>>>(c_out,a_in,b_in);
	cudaMemcpy(c,c_out,arraySize*sizeof(int),cudaMemcpyDeviceToHost);
	cudaFree(a_in);
	cudaFree(b_in);
	cudaFree(c_out);
	cudaThreadExit();
	printf("\nResultant Array : ");
	for(int i=0;i<arraySize;i++){
		printf("%d ",c[i]);
}
printf("\n");
	return 0;
	
}
