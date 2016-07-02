#ifndef _CL_UTILS_H
#define _CL_UTILS_H

#include <CL/opencl.h>

struct clSettingsStub;
typedef struct clSettingsStub {
	cl_platform_id platform;
	cl_device_id device;
	cl_context context;
	cl_command_queue queue;
	int initialized;
} clSettings;

struct clStandAloneKernelStub;
typedef struct clStandAloneKernelStub {
	cl_program program;
	cl_kernel kernel;
} clStandAloneKernel;



struct clKernelsStub;
typedef struct clKernelsStub {
	clStandAloneKernel* transMatrixMult;
	cl_mem inputA;
	cl_mem inputB;
	cl_mem outputC;
} clKernels;


extern clSettings globalClSettings;
extern clKernels globalClKernels;


int clCoreInit();
void clCoreEnd();


int clInit();
void clEnd();

void clTest();
clStandAloneKernel* createStandAloneKernel(const char* src, const char* name);
void deleteStandAloneKernel(clStandAloneKernel* kernel);


#endif