#include <jni.h>
#include <string.h>
#include <stdlib.h>
#include "hello.h"
#include "utf8ncpy.h"

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
		return NULL;
	char* jni_str = (char*)he->stringFromJNI();
	size_t size = strlen(jni_str);
	jchar* data = UTF8toUTF16((char*)jni_str,&size);
	jstring str = env->NewString(data,size);
	free(data);
	return str;
}

static jint Hello_calculate(JNIEnv* env,jobject thiz,jstring calculate,jint math,jint math2)
{
	Hello* he = (Hello*)env->GetIntField(thiz,helloFieldID);
	if(he == NULL)
		return -1;
	const jchar* cal = env->GetStringChars(calculate,NULL);
	jsize cal_size = env->GetStringLength(calculate);
	char* cal2 = UTF16toUTF8((jchar*)cal,(size_t*)&cal_size);
	int result = he->calculate(cal2,math,math2);
	env->ReleaseStringChars(calculate,cal);
	free(cal2);
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
