#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//当成八进制做
int main()
{
    int len,i,sum;
    char a[20];
    while(~scanf("%s",a))
    {
        len=strlen(a);
        for(i=0;i<len;i++)
        {
            a[i]=a[i]-48;
            if(a[i]<6&&a[i]>2) a[i]-=1;
            if(a[i]<=9&&a[i]>6) a[i]-=2;
        }
        sum=0;
        for(i=0;i<len;i++)
        {
            sum=sum*8+a[i];
        }
        printf("%d\n",sum);
    }
    return 0;
}
