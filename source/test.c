#include <stdio.h>
#include <windows.h>

void pause()
{
    system("pause");
}
int main()
{

    FILE *file; // 声明文件指针

    file = fopen("C:\\C_PP\\txt\\example.txt", "w");

    SYSTEMTIME sysTime;
    GetLocalTime(&sysTime); // 获取本地时间（含毫秒）

    // 格式化输出时间
    printf("time:%04d-%02d-%02d %02d:%02d:%02d.%03d\n",
           sysTime.wYear, sysTime.wMonth, sysTime.wDay,
           sysTime.wHour, sysTime.wMinute, sysTime.wSecond, sysTime.wMilliseconds);

    // 获取 UTC 时间（不含时区偏移）
    GetSystemTime(&sysTime);
    printf("time:%04d-%02d-%02d %02d:%02d:%02d.%03d\n",
           sysTime.wYear, sysTime.wMonth, sysTime.wDay,
           sysTime.wHour, sysTime.wMinute, sysTime.wSecond, sysTime.wMilliseconds);

    fprintf(file, "%04d-%02d-%02d %02d:%02d:%02d.%03d\n", sysTime.wYear, sysTime.wMonth, sysTime.wDay,
            sysTime.wHour, sysTime.wMinute, sysTime.wSecond, sysTime.wMilliseconds);

    fclose(file);
    printf("文件已成功写入！\n");
    pause();
    return 0;
}