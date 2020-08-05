#include "pch.h"
#include <yezhss/cn_yezhss_seetaface_cxx_GenderPredictorNative.h>
#include <seeta/GenderPredictor.h>

/*
 * Class:     cn_yezhss_seetaface_cxx_GenderPredictorNative
 * Method:    init
 * Signature: (Lcn/yezhss/seetaface/po/SeetaModelSetting;)J
 */
JNIEXPORT jlong JNICALL Java_cn_yezhss_seetaface_cxx_GenderPredictorNative_init
(JNIEnv* env, jclass, jobject setting)
{
	seeta::ModelSetting modelSetting = toSetting(env, setting);
	seeta::GenderPredictor* genderPredictor = new seeta::GenderPredictor(modelSetting);
	return (jlong)genderPredictor;
}

/*
 * Class:     cn_yezhss_seetaface_cxx_GenderPredictorNative
 * Method:    cropFace
 * Signature: (JLcn/yezhss/seetaface/po/SeetaImageData;[Lcn/yezhss/seetaface/po/SeetaPointF;)Lcn/yezhss/seetaface/po/SeetaImageData;
 */
JNIEXPORT jobject JNICALL Java_cn_yezhss_seetaface_cxx_GenderPredictorNative_cropFace
(JNIEnv* env, jclass, jlong nativeId, jobject imageData, jobjectArray seetaPointFs)
{
	seeta::GenderPredictor* genderPredictor = (seeta::GenderPredictor*) nativeId;
	SeetaImageData image = toSeetaImageData(env, imageData);
	SeetaImageData face;
	SeetaPointF* points = toPoints(env, seetaPointFs);
	bool isCrop = genderPredictor->CropFace(image, points, face);
	delete points;
	return isCrop ? toSeetaImageData(env, face) : NULL;
}

/*
 * Class:     cn_yezhss_seetaface_cxx_GenderPredictorNative
 * Method:    predictGender
 * Signature: (JLcn/yezhss/seetaface/po/SeetaImageData;)I
 */
JNIEXPORT jint JNICALL Java_cn_yezhss_seetaface_cxx_GenderPredictorNative_predictGender
(JNIEnv* env, jclass, jlong nativeId, jobject face)
{
	seeta::GenderPredictor* genderPredictor = (seeta::GenderPredictor*) nativeId;
	SeetaImageData image = toSeetaImageData(env, face);
	seeta::GenderPredictor::GENDER gender;
	bool isSuccess = genderPredictor->PredictGender(image, gender);
	int result = -1;
	if (isSuccess) {
		result = gender;
	}
	return result;
}

/*
 * Class:     cn_yezhss_seetaface_cxx_GenderPredictorNative
 * Method:    predictGenderWithCrop
 * Signature: (JLcn/yezhss/seetaface/po/SeetaImageData;[Lcn/yezhss/seetaface/po/SeetaPointF;)I
 */
JNIEXPORT jint JNICALL Java_cn_yezhss_seetaface_cxx_GenderPredictorNative_predictGenderWithCrop
(JNIEnv* env, jclass, jlong nativeId, jobject imageData, jobjectArray points)
{
	seeta::GenderPredictor* genderPredictor = (seeta::GenderPredictor*) nativeId;
	SeetaImageData image = toSeetaImageData(env, imageData);
	SeetaPointF* pointFs = toPoints(env, points);
	seeta::GenderPredictor::GENDER gender;
	bool isSuccess = genderPredictor->PredictGenderWithCrop(image, pointFs, gender);
	int result = -1;
	if (isSuccess) {
		result = gender;
	}
	delete pointFs;
	return result;
}

/*
 * Class:     cn_yezhss_seetaface_cxx_GenderPredictorNative
 * Method:    set
 * Signature: (JID)V
 */
JNIEXPORT void JNICALL Java_cn_yezhss_seetaface_cxx_GenderPredictorNative_set
(JNIEnv* env, jclass, jlong nativeId, jint property, jdouble value)
{
	seeta::GenderPredictor* genderPredictor = (seeta::GenderPredictor*) nativeId;
	genderPredictor->set(seeta::GenderPredictor::Property(property), value);
}

/*
 * Class:     cn_yezhss_seetaface_cxx_GenderPredictorNative
 * Method:    get
 * Signature: (JI)D
 */
JNIEXPORT jdouble JNICALL Java_cn_yezhss_seetaface_cxx_GenderPredictorNative_get
(JNIEnv*, jclass, jlong nativeId, jint property)
{
	seeta::GenderPredictor* genderPredictor = (seeta::GenderPredictor*) nativeId;
	return genderPredictor->get(seeta::GenderPredictor::Property(property));
}

/*
 * Class:     cn_yezhss_seetaface_cxx_GenderPredictorNative
 * Method:    close
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_cn_yezhss_seetaface_cxx_GenderPredictorNative_close
(JNIEnv*, jclass, jlong nativeId)
{
	seeta::GenderPredictor* genderPredictor = (seeta::GenderPredictor*) nativeId;
	delete genderPredictor;
}