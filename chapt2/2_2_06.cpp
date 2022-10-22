/*
2-2-5 用函数实现反弹球消去砖块
小球代码重构
显示边框
显示移动挡板
挡板碰撞
消砖块
增大砖块
---------
与砖块的碰撞
游戏暂停
玩家可以控制小球
*/
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
//全局变量
int high,width;             //游戏画面大小
int ball_x,ball_y;          //小球的坐标
int ball_vx,ball_vy;        //小球的速度
int position_x,position_y;  //移动挡板
int ridus;                  //挡板半径大小
int left,right;             //挡板的左右位置
int ball_number;            //反弹小球的次数
int block_x,block_y;        //砖块位置
int score;                  //消掉砖块个数
int speed,speed_level;      //小球速度
int game_lose;              //游戏失败标志位
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
    //画面
    high=15;
    width=20;
    //小球
    ball_x=high-3;
    ball_y=width/2;
    ball_vx=1;
    ball_vy=1;
    //挡板
    ridus=5;
    position_x=high;
    position_y=width/2;
    left=position_y-ridus;
    right=position_y+ridus;
    //砖块
    block_x=0;
    block_y=width/2+1;
    //玩家得分
    ball_number=0;
    score=0;
    //小球速度
    speed=0;
    speed_level=30;
    //游戏失败
    game_lose=0;
}
void show()//显示画面
{
    gotoxy(0,0);
    int i,j;
    for(int ii=0;ii<width+2;ii++)
    {
        printf("□");
    }
    printf("\n");
    for(i=0;i<high;i++)
    {
        printf("□");
        for(j=0;j<width;j++)
        {
            if(i==ball_x && j==ball_y)
                printf("⊙");        //输出小球
            else if(i==high-1 && abs(j-position_y)<=5)
                printf("**");
            else if(abs(i-block_x)<=1 && abs(j-block_y)<=1)
                printf("〓");
            else
                printf("  ");       //输出空格（两个）
        }
        printf("□");
        printf("\n");
    }
    //最后一行边框
    for(int ii=0;ii<width+2;ii++)
    {
        printf("□");
    }
    printf("\n");
    printf("控制小球击中砖块！\nad移动挡板，空格改变小球左右移动方向，失败后r重开\n");
    printf("反弹小球数：%d\n",ball_number);
    printf("消掉的砖块数：%d\n",score);
}
void updateWithoutInput()//与用户输入无关的更新
{
    //小球移动
    if(speed<speed_level)
        speed++;
    if(speed==speed_level)
    {
        ball_x += ball_vx;
        ball_y += ball_vy;
        //边界碰撞
        if(ball_x==0)
            ball_vx = -ball_vx;
        if(ball_y==0 || ball_y==width-1)
            ball_vy = -ball_vy;
        //挡板挡住
        if(ball_x==high-2)
        {
            if(ball_y>=left && ball_y<=right)
            {
                ball_vx = -ball_vx;
                ball_number++;
                printf("\a");
            }
        }
        if(ball_x==high-1)//挡板没挡住
        {
            //玩家输了，r键重开
            game_lose=1;
            printf("你输了，按下r键可重新开始。");
        }

        //消掉砖块
        if(abs(ball_x-block_x)<=2 && abs(ball_y-block_y)<=2)
        {
            //与砖块的碰撞
            if(abs(ball_x-block_x)==2)
                ball_vx = -ball_vx;
            if(abs(ball_y-block_y)==2)
                ball_vy = -ball_vy;
            score++;
            block_y=rand()%width;
            //小球速度变快
            if(speed_level>5)
            {
                speed=0;
                speed_level=speed_level-5;
            }
        }
        //重置速度计数器
        speed=0;
    }



}
void updateWithInput()//与用户输入有关的的更新
{
    char input;
    if(kbhit())
    {
        input=getch();
        if(!game_lose)
        {
            if(input=='a')  //挡板左移
            {
                position_y--;
                left=position_y-ridus;
                right=position_y+ridus;
            }
            if(input=='d')  //挡板右移
            {
                position_y++;
                left=position_y-ridus;
                right=position_y+ridus;
            }
            if(input==' ')  //反转小球左右移动方向
            {
                if(ball_y!=0 && ball_y!=width-1)
                    ball_vy = -ball_vy;
            }
        }

        if(input=='r')  //重开
        {
            if(game_lose)//游戏重开，重置各参数
            {
                startup();
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
        if(!game_lose)//游戏没失败
        {
            show();                 //显示画面
            updateWithoutInput();   //与用户输入无关的更新
        }
        updateWithInput();      //与用户输入有关的更新
    }
    return 0;
}