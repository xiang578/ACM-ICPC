#include<bits/stdc++.h>
using namespace std;
char s[1024];

int main()
{
    int i,j,n,dot,cnt,f,len,flag,fdot;
    double tmp,sum,t;
    while(~scanf("%d",&n))
    {

        sum=0;
        cnt=0;
        for(i=0; i<n; i++)
        {

            scanf("%s",s);
            len=strlen(s);
            f=1;
            dot=0;
            flag=1;
            fdot=1;
            t=1;
            tmp=0;
            for(j=0; j<len; j++)
            {
                if(s[j]=='.'||s[j]=='-'||(s[j]<='9'&&s[j]>='0'))
                {
                    if(s[j]=='-')
                    {
                        if(j==0) flag=-1;
                        else
                        {
                            f=0;
                            break;
                        }
                    }
                    if(s[j]=='.')
                    {
                        if(j==0||dot==1)
                        {
                            f=0;
                            break;
                        }
                        dot=1;
                        t=0.1;
                    }
                    if(s[j]<='9'&&s[j]>='0')
                    {
                        if(dot) fdot++;
                        if(fdot>3)
                        {
                            f=0;
                            break;
                        }
                        if(dot)
                        {
                            tmp+=(s[j]-'0')*t;
                            t/=10;
                        }
                        else
                        {
                            tmp=tmp*10+s[j]-'0';
                            //printf("%c %.2f %.2f\n",s[j],t,tmp);
                        }
                    }
                }
                else
                {
                    f=0;
                    break;
                }
            }
            if(f)
            {

                tmp=tmp*flag;
                //printf("%.2f\n",tmp);
                if(tmp<=1000&&tmp>=-1000)
                {
                    cnt++;
                    sum+=tmp;
                }
                else
                {
                    f=0;
                }
            }
            if(!f) printf("ERROR: %s is not a legal number\n",s);
        }
        if(cnt==0) puts("The average of 0 numbers is Undefined");
        else if(cnt==1) printf("The average of 1 number is %.2f\n",sum);
        else printf("The average of %d numbers is %.2f\n",cnt,sum/cnt);
    }
    return 0;
}
