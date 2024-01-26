#include "kuda_driver_api.h"
#include <jni.h>
#include <cuda.h>

//2. Error Handling
JNIEXPORT jstring JNICALL Java_kuda_driverapi_DriverAPI_getErrorName(JNIEnv* env, jobject obj, jint error) {
	
	const char* pStr;

	CUresult cudaStatus = cuGetErrorName(static_cast<CUresult>(error), &pStr);
	
	jstring javaString = env->NewStringUTF(pStr);

	return javaString;
}

JNIEXPORT jstring JNICALL Java_kuda_driverapi_DriverAPI_getErrorString(JNIEnv* env, jobject obj, jint error) {

	const char* pStr;

	CUresult cudaStatus = cuGetErrorString(static_cast<CUresult>(error), &pStr);

	jstring javaString = env->NewStringUTF(pStr);

	return javaString;
}

JNIEXPORT jint JNICALL Java_kuda_driverapi_DriverAPI_init(JNIEnv* env, jobject obj, jint flags) {
	
	CUresult cudaStatus = cuInit((unsigned int) flags);

	return cudaStatus;
}

JNIEXPORT jint JNICALL Java_kuda_driverapi_DriverAPI_driverGetVersion(JNIEnv* env, jobject obj) {
	
	int driverVersion;

	CUresult cudaStatus = cuDriverGetVersion(&driverVersion);

	if (cudaStatus != CUDA_SUCCESS) {
		return cudaStatus;
	}

	return driverVersion;
}

JNIEXPORT jint JNICALL Java_kuda_driverapi_DriverAPI_deviceGet(JNIEnv* env, jobject obj, jint ordinal) {

	CUdevice device;

	CUresult cudaStatus = cuDeviceGet(&device, ordinal);

	if (cudaStatus != CUDA_SUCCESS) {
		return cudaStatus;
	}

	return cudaStatus;
}

JNIEXPORT jint JNICALL Java_kuda_driverapi_DriverAPI_deviceGetCount(JNIEnv* env, jobject obj) {
	
	int count;

	CUresult cudaStatus = cuDeviceGetCount(&count);

	if (cudaStatus != CUDA_SUCCESS) {
		return cudaStatus;
	}

	return count;
}

//7. Primary Context Management

//CUresult cuDevicePrimaryCtxGetState(CUdevice dev, unsigned int* flags, int* active)

JNIEXPORT jint JNICALL Java_kuda_driverapi_DriverAPI_devicePrimaryCtxRelease(JNIEnv* env, jobject obj, jint dev) {
	
	CUresult cudaStatus = cuDevicePrimaryCtxRelease(dev);

	return cudaStatus;
}

JNIEXPORT jint JNICALL Java_kuda_driverapi_DriverAPI_devicePrimaryCtxReset(JNIEnv* env, jobject obj, jint dev) {

	CUresult cudaStatus = cuDevicePrimaryCtxReset(dev);

	return cudaStatus;
}

//CUresult cuDevicePrimaryCtxRetain(CUcontext* pctx, CUdevice dev)

JNIEXPORT jint JNICALL Java_kuda_driverapi_DriverAPI_devicePrimaryCtxSetFlags(JNIEnv* env, jobject obj, jint dev, jint flags) {

	CUresult cudaStatus = cuDevicePrimaryCtxSetFlags(dev, (unsigned int)flags);

	return cudaStatus;
}

//8. Context Management
//CUresult cuCtxCreate(CUcontext* pctx, unsigned int  flags, CUdevice dev)
//CUresult cuCtxCreate_v3(CUcontext* pctx, CUexecAffinityParam* paramsArray, int  numParams, unsigned int  flags, CUdevice dev)
//CUresult cuCtxDestroy(CUcontext ctx)
//CUresult cuCtxGetApiVersion(CUcontext ctx, unsigned int* version)

JNIEXPORT jint JNICALL Java_kuda_driverapi_DriverAPI_ctxGetCacheConfig(JNIEnv* env, jobject obj, jboolean dummy) {
	
	CUfunc_cache pconfig;

	CUresult cudaStatus = cuCtxGetCacheConfig(&pconfig);

	if (cudaStatus != CUDA_SUCCESS) {
		return cudaStatus;
	}

	return static_cast<int>(pconfig);
}

//CUresult cuCtxGetCurrent(CUcontext * pctx)

JNIEXPORT jint JNICALL Java_kuda_driverapi_DriverAPI_ctxGetDevice(JNIEnv* env, jobject obj) {
	
	CUdevice device;

	CUresult cudaStatus = cuCtxGetDevice(&device);

	if (cudaStatus != CUDA_SUCCESS) {
		return cudaStatus;
	}

	return (jint)device;
}

//CUresult cuCtxGetExecAffinity(CUexecAffinityParam * pExecAffinity, CUexecAffinityType type)

JNIEXPORT jint JNICALL Java_kuda_driverapi_DriverAPI_ctxGetFlags(JNIEnv* env, jobject obj) {
	unsigned int flags;

	CUresult cudaStatus = cuCtxGetFlags(&flags);

	if (cudaStatus != CUDA_SUCCESS) {
		return cudaStatus;
	}
	
	return (jint)flags;
}
//CUresult cuCtxGetId(CUcontext ctx, unsigned long long* ctxId)
//CUresult cuCtxGetLimit(size_t * pvalue, CUlimit limit)
//CUresult cuCtxGetSharedMemConfig(CUsharedconfig * pConfig)
//CUresult cuCtxGetStreamPriorityRange(int* leastPriority, int* greatestPriority)
//CUresult cuCtxPopCurrent(CUcontext * pctx)
//CUresult cuCtxPushCurrent(CUcontext ctx)

JNIEXPORT jint JNICALL Java_kuda_driverapi_DriverAPI_ctxResetPersistingL2Cache(JNIEnv* env, jobject obj) {

	CUresult cudaStatus = cuCtxResetPersistingL2Cache();

	return cudaStatus;
}

JNIEXPORT jint JNICALL Java_kuda_driverapi_DriverAPI_ctxSetCacheConfig(JNIEnv* env, jobject obj, jint config) {
	
	CUresult cudaStatus = cuCtxSetCacheConfig(static_cast<CUfunc_cache>(config));
	
	return cudaStatus;
}

//CUresult cuCtxSetCurrent(CUcontext ctx)

JNIEXPORT jint JNICALL Java_kuda_driverapi_DriverAPI_ctxSetFlags(JNIEnv* env, jobject obj, jint flags) {
	
	CUresult cudaStatus = cuCtxSetFlags((unsigned int) flags);
	
	return cudaStatus;
}

