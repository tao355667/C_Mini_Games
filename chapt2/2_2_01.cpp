/*
2-2-1 用函数实现反弹球消去砖块
小球代码重构
*/
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
//全局变量
int high,width;         //游戏画面大小
int ball_x,ball_y;      //小球的坐标
int ball_vx,ball_vy;    //小球的速度
//隐藏光标
void HideCursor()
{
    CONSOLE_CURSOR_INFO cursor_info={1,0};//第二个值为0表示隐藏光标
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
//将光标移动到(x,y)位置
void gotoxy(int x,int y)
{
    HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X=x;
    pos.Y=y;
    SetConsoleCursorPosition(handle,pos);
}

void startup()//数据初始化
{
    high=15;
    width=20;
    ball_x=0;
    ball_y=width/2;
    ball_vx=1;
    ball_vy=1;
}
void show()//显示画面
{
    gotoxy(0,0);
    int i,j;
    for(i=0;i<high;i++)
    {
        for(j=0;j<width;j++)
        {
            if(i==ball_x && j==ball_y)
                printf("⊙");        //输出小球
            else
                printf("  ");       //输出空格（两个）
        }
        printf("\n");
    }
}
void updateWithoutInput()//与用户输入无关的更新
{
    //小球移动
    ball_x += ball_vx;
    ball_y += ball_vy;
    //边界碰撞
    if(ball_x==0 || ball_x==high-1)
        ball_vx = -ball_vx;
    if(ball_y==0 || ball_y==width-1)
        ball_vy = -ball_vy;
}
void updateWithInput()//与用户输入有关的的更新
{
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