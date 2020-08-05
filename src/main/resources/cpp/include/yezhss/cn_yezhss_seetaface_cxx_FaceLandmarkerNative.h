/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class cn_yezhss_seetaface_cxx_FaceLandmarkerNative */

#ifndef _Included_cn_yezhss_seetaface_cxx_FaceLandmarkerNative
#define _Included_cn_yezhss_seetaface_cxx_FaceLandmarkerNative
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     cn_yezhss_seetaface_cxx_FaceLandmarkerNative
 * Method:    init
 * Signature: (Lcn/yezhss/seetaface/po/SeetaModelSetting;)J
 */
JNIEXPORT jlong JNICALL Java_cn_yezhss_seetaface_cxx_FaceLandmarkerNative_init
  (JNIEnv *, jclass, jobject);

/*
 * Class:     cn_yezhss_seetaface_cxx_FaceLandmarkerNative
 * Method:    number
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_cn_yezhss_seetaface_cxx_FaceLandmarkerNative_number
  (JNIEnv *, jclass, jlong);

/*
 * Class:     cn_yezhss_seetaface_cxx_FaceLandmarkerNative
 * Method:    mark
 * Signature: (JLcn/yezhss/seetaface/po/SeetaImageData;Lcn/yezhss/seetaface/po/SeetaRect;)[Lcn/yezhss/seetaface/po/PointWithMask;
 */
JNIEXPORT jobjectArray JNICALL Java_cn_yezhss_seetaface_cxx_FaceLandmarkerNative_mark
  (JNIEnv *, jclass, jlong, jobject, jobject);

/*
 * Class:     cn_yezhss_seetaface_cxx_FaceLandmarkerNative
 * Method:    close
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_cn_yezhss_seetaface_cxx_FaceLandmarkerNative_close
  (JNIEnv *, jclass, jlong);

#ifdef __cplusplus
}
#endif
#endif
