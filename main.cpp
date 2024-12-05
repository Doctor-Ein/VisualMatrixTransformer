#include "dependecne.h"
#include "Matrix.h"
#include "io_lib.h"
#include <cstdlib>

int main()
{
    int m, n;
    cout << "Please input m by n matrix" << endl;
    cin >> m >> n;
    Matrix mat = Matrix(m, n);
    PrintMatrix(mat);
    int mode, index;
    cout << "input the mode and the index:";
    cin >> mode >> index;
    while (true)
    {
        // std::system("clear");
        cout << endl;
        mat.Transform(mode, index);
        PrintMatrix(mat);
        cout << "input the mode(0 for row,1 for col,-1 to quit) and the index:";
        cin >> mode >> index;
        if (mode == -1 && index == 1) // 确认退出
        {
            break;
        }
        else if (mode == -1 && index == 0) // 输出帮助文档
        {
            PrintHelp();
        }
    }
    PrintLog(mat.ReturnLog(false));
    cout << "exit with " << cnt << " times operations and all the log are recorded!" << endl;
}