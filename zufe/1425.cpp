#include<stdio.h>
int main()
{
    char c[5];
    int i;
    scanf("%s%*c",c);
    for(i=0;i<5;i++){
    printf("%c",c[i]+4);}

    return 0;
}
