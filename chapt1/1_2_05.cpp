/*
1-2-4 最简单的飞机游戏
scanf控制飞机移动
getch控制飞机移动
显示复杂的飞机图案
发射激光
打靶练习
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
    //靶子
    int ny=5;       //一个靶子，放在第一行的ny列上
    int isKilled=0; //判断靶子是否被打到
    while(1)
    {
        HideCursor();
        system("cls");
        if(!isKilled){//输出靶子
            for(j=0;j<ny;j++)
                printf(" ");
            printf("+\n");
        }
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
            if(y+2==ny)     //激光在飞机的正中间，距离最左边两个坐标。
                isKilled=1;
            isFire=0;       //打没打到激光都消失
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