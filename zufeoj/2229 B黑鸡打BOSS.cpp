#include<stdio.h>
int main()
{
    int h1,h2,a,b,c,i,j,k,t,y,x,f,m;
    while(~scanf("%d%d%d%d%d",&h1,&h2,&a,&b,&c))
    {
        k=1,t=0;
        for(m=0;;m++)
        {
          h2=h2-a-t*b;
          if(k==3) h2-=a;
          if(h2<=0) {printf("victory\n");break;}
          h1-=c;
          k++;if(k==4) k=1;
          t++;if(t==4) t=0;
          if(h1<=0) {printf("defeated\n");break;}
        }
    }
    return 0;
}
