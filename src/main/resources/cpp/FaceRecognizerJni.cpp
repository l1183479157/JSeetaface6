#include "pch.h"
#include <yezhss/cn_yezhss_seetaface_cxx_FaceRecognizerNative.h>
#include <seeta/FaceRecognizer.h>

/*
 * Class:     cn_yezhss_seetaface_cxx_FaceRecognizerNative
 * Method:    init
 * Signature: (Lcn/yezhss/seetaface/po/SeetaModelSetting;)J
 */
JNIEXPORT jlong JNICALL Java_cn_yezhss_seetaface_cxx_FaceRecognizerNative_init
(JNIEnv* env, jclass, jobject setting)
{
	seeta::ModelSetting modelSetting = toSetting(env, setting);
	seeta::FaceRecognizer* recognizer = new seeta::FaceRecognizer(modelSetting);
	return (jlong)recognizer;
}

/*
 * Class:     cn_yezhss_seetaface_cxx_FaceRecognizerNative
 * Method:    cropFace
 * Signature: (JLcn/yezhss/seetaface/po/SeetaImageData;[Lcn/yezhss/seetaface/po/SeetaPointF;)Lcn/yezhss/seetaface/po/SeetaImageData;
 */
JNIEXPORT jobject JNICALL Java_cn_yezhss_seetaface_cxx_FaceRecognizerNative_cropFace
(JNIEnv* env, jclass, jlong nativeId, jobject image, jobjectArray points)
{
	seeta::FaceRecognizer* recognizer = (seeta::FaceRecognizer*) nativeId;
	SeetaImageData imageData = toSeetaImageData(env, image);
	SeetaPointF* pointFs = toPoints(env, points);
	SeetaImageData face = recognizer->CropFace(imageData, pointFs);
	delete pointFs;
	return toSeetaImageData(env, face);
}

/*
 * Class:     cn_yezhss_seetaface_cxx_FaceRecognizerNative
 * Method:    extractCroppedFace
 * Signature: (JLcn/yezhss/seetaface/po/SeetaImageData;)[F
 */
JNIEXPORT jfloatArray JNICALL Java_cn_yezhss_seetaface_cxx_FaceRecognizerNative_extractCroppedFace
(JNIEnv* env, jclass, jlong nativeId, jobject image)
{
	seeta::FaceRecognizer* recognizer = (seeta::FaceRecognizer*) nativeId;
	int size = recognizer->GetExtractFeatureSize();
	float* features = new float[size];
	SeetaImageData imageData = toSeetaImageData(env, image);
	bool isSuccess = recognizer->ExtractCroppedFace(imageData, features);
	if (isSuccess) 
	{
		int size = recognizer->GetExtractFeatureSize();
		jfloatArray featuresJava = env->NewFloatArray(size);
		env->SetFloatArrayRegion(featuresJava, 0, size, features);
		delete features;
		return featuresJava;
	}
	else
	{
		delete features;
		return NULL;
	}
}

/*
 * Class:     cn_yezhss_seetaface_cxx_FaceRecognizerNative
 * Method:    extract
 * Signature: (JLcn/yezhss/seetaface/po/SeetaImageData;[Lcn/yezhss/seetaface/po/SeetaPointF;)[F
 */
JNIEXPORT jfloatArray JNICALL Java_cn_yezhss_seetaface_cxx_FaceRecognizerNative_extract
(JNIEnv* env, jclass, jlong nativeId, jobject image, jobjectArray points)
{
	seeta::FaceRecognizer* recognizer = (seeta::FaceRecognizer*) nativeId;
	int size = recognizer->GetExtractFeatureSize();
	float* features = new float[size];
	SeetaImageData imageData = toSeetaImageData(env, image);
	SeetaPointF* pointFs = toPoints(env, points);
	bool isSuccess = recognizer->Extract(imageData, pointFs, features);
	if (isSuccess)
	{
		jfloatArray featuresJava = env->NewFloatArray(size);
		env->SetFloatArrayRegion(featuresJava, 0, size, features);
		delete features, pointFs;
		return featuresJava;
	}
	else
	{
		delete features, pointFs;
		return NULL;
	}
}

/*
 * Class:     cn_yezhss_seetaface_cxx_FaceRecognizerNative
 * Method:    calculateSimilarity
 * Signature: (J[F[F)F
 */
JNIEXPORT jfloat JNICALL Java_cn_yezhss_seetaface_cxx_FaceRecognizerNative_calculateSimilarity
(JNIEnv* env, jclass, jlong nativeId, jfloatArray featuresOne, jfloatArray featuresTwo)
{
	seeta::FaceRecognizer* recognizer = (seeta::FaceRecognizer*) nativeId;
	jfloat* features1 = env->GetFloatArrayElements(featuresOne, 0);
	jfloat* features2 = env->GetFloatArrayElements(featuresTwo, 0);
	return recognizer->CalculateSimilarity(features1, features2);
}

/*
 * Class:     cn_yezhss_seetaface_cxx_FaceRecognizerNative
 * Method:    set
 * Signature: (JID)V
 */
JNIEXPORT void JNICALL Java_cn_yezhss_seetaface_cxx_FaceRecognizerNative_set
(JNIEnv* env, jclass, jlong nativeId, jint property, jdouble val)
{
	seeta::FaceRecognizer* recognizer = (seeta::FaceRecognizer*) nativeId;
	recognizer->set(seeta::FaceRecognizer::Property(property), val);
}

/*
 * Class:     cn_yezhss_seetaface_cxx_FaceRecognizerNative
 * Method:    get
 * Signature: (JI)D
 */
JNIEXPORT jdouble JNICALL Java_cn_yezhss_seetaface_cxx_FaceRecognizerNative_get
(JNIEnv* env, jclass, jlong nativeId, jint property)
{
	seeta::FaceRecognizer* recognizer = (seeta::FaceRecognizer*) nativeId;
	return recognizer->get(seeta::FaceRecognizer::Property(property));
}

/*
 * Class:     cn_yezhss_seetaface_cxx_FaceRecognizerNative
 * Method:    close
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_cn_yezhss_seetaface_cxx_FaceRecognizerNative_close
(JNIEnv*, jclass, jlong nativeId)
{
	seeta::FaceRecognizer* recognizer = (seeta::FaceRecognizer*) nativeId;
	delete recognizer;
}