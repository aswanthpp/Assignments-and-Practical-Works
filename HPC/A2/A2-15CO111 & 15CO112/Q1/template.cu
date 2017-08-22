#include <thrust/device_vector.h>
#include <thrust/host_vector.h>

int main(int argc, char *argv[]) {

  float *hostInput1 = nullptr;
  float *hostInput2 = nullptr;
  float *hostOutput = nullptr;
  int inputLength;

  /* parse the input arguments */
  if(argc != 4 && argc != 5)
  {
	printf("Input parameters should be of the form:\nExpectedFile.raw InputFile1.raw InputFile2.raw [Output.raw]\n");
	return 1;
  }
  
  FILE *exp = fopen(argv[1], "r");
  FILE *inp1 = fopen(argv[2], "r");
  FILE *inp2 = fopen(argv[3], "r");
  
  // Import host input data
  //@@ Read data from the raw files here
  fscanf(inp1, "%d", &inputLength);
  fscanf(inp2, "%d", &inputLength);
  //@@ Insert code here
  hostInput1 = new float[inputLength];
  hostInput2 = new float[inputLength];
  for(int i = 0; i < inputLength; ++i)
  {
	fscanf(inp1, "%f", &hostInput1[i]);
	fscanf(inp2, "%f", &hostInput2[i]);
  }

  // Declare and allocate host output
  //@@ Insert code here
  hostOutput = new float[inputLength];
  // Declare and allocate thrust device input and output vectors
  //@@ Insert code here
  thrust::device_vector<float> deviceInput1 (inputLength);
  thrust::device_vector<float> deviceInput2 (inputLength);
  thrust::device_vector<float> deviceOutput (inputLength);
  // Copy to device
  //@@ Insert code here 
  thrust::copy(hostInput1, hostInput1 + inputLength, deviceInput1.begin());
  thrust::copy(hostInput2, hostInput2 + inputLength, deviceInput2.begin());
  // Execute vector addition
  //@@ Insert Code here
  thrust::transform(deviceInput1.begin(), deviceInput1.end(), deviceInput2.begin(), deviceOutput.begin(), thrust::plus<float>());
  /////////////////////////////////////////////////////////

  // Copy data back to host
  thrust::copy(deviceOutput.begin(), deviceOutput.end(), hostOutput);
  if(argc == 5)
  {
	FILE *outp = fopen(argv[4], "w");
	fprintf(outp, "%d", inputLength);
	for(int i = 0; i < inputLength; ++i)
	{
	  fprintf(outp, "\n%.2f", hostOutput[i]);
	}
  }
  // Check if everything is valid
  bool valid = true;
  fscanf(exp, "%d", &inputLength);
  for(int i = 0; i < inputLength; ++i)
  {
	float check;
	fscanf(exp, "%f", &check);
	// Check if our answer matches up
	if(fabs(check - hostOutput[i]) > 0.001f)
	{
	  valid = false;
	  break;
	}
  }
  if(valid)
    printf("Expected output and generated output matches up\n");
  else
    printf("Expected output does not match generated output\n");
  free(hostInput1);
  free(hostInput2);
  free(hostOutput);
  return 0;
}
