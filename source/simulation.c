#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <my_math.h>
#include <Windows.h>
#include <string.h>
#include <my_sort.h>
#include <time.h>
#include <easyx.h>
#include <graphics.h>

void pause()
{
    system("pause");
}

void clear()
{
    system("cls");
}

void ClearScreen_WinAPI()
{
    COORD coord = {0, 0};
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD count;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    FillConsoleOutputCharacter(hConsole, ' ', csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
    SetConsoleCursorPosition(hConsole, coord);
}

int main()
{

    double g = 9.8, x = 0, m = 0, v = 0, f = 0;
    double end_time = 1.0;
    double sim_time = 0.0;
    double gap_time = 0.0;
    double fix_time = 0.0;
    double sleep_time = 0.0;
    double per_sim_time = 0.0;
    double per_refresh_time = 0.0;
    double time_used = 0;

    int sim_times = 0;
    int mod = 0;

    clock_t start, end;

    printf("Select mod :\nMod 0 : NEW\nMod 1 : test \n");
    scanf("%d", &mod);
    clear();
    printf("You have chosen Mod %d\n", mod);
    Sleep(2000);

    if (mod)
    {
        end_time = 10;
        f = 60;
    }
    else
    {
        printf("Enter simulation time (s)\n");
        scanf("%lf", &end_time);
        printf("Enter f (hz)\n");
        scanf("%lf", &f);
    }

    gap_time = 1000 / f;
    while (getchar() != '\n')
        ;
    clear();

    start = clock();
    for (sim_time = 0, sim_times = 0; sim_time < 3000 + gap_time; sim_time += gap_time, sim_times++)
    {
        ClearScreen_WinAPI();
        printf("Simulation will last %lf (s)\n", end_time);
        printf("Simulation start in %lf (s)\n", (3000 - sim_time) / 1000);

        Sleep(gap_time);
    }
    end = clock();

    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    fix_time = (time_used - 3) * 1000 / sim_times;

    start = clock();

    {
        if (fix_time > gap_time)

            sleep_time = 0;

        else

            sleep_time = gap_time - fix_time;
    }

    for (sim_time = 0, sim_times = 0; sim_time < end_time * 1000 + gap_time; sim_time += gap_time, sim_times++)
    {
        ClearScreen_WinAPI();
        v = g * sim_time / 1000;
        x = 0.5 * g * sim_time / 1000 * sim_time / 1000;
        printf("Simulation time : %lf\n", sim_time);
        printf("speed= %lf m/s\nx= %lf m\n", v, x);
        Sleep(sleep_time);
    }

    end = clock();

    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    per_sim_time = time_used * 1000 / sim_times;
    per_refresh_time = (time_used * 1000) / sim_times - sleep_time;

    printf("\nSim_times : %d\n", sim_times);
    printf("Time cost : %lf\n", time_used);
    printf("Time cost per simulation : %lf\n", per_sim_time);
    printf("Time cost for per refresh : %lf\n", per_refresh_time);
    printf("Time cost per caulation : %lf\n", per_sim_time - per_refresh_time);
    printf("Gap timr : %lf\n", gap_time);
    printf("Fix time : %lf\n", fix_time);
    printf("Sleep time : %lf\n", sleep_time);

    pause();
    return 0;
}