JNIEXPORT jint JNICALL Java_kuda_driverapi_DriverAPI_ctxSetLimit(JNIEnv* env, jobject obj, jbyte limit, jsize value) {
	CUresult cudaStatus = cuCtxSetLimit(static_cast<CUlimit>(limit), value);
	
	return cudaStatus;
}

//CUresult cuCtxSetSharedMemConfig(CUsharedconfig config)

JNIEXPORT jint JNICALL Java_kuda_driverapi_DriverAPI_ctxSynchronize(JNIEnv* env, jobject obj) {

	CUresult cudaStatus = cuCtxSynchronize();

	return cudaStatus;
}

//9. Context Management (DEPRECATED)

//10. Module Management
//CUresult cuLinkAddData(CUlinkState state, CUjitInputType type, void* data, size_t size, const char* name, unsigned int  numOptions, CUjit_option* options, void** optionValues)
//CUresult cuLinkAddFile(CUlinkState state, CUjitInputType type, const char* path, unsigned int  numOptions, CUjit_option* options, void** optionValues)
//CUresult cuLinkComplete(CUlinkState state, void** cubinOut, size_t* sizeOut)
//CUresult cuLinkCreate(unsigned int  numOptions, CUjit_option* options, void** optionValues, CUlinkState* stateOut)

JNIEXPORT jint JNICALL Java_kuda_driverapi_DriverAPI_linkDestroy(JNIEnv* env, jobject obj, jlong state) {
	
	CUlinkState cuLinkState = reinterpret_cast<CUlinkState>(state);

	CUresult cudaStatus = cuLinkDestroy(cuLinkState);

	return cudaStatus;
}

//CUresult cuModuleGetFunction(CUfunction * hfunc, CUmodule hmod, const char* name)
//CUresult cuModuleGetGlobal(CUdeviceptr * dptr, size_t * bytes, CUmodule hmod, const char* name)
//CUresult cuModuleGetLoadingMode(CUmoduleLoadingMode * mode)
//CUresult cuModuleLoad(CUmodule * module, const char* fname)
//CUresult cuModuleLoadData(CUmodule * module, const void* image)
//CUresult cuModuleLoadDataEx(CUmodule * module, const void* image, unsigned int  numOptions, CUjit_option * options, void** optionValues)
//CUresult cuModuleLoadFatBinary(CUmodule * module, const void* fatCubin)

JNIEXPORT jint JNICALL Java_kuda_driverapi_DriverAPI_moduleUnload(JNIEnv* env, jobject obj, jlong hmod) {

	CUmodule cuModule = reinterpret_cast<CUmodule>(hmod);

	CUresult cudaStatus = cuModuleUnload(cuModule);

	return cudaStatus;
}

//11. Module Management (DEPRECATED)

//12. Library Management
//CUresult cuKernelGetAttribute(int* pi, CUfunction_attribute attrib, CUkernel kernel, CUdevice dev)
//CUresult cuKernelGetFunction(CUfunction* pFunc, CUkernel kernel)
//CUresult cuKernelGetName(const char** name, CUkernel hfunc)
//CUresult cuKernelSetAttribute(CUfunction_attribute attrib, int  val, CUkernel kernel, CUdevice dev)
//CUresult cuKernelSetCacheConfig(CUkernel kernel, CUfunc_cache config, CUdevice dev)
//CUresult cuLibraryGetGlobal(CUdeviceptr * dptr, size_t * bytes, CUlibrary library, const char* name)
//CUresult cuLibraryGetKernel(CUkernel * pKernel, CUlibrary library, const char* name)
//CUresult cuLibraryGetManaged(CUdeviceptr * dptr, size_t * bytes, CUlibrary library, const char* name)
//CUresult cuLibraryGetModule(CUmodule * pMod, CUlibrary library)
//CUresult cuLibraryGetUnifiedFunction(void** fptr, CUlibrary library, const char* symbol)
//CUresult cuLibraryLoadData(CUlibrary * library, const void* code, CUjit_option * jitOptions, void** jitOptionsValues, unsigned int  numJitOptions, CUlibraryOption * libraryOptions, void** libraryOptionValues, unsigned int  numLibraryOptions)
//CUresult cuLibraryLoadFromFile(CUlibrary * library, const char* fileName, CUjit_option * jitOptions, void** jitOptionsValues, unsigned int  numJitOptions, CUlibraryOption * libraryOptions, void** libraryOptionValues, unsigned int  numLibraryOptions)

JNIEXPORT jint JNICALL Java_kuda_driverapi_DriverAPI_libraryUnload(JNIEnv* env, jobject obj, jlong library) {
	
	CUlibrary cuLibrary = reinterpret_cast<CUlibrary>(library);

	CUresult cudaStatus = cuLibraryUnload(cuLibrary);

	return cudaStatus;
}

//13. Memory Management
//CUresult cuArray3DCreate(CUarray* pHandle, const CUDA_ARRAY3D_DESCRIPTOR* pAllocateArray)
//CUresult cuArray3DGetDescriptor(CUDA_ARRAY3D_DESCRIPTOR * pArrayDescriptor, CUarray hArray)
//CUresult cuArrayCreate(CUarray * pHandle, const CUDA_ARRAY_DESCRIPTOR * pAllocateArray)

JNIEXPORT jint JNICALL Java_kuda_driverapi_DriverAPI_arrayDestroy(JNIEnv* env, jobject obj, jlong hArray) {
	
	CUarray cuArray = reinterpret_cast<CUarray>(hArray);
	
	CUresult cudaStatus = cuArrayDestroy(cuArray);

	return cudaStatus;
}

//CUresult cuArrayGetDescriptor(CUDA_ARRAY_DESCRIPTOR * pArrayDescriptor, CUarray hArray)
//CUresult cuArrayGetMemoryRequirements(CUDA_ARRAY_MEMORY_REQUIREMENTS * memoryRequirements, CUarray array, CUdevice device)
//CUresult cuArrayGetPlane(CUarray * pPlaneArray, CUarray hArray, unsigned int  planeIdx)
//CUresult cuArrayGetSparseProperties(CUDA_ARRAY_SPARSE_PROPERTIES * sparseProperties, CUarray array)
//CUresult cuDeviceGetByPCIBusId(CUdevice * dev, const char* pciBusId)
//CUresult cuDeviceGetPCIBusId(char* pciBusId, int  len, CUdevice dev)

JNIEXPORT jint JNICALL Java_kuda_driverapi_DriverAPI_ipcCloseMemHandle(JNIEnv* env, jobject obj, jlong dptr) {

	CUresult cudaStatus = cuIpcCloseMemHandle(dptr);

	return cudaStatus;
}

