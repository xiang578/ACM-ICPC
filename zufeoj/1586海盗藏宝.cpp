#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
    char c[100];
    int bi=0,i,j,k;
    double t,x,y,n,m,q=sqrt(2);
    while(gets(c))
    {
        bi++;
        if(c[0]=='E') break;
        x=0;y=0;
        printf("Example #%d\n",bi);
        int len=strlen(c);
        t=0;
        for(i=0;c[i]!='.';i++)
        {
            if(c[i]>='0'&&c[i]<='9') t=t*10+c[i]-'0';
            else if(c[i]=='N')
            {
                if(c[i+1]=='E'){x+=t/q;y+=t/q;i++;}
                else if(c[i+1]=='W') {x-=t/q;y+=t/q;i++;}
                else {y+=t;}
                t=0;
            }
            else if(c[i]=='S')
            {
                if(c[i+1]=='E'){x+=t/q;y-=t/q;i++;}
                else if(c[i+1]=='W') {x-=t/q;y-=t/q;i++;}
                else {y-=t;}
                t=0;

            }
            else if(c[i]=='E')
            {
                x+=t;t=0;
            }
            else if(c[i]=='W')
            {
                x-=t;t=0;
            }
        }
        printf("The treasure is located at (%.3f,%.3f).\n",x,y);
        t=x*x+y*y;
        t=sqrt(t);
        printf("The distance to the treasure is %.3f.\n",t);
    }
    return 0;
}
