#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void pause()
{
    system("pause");
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   PSTR szCmdLine, int iCmdShow)
{
    // 在这里添加代码逻辑，比如调用 Windows API 函数创建窗口等

    ShowWindow(GetConsoleWindow(), SW_HIDE);
    // 这里简单地使用 MessageBox 显示信息
    MessageBox(NULL, TEXT("Hello, Windows!"), TEXT("Message"), MB_OK);
    // pause();

    return 0;
}