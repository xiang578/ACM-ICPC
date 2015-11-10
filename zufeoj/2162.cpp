#include<stdio.h>
int  main()
{
    int x;
    while (scanf("%d",&x)!=EOF)
    {
        if(x%3==0&&x%5==0&&x%7==0) printf("能同时被3、5、7整除\n");
        else if(x%3!=0&&x%5!=0&&x%7!=0) printf("不能被3、5、7任一个数整除\n");
        else if(x%3!=0&&x%5==0&&x%7==0) printf("能被其中两数整除\n");
        else if(x%3==0&&x%5==0&&x%7!=0) printf("能被其中两数整除\n");
        else if(x%3==0&&x%5!=0&&x%7==0) printf("能被其中两数整除\n");
        else printf("能被其中一个数整除\n");
    }
    return 0;
}
