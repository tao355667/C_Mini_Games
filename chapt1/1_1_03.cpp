/*
1-1-3 上下弹跳的小球
增加记录速度的变量，velocity，新位置=旧位置+velocity
*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,j;
    int x=5;
    int y=10;

    int height=20;
    int velocity=1;
    while(1){
        x=x+velocity;
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
        if(x==height) velocity=-velocity;
        if(x==0) velocity=-velocity;
    }
    
    system("pause");
    return 0;
}