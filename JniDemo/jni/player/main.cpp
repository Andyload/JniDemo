#include <jni.h>
#include <string.h>

extern int register_com_qzi_jnidemo_HelloJni(JNIEnv* env);
extern int register_com_qzi_jnidemo_FileUtils(JNIEnv* env);

jint JNI_OnLoad(JavaVM *vm, void *reserved)
{
	JNIEnv* env = NULL;

	if(vm->GetEnv((void**) &env,JNI_VERSION_1_4) != JNI_OK)
	{
		return -1;
	}

	if(-1 == register_com_qzi_jnidemo_HelloJni(env))
	{
		return -1;
	}

	if(-1 == register_com_qzi_jnidemo_FileUtils(env))
	{
		return -1;
	}

	return JNI_VERSION_1_4;

}
