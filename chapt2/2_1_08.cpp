/*
2-1-8 最简单的飞机游戏
scanf控制飞机移动
getch控制飞机移动
显示复杂的飞机图案
发射激光
打靶练习
飞机游戏代码重构
新式子弹
静止的敌人
敌机移动
击中敌机，得分
清屏功能
---------
防止飞机飞出边界
复杂的飞机图形
积分增加，下落速度增加
按下ESC后游戏暂停
--------
边框
敌机走到尽头则玩家输了,r键重开
*/
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>

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
//全局变量
int high,width;             //画面大小
int position_x,position_y;  //飞机位置
int bullet_x,bullet_y;      //子弹位置
int enemy_x,enemy_y;        //敌机位置
int score;                  //得分
int speed,speed_level;      //下落速度，越大越慢
int game_pause;             //游戏是否暂停
int game_lose;              //游戏是否失败

void startup()//数据初始化
{
    high=24;                //窗口高度
    width=30;               //窗口宽度
    position_x=high/2;      //飞机初始坐标x    
    position_y=width/2;     //飞机初始坐标y
    bullet_x=-1;            //子弹初始坐标x
    bullet_y=position_y;    //子弹初始坐标y
    enemy_x=0;              //敌机初始坐标x
    enemy_y=position_y;     //敌机初始坐标y
    score=0;                //初始得分
    speed=0;                //速度计数器
    speed_level=100;        //下落速度
    game_pause=0;           //暂停标志
    game_lose=0;            //失败标志
}
void show()//显示画面
{
    if(!game_lose)//没输
    {
        gotoxy(0,0);
        int i,j;
        for(int ii=0;ii<width/2+2;ii++) printf("□");//边框
        printf("\n");
        for(i=0;i<high;i++)
        {
            printf("□");        //输出边框
            for(j=0;j<width;j++)
            {
                if(((i==position_x && j==position_y)
                ||(i==position_x+1 && abs(j-position_y)<=2)
                ||(i==position_x+2 && abs(j-position_y)==1)))
                    printf("*");        //输出飞机
                else if(i==enemy_x&&j==enemy_y)
                    printf("@");        //输出敌机
                else if(i==bullet_x&&j==bullet_y)
                    printf("|");        //输出子弹
                else
                    printf(" ");        //输出空格
            }
            printf("□");        //输出边框
            printf("\n");
        }
        for(int ii=0;ii<width/2+2;ii++) printf("□");//边框
        printf("\n");
        printf("简单飞机游戏  得分：%d",score);
        if(game_pause) printf("  游戏已暂停");
        else printf("            ");
        printf("\n",score);
        printf("wasd移动，空格射击，ESC暂停，r重新开始");
    }
    else//输了
    {
        gotoxy(2,high/2);
        printf("\t     你输了\n");
        gotoxy(2,high/2+1);
        printf("\t   你的得分是%d\n",score);
        gotoxy(2,high/2+2);
        printf("\t按下r键可重新开始");
    }
    
}
void updateWithoutInput()//与用户输入无关的更新
{
    if(!game_pause && !game_lose)
    {
        if(bullet_x>=-1)
            bullet_x--;
        if(bullet_x==enemy_x && bullet_y==enemy_y)//子弹击中敌机
        {
            score++;                //分数加1
            if(speed_level>10)//难度增加，敌机下落速度变快
            {
                speed_level-=5;
                speed=0;
            }
            enemy_x=-1;            //产生新的飞机
            enemy_y=rand()%width;
            bullet_x=-2;            //子弹无效
            
        }
        //用来控制敌机向下移动的速度，每隔几次循环才移动一次敌机
        //这样修改，虽然用户按键的交互速度还是很快，但NPC的移动显示可以降速
        if(speed<speed_level)
            speed++;
        if(speed==speed_level)
        {
            enemy_x++;
            speed=0;
        }
        if(enemy_x==high) game_lose=1;
    }
    
}
void updateWithInput()//与用户输入有关的的更新
{
    char input;
    if(kbhit())//是否有输入
    {        
        input=getch();
        if(!game_pause && !game_lose)
        {
            if(input=='a' && position_y>0)
                position_y--;
            if(input=='d' && position_y<width-1)
                position_y++;
            if(input=='w' && position_x>0)
                position_x--;
            if(input=='s' && position_x<high-1)
                position_x++;
            if(input==' ')
            {
                bullet_x=position_x-1;//子弹在飞机正上方
                bullet_y=position_y;
            }
        }
        if(input==0x1b && !game_lose)//ESC键按下暂停，再按取消暂停
        {
            game_pause=!game_pause;
        }
        if(input=='r')//游戏失败后按下p键重开
        {
            if(game_lose==1)//防误触
            {
                startup();//重新初始化
            }
            game_lose=0;
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