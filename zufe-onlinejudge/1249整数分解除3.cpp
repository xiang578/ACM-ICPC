#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,j,m,s[1500],max;
    while(~scanf("%d",&n))
    {
        if(n==1) printf("1\n");
        else
        {
            max=0;
            memset(s,0,sizeof(s));
            int k;
            k=n/3;
            m=n%3;
            if(m==0) s[0]=1;
            else if(m==2) s[0]=2;
            else if(m==1)
            {
                s[0]=4;
                k-=1;
            }
            for(i=1; i<=k; i++)
            {
                for(j=0; j<=max; j++)
                s[j]=s[j]*3;
                for(j=0; j<=max; j++)
                    if(s[j]>=10)
                    {
                        s[j+1]+=s[j]/10;
                        s[j]=s[j]%10;
                        if(j+1>max) max=j+1;
                    }
            }
            for(i=max; i>-1; i--)
            {
                printf("%d",s[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
