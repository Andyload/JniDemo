/*
 * fileutils.h
 *
 *  Created on: 2016Äê4ÔÂ17ÈÕ
 *      Author: Administrator
 */

#ifndef FILEUTILS_H_
#define FILEUTILS_H_

class FileUtils
{
	public:
		bool copy(const char* firstPath,const char* copyPath);
		bool move(const char* firstPath,const char* movePath);
		bool createFile(const char* fileName);
};

#endif /* FILEUTILS_H_ */
