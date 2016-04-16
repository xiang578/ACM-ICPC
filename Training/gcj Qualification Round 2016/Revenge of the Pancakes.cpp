 #include<bits/stdc++.h>
using namespace std;
char s[1024];

int main()
{
    int __,_,len,i,has,ans;
    //freopen("B-small-attempt0.in","r",stdin);
    freopen("B-large-practice.in","r",stdin);
     freopen("B-out.out","w",stdout);
    scanf("%d",&__);
    for(_=1;_<=__;_++)
    {
        scanf("%s",s);
        len=strlen(s);
        has=0;
        ans=0;
        for(int i=0;i<len;i++)
        {
            if(s[i]=='-')
            {
                while(s[i]=='-'&&i<len)
                {
                    i++;
                }
                //if(s[i]=='+'&&i<len) has=1;
                ans+=has+1;
                //printf("%d\n",ans);
            }
            if(s[i]=='+') has=1;
        }
        printf("Case #%d: %d\n",_,ans);
    }
    return 0;
}
