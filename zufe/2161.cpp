#include<stdio.h>
int main()
{
    int x,y;
    while (scanf("%d",&x)!=EOF)
    {
    if(x<0) y=-1;
    else if(x>0) y=1;
    else y=0;
    printf("%d\n",y);
    }
    return 0;
}
