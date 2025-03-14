#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <my_math.h>
#include <Windows.h>
#include <string.h>
#include <my_sort.h>
#include <time.h>
#include <easyx.h>

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

int y_convert(int y, int h)
{
    return h - y;
}

int main()
{

    double a = 0, g = 9.8, x = 0, m = 0, v = 0, f = 0;
    double end_time = 1.0;
    double sim_time = 0.0;
    double gap_time = 0.0;
    double fix_time = 0.0;
    double sleep_time = 0.0;
    double per_sim_time = 0.0;
    double per_refresh_time = 0.0;
    double time_used = 0;
    double step_sim = 0;
    double step_time = 0;
    double xpercent = 0;
    double ypercent = 0;
    double max_y_ratio = 1;
    double linear_ratio = 1;

    double info[2][256][256] = {0};
    double last_point[2];
    double new_point[2];
    double max_num[20] = {0};
    double y_ratio = 1;

    int sim_times = 0;
    int RRound = 0;
    int RRound_1 = 0;
    int tries = 0;
    int tries_1 = 0;
    int mod = 0;
    int width = 0;
    int height = 0;
    int i, j, k = 0;

    int old_coordinate[2] = {0};
    int new_coordinate[2] = {0};

    clock_t start,
        end;

    printf("Select mod :\nMod 0 : NEW\nMod 1 : test \n");
    scanf("%d", &mod);
    clear();
    printf("You have chosen Mod %d\n", mod);
    Sleep(200);

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
        // ClearScreen_WinAPI();
        //  printf("Simulation will last %lf (s)\n", end_time);
        //  printf("Simulation start in %lf (s)\n", (3000 - sim_time) / 1000);

        // Sleep(gap_time);
    }
    end = clock();

    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    fix_time = (time_used) * 1000;

    start = clock();

    {
        if (fix_time > gap_time)

            sleep_time = 0;

        else

            sleep_time = gap_time - fix_time;
    }
    sleep_time = 0;

    ClearScreen_WinAPI();

    for (sim_time = 0, sim_times = 0; sim_time < end_time * 1000 + gap_time; sim_time += gap_time, sim_times++)
    {
        // ClearScreen_WinAPI();
        v = g * sim_time / 1000;
        if (v > max_num[0])
        {
            max_num[0] = v;
        }
        x = 0.5 * g * sim_time / 1000 * sim_time / 1000;
        if (x > max_num[1])
        {
            max_num[1] = x;
        }
        RRound = sim_times / 256;
        tries = sim_times % 256;
        info[0][RRound][tries] = v;
        info[1][RRound][tries] = x;
        // printf("v = %lf \n", info[0][RRound][tries]);

        // printf("Simulation time : %lf\n", sim_time);
        // printf("speed= %lf m/s\nx= %lf m\n", v, x);
        Sleep(sleep_time);
    }
    sim_times -= 1;

    end = clock();

    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    per_sim_time = time_used * 1000 / sim_times;
    per_refresh_time = (time_used * 1000) / sim_times - sleep_time;

    width = sim_times * 2;
    {
        initgraph(width + 100, 900, EX_SHOWCONSOLE);
        setbkcolor(WHITE);
        cleardevice();

        setlinecolor(BLACK);
        for (i = 0; i < 10; i++)
        {
            line(50, 850 - 0.1 * (1 + i) * 800, width + 50, 850 - 0.1 * (1 + i) * 800);
            line(50 + 0.1 * (i + 1) * width, 50, 50 + 0.1 * (1 + i) * width, 850);
        }
        setlinestyle(PS_SOLID, 3);

        line(50, 850, width + 50, 850);
        line(50, 850, 50, 50);
        line(width + 50, 850, width + 50, 50);
    }
    // 框架

    step_sim = sim_times / 22.0;

    for (i = 0; i < 2; i++)
    {
        last_point[0] = 50, last_point[1] = 0;
        y_ratio = 800 / max_num[i] * 0.8;

        for (j = 0; j < 22; j++)
        {
            xpercent = (j + 1) / 22.0;

            new_point[0] = xpercent * width + 50;
            RRound = (int)floor(xpercent * sim_times) / 256;
            tries = (int)floor(xpercent * sim_times) % 256;
            linear_ratio = (xpercent * sim_times) - (256 * RRound + tries);

            printf("%lf %d %lf \n", xpercent * sim_times, 256 * RRound + tries, linear_ratio);

            if (tries == 255)
            {
                RRound_1 = RRound + 1;
                tries_1 = 0;
            }
            else
            {
                RRound_1 = RRound;
                tries_1 = tries + 1;
            }

            new_point[1] = info[i][RRound][tries] + linear_ratio * (info[i][RRound_1][tries_1] - info[i][RRound][tries]);

            old_coordinate[0] = (int)round(last_point[0]);
            old_coordinate[1] = (int)round(y_convert((int)floor(last_point[1] * y_ratio), 900) - 50);
            new_coordinate[0] = (int)round(new_point[0]);
            new_coordinate[1] = (int)round(y_convert((int)floor(new_point[1] * y_ratio), 900) - 50);

            // printf("x percent : %lf RRound : %d tries : %d\n", xpercent, RRound, tries);
            // printf("%d %d \n", new_coordinate[0], new_coordinate[1]);

            line(old_coordinate[0], old_coordinate[1], new_coordinate[0], new_coordinate[1]);

            last_point[0] = new_point[0];
            last_point[1] = new_point[1];
        }
    }

    {
        printf("\nSim_times : %d\n", sim_times);
        printf("Time cost : %lf\n", time_used);
        printf("Time cost per simulation : %lf\n", per_sim_time);
        printf("Time cost for per refresh : %lf\n", per_refresh_time);
        printf("Time cost per caulation : %lf\n", per_sim_time - per_refresh_time);
        printf("Gap timr : %lf\n", gap_time);
        printf("Fix time : %lf\n", fix_time);
        printf("Sleep time : %lf\n", sleep_time);
    }

    pause();
    return 0;
}