//CUresult cuIpcGetEventHandle(CUipcEventHandle * pHandle, CUevent event)
//CUresult cuIpcGetMemHandle(CUipcMemHandle * pHandle, CUdeviceptr dptr)
//CUresult cuIpcOpenEventHandle(CUevent * phEvent, CUipcEventHandle handle)
//CUresult cuIpcOpenMemHandle(CUdeviceptr * pdptr, CUipcMemHandle handle, unsigned int  Flags)
//CUresult cuMemAlloc(CUdeviceptr * dptr, size_t bytesize)
//CUresult cuMemAllocHost(void** pp, size_t bytesize)
//CUresult cuMemAllocManaged(CUdeviceptr * dptr, size_t bytesize, unsigned int  flags)
//CUresult cuMemAllocPitch(CUdeviceptr * dptr, size_t * pPitch, size_t WidthInBytes, size_t Height, unsigned int  ElementSizeBytes)

JNIEXPORT jint JNICALL Java_kuda_driverapi_DriverAPI_memFree(JNIEnv* env, jobject obj, jlong dptr) {

	CUresult cudaStatus = cuMemFree(dptr);

	return cudaStatus;
}

JNIEXPORT jint JNICALL Java_kuda_driverapi_DriverAPI_memFreeHost(JNIEnv* env, jobject obj, jlong p) {
	
	void* hostMemoryPointer = (void*)p;

	CUresult result = cuMemFreeHost(hostMemoryPointer);

	return result;
}

//CUresult cuMemGetAddressRange(CUdeviceptr * pbase, size_t * psize, CUdeviceptr dptr)
//CUresult cuMemGetHandleForAddressRange(void* handle, CUdeviceptr dptr, size_t size, CUmemRangeHandleType handleType, unsigned long long flags)
//CUresult cuMemGetInfo(size_t * free, size_t * total)
//CUresult cuMemHostAlloc(void** pp, size_t bytesize, unsigned int  Flags)
//CUresult cuMemHostGetDevicePointer(CUdeviceptr * pdptr, void* p, unsigned int  Flags)
//CUresult cuMemHostGetFlags(unsigned int* pFlags, void* p)
//CUresult cuMemHostRegister(void* p, size_t bytesize, unsigned int  Flags)

JNIEXPORT jint JNICALL Java_kuda_driverapi_DriverAPI_memHostUnregister(JNIEnv* env, jobject obj, jlong p) {

	void* hostMemoryPointer = (void*)p;

	CUresult result = cuMemHostUnregister(hostMemoryPointer);

	return result;
}

//CUresult cuMemcpy(CUdeviceptr dst, CUdeviceptr src, size_t ByteCount)
//CUresult cuMemcpy2D(const CUDA_MEMCPY2D * pCopy)
//CUresult cuMemcpy2DAsync(const CUDA_MEMCPY2D * pCopy, CUstream hStream)
//CUresult cuMemcpy2DUnaligned(const CUDA_MEMCPY2D * pCopy)
//CUresult cuMemcpy3D(const CUDA_MEMCPY3D * pCopy)
//CUresult cuMemcpy3DAsync(const CUDA_MEMCPY3D * pCopy, CUstream hStream)
//CUresult cuMemcpy3DPeer(const CUDA_MEMCPY3D_PEER * pCopy)
//CUresult cuMemcpy3DPeerAsync(const CUDA_MEMCPY3D_PEER * pCopy, CUstream hStream)
//CUresult cuMemcpyAsync(CUdeviceptr dst, CUdeviceptr src, size_t ByteCount, CUstream hStream)
//CUresult cuMemcpyAtoA(CUarray dstArray, size_t dstOffset, CUarray srcArray, size_t srcOffset, size_t ByteCount)
//CUresult cuMemcpyAtoD(CUdeviceptr dstDevice, CUarray srcArray, size_t srcOffset, size_t ByteCount)
//CUresult cuMemcpyAtoH(void* dstHost, CUarray srcArray, size_t srcOffset, size_t ByteCount)
//CUresult cuMemcpyAtoHAsync(void* dstHost, CUarray srcArray, size_t srcOffset, size_t ByteCount, CUstream hStream)
//CUresult cuMemcpyDtoA(CUarray dstArray, size_t dstOffset, CUdeviceptr srcDevice, size_t ByteCount)
//CUresult cuMemcpyDtoD(CUdeviceptr dstDevice, CUdeviceptr srcDevice, size_t ByteCount)
//CUresult cuMemcpyDtoDAsync(CUdeviceptr dstDevice, CUdeviceptr srcDevice, size_t ByteCount, CUstream hStream)
//CUresult cuMemcpyDtoH(void* dstHost, CUdeviceptr srcDevice, size_t ByteCount)
//CUresult cuMemcpyDtoHAsync(void* dstHost, CUdeviceptr srcDevice, size_t ByteCount, CUstream hStream)
//CUresult cuMemcpyHtoA(CUarray dstArray, size_t dstOffset, const void* srcHost, size_t ByteCount)
//CUresult cuMemcpyHtoAAsync(CUarray dstArray, size_t dstOffset, const void* srcHost, size_t ByteCount, CUstream hStream)
//CUresult cuMemcpyHtoD(CUdeviceptr dstDevice, const void* srcHost, size_t ByteCount)
//CUresult cuMemcpyHtoDAsync(CUdeviceptr dstDevice, const void* srcHost, size_t ByteCount, CUstream hStream)
//CUresult cuMemcpyPeer(CUdeviceptr dstDevice, CUcontext dstContext, CUdeviceptr srcDevice, CUcontext srcContext, size_t ByteCount)
//CUresult cuMemcpyPeerAsync(CUdeviceptr dstDevice, CUcontext dstContext, CUdeviceptr srcDevice, CUcontext srcContext, size_t ByteCount, CUstream hStream)
//CUresult cuMemsetD16(CUdeviceptr dstDevice, unsigned short us, size_t N)
//CUresult cuMemsetD16Async(CUdeviceptr dstDevice, unsigned short us, size_t N, CUstream hStream)
//CUresult cuMemsetD2D16(CUdeviceptr dstDevice, size_t dstPitch, unsigned short us, size_t Width, size_t Height)
//CUresult cuMemsetD2D16Async(CUdeviceptr dstDevice, size_t dstPitch, unsigned short us, size_t Width, size_t Height, CUstream hStream)
//CUresult cuMemsetD2D32(CUdeviceptr dstDevice, size_t dstPitch, unsigned int  ui, size_t Width, size_t Height)
//CUresult cuMemsetD2D32Async(CUdeviceptr dstDevice, size_t dstPitch, unsigned int  ui, size_t Width, size_t Height, CUstream hStream)
//CUresult cuMemsetD2D8(CUdeviceptr dstDevice, size_t dstPitch, unsigned char  uc, size_t Width, size_t Height)
//CUresult cuMemsetD2D8Async(CUdeviceptr dstDevice, size_t dstPitch, unsigned char  uc, size_t Width, size_t Height, CUstream hStream)
//CUresult cuMemsetD32(CUdeviceptr dstDevice, unsigned int  ui, size_t N)
//CUresult cuMemsetD32Async(CUdeviceptr dstDevice, unsigned int  ui, size_t N, CUstream hStream)
//CUresult cuMemsetD8(CUdeviceptr dstDevice, unsigned char  uc, size_t N)
//CUresult cuMemsetD8Async(CUdeviceptr dstDevice, unsigned char  uc, size_t N, CUstream hStream)
//CUresult cuMipmappedArrayCreate(CUmipmappedArray * pHandle, const CUDA_ARRAY3D_DESCRIPTOR * pMipmappedArrayDesc, unsigned int  numMipmapLevels)
//CUresult cuMipmappedArrayDestroy(CUmipmappedArray hMipmappedArray)
//CUresult cuMipmappedArrayGetLevel(CUarray * pLevelArray, CUmipmappedArray hMipmappedArray, unsigned int  level)
//CUresult cuMipmappedArrayGetMemoryRequirements(CUDA_ARRAY_MEMORY_REQUIREMENTS * memoryRequirements, CUmipmappedArray mipmap, CUdevice device)
//CUresult cuMipmappedArrayGetSparseProperties(CUDA_ARRAY_SPARSE_PROPERTIES * sparseProperties, CUmipmappedArray mipmap)

