/*
 * Copyright (C) 2009 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
#include <string.h>
#include <jni.h>
#include <stdio.h>
#include "hello-jni.h"
#include "include/Utils.h"
#include "my_log.h"

/* This is a trivial JNI example where we use a native method
 * to return a new VM String. See the corresponding Java source
 * file located at:
 *
 *   apps/samples/hello-jni/project/src/com/example/hellojni/HelloJni.java
 */
jstring
Java_com_qzi_jnidemo2_Utils_GetText( JNIEnv* env,jobject thiz)
{

    return (*env)->NewStringUTF(env, "Hello from JNI !");
}

jint
Java_com_qzi_jnidemo2_Utils_add( JNIEnv* env,jobject thiz,jint a,jint b)
{
    int aa =a;
    int bb = b;
    return (jint)qq_add(aa,bb);
}

jboolean Java_com_qzi_jnidemo2_Utils_createFile( JNIEnv* env,jobject thiz,jstring sPath)
{
	const char* s_path = (*env)->GetStringUTFChars(env,sPath,NULL);
	MY_LOG_INFO("openfile_%s",s_path);
	FILE* f_stream = fopen(s_path,"w+");
	if(NULL == f_stream)
	{
		return 0;
	}
	else
	{
		if(EOF == fputs("hello\n",f_stream))
		{

		}
		else
		{
			fflush(f_stream);
			f_stream = NULL;
		}
		return 1;
	}
}

