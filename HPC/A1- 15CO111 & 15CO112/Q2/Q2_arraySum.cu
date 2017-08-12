#include<stdio.h>

__global__ void addKernel( float *s, const float *a)
{
    int i = threadIdx.x;
    atomicAdd(s,a[i]);
}

int main(){
	int arraySize;
	float a[100],sum;
	printf("\nAray Size : ");
	scanf("%d",&arraySize);
	printf("\nEnter Elements :");

	for(int i=0;i<arraySize;i++){
	scanf("%f",&a[i]);
	}
	float *a_in = 0;
	float *s_out=0;
	cudaMalloc((void**)&a_in, arraySize * sizeof(float));
	cudaMemcpy(a_in, a, arraySize * sizeof(float), cudaMemcpyHostToDevice);

	cudaMalloc((void **)&s_out,sizeof(float));
	cudaMemcpy(s_out,&sum,sizeof(float),cudaMemcpyHostToDevice);

	addKernel<<<1,arraySize>>>(s_out,a_in);

	cudaMemcpy(&sum,s_out,sizeof(float),cudaMemcpyDeviceToHost);
    	cudaFree(a_in);
   	cudaFree(s_out);
	cudaThreadExit();
	printf("\nSum = %f\n",sum);
    return 0;
}