//14. Virtual Memory Management
//CUresult cuMemAddressFree(CUdeviceptr ptr, size_t size)
//CUresult cuMemAddressReserve(CUdeviceptr* ptr, size_t size, size_t alignment, CUdeviceptr addr, unsigned long long flags)
//CUresult cuMemCreate(CUmemGenericAllocationHandle* handle, size_t size, const CUmemAllocationProp* prop, unsigned long long flags)
//CUresult cuMemExportToShareableHandle(void* shareableHandle, CUmemGenericAllocationHandle handle, CUmemAllocationHandleType handleType, unsigned long long flags)
//CUresult cuMemGetAccess(unsigned long long* flags, const CUmemLocation* location, CUdeviceptr ptr)
//CUresult cuMemGetAllocationGranularity(size_t * granularity, const CUmemAllocationProp * prop, CUmemAllocationGranularity_flags option)
//CUresult cuMemGetAllocationPropertiesFromHandle(CUmemAllocationProp * prop, CUmemGenericAllocationHandle handle)
//CUresult cuMemImportFromShareableHandle(CUmemGenericAllocationHandle * handle, void* osHandle, CUmemAllocationHandleType shHandleType)
//CUresult cuMemMap(CUdeviceptr ptr, size_t size, size_t offset, CUmemGenericAllocationHandle handle, unsigned long long flags)
//CUresult cuMemMapArrayAsync(CUarrayMapInfo * mapInfoList, unsigned int  count, CUstream hStream)

JNIEXPORT jint JNICALL Java_kuda_driverapi_DriverAPI_memRelease(JNIEnv* env, jobject obj, jlong handle) {

	CUresult result = cuMemRelease(handle);

	return result;
}

//CUresult cuMemRetainAllocationHandle(CUmemGenericAllocationHandle * handle, void* addr)
//CUresult cuMemSetAccess(CUdeviceptr ptr, size_t size, const CUmemAccessDesc * desc, size_t count)	
//CUresult cuMemUnmap(CUdeviceptr ptr, size_t size)

//15. Steam Ordered Memory Allocator
//CUresult cuMemAllocAsync(CUdeviceptr* dptr, size_t bytesize, CUstream hStream)
//CUresult cuMemAllocFromPoolAsync(CUdeviceptr* dptr, size_t bytesize, CUmemoryPool pool, CUstream hStream)
//CUresult cuMemFreeAsync(CUdeviceptr dptr, CUstream hStream)
//CUresult cuMemPoolCreate(CUmemoryPool* pool, const CUmemPoolProps* poolProps)

JNIEXPORT jint JNICALL Java_kuda_driverapi_DriverAPI_memPoolDestroy(JNIEnv* env, jobject obj, jlong pool) {

	CUmemoryPool cuMemoryPool = reinterpret_cast<CUmemoryPool>(pool);

	CUresult result = cuMemPoolDestroy(cuMemoryPool);

	return result;
}

//CUresult cuMemPoolDestroy(CUmemoryPool pool)
//CUresult cuMemPoolExportPointer(CUmemPoolPtrExportData* shareData_out, CUdeviceptr ptr)
//CUresult cuMemPoolExportToShareableHandle(void* handle_out, CUmemoryPool pool, CUmemAllocationHandleType handleType, unsigned long long flags)
//CUresult cuMemPoolGetAccess(CUmemAccess_flags* flags, CUmemoryPool memPool, CUmemLocation* location)
//CUresult cuMemPoolGetAttribute(CUmemoryPool pool, CUmemPool_attribute attr, void* value)
//CUresult cuMemPoolImportFromShareableHandle(CUmemoryPool* pool_out, void* handle, CUmemAllocationHandleType handleType, unsigned long long flags)
//CUresult cuMemPoolImportPointer(CUdeviceptr* ptr_out, CUmemoryPool pool, CUmemPoolPtrExportData* shareData)
//CUresult cuMemPoolSetAccess(CUmemoryPool pool, const CUmemAccessDesc* map, size_t count)
//CUresult cuMemPoolSetAttribute(CUmemoryPool pool, CUmemPool_attribute attr, void* value)
//CUresult cuMemPoolTrimTo(CUmemoryPool pool, size_t minBytesToKeep)

//16. Multicast Object Management
//CUresult cuMulticastAddDevice(CUmemGenericAllocationHandle mcHandle, CUdevice dev)
//CUresult cuMulticastBindAddr(CUmemGenericAllocationHandle mcHandle, size_t mcOffset, CUdeviceptr memptr, size_t size, unsigned long long flags)
//CUresult cuMulticastBindMem(CUmemGenericAllocationHandle mcHandle, size_t mcOffset, CUmemGenericAllocationHandle memHandle, size_t memOffset, size_t size, unsigned long long flags)
//CUresult cuMulticastCreate(CUmemGenericAllocationHandle* mcHandle, const CUmulticastObjectProp* prop)
//CUresult cuMulticastGetGranularity(size_t* granularity, const CUmulticastObjectProp* prop, CUmulticastGranularity_flags option)
//CUresult cuMulticastUnbind(CUmemGenericAllocationHandle mcHandle, CUdevice dev, size_t mcOffset, size_t size)

