#include<stdio.h>
int main()
{

    int d,h,m,t,n,g,x,y,i,c,j;
    int a[2000],f[2000];
    scanf("%d",&g);
    for(h=0;h<g;h++)
    {
        scanf("%d.%d%d",&d,&m,&n);
        if(m>=1000) printf("%d.%04d(10)=",d,m);
        x=d;c=0;j=0;
        for(i=0;i<2000;i++){a[i]=0;f[i]=0;}
        while(x!=0)
        {
            i=x%2;
            a[c]=i;
            c++;
            x=x/2;
        }
       while(j<n)
            {t=m*2;
            if(t>=10000) {f[j]=1;m=t-10000;}
            else {f[j]=0;m=t;}
            j++;}
        if(d==0) printf("0");
        else{for(;c>=1;c--)printf("%d",a[c-1]);}
        printf(".");
        for(i=0;i<n;i++){printf("%d",f[i]);}
        printf("(2)\n");
    }
    return 0;
}


