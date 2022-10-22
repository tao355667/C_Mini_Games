/*
1-1-4 斜着弹跳的小球
增加记录速度的变量，velocity，新位置=旧位置+velocity
将速度分为两个方向，velocity_x,velocity_y
*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,j;
    //小球初始位置
    int x=0;
    int y=5;
    //边框大小
    int left=0;
    int right=20;
    int top=0;
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
        //碰到边界改变速度方向
        if(x==top || x==bottom) velocity_x=-velocity_x;
        if(x==left || x==right) velocity_y=-velocity_y;
    }
    
    system("pause");
    return 0;
}