//17. Unified Addressing
//CUresult cuMemAdvise(CUdeviceptr devPtr, size_t count, CUmem_advise advice, CUdevice device)
//CUresult cuMemAdvise_v2(CUdeviceptr devPtr, size_t count, CUmem_advise advice, CUmemLocation location)
//CUresult cuMemPrefetchAsync(CUdeviceptr devPtr, size_t count, CUdevice dstDevice, CUstream hStream)
//CUresult cuMemPrefetchAsync_v2(CUdeviceptr devPtr, size_t count, CUmemLocation location, unsigned int  flags, CUstream hStream)
//CUresult cuMemRangeGetAttribute(void* data, size_t dataSize, CUmem_range_attribute attribute, CUdeviceptr devPtr, size_t count)
//CUresult cuMemRangeGetAttributes(void** data, size_t* dataSizes, CUmem_range_attribute* attributes, size_t numAttributes, CUdeviceptr devPtr, size_t count)
//CUresult cuPointerGetAttribute(void* data, CUpointer_attribute attribute, CUdeviceptr ptr)
//CUresult cuPointerGetAttributes(unsigned int  numAttributes, CUpointer_attribute* attributes, void** data, CUdeviceptr ptr)
//CUresult cuPointerSetAttribute(const void* value, CUpointer_attribute attribute, CUdeviceptr ptr)

//18. Stream Management
//CUresult cuStreamAddCallback(CUstream hStream, CUstreamCallback callback, void* userData, unsigned int  flags)
//CUresult cuStreamAttachMemAsync(CUstream hStream, CUdeviceptr dptr, size_t length, unsigned int  flags)
//CUresult cuStreamBeginCapture(CUstream hStream, CUstreamCaptureMode mode)
//CUresult cuStreamBeginCaptureToGraph(CUstream hStream, CUgraph hGraph, const CUgraphNode* dependencies, const CUgraphEdgeData* dependencyData, size_t numDependencies, CUstreamCaptureMode mode)
//CUresult cuStreamCopyAttributes(CUstream dst, CUstream src)
//CUresult cuStreamCreate(CUstream* phStream, unsigned int  Flags)
//CUresult cuStreamCreateWithPriority(CUstream* phStream, unsigned int  flags, int  priority)

JNIEXPORT jint JNICALL Java_kuda_driverapi_DriverAPI_streamDestroy(JNIEnv* env, jobject obj, jlong hStream) {

	CUstream cuStream = reinterpret_cast<CUstream>(hStream);

	CUresult result = cuStreamDestroy(cuStream);

	return result;
}

//CUresult cuStreamEndCapture(CUstream hStream, CUgraph* phGraph)
//CUresult cuStreamGetAttribute(CUstream hStream, CUstreamAttrID attr, CUstreamAttrValue* value_out)
//CUresult cuStreamGetCaptureInfo(CUstream hStream, CUstreamCaptureStatus* captureStatus_out, cuuint64_t* id_out, CUgraph* graph_out, const CUgraphNode** dependencies_out, size_t* numDependencies_out)
//CUresult cuStreamGetCaptureInfo_v3(CUstream hStream, CUstreamCaptureStatus * captureStatus_out, cuuint64_t * id_out, CUgraph * graph_out, const CUgraphNode * *dependencies_out, const CUgraphEdgeData * *edgeData_out, size_t * numDependencies_out)
//CUresult cuStreamGetCtx(CUstream hStream, CUcontext * pctx)
//CUresult cuStreamGetFlags(CUstream hStream, unsigned int* flags)
//CUresult cuStreamGetId(CUstream hStream, unsigned long long* streamId)
//CUresult cuStreamGetPriority(CUstream hStream, int* priority)
//CUresult cuStreamIsCapturing(CUstream hStream, CUstreamCaptureStatus * captureStatus)

JNIEXPORT jint JNICALL Java_kuda_driverapi_DriverAPI_streamQuery(JNIEnv* env, jobject obj, jlong hStream) {
	
	CUstream cuStream = reinterpret_cast<CUstream>(hStream);

	CUresult result = cuStreamQuery(cuStream);

	return result;
}

//CUresult cuStreamSetAttribute(CUstream hStream, CUstreamAttrID attr, const CUstreamAttrValue * value)

JNIEXPORT jint JNICALL Java_kuda_driverapi_DriverAPI_streamSynchronize(JNIEnv* env, jobject obj, jlong hStream) {

	CUstream cuStream = reinterpret_cast<CUstream>(hStream);

	CUresult result = cuStreamSynchronize(cuStream);

	return result;
}

//CUresult cuStreamUpdateCaptureDependencies(CUstream hStream, CUgraphNode * dependencies, size_t numDependencies, unsigned int  flags)
//CUresult cuStreamUpdateCaptureDependencies_v2(CUstream hStream, CUgraphNode * dependencies, const CUgraphEdgeData * dependencyData, size_t numDependencies, unsigned int  flags)
//CUresult cuStreamWaitEvent(CUstream hStream, CUevent hEvent, unsigned int  Flags)

JNIEXPORT jint JNICALL Java_kuda_driverapi_DriverAPI_threadExchangeStreamCaptureMode(JNIEnv* env, jobject obj, jint mode) {
	
	CUstreamCaptureMode cuStreamCaptureMode = static_cast<CUstreamCaptureMode>(mode);

	CUresult result = cuThreadExchangeStreamCaptureMode(&cuStreamCaptureMode);

	return result;
}

//19.Event Management

//CUresult cuEventCreate(CUevent * phEvent, unsigned int  Flags)

JNIEXPORT jint JNICALL Java_kuda_driverapi_DriverAPI_eventDestroy(JNIEnv* env, jobject obj, jlong hEvent) {
	
	CUevent cuEvent = reinterpret_cast<CUevent>(hEvent);

	CUresult result = cuEventDestroy(cuEvent);

	return result;
}

//CUresult cuEventElapsedTime(float* pMilliseconds, CUevent hStart, CUevent hEnd)

