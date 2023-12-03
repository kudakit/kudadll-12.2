#include <jni.h>

//https://docs.nvidia.com/cuda/cuda-runtime-api/index.html

#ifdef __cplusplus
extern "C" {
#endif
	//6.1 Device Management
	JNIEXPORT jint JNICALL Java_kuda_RuntimeAPI_getLimit(JNIEnv* env, jobject obj, jbyte limit);

	JNIEXPORT jstring JNICALL Java_kuda_RuntimeAPI_getPCIBusId(JNIEnv* env, jobject obj, jint device);

	JNIEXPORT jint JNICALL Java_kuda_RuntimeAPI_getStreamPriorityRange(JNIEnv* env, jobject obj);

	JNIEXPORT jint JNICALL Java_kuda_RuntimeAPI_setCacheConfig(JNIEnv* env, jobject obj, jint cacheConfig);

	JNIEXPORT jint JNICALL Java_kuda_RuntimeAPI_setLimit(JNIEnv* env, jobject obj, jint limit, jsize value);

	JNIEXPORT jint JNICALL Java_kuda_RuntimeAPI_syncDevice(JNIEnv* env, jobject obj);

	JNIEXPORT jint JNICALL Java_kuda_RuntimeAPI_resetDevice(JNIEnv* env, jobject obj);

	JNIEXPORT jint JNICALL Java_kuda_RuntimeAPI_getRuntimeVersion(JNIEnv* env, jobject obj);

	JNIEXPORT jint JNICALL Java_kuda_RuntimeAPI_getDivice(JNIEnv* env, jobject obj);

	JNIEXPORT jint JNICALL Java_kuda_RuntimeAPI_getDiviceCount(JNIEnv* env, jobject obj);

	JNIEXPORT jint JNICALL Java_kuda_RuntimeAPI_initDevice(JNIEnv* env, jobject obj, jint device, jint deviceFlags, jint flags);

	JNIEXPORT jint JNICALL Java_kuda_RuntimeAPI_lpcCloseMemHandle(JNIEnv* env, jobject obj, jlong devicePtr);

	JNIEXPORT jint JNICALL Java_kuda_RuntimeAPI_setDevice(JNIEnv* env, jobject obj, jint device);

	JNIEXPORT jint JNICALL Java_kuda_RuntimeAPI_setDeviceFlags(JNIEnv* env, jobject obj, jint flags);
#ifdef __cplusplus
}
#endif