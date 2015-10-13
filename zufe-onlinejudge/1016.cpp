#include<stdio.h>
int main()
{
    double s;
    while (scanf("%lf",&s)!=EOF)
    {
        if(s>=90.0) printf("优秀\n");
        else if(s>=80.0) printf("良\n");
        else if(s>=70.0) printf("中\n");
        else if(s>=60.0) printf("及格\n");
        else  printf("不及格\n");
    }
    return 0;
}