JNIEXPORT jint JNICALL Java_kuda_driverapi_DriverAPI_eventQuery(JNIEnv* env, jobject obj, jlong hEvent) {

	CUevent cuEvent = reinterpret_cast<CUevent>(hEvent);

	CUresult result = cuEventQuery(cuEvent);

	return result;
}

//CUresult cuEventRecord(CUevent hEvent, CUstream hStream)
//CUresult cuEventRecordWithFlags(CUevent hEvent, CUstream hStream, unsigned int  flags)

JNIEXPORT jint JNICALL Java_kuda_driverapi_DriverAPI_eventSynchronize(JNIEnv* env, jobject obj, jlong hEvent) {

	CUevent cuEvent = reinterpret_cast<CUevent>(hEvent);

	CUresult result = cuEventSynchronize(cuEvent);

	return result;
}

//20. External Resource Interoperability

JNIEXPORT jint JNICALL Java_kuda_driverapi_DriverAPI_destroyExternalMemory(JNIEnv* env, jobject obj, jlong extMem) {

	CUexternalMemory cuExternalMemory = reinterpret_cast<CUexternalMemory>(extMem);

	CUresult result = cuDestroyExternalMemory(cuExternalMemory);

	return result;
}

JNIEXPORT jint JNICALL Java_kuda_driverapi_DriverAPI_destroyExternalSemaphore(JNIEnv* env, jobject obj, jlong extSem) {

	CUexternalSemaphore cuExternalSemaphore = reinterpret_cast<CUexternalSemaphore>(extSem);

	CUresult result = cuDestroyExternalSemaphore(cuExternalSemaphore);

	return result;
}

//CUresult cuExternalMemoryGetMappedBuffer(CUdeviceptr* devPtr, CUexternalMemory extMem, const CUDA_EXTERNAL_MEMORY_BUFFER_DESC* bufferDesc)
//CUresult cuExternalMemoryGetMappedMipmappedArray(CUmipmappedArray* mipmap, CUexternalMemory extMem, const CUDA_EXTERNAL_MEMORY_MIPMAPPED_ARRAY_DESC* mipmapDesc)
//CUresult cuImportExternalMemory(CUexternalMemory* extMem_out, const CUDA_EXTERNAL_MEMORY_HANDLE_DESC* memHandleDesc)
//CUresult cuImportExternalSemaphore(CUexternalSemaphore* extSem_out, const CUDA_EXTERNAL_SEMAPHORE_HANDLE_DESC* semHandleDesc)
//CUresult cuSignalExternalSemaphoresAsync(const CUexternalSemaphore* extSemArray, const CUDA_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS* paramsArray, unsigned int  numExtSems, CUstream stream)
//CUresult cuWaitExternalSemaphoresAsync(const CUexternalSemaphore* extSemArray, const CUDA_EXTERNAL_SEMAPHORE_WAIT_PARAMS* paramsArray, unsigned int  numExtSems, CUstream stream)

//21. Stream Memory Operations
//CUresult cuStreamBatchMemOp(CUstream stream, unsigned int  count, CUstreamBatchMemOpParams* paramArray, unsigned int  flags)
//CUresult cuStreamWaitValue32(CUstream stream, CUdeviceptr addr, cuuint32_t value, unsigned int  flags)
//CUresult cuStreamWaitValue64(CUstream stream, CUdeviceptr addr, cuuint64_t value, unsigned int  flags)
//CUresult cuStreamWriteValue32(CUstream stream, CUdeviceptr addr, cuuint32_t value, unsigned int  flags)
//CUresult cuStreamWriteValue64(CUstream stream, CUdeviceptr addr, cuuint64_t value, unsigned int  flags)

//22. Execution Control
//CUresult cuFuncGetAttribute(int* pi, CUfunction_attribute attrib, CUfunction hfunc)
//CUresult cuFuncGetModule(CUmodule* hmod, CUfunction hfunc)
//CUresult cuFuncGetName(const char** name, CUfunction hfunc)
//CUresult cuFuncSetAttribute(CUfunction hfunc, CUfunction_attribute attrib, int  value)
//CUresult cuFuncSetCacheConfig(CUfunction hfunc, CUfunc_cache config)
//CUresult cuFuncSetSharedMemConfig(CUfunction hfunc, CUsharedconfig config)
//CUresult cuLaunchCooperativeKernel(CUfunction f, unsigned int  gridDimX, unsigned int  gridDimY, unsigned int  gridDimZ, unsigned int  blockDimX, unsigned int  blockDimY, unsigned int  blockDimZ, unsigned int  sharedMemBytes, CUstream hStream, void** kernelParams)
//CUresult cuLaunchCooperativeKernelMultiDevice(CUDA_LAUNCH_PARAMS * launchParamsList, unsigned int  numDevices, unsigned int  flags)
//CUresult cuLaunchHostFunc(CUstream hStream, CUhostFn fn, void* userData)
//CUresult cuLaunchKernel(CUfunction f, unsigned int  gridDimX, unsigned int  gridDimY, unsigned int  gridDimZ, unsigned int  blockDimX, unsigned int  blockDimY, unsigned int  blockDimZ, unsigned int  sharedMemBytes, CUstream hStream, void** kernelParams, void** extra)
//CUresult cuLaunchKernelEx(const CUlaunchConfig * config, CUfunction f, void** kernelParams, void** extra)

//24. Graph Management
//CUresult cuDeviceGetGraphMemAttribute(CUdevice device, CUgraphMem_attribute attr, void* value)

JNIEXPORT jint JNICALL Java_kuda_driverapi_DriverAPI_deviceGraphMemTrim(JNIEnv* env, jobject obj, jint device) {

	CUresult result = cuDeviceGraphMemTrim(device);

	return result;
}

