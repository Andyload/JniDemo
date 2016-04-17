/*
 * hello.h
 *
 *  Created on: 2016Äê4ÔÂ17ÈÕ
 *      Author: Administrator
 */
#include "hello.h"
#include <string.h>
const char* Hello::stringFromJNI()
{
	const char* ch = {"hello,JNI!"};
	return ch;
}

int Hello::calculate(const char* sCalculate,int math,int math2)
{
	int result = 0;
	if(strcmp(sCalculate,"-") == 0)
	{
		result = math - math2;
	}
	else if(strcmp(sCalculate,"*") == 0)
	{
		result = math * math2;
	}
	else if(strcmp(sCalculate,"/") == 0)
	{
		if(math2 == 0)
			result = 1001;
		else
			result = math / math2;

	}else{
		result = math + math2;
	}
	return result;
}
