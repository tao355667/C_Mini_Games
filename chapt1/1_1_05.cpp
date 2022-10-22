/*
1-1-5 控制小球弹跳速度
增加记录速度的变量，velocity，新位置=旧位置+velocity
将速度分为两个方向，velocity_x,velocity_y
使用Sleep函数控制小球弹跳的速度
隐藏光标
*/
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
//隐藏光标
void HideCursor()
{
 CONSOLE_CURSOR_INFO cursor;    
 cursor.bVisible = FALSE;    
 cursor.dwSize = sizeof(cursor);    
 HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);    
 SetConsoleCursorInfo(handle, &cursor);
}
int main()
{
    HideCursor();
    int i,j;
    //小球初始位置
    int x=1;
    int y=5;
    //边框大小
    int left=1;
    int right=20;
    int top=1;
    int bottom=10;
    //两个方向的速度
    int velocity_x=1;
    int velocity_y=1;
    while(1){
        x=x+velocity_x;
        y=y+velocity_y;
        system("cls");
        //输出小球上面的空行
        for(i=0;i<x;i++)
            printf("\n");
        //输出小球左边的空格
        for(j=0;j<y;j++)
            printf(" ");
        //输出小球o
        printf("o");
        printf("\n");
        Sleep(50);
        //碰到边界改变速度方向
        if(x==top || x==bottom) velocity_x=-velocity_x;
        if(y==left || y==right) velocity_y=-velocity_y;
    }
    
    system("pause");
    return 0;
}