//CUresult cuDeviceSetGraphMemAttribute(CUdevice device, CUgraphMem_attribute attr, void* value)
//CUresult cuGraphAddBatchMemOpNode(CUgraphNode * phGraphNode, CUgraph hGraph, const CUgraphNode * dependencies, size_t numDependencies, const CUDA_BATCH_MEM_OP_NODE_PARAMS * nodeParams)
//CUresult cuGraphAddChildGraphNode(CUgraphNode * phGraphNode, CUgraph hGraph, const CUgraphNode * dependencies, size_t numDependencies, CUgraph childGraph)
//CUresult cuGraphAddDependencies(CUgraph hGraph, const CUgraphNode * from, const CUgraphNode * to, size_t numDependencies)
//CUresult cuGraphAddDependencies_v2(CUgraph hGraph, const CUgraphNode * from, const CUgraphNode * to, const CUgraphEdgeData * edgeData, size_t numDependencies)
//CUresult cuGraphAddEmptyNode(CUgraphNode * phGraphNode, CUgraph hGraph, const CUgraphNode * dependencies, size_t numDependencies)
//CUresult cuGraphAddEventRecordNode(CUgraphNode * phGraphNode, CUgraph hGraph, const CUgraphNode * dependencies, size_t numDependencies, CUevent event)
//CUresult cuGraphAddEventWaitNode(CUgraphNode * phGraphNode, CUgraph hGraph, const CUgraphNode * dependencies, size_t numDependencies, CUevent event)
//CUresult cuGraphAddExternalSemaphoresSignalNode(CUgraphNode * phGraphNode, CUgraph hGraph, const CUgraphNode * dependencies, size_t numDependencies, const CUDA_EXT_SEM_SIGNAL_NODE_PARAMS * nodeParams)
//CUresult cuGraphAddExternalSemaphoresWaitNode(CUgraphNode * phGraphNode, CUgraph hGraph, const CUgraphNode * dependencies, size_t numDependencies, const CUDA_EXT_SEM_WAIT_NODE_PARAMS * nodeParams)
//CUresult cuGraphAddHostNode(CUgraphNode * phGraphNode, CUgraph hGraph, const CUgraphNode * dependencies, size_t numDependencies, const CUDA_HOST_NODE_PARAMS * nodeParams)
//CUresult cuGraphAddKernelNode(CUgraphNode * phGraphNode, CUgraph hGraph, const CUgraphNode * dependencies, size_t numDependencies, const CUDA_KERNEL_NODE_PARAMS * nodeParams)
//CUresult cuGraphAddMemAllocNode(CUgraphNode * phGraphNode, CUgraph hGraph, const CUgraphNode * dependencies, size_t numDependencies, CUDA_MEM_ALLOC_NODE_PARAMS * nodeParams)
//CUresult cuGraphAddMemFreeNode(CUgraphNode * phGraphNode, CUgraph hGraph, const CUgraphNode * dependencies, size_t numDependencies, CUdeviceptr dptr)
//CUresult cuGraphAddMemcpyNode(CUgraphNode * phGraphNode, CUgraph hGraph, const CUgraphNode * dependencies, size_t numDependencies, const CUDA_MEMCPY3D * copyParams, CUcontext ctx)
//CUresult cuGraphAddMemsetNode(CUgraphNode * phGraphNode, CUgraph hGraph, const CUgraphNode * dependencies, size_t numDependencies, const CUDA_MEMSET_NODE_PARAMS * memsetParams, CUcontext ctx)
//CUresult cuGraphAddNode(CUgraphNode * phGraphNode, CUgraph hGraph, const CUgraphNode * dependencies, size_t numDependencies, CUgraphNodeParams * nodeParams)
//CUresult cuGraphAddNode_v2(CUgraphNode * phGraphNode, CUgraph hGraph, const CUgraphNode * dependencies, const CUgraphEdgeData * dependencyData, size_t numDependencies, CUgraphNodeParams * nodeParams)
//CUresult cuGraphBatchMemOpNodeGetParams(CUgraphNode hNode, CUDA_BATCH_MEM_OP_NODE_PARAMS * nodeParams_out)
//CUresult cuGraphBatchMemOpNodeSetParams(CUgraphNode hNode, const CUDA_BATCH_MEM_OP_NODE_PARAMS * nodeParams)
//CUresult cuGraphChildGraphNodeGetGraph(CUgraphNode hNode, CUgraph * phGraph)
//CUresult cuGraphClone(CUgraph * phGraphClone, CUgraph originalGraph)
//CUresult cuGraphConditionalHandleCreate(CUgraphConditionalHandle * pHandle_out, CUgraph hGraph, CUcontext ctx, unsigned int  defaultLaunchValue, unsigned int  flags)
//CUresult cuGraphCreate(CUgraph * phGraph, unsigned int  flags)
//CUresult cuGraphDebugDotPrint(CUgraph hGraph, const char* path, unsigned int  flags)

JNIEXPORT jint JNICALL Java_kuda_driverapi_DriverAPI_graphDestroy(JNIEnv* env, jobject obj, jlong hGraph) {

	CUgraph cuGraph= reinterpret_cast<CUgraph>(hGraph);

	CUresult result = cuGraphDestroy(cuGraph);

	return result;
}

JNIEXPORT jint JNICALL Java_kuda_driverapi_DriverAPI_graphDestroyNode(JNIEnv* env, jobject obj, jlong hNode) {

	CUgraphNode cuGraphNode = reinterpret_cast<CUgraphNode>(hNode);

	CUresult result = cuGraphDestroyNode(cuGraphNode);

	return result;
}

//CUresult cuGraphEventRecordNodeGetEvent(CUgraphNode hNode, CUevent * event_out)
//CUresult cuGraphEventRecordNodeSetEvent(CUgraphNode hNode, CUevent event)
//CUresult cuGraphEventWaitNodeGetEvent(CUgraphNode hNode, CUevent * event_out)
//CUresult cuGraphEventWaitNodeSetEvent(CUgraphNode hNode, CUevent event)
//CUresult cuGraphExecBatchMemOpNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode, const CUDA_BATCH_MEM_OP_NODE_PARAMS * nodeParams)
//CUresult cuGraphExecChildGraphNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode, CUgraph childGraph)

JNIEXPORT jint JNICALL Java_kuda_driverapi_DriverAPI_graphExecDestroy(JNIEnv* env, jobject obj, jlong hGraphExec) {

	CUgraphExec cuGraphExec = reinterpret_cast<CUgraphExec>(hGraphExec);

	CUresult result = cuGraphExecDestroy(cuGraphExec);

	return result;
}

