/*
 * fileutils.cpp
 *
 *  Created on: 2016Äê4ÔÂ17ÈÕ
 *      Author: Administrator
 */
#include "fileutils.h"
#include <string.h>
#include <stdlib.h>
#include "my_log.h"

bool FileUtils::copy(const char* firstPath,const char* copyPath)
{
	char execute[500] = {"cp -r "};
	strcat(execute,firstPath);
	strcat(execute," ");
	strcat(execute,copyPath);
	if(system(execute) < 0)
		return false;
	return true;
}

bool FileUtils::move(const char* firstPath,const char* movePath)
{
	char execute[500] = {"mv "};
	strcat(execute,firstPath);
	strcat(execute," ");
	strcat(execute,movePath);
	if(system(execute) < 0)
		return false;
	return true;
}

bool FileUtils::createFile(const char* fileName)
{
	char command[200] = {"touch "};
	char* execute = strcat(command,fileName);
	int ret = system(execute);
	if(ret<0)
		return false;
	return true;
}



