#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 10
int q=1;
void printMatrix(int*,int);
__global__ void MatrixAddKernel(int*,int*,int*,int,int);


int main()
{	
	int nrow=500;
	int ncol=500;
	 
	int mat1[nrow*ncol];
	int mat2[nrow*ncol];
	int sum[nrow*ncol];
	
	srand(time(NULL));
	
	for(int i=0;i<nrow;i++)
	for(int j=0;j<ncol;j++)
	{
		mat1[i*ncol+j]=rand()%4;
		mat2[i*ncol+j]=rand()%6;
	}

	int size=nrow*ncol*sizeof(int);
	
	int* mat1_d, *mat2_d, *sum_d;
	
	cudaMalloc((void**)&mat1_d,size);
	cudaMalloc((void**)&mat2_d,size);
	cudaMalloc((void**)&sum_d,size);
	
	cudaMemcpy(mat1_d,mat1,size,cudaMemcpyHostToDevice);
	cudaMemcpy(mat2_d,mat2,size,cudaMemcpyHostToDevice);
	
	dim3 dimBlock(32,32);
	dim3 dimGrid(ceil(ncol/32.0),ceil(nrow/32.0));
	MatrixAddKernel<<<dimGrid,dimBlock>>>(mat1_d,mat2_d,sum_d,nrow,ncol);
	
	cudaMemcpy(sum,sum_d,size,cudaMemcpyDeviceToHost);
	
	printMatrix(mat1,ncol);
	printMatrix(mat2,ncol);
	printMatrix(sum,ncol);
	
	cudaFree(mat1_d);
	cudaFree(mat2_d);
	cudaFree(sum_d);	
}

__global__ void MatrixAddKernel(int* mat1_d, int* mat2_d, int* sum_d, int nrow, int ncol)
{
	int row=blockIdx.y*blockDim.y+threadIdx.y;
	int col=blockIdx.x*blockDim.x+threadIdx.x;
	
	if(row<nrow && col<ncol)
	sum_d[row*ncol+col]=mat1_d[row*ncol+col]+mat2_d[row*ncol+col];
	
}

void printMatrix(int* mat,int ncol)
{
	if(q==3)
	{
		printf("sum matrix is :\n");
		q=0;
	}
	else
	{
		printf("array %d is :\n",q);
		q++;
	}

	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		printf("%d ",mat[i*ncol+j]);
	    
		printf("\n");
	}
	printf("\n\n");
}