//CUresult cuGraphExecEventRecordNodeSetEvent(CUgraphExec hGraphExec, CUgraphNode hNode, CUevent event)
//CUresult cuGraphExecEventWaitNodeSetEvent(CUgraphExec hGraphExec, CUgraphNode hNode, CUevent event)
//CUresult cuGraphExecExternalSemaphoresSignalNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode, const CUDA_EXT_SEM_SIGNAL_NODE_PARAMS * nodeParams)
//CUresult cuGraphExecExternalSemaphoresWaitNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode, const CUDA_EXT_SEM_WAIT_NODE_PARAMS * nodeParams)
//CUresult cuGraphExecGetFlags(CUgraphExec hGraphExec, cuuint64_t * flags)
//CUresult cuGraphExecHostNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode, const CUDA_HOST_NODE_PARAMS * nodeParams)
//CUresult cuGraphExecKernelNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode, const CUDA_KERNEL_NODE_PARAMS * nodeParams)
//CUresult cuGraphExecMemcpyNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode, const CUDA_MEMCPY3D * copyParams, CUcontext ctx)
//CUresult cuGraphExecMemsetNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode, const CUDA_MEMSET_NODE_PARAMS * memsetParams, CUcontext ctx)
//CUresult cuGraphExecNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode, CUgraphNodeParams * nodeParams)
//CUresult cuGraphExecUpdate(CUgraphExec hGraphExec, CUgraph hGraph, CUgraphExecUpdateResultInfo * resultInfo)
//CUresult cuGraphExternalSemaphoresSignalNodeGetParams(CUgraphNode hNode, CUDA_EXT_SEM_SIGNAL_NODE_PARAMS * params_out)
//CUresult cuGraphExternalSemaphoresSignalNodeSetParams(CUgraphNode hNode, const CUDA_EXT_SEM_SIGNAL_NODE_PARAMS * nodeParams)
//CUresult cuGraphExternalSemaphoresWaitNodeGetParams(CUgraphNode hNode, CUDA_EXT_SEM_WAIT_NODE_PARAMS * params_out)
//CUresult cuGraphExternalSemaphoresWaitNodeSetParams(CUgraphNode hNode, const CUDA_EXT_SEM_WAIT_NODE_PARAMS * nodeParams)
//CUresult cuGraphGetEdges(CUgraph hGraph, CUgraphNode * from, CUgraphNode * to, size_t * numEdges)
//CUresult cuGraphGetEdges_v2(CUgraph hGraph, CUgraphNode * from, CUgraphNode * to, CUgraphEdgeData * edgeData, size_t * numEdges)
//CUresult cuGraphGetNodes(CUgraph hGraph, CUgraphNode * nodes, size_t * numNodes)
//CUresult cuGraphGetRootNodes(CUgraph hGraph, CUgraphNode * rootNodes, size_t * numRootNodes)
//CUresult cuGraphHostNodeGetParams(CUgraphNode hNode, CUDA_HOST_NODE_PARAMS * nodeParams)
//CUresult cuGraphHostNodeSetParams(CUgraphNode hNode, const CUDA_HOST_NODE_PARAMS * nodeParams)
//CUresult cuGraphInstantiate(CUgraphExec * phGraphExec, CUgraph hGraph, unsigned long long flags)
//CUresult cuGraphInstantiateWithParams(CUgraphExec * phGraphExec, CUgraph hGraph, CUDA_GRAPH_INSTANTIATE_PARAMS * instantiateParams)
//CUresult cuGraphKernelNodeCopyAttributes(CUgraphNode dst, CUgraphNode src)
//CUresult cuGraphKernelNodeGetAttribute(CUgraphNode hNode, CUkernelNodeAttrID attr, CUkernelNodeAttrValue * value_out)
//CUresult cuGraphKernelNodeGetParams(CUgraphNode hNode, CUDA_KERNEL_NODE_PARAMS * nodeParams)
//CUresult cuGraphKernelNodeSetAttribute(CUgraphNode hNode, CUkernelNodeAttrID attr, const CUkernelNodeAttrValue * value)
//CUresult cuGraphKernelNodeSetParams(CUgraphNode hNode, const CUDA_KERNEL_NODE_PARAMS * nodeParams)
//CUresult cuGraphLaunch(CUgraphExec hGraphExec, CUstream hStream)
//CUresult cuGraphMemAllocNodeGetParams(CUgraphNode hNode, CUDA_MEM_ALLOC_NODE_PARAMS * params_out)
//CUresult cuGraphMemFreeNodeGetParams(CUgraphNode hNode, CUdeviceptr * dptr_out)
//CUresult cuGraphMemcpyNodeGetParams(CUgraphNode hNode, CUDA_MEMCPY3D * nodeParams)
//CUresult cuGraphMemcpyNodeSetParams(CUgraphNode hNode, const CUDA_MEMCPY3D * nodeParams)
//CUresult cuGraphMemsetNodeGetParams(CUgraphNode hNode, CUDA_MEMSET_NODE_PARAMS * nodeParams)
//CUresult cuGraphMemsetNodeSetParams(CUgraphNode hNode, const CUDA_MEMSET_NODE_PARAMS * nodeParams)
//CUresult cuGraphNodeFindInClone(CUgraphNode * phNode, CUgraphNode hOriginalNode, CUgraph hClonedGraph)
//CUresult cuGraphNodeGetDependencies(CUgraphNode hNode, CUgraphNode * dependencies, size_t * numDependencies)
//CUresult cuGraphNodeGetDependencies_v2(CUgraphNode hNode, CUgraphNode * dependencies, CUgraphEdgeData * edgeData, size_t * numDependencies)
//CUresult cuGraphNodeGetDependentNodes(CUgraphNode hNode, CUgraphNode * dependentNodes, size_t * numDependentNodes)
//CUresult cuGraphNodeGetDependentNodes_v2(CUgraphNode hNode, CUgraphNode * dependentNodes, CUgraphEdgeData * edgeData, size_t * numDependentNodes)
//CUresult cuGraphNodeGetEnabled(CUgraphExec hGraphExec, CUgraphNode hNode, unsigned int* isEnabled)
//CUresult cuGraphNodeGetType(CUgraphNode hNode, CUgraphNodeType * type)
//CUresult cuGraphNodeSetEnabled(CUgraphExec hGraphExec, CUgraphNode hNode, unsigned int  isEnabled)
//CUresult cuGraphNodeSetParams(CUgraphNode hNode, CUgraphNodeParams * nodeParams)
//CUresult cuGraphReleaseUserObject(CUgraph graph, CUuserObject object, unsigned int  count)
//CUresult cuGraphRemoveDependencies(CUgraph hGraph, const CUgraphNode * from, const CUgraphNode * to, size_t numDependencies)
//CUresult cuGraphRemoveDependencies_v2(CUgraph hGraph, const CUgraphNode * from, const CUgraphNode * to, const CUgraphEdgeData * edgeData, size_t numDependencies)
//CUresult cuGraphRetainUserObject(CUgraph graph, CUuserObject object, unsigned int  count, unsigned int  flags)
//CUresult cuGraphUpload(CUgraphExec hGraphExec, CUstream hStream)
//CUresult cuUserObjectCreate(CUuserObject * object_out, void* ptr, CUhostFn destroy, unsigned int  initialRefcount, unsigned int  flags)
//CUresult cuUserObjectRelease(CUuserObject object, unsigned int  count)
//CUresult cuUserObjectRetain(CUuserObject object, unsigned int  count)