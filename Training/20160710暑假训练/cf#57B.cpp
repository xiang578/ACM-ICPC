#include<bits/stdc++.h>
using namespace std;
char s[1024];
string a1,a2,a3,t,ans[100];

int main()
{
    int n;
    scanf("%s",s);
    n=strlen(s);
    for(int i=0; i<n; i++)
    {
        if(s[i]>='A'&&s[i]<='Z') s[i]=s[i]-'A'+'a';
        if(s[i]>='a'&&s[i]<='z') a1+=s[i];
    }
    scanf("%s",s);
    n=strlen(s);
    for(int i=0; i<n; i++)
    {
        if(s[i]>='A'&&s[i]<='Z') s[i]=s[i]-'A'+'a';
        if(s[i]>='a'&&s[i]<='z') a2+=s[i];
    }
    scanf("%s",s);
    n=strlen(s);
    for(int i=0; i<n; i++)
    {
        if(s[i]>='A'&&s[i]<='Z') s[i]=s[i]-'A'+'a';
        if(s[i]>='a'&&s[i]<='z') a3+=s[i];
    }
    int p[3]= {1,2,3};
    int cnt=0;
    do
    {
        for(int i=0; i<3; i++)
        {
            if(p[i]==1)
                ans[cnt]+=a1;
            else if(p[i]==2)
                ans[cnt]+=a2;
            else if(p[i]==3)
                ans[cnt]+=a3;
        }
        cnt++;
    }while(next_permutation(p,p+3));
    //printf("%d\n",cnt);
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",s);
        int len=strlen(s);
        t="";
        for(int i=0; i<len; i++)
        {
            if(s[i]>='A'&&s[i]<='Z') s[i]=s[i]-'A'+'a';
            if(s[i]>='a'&&s[i]<='z') t+=s[i];
        }
        //cout<<t<<endl;
        int k=0;
        for(k=0;k<cnt;k++)
        {
            if(t==ans[k])
            {
                break;
            }
        }
        if(k==cnt) puts("WA");
        else puts("ACC");
    }
    return 0;
}
