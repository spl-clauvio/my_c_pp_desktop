#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void pause()
{
    system("pause");
}

int main()
{
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    int i = 1;
    int flag = 1;
    FILE *file;

    SYSTEMTIME sysTime;
    GetLocalTime(&sysTime); // 获取本地时间（含毫秒）

    file = fopen("C:\\C_PP\\txt\\bitsrun log.txt", "a");

    fprintf(file, "activate time:%04d-%02d-%02d %02d:%02d:%02d.%03d\n", sysTime.wYear, sysTime.wMonth, sysTime.wDay,
            sysTime.wHour, sysTime.wMinute, sysTime.wSecond, sysTime.wMilliseconds);

    fclose(file);
    // system("bitsrun logout");

    do
    {
        flag = system("bitsrun login");
        printf("%d  ", flag);
        if (flag)
        {
            printf("Try times: %d   failed\n", i, flag);
        }
        else
            printf("Try times: %d   sucessed\n", i, flag);

        i++;
        Sleep(1000);
    } while (flag && i < 30);

    GetLocalTime(&sysTime); // 获取本地时间（含毫秒）
    file = fopen("C:\\C_PP\\txt\\bitsrun log.txt", "a");

    fprintf(file, "end time:%04d-%02d-%02d %02d:%02d:%02d.%03d\n\n", sysTime.wYear, sysTime.wMonth, sysTime.wDay,
            sysTime.wHour, sysTime.wMinute, sysTime.wSecond, sysTime.wMilliseconds);

    fclose(file);

    Sleep(5000);

    return 0;
}