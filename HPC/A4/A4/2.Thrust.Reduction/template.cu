#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include "wb.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
  wbArg_t args;
  float *hostInput;
  float hostOutput;
  int inputLength;

  args = wbArg_read(argc, argv); /* parse the input arguments */

  // Import host input data
  wbTime_start(Generic, "Importing data to host");
  hostInput = (float *)wbImport(wbArg_getInputFile(args, 0), &inputLength);
  wbTime_stop(Generic, "Importing data to host");

  wbTime_start(GPU, "Doing GPU Computation (memory + compute)");
  // Declare and allocate thrust device input and output vectors
  thrust::device_vector< float> deviceInput(inputLength);
  
  
  wbTime_start(GPU, "Doing GPU memory allocation");
  //@@ Insert code here
  thrust::copy(hostInput, hostInput + inputLength, deviceInput.begin());
  wbTime_stop(GPU, "Doing GPU memory allocation");
 	hostOutput=thrust::reduce(deviceInput.begin(),deviceInput.end());
  // Copy to device
  wbTime_start(Copy, "Copying data to the GPU");
  //@@ Insert code here
  wbTime_stop(Copy, "Copying data to the GPU");

  // Execute vector addition
  wbTime_start(Compute, "Doing the computation on the GPU");
  //@@ Insert Code here
  wbTime_stop(Compute, "Doing the computation on the GPU");
  /////////////////////////////////////////////////////////

  wbTime_stop(GPU, "Doing GPU Computation (memory + compute)");

  wbSolution(args, &hostOutput, 1);

  free(hostInput);
  return 0;
}
