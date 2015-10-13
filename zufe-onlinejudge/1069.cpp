#include<stdio.h>
int main()
{
    int f;
    double c;
    while (scanf("%d",&f)!=EOF)
    {
    c=5.0*(f-32)/9;
    printf("%.2f\n",c);
    }
    return 0;
}
