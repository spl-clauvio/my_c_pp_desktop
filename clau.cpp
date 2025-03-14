#include <graphics.h>
#include <iostream>
#include <stdio.h>
#include <conio.h>

int main()
{
    initgraph(1000, 1000);
    IMAGE clauvio;
    loadimage(&clauvio, _T("./picture/clauvio.jpg"));
    putimage(0, 0, &clauvio);
    while (1)
    {
        ;
    }
    closegraph();
    return 0;
}