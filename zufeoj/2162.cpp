#include<stdio.h>
int  main()
{
    int x;
    while (scanf("%d",&x)!=EOF)
    {
        if(x%3==0&&x%5==0&&x%7==0) printf("��ͬʱ��3��5��7����\n");
        else if(x%3!=0&&x%5!=0&&x%7!=0) printf("���ܱ�3��5��7��һ��������\n");
        else if(x%3!=0&&x%5==0&&x%7==0) printf("�ܱ�������������\n");
        else if(x%3==0&&x%5==0&&x%7!=0) printf("�ܱ�������������\n");
        else if(x%3==0&&x%5!=0&&x%7==0) printf("�ܱ�������������\n");
        else printf("�ܱ�����һ��������\n");
    }
    return 0;
}
