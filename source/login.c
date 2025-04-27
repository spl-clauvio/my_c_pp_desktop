#include <stdio.h>
#include <io.h> // Windows 必须包含
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

void pause()
{
    system("pause");
}

int main()
{
    int i = 0, j = 0;
    int length = 1;
    int flag = 0;
    FILE *pipe;
    char *a[20];
    char b[] = "abc";
    char sucesseed[] = "bitsrun: 1120212759 (10.175.150.92) logged in";
    char already_online[] = "error: 1120212759, you are already online";

    char buffer[1024];

    system("bitsrun");

    // 执行命令并读取输出（注意命令格式）
    pipe = _popen("bitsrun login", "r");
    if (!pipe)
    {
        printf("failed to open pipe\n");
        perror("_popen failed");
        return 1;
    }

    // 逐行读取输出
    fgets(buffer, sizeof(buffer), pipe);
    do
    {
        strcpy(b, buffer);
        printf("%d Output: %s", i, buffer);
        printf("%d\n", length = strlen(b));
        i++;
        Sleep(1000);
    } while (fgets(buffer, sizeof(buffer), pipe) != NULL);
    printf("111 %s  111\n", b);

    // 关闭管道并等待子进程结束 bitsrun: 1120212759 (10.175.150.92) logged in
    int exit_code = _pclose(pipe);
    printf("子进程退出码: %d\n", exit_code);
    pause();
    return 0;
}