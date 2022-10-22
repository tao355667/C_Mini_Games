/*
1-2-1 最简单的飞机游戏
scanf控制飞机移动
*/
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

int main()
{
    int i,j;
    int x=5;
    int y=10;
    char input;
    while(1)
    {
        system("cls");
        //输出飞机上面的空行
        for(i=0;i<x;i++)
            printf("\n");
        //输出飞机左边的空格
        for(j=0;j<y;j++)
            printf(" ");
        //输出飞机
        printf("*");
        printf("\n");

        //根据用户输入数据的不同实现移动
        scanf("%c",&input);
        if(input=='a') y--;
        if(input=='d') y++;
        if(input=='w') x--;
        if(input=='s') x++;
    }
    system("pause");
    return 0;
}