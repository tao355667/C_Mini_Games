/*
1-2-2 最简单的飞机游戏
scanf控制飞机移动
getch控制飞机移动
*/
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>


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

        //判断有无输入
        if(kbhit())
        {
            input=getch();
            if(input=='a')//左移
                y--;
            if(input=='d')//右移
                y++;
            if(input=='w')//上移
                x--;
            if(input=='s')//下移
                x++;
        }
        
    }
    system("pause");
    return 0;
}