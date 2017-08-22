// 15CO111 - ARVIND RAMACHANDRAN
// 15CO112 - ASWANTH P. P.

#include<iostream>
#include<assert.h>
#include"math_functions.h"
#include<cuda_runtime.h>
#include<cuda.h>

using namespace std;

__global__ void prod_arr(float* arr1,float* arr2,float* arr3,size_t M,size_t N,size_t P)
{
   size_t y=blockIdx.y*blockDim.y+threadIdx.y;
   size_t x=blockIdx.x*blockDim.x+threadIdx.x;

   if(y<M&&x<P)
   {
      float sum=0; 
      for(size_t i=0;i<N;++i)
      { 
         sum+=arr1[y*N+i]*arr2[i*P+x];
      }
      arr3[y*P+x]=sum; 
   }
}

int main()
{
   float *arr1,*arr2,*arr3;
   float *d_arr1,*d_arr2,*d_arr3;
   const size_t M=512;
   const size_t N=512;
   const size_t P=513;
   const size_t thread_count=32;
   dim3 thread_blk(thread_count,thread_count,1);
   dim3 grid((int)(M/thread_count)+1,(int)(P/thread_count)+1,1);
   
   cout<<grid.x<<","<<grid.y<<endl;
   arr1=(float *)malloc(N*M*sizeof(float));
   cudaMalloc(&d_arr1,N*M*sizeof(float));
   arr2=(float *)malloc(N*P*sizeof(float));
   cudaMalloc(&d_arr2,N*P*sizeof(float));
   arr3=(float *)malloc(P*M*sizeof(float));
   cudaMalloc(&d_arr3,P*M*sizeof(float));

   for(size_t i=0;i<M;++i)
   {
      for(size_t j=0;j<N;++j)
      {
         arr1[i*N+j]=1;
      }
   }

   for(size_t i=0;i<N;++i)
   {
      for(size_t j=0;j<P;++j)
      {
         arr2[i*P+j]=1;
      }
   }

   cudaMemcpy(d_arr1,arr1,N*M*sizeof(float),cudaMemcpyHostToDevice);
   cudaMemcpy(d_arr2,arr2,N*P*sizeof(float),cudaMemcpyHostToDevice);

   prod_arr<<< grid,thread_blk >>>(d_arr1,d_arr2,d_arr3,M,N,P);

   cudaMemcpy(arr3,d_arr3,P*M*sizeof(float),cudaMemcpyDeviceToHost);
   cudaMemcpy(arr1,d_arr1,N*M*sizeof(float),cudaMemcpyDeviceToHost);
   cudaMemcpy(arr2,d_arr2,N*P*sizeof(float),cudaMemcpyDeviceToHost);

   int count=0;

   for(size_t i=0;i<M;++i)
   {
      for(size_t j=0;j<P-1;++j)
      {
         if(arr3[i*P+j]!=arr3[i*P+j+1]) 
         {  
            count++;
            cout<<i<<","<<j<<endl;
         }
      }
   }
   
   cout<<count<<endl;

   cudaFree(d_arr1);
   cudaFree(d_arr2);
   cudaFree(d_arr3);

   free(arr1);
   free(arr2);
   free(arr3);

   cout<<"DONE\n";
   return 0;
}
