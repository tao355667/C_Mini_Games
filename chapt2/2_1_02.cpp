/*
2-1-2 最简单的飞机游戏
scanf控制飞机移动
getch控制飞机移动
显示复杂的飞机图案
发射激光
打靶练习
飞机游戏代码重构
新式子弹
*/
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>

//隐藏光标
void HideCursor()
{
    CONSOLE_CURSOR_INFO cursor;
    cursor.bVisible = FALSE;
    cursor.dwSize = sizeof(cursor);
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorInfo(handle, &cursor);
}
//全局变量
int high,width;             //画面大小
int position_x,position_y;  //飞机位置
int bullet_x,bullet_y;      //子弹位置

void startup()//数据初始化
{
    high=20;                //窗口高度
    width=30;               //窗口宽度
    position_x=high/2;      //飞机初始坐标x    
    position_y=width/2;     //飞机初始坐标y
    bullet_x=-1;            //子弹初始坐标x
    bullet_y=position_y;    //子弹初始坐标y
}
void show()//显示画面
{
    system("cls");
    int i,j;
    for(i=0;i<high;i++)
    {
        for(j=0;j<width;j++)
        {
            if(i==position_x && j==position_y)
                printf("*");        //输出飞机
            else if(i==bullet_x&&j==bullet_y)
                printf("|");        //输出子弹
            else
                printf(" ");        //输出空格
        }
        printf("\n");
    }
}
void updateWithoutInput()//与用户输入无关的更新
{
    if(bullet_x>=-1)
        bullet_x--;
}
void updateWithInput()//与用户输入有关的的更新
{
    char input;
    if(kbhit()){        //是否有输入
        input=getch();
        if(input=='a')
            position_y--;
        if(input=='d')
            position_y++;
        if(input=='w')
            position_x--;
        if(input=='s')
            position_x++;
        if(input==' '){
            bullet_x=position_x-1;//子弹在飞机正上方
            bullet_y=position_y;
        }
    }
}

int main()
{
    HideCursor();               //隐藏光标
    startup();                  //数据初始化，画面大小，飞机位置
    while(1)
    {
        show();                 //显示画面
        updateWithoutInput();   //与用户输入无关的更新
        updateWithInput();      //与用户输入有关的更新
    }
    return 0;
}