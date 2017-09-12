#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include "wb.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
  wbArg_t args;
  float *hostInput;  // The input 1D list
  int num_elements;              // number of elements in the input list

  args = wbArg_read(argc, argv);

  wbTime_start(Generic, "Importing data and creating memory on host");
  hostInput =
      (float *)wbImport(wbArg_getInputFile(args, 0), &num_elements);
  wbTime_stop(Generic, "Importing data and creating memory on host");

  wbLog(TRACE, "The number of input elements in the input is ",
        num_elements);

  // Declare and allocate the host output array
  //@@ Insert code here

thrust::host_vector<float> hostOutput(num_elements);
	for(int i=0;i<num_elements;i++){
	hostOutput[i]=0;
	}
	
thrust::device_vector <float> deviceInput(num_elements);
thrust::device_vector<float>deviceOutput(num_elements);
 
  wbTime_start(GPU, "Allocating GPU memory.");
  
  thrust::copy(hostInput,hostInput+num_elements,deviceInput.begin());
  
  wbTime_stop(GPU, "Allocating GPU memory.");

thrust::inclusive_scan(deviceInput.begin(),deviceInput.end(),deviceOutput.begin());

  
  
  thrust::copy(deviceOutput.begin(),deviceOutput.end(),hostOutput.begin());
  
  wbSolution(args, hostOutput, num_elements);
free(hostInput);

 

  return 0;
}
