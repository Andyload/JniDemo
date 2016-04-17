#include <jni.h>
#include <string.h>
#include <stdlib.h>
#include "hello.h"

jfieldID helloFieldID;

static void Hello_nativeConstructor(JNIEnv* env,jobject thiz)
{
	Hello* he = new Hello();
	env->SetIntField(thiz,helloFieldID,(int)he);
}

static void Hello_nativeDestructor(JNIEnv* env,jobject thiz)
{
	Hello* he = (Hello*)env->GetIntField(thiz,helloFieldID);
	if(he)
		delete he;
	env->SetIntField(thiz,helloFieldID,0);
}

static jstring Hello_stringFromJNI(JNIEnv* env,jobject thiz)
{
	Hello* he = (Hello*)env->GetIntField(thiz,helloFieldID);
	if(he == NULL)
		return env->NewStringUTF("error");
	return env->NewStringUTF(he->stringFromJNI());
}

static jint Hello_calculate(JNIEnv* env,jobject thiz,jstring calculate,jint math,jint math2)
{
	Hello* he = (Hello*)env->GetIntField(thiz,helloFieldID);
	if(he == NULL)
		return -1;
	int n_math = math;
	int n_math2 = math2;
	const char* cal = env->GetStringUTFChars(calculate,NULL);
	int result = he->calculate(cal,n_math,n_math2);
	env->ReleaseStringUTFChars(calculate,cal);
	return (jint)result;
}

int register_com_qzi_jnidemo_HelloJni(JNIEnv* env)
{
	static JNINativeMethod CMHelloMethods[]= {
			{"nativeConstructor","()V",(void*)Hello_nativeConstructor},
			{"stringFromJNI","()Ljava/lang/String;",(void*)Hello_stringFromJNI},
			{"calculate","(Ljava/lang/String;II)I",(void*)Hello_calculate},
			{"nativeDestructor","()V",(void*)Hello_nativeDestructor}
	};

	jclass clazz = env->FindClass("com/qzi/jnidemo/HelloJni");
	if(clazz == 0){
		return -1;
	}
	helloFieldID = env->GetFieldID(clazz,"mJniObject","I");
	if(helloFieldID == 0)
	{
		return -1;
	}

	return env->RegisterNatives(clazz,CMHelloMethods,sizeof(CMHelloMethods)/sizeof(CMHelloMethods[0]));

}
