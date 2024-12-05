#include "io_lib.h"
#include <iostream>
#include <fstream>
#include <string>

int PrintLog(LogFile log_temp)
{
    std::ofstream outfile("VMT_log.txt", std::ios::app); // 打开文件以追加模式
    if (!outfile)
    {
        cerr << "Failed to open file at PrintLog!" << endl;
        return 1;
    }

    cout.rdbuf(outfile.rdbuf()); // 重定向 cout 到文件流
    string title;
    if (log_temp.type)
    {
        title = "[Error]Log_ID:" + to_string(log_temp.id);
    }
    else
    {
        title = "[Normal]Log_ID:" + to_string(log_temp.id);
    }
    cout << title << endl;
    cout << log_temp.message; // 每一条单独的message都自带了\t和\n
    outfile.close();
    return 0;
}

void PrintMatrix(const Matrix &mat)
{
    for (int i = 0; i < mat.rows; i++)
    {
        for (int j = 0; j < mat.columns; j++)
        {
            cout << mat.array_ptr[i][j];
        }
        cout << endl;
    }
}

int PrintHelp()
{
    std::ifstream help_document("help_document.txt", std::ios::in);
    if (!help_document)
    {
        cerr << "Failed to open file at PrintHelp!" << endl;
        return 1;
    }

    string line;
    while (std::getline(help_document, line))
    {
        cout << line << endl; // 输出每一行
    }

    help_document.close();
    return 0;
}