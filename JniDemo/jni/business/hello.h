/*
 * hello.h
 *
 *  Created on: 2016��4��17��
 *      Author: Administrator
 */

#ifndef HELLO_H_
#define HELLO_H_

class Hello
{
public:
	const char* stringFromJNI();
	int calculate(const char* sCalculate,int math,int math2);
};

#endif /* HELLO_H_ */
