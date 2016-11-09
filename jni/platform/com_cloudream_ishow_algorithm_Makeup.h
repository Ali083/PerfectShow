/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_cloudream_ishow_algorithm_Makeup */

#ifndef _Included_com_cloudream_ishow_algorithm_Makeup
#define _Included_com_cloudream_ishow_algorithm_Makeup
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_cloudream_ishow_algorithm_Makeup
 * Method:    nativeApplyBrow
 * Signature: (Landroid/graphics/Bitmap;Landroid/graphics/Bitmap;[Landroid/graphics/PointF;Landroid/graphics/Bitmap;IF)V
 */
JNIEXPORT void JNICALL Java_com_cloudream_ishow_algorithm_Makeup_nativeApplyBrow
  (JNIEnv *, jclass, jobject, jobject, jobjectArray, jobject, jint, jfloat);

/*
 * Class:     com_cloudream_ishow_algorithm_Makeup
 * Method:    nativeApplyEye
 * Signature: (Landroid/graphics/Bitmap;Landroid/graphics/Bitmap;[Landroid/graphics/PointF;Landroid/graphics/Bitmap;F)V
 */
JNIEXPORT void JNICALL Java_com_cloudream_ishow_algorithm_Makeup_nativeApplyEye
  (JNIEnv *, jclass, jobject, jobject, jobjectArray, jobject, jfloat);

/*
 * Class:     com_cloudream_ishow_algorithm_Makeup
 * Method:    nativeApplyEyeLash
 * Signature: (Landroid/graphics/Bitmap;Landroid/graphics/Bitmap;[Landroid/graphics/PointF;Landroid/graphics/Bitmap;IF)V
 */
JNIEXPORT void JNICALL Java_com_cloudream_ishow_algorithm_Makeup_nativeApplyEyeLash
  (JNIEnv *, jclass, jobject, jobject, jobjectArray, jobject, jint, jfloat);

/*
 * Class:     com_cloudream_ishow_algorithm_Makeup
 * Method:    nativeApplyEyeShadow
 * Signature: (Landroid/graphics/Bitmap;Landroid/graphics/Bitmap;[Landroid/graphics/PointF;[Landroid/graphics/Bitmap;[IF)V
 */
JNIEXPORT void JNICALL Java_com_cloudream_ishow_algorithm_Makeup_nativeApplyEyeShadow
  (JNIEnv *, jclass, jobject, jobject, jobjectArray, jobjectArray, jintArray, jfloat);

/*
 * Class:     com_cloudream_ishow_algorithm_Makeup
 * Method:    nativeApplyIris
 * Signature: (Landroid/graphics/Bitmap;Landroid/graphics/Bitmap;[Landroid/graphics/PointF;Landroid/graphics/Bitmap;Landroid/graphics/Bitmap;F)V
 */
JNIEXPORT void JNICALL Java_com_cloudream_ishow_algorithm_Makeup_nativeApplyIris
  (JNIEnv *, jclass, jobject, jobject, jobjectArray, jobject, jobject, jfloat);

/*
 * Class:     com_cloudream_ishow_algorithm_Makeup
 * Method:    nativeApplyBlush
 * Signature: (Landroid/graphics/Bitmap;Landroid/graphics/Bitmap;[Landroid/graphics/PointF;IIF)V
 */
JNIEXPORT void JNICALL Java_com_cloudream_ishow_algorithm_Makeup_nativeApplyBlush
  (JNIEnv *, jclass, jobject, jobject, jobjectArray, jint, jint, jfloat);

/*
 * Class:     com_cloudream_ishow_algorithm_Makeup
 * Method:    nativeApplyLip
 * Signature: (Landroid/graphics/Bitmap;Landroid/graphics/Bitmap;[Landroid/graphics/PointF;IF)V
 */
JNIEXPORT void JNICALL Java_com_cloudream_ishow_algorithm_Makeup_nativeApplyLip
  (JNIEnv *, jclass, jobject, jobject, jobjectArray, jint, jfloat);

#ifdef __cplusplus
}
#endif
#endif
