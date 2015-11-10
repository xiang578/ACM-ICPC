#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,t,k,m,a;
    char c[100005];
    while(gets(c))
    {
        t=0,k=0,j=0,a=0;
        for(i=0;c[i]!=0;i++)
        {
            if(c[i]=='p')t++;
            if(c[i]=='i')if(t>0){k++;t--;}
            if(c[i]=='z')if(k>0){j++;if(j%2==0) k--;}
            if(c[i]=='a')if(j>1){a++;j-=2;}
        }
        printf("%d\n",a);
    }
    return 0;
}
