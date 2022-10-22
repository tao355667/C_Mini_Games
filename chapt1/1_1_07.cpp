/*
1-1-6 弹跳的小球1.1
增加记录速度的变量，velocity，新位置=旧位置+velocity
将速度分为两个方向，velocity_x,velocity_y
使用Sleep函数控制小球弹跳的速度
隐藏光标
碰到边界时响铃
有边框
解决清屏闪烁问题
system("cls");//清空画面,此函数调用了外部进程清屏，速度慢，屏幕闪烁，很难受
*/
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

//解决system("cls")闪烁问题，目前看不懂
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//定义显示器句柄变量,并且这个只能在每个头文件中单独定义句柄和函数，否则无效
//类似system("cls");的清屏函数？
void gotoxy(HANDLE hOut, int x, int y)//其中x，y是与正常理解相反的，注意区分
{
	COORD pos;
	pos.X = x;             //横坐标
	pos.Y = y;            //纵坐标
	SetConsoleCursorPosition(hOut, pos);
}
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
    //小球初始位置
    int x=3;
    int y=12;
    //边框高和宽
    int heigh=15;
    int width=20;
    //边框边界
    int left=1;
    int right=width+1;
    int top=1;
    int bottom=heigh+1;
    //两个方向的速度
    int velocity_x=1;
    int velocity_y=1;
    while(1){
        HideCursor();//隐藏光标
        x=x+velocity_x;
        y=y+velocity_y;
        gotoxy(hOut,0,0);//清屏
        //输出小球上面的空行和边框
        for(i=0;i<x;i++){
            if(i==0){
                for(int ii=1;ii<=right+2;ii++){printf("□");}
                printf("\n");
            }else{
                printf("□");
                for(int ii=1;ii<=right;ii++){printf("  ");}
                printf("□");
                printf("\n");
            }
        }
        //输出小球左边的空格和边框
        for(j=0;j<y;j++){
            if(j==0){printf("□");}
            else{printf("  ");}
        }
        //输出小球⊙
        printf("⊙");
        //输出小球右边的空格和边框
        for(;j<=right;j++){
            if(j==right){printf("□");}
            else{printf("  ");}
        }
        printf("\n");
        //输出小球下面的空行和边框
        for(;i<=bottom;i++){
            if(i==bottom){
                for(int ii=1;ii<=right+2;ii++){printf("□");}
            }else{
                printf("□");
                for(int ii=1;ii<=right;ii++){printf("  ");}
                printf("□");
                printf("\n");
            }
        }        
        Sleep(50);//延时，让小球跳得慢一点
        //碰到边界改变速度方向,响铃
        if(x==top || x==bottom){velocity_x=-velocity_x;printf("\a");}
        if(y==left || y==right){velocity_y=-velocity_y;printf("\a");}
    }
    
    system("pause");
    return 0;
}