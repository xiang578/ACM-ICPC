#include <bits/stdc++.h>
using namespace std;
char s[1024];
int n,a[10];
string ans;

void print(int x,int y)
{
    memset(a,0,sizeof(a));
    int cnt=0,now=n-x;
    string tmp="";
    for(int i=max(x-1,0); i<n; i++)
    {
        int t=s[i]-'0';
        while(t%2==0&&t)
        {
            a[2]++;
            t/=2;
        }
        while(t%3==0&&t)
        {
            a[3]++;
            t/=3;
        }
        if(t==5) a[5]++;
        if(t==7) a[7]++;
    }
    int t=y-'0';
    while(t%2==0&&t)
    {
        a[2]--;
        t/=2;
    }
    while(t%3==0&&t)
    {
        a[3]--;
        t/=3;
    }
    if(t==5) a[5]--;
    if(t==7) a[7]--;
    tmp="";
    while(a[3]>=2)
    {
        tmp+='9';
        cnt++;
        a[3]-=2;
    }
    while(a[2]>=3)
    {
        tmp+='8';
        cnt++;
        a[2]-=3;
    }
    while(a[7])
    {
        tmp+='7';
        cnt++;
        a[7]--;
    }
    while(a[2]&&a[3])
    {
        tmp+='6';
        cnt++;
        a[2]--;
        a[3]--;
    }
    while(a[5])
    {
        tmp+='5';
        cnt++;
        a[5]--;
    }
    while(a[2]>=2)
    {
        tmp+='4';
        cnt++;
        a[2]-=2;
    }
    if(a[3]) {tmp+='3';cnt++;}
    if(a[2]) {tmp+='2';cnt++;}
    /*
    while(a[3])
    {
        tmp+='3';
        cnt++;
        a[3]--;
    }

    while(a[2])
    {
        tmp+='2';
        cnt++;
        a[2]--;
    }*/
    while(cnt<now)
    {
        cnt++;
        ans+='1';
    }
    for(int i=tmp.size()-1; i>=0; i--)
        ans+=tmp[i];
}

int get(int x,int y)
{
    memset(a,0,sizeof(a));
    for(int i=x; i<n; i++)
    {
        int t=s[i]-'0';
        while(t%2==0&&t)
        {
            a[2]++;
            t/=2;
        }
        while(t%3==0&&t)
        {
            a[3]++;
            t/=3;
        }
        if(t==5) a[5]++;
        if(t==7) a[7]++;
    }
    int t=y-'0';
    while(t%2==0&&a[2])
    {
        a[2]--;
        t/=2;
    }
    while(t%3==0&&a[3])
    {
        a[3]--;
        t/=3;
    }
    if(t%5==0&&a[5])
    {
        t=1;
        a[5]--;
    }
    if(t%7==0&&a[7])
    {
        t=1;
        a[7]--;
    }
    //printf("%d %d %d\n",x,y,t);
    if(t==1) return 1;
    return 0;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _;
    cin>>_;
    while(_--)
    {
        scanf("%s",s);
        n=strlen(s);
        int cnt=0;
        for(int i=0; i<n; i++) if(s[i]=='0') cnt++;
        if(cnt==0)
        {
            int ok=0;
            for(int i=n-1; i>=0; i--)
            {
                for(int j=s[i]+1; j<='9'; j++)
                {
                    if(get(i,j))
                    {
                        //printf("%d %c\n",i,j);
                        ok=1;
                        ans="";
                        for(int k=0; k<i; k++)
                            ans+=s[k];
                        ans+=(char)j;
                        print(i+1,j);
                        break;
                    }
                }
                if(ok) break;
            }
            if(!ok)
            {
                //printf("*****\n");
                ans="1";
                print(0,1);
            }
            cout<<ans<<endl;
        }
        else
        {
            int d=1,st;
            if(cnt==1&&s[n-1]=='0') st=n-2;
            else st=n-1;
            for(int j=st; j>=0; j--)
            {
                if(s[j]!='9')
                {
                    s[j]++;
                    d=0;
                    break;
                }
                else
                {
                    s[j]='0';
                    d=1;
                }
            }
            if(d==1) printf("1");
            printf("%s\n",s);
        }

    }
    return 0;
}
