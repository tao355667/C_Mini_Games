/*
1-2-4 最简单的飞机游戏
scanf控制飞机移动
getch控制飞机移动
显示复杂的飞机图案
发射激光
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

int main()
{
    int i,j;
    //飞机初始位置
    int x=5;
    int y=10;
    char input;//用户输入字符
    int isFire;//记录有无激光
    while(1)
    {
        HideCursor();
        system("cls");
        if(isFire==0){
            //输出飞机上面的空行
            for(i=0;i<x;i++)
                printf("\n");
        }else{
            for(i=0;i<x;i++){
                for(j=0;j<y;j++)
                    printf(" ");
                printf("  |\n");
            }
        }
        //一个复杂的飞机图案
        //输出飞机左边的空格
        for(j=0;j<y;j++)
            printf(" ");
        printf("  *\n");
        for(j=0;j<y;j++)
            printf(" ");
        printf("*****\n");
        for(j=0;j<y;j++)
            printf(" ");
        printf(" * * ");
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
            if(input==' ')//激光
                isFire=1;
        }
        
    }
    system("pause");
    return 0;
}