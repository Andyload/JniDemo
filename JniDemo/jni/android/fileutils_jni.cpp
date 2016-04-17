#include <jni.h>
#include <string.h>
#include <stdlib.h>
#include "fileutils.h"
#include "my_log.h"

jfieldID fileUtilsFieldID;

static void FileUtils_nativeConstructor(JNIEnv* env,jobject thiz)
{
	FileUtils* fileUtils = new FileUtils();
	env->SetIntField(thiz,fileUtilsFieldID,(int)fileUtils);
}

static void FileUtils_nativeDestructor(JNIEnv* env,jobject thiz)
{
	FileUtils* fileUtils = (FileUtils*)env->GetIntField(thiz,fileUtilsFieldID);
	if(fileUtils)
		delete fileUtils;
	env->SetIntField(thiz,fileUtilsFieldID,0);
}

static jboolean FileUtils_copy(JNIEnv* env,jobject thiz,jstring firstPath,jstring copyPath)
{
	FileUtils* fileUtils = (FileUtils*)env->GetIntField(thiz,fileUtilsFieldID);
	if(fileUtils == NULL)
		return -1;
	const char* s_filePath = env->GetStringUTFChars(firstPath,NULL);
	const char* s_copyPath = env->GetStringUTFChars(copyPath,NULL);
	bool ret = fileUtils->copy(s_filePath,s_copyPath);
	env->ReleaseStringUTFChars(firstPath,s_filePath);
	env->ReleaseStringUTFChars(copyPath,s_copyPath);
	return ret;
}

static jboolean FileUtils_move(JNIEnv* env,jobject thiz,jstring firstPath,jstring copyPath)
{
	FileUtils* fileUtils = (FileUtils*)env->GetIntField(thiz,fileUtilsFieldID);
	if(fileUtils == NULL)
		return -1;
	const char* s_filePath = env->GetStringUTFChars(firstPath,NULL);
	const char* s_copyPath = env->GetStringUTFChars(copyPath,NULL);
	bool ret = fileUtils->move(s_filePath,s_copyPath);
	env->ReleaseStringUTFChars(firstPath,s_filePath);
	env->ReleaseStringUTFChars(copyPath,s_copyPath);
	return ret;
}

static jboolean FileUtils_createFile(JNIEnv* env,jobject thiz,jstring filePath)
{
	FileUtils* fileUtils = (FileUtils*)env->GetIntField(thiz,fileUtilsFieldID);
	if(fileUtils == NULL)
		return -1;
	const char* s_filePath = env->GetStringUTFChars(filePath,NULL);
	bool ret = fileUtils->createFile(s_filePath);
	env->ReleaseStringUTFChars(filePath,s_filePath);
	return ret;
}

int register_com_qzi_jnidemo_FileUtils(JNIEnv* env)
{
	static JNINativeMethod CMFileUtilsMethods[]= {
			{"nativeConstructor","()V",(void*)FileUtils_nativeConstructor},
			{"copy","(Ljava/lang/String;Ljava/lang/String;)Z",(void*)FileUtils_copy},
			{"move","(Ljava/lang/String;Ljava/lang/String;)Z",(void*)FileUtils_move},
			{"createFile","(Ljava/lang/String;)Z",(void*)FileUtils_createFile},
			{"nativeDestructor","()V",(void*)FileUtils_nativeDestructor}
	};

	jclass clazz = env->FindClass("com/qzi/jnidemo/FileUtils");
	if(clazz == 0){
		return -1;
	}
	fileUtilsFieldID = env->GetFieldID(clazz,"mJniObject","I");
	if(fileUtilsFieldID == 0)
	{
		return -1;
	}

	return env->RegisterNatives(clazz,CMFileUtilsMethods,sizeof(CMFileUtilsMethods)/sizeof(CMFileUtilsMethods[0]));

}
