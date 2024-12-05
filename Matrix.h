#ifndef _Matrix_h
#define _Matrix_h
#include <dependence.h>

// 矩阵类
class Matrix
{

private:
    int columns;
    int rows;
    int **array_ptr;
    string temp_message;

public:
    Matrix() : columns(0), rows(0), array_ptr(nullptr), temp_message("") {} // 默认构造函数
    Matrix(int row, int col);                                               // 参数构造函数
    Matrix(const Matrix &);                                                 // 复制构造函数
    // Matrix(Matrix &&);                                                      // 移动构造函数

    void Transform(int mode, int index); // 选择row/col， 选择位置
    // int CheckRank();                     // 计算检查rank
    LogFile ReturnLog(bool is_wrong);

    ~Matrix();
};

#endif