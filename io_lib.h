#ifndef _io_lib_h
#define _io_lib_h
#include "dependence.h"
#include "Matrix.h"

int PrintLog(LogFile);            // ReturnLog函数返回的是一个临时的右值，如果引用传参会被销毁
void PrintMatrix(const Matrix &); // Matrix的生命周期很久
int PrintHelp();

#endif