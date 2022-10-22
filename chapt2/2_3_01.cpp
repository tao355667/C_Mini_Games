/*
2-2-6 flappy bird
下落的小鸟
*/
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
//全局变量

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
    
}
void show()//显示画面
{
   
}
void updateWithoutInput()//与用户输入无关的更新
{
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