/*
1-1-1 显示静止的小球
使用printf函数在坐标(x,y)处显示一个静止的小球字符'o'
*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,j;
    int x=5;
    int y=10;
    //输出小球上面的空行
    for(i=0;i<x;i++)
        printf("\n");
    //输出小球左边的空格
    for(j=0;j<y;j++)
        printf(" ");
    printf("o");
    printf("\n");
    system("pause");
    return 0;
}