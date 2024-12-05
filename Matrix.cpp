#include "Matrix.h"
#include "dependence.h"
#include <random>

Matrix::Matrix(int row, int col) : rows(row), columns(col), temp_message("")
{
    cerr << "Correctly Enter the func to construct Matrix!Keep Going?" << endl;
    char s;
    cin >> s;
    std::random_device rd;                         // 使用随机设备初始化随机数生成器
    std::mt19937 generator(rd());                  // 使用随机设备初始化随机数生成器
    std::uniform_int_distribution<int> dist(0, 1); // 生成 0 或 1

    // 动态分配二维数组
    array_ptr = new int *[rows]; // 行数为 rows，列数为 columns
    if (array_ptr == nullptr)
    {
        cerr << "[Error]array_ptr is not correctly constructed!" << endl;
    }
    for (int i = 0; i < rows; i++)
    {
        array_ptr[i] = new int[columns]; // 每行分配 columns 个 int
        if (array_ptr == nullptr)
        {
            cerr << "[Error]array_ptr[" << i << "] is not correctly constructed!" << endl;
        }
        for (int j = 0; j < columns; j++)
        {
            array_ptr[i][j] = dist(generator); // 使用随机数生成器填充矩阵
        }
    }
}

Matrix::Matrix(const Matrix &mat) : rows(mat.rows), columns(mat.columns), temp_message(mat.temp_message)
{
    temp_message += "\tMatrix Copy Construction Complete\n"; // 默认保留原日志信息
    // 动态分配二维数组，并复制val
    array_ptr = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        array_ptr[i] = new int[columns];
        for (int j = 0; j < columns; j++)
        {
            array_ptr[i][j] = mat.array_ptr[i][j];
        }
    }
}

// Matrix::Matrix(Matrix &&mat) : rows(mat.rows), columns(mat.columns), array_ptr(mat.array_ptr), temp_message(mat.temp_message)
// {
//     temp_message += "\tMatrix Move Construction Complete\n"; // 默认保留原日志信息
//     mat.array_ptr = nullptr;
// }

void Matrix::Transform(int mode, int index)
{
    temp_message += "\tGetCommand:mode=" + to_string(mode) + ",index=" + to_string(index) + "\n";
    if (mode == 0) // 行变换
    {
        for (int j = 0; j < columns; j++)
        {
            array_ptr[index][j] = !(array_ptr[index][j]);
        }
    }
    else if (mode == 1) // 列变换
    {
        for (int i = 0; i < rows; i++)
        {
            array_ptr[i][index] = !(array_ptr[i][index]);
        }
    }
    else
    {
        cout << "[Warning]:invalid Transform mode,read " << mode << ", expect 0 for rows, 1 for columns!" << endl;
        temp_message += "\tGet invalid Transform mode:" + to_string(mode) + ", no other operation by default\n";

        // TODO:问题发生时的临时日志登记
    }
}

// int Matrix::CheckRank // TODO
// {
//     return 0;
// }

LogFile Matrix::ReturnLog(bool is_wrong)
{
    if (is_wrong)
    {
        return LogFile(++cnt, 1, temp_message);
    }
    else
    {
        return LogFile(++cnt, 0, temp_message);
    }
}

Matrix::~Matrix()
{
    for (int i = 0; i < rows; i++) // 删除每一行的数组
    {
        delete[] array_ptr[i];
    }
    delete[] array_ptr; // 删除行指针数组
}