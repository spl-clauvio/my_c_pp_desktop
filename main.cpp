#include <iostream>
#include <graphics.h>
// with old
// #include <easyx.h>
// with only new library
#include <conio.h>
#include <stdio.h>
#include <math.h>
// #include<SDL2/SDL.h>

double pi = 3.1415926;

void draw_chessboard(int r, int c)
{

    int i = 0;
    int block_x = 30, block_y = 30;
    int xt = 100 + block_x * (c + 1);
    int yt = 100 + block_y * (r + 1);
    initgraph(xt, yt);
    setbkcolor(CYAN);
    cleardevice();

    IMAGE clauv[2];
    loadimage(clauv + 0, _T("D:/C_PP/picture/clauvio.png"), xt, yt);
    loadimage(clauv + 1, _T("D:/C_PP/picture/clauviooo.png"), xt, yt);
    putimage(0, 0, clauv + 0);
    // putimage(0, 0, &clauv[1]);

    for (i = 0; i < r + 2; i++)
    {
        line(50, 50 + block_y * i, xt - 50, 50 + block_y * i);
    }

    for (i = 0; i < c + 2; i++)
    {
        line(50 + block_x * i, 50, 50 + block_x * i, yt - 50);
    }
}

int main()
{

    double o = 0.0;
    double x = 0.0, y = 0.0;
    printf("%f\n", x = sin(pi / 2));
    initgraph(960, 540, 0);
    setbkcolor(BROWN);
    cleardevice();

    line(0, 0, 960, 540);

    setfillcolor(BLACK);

    fillrectangle(300, 300, 400, 400);
    solidrectangle(300, 300, 400, 400);

    setfillcolor(WHITE);

    fillcircle(480, 270, 100);

    for (o = 0; o < 360; o += 8)
    {
        circle(480 + 100 * sin(o / 180 * pi), 270 + 100 * cos(o / 180 * pi), 50);
    }

    IMAGE clauv;
    loadimage(&clauv, _T("D:/C_PP/picture/clauvio.jpg"));
    putimage(0, 0, &clauv);

    //_getch();

    draw_chessboard(9, 9);

    _getch();
    closegraph();
    printf("hello world\n");
    std::cout << "hello world!\n";
    return 0;
}