#include <jni.h>
#include <string.h>
#include <stdlib.h>
#include "fileutils.h"
#include "my_log.h"
#include "utf8ncpy.h"

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
	const jchar* j_file = env->GetStringChars(firstPath,NULL);
	jsize f_size = env->GetStringLength(firstPath);
	char* s_file = UTF16toUTF8((jchar*)j_file,(size_t*)&f_size);

	const jchar* j_cp = env->GetStringChars(copyPath,NULL);
	jsize f_size2 = env->GetStringLength(copyPath);
	char* s_cp_file = UTF16toUTF8((jchar*)j_cp,(size_t*)&f_size2);
	bool ret = fileUtils->copy(s_file,s_cp_file);
	env->ReleaseStringChars(firstPath,j_file);
	env->ReleaseStringChars(copyPath,j_cp);
	free(s_file);
	free(s_cp_file);
	return ret;
}

static jboolean FileUtils_move(JNIEnv* env,jobject thiz,jstring firstPath,jstring copyPath)
{
	FileUtils* fileUtils = (FileUtils*)env->GetIntField(thiz,fileUtilsFieldID);
	if(fileUtils == NULL)
		return -1;
	const jchar* j_file = env->GetStringChars(firstPath,NULL);
	jsize f_size = env->GetStringLength(firstPath);
	char* s_file = UTF16toUTF8((jchar*)j_file,(size_t*)&f_size);

	const jchar* j_cp = env->GetStringChars(copyPath,NULL);
	jsize f_size2 = env->GetStringLength(copyPath);
	char* s_cp_file = UTF16toUTF8((jchar*)j_cp,(size_t*)&f_size2);
	bool ret = fileUtils->copy(s_file,s_cp_file);
	env->ReleaseStringChars(firstPath,j_file);
	env->ReleaseStringChars(copyPath,j_cp);
	free(s_file);
	free(s_cp_file);
	return ret;
}

static jboolean FileUtils_createFile(JNIEnv* env,jobject thiz,jstring filePath)
{
	FileUtils* fileUtils = (FileUtils*)env->GetIntField(thiz,fileUtilsFieldID);
	if(fileUtils == NULL)
		return -1;
	const jchar* jFilePath = env->GetStringChars(filePath,NULL);
	jsize j_size = env->GetStringLength(filePath);
	char* s_filePath = UTF16toUTF8((jchar*)jFilePath,(size_t*)&j_size);
	bool ret = fileUtils->createFile(s_filePath);
	env->ReleaseStringChars(filePath,jFilePath);
	free(s_filePath);
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
