#include<stdio.h>
int main()
{
    double s;
    while (scanf("%lf",&s)!=EOF)
    {
        if(s>=90.0) printf("����\n");
        else if(s>=80.0) printf("��\n");
        else if(s>=70.0) printf("��\n");
        else if(s>=60.0) printf("����\n");
        else  printf("������\n");
    }
    return 0;
}
