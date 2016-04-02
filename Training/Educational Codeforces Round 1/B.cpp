#include<bits/stdc++.h>
using namespace std;

char s[100000+5],a[100000+5];
void cpy(int sa,int ss,int len)
{
    for(int i=0;i<len;i++)
    {
        a[sa+i]=s[ss+i];
    }
}
int main()
{

    scanf("%s",s);
    int _,i,l,r,k,len,st,t;
    len=strlen(s);
    cin>>_;
    while(_--)
    {
        scanf("%d%d%d",&l,&r,&k);
        l--;
        r--;
        k%=(r-l+1);
        if(k==0) continue;
        else k=r-k+1;
        memset(a,0,sizeof(a));
        cpy(0,0,l);
        cpy(l,k,r-k+1);
        cpy(l+r-k+1,l,k-l+1);
        //printf("%s\n",a);
        cpy(r+1,r+1,len-r+1);
        for(i=0;i<=len;i++)
            s[i]=a[i];
        //printf("%s\n",s);
     }
     printf("%s\n",s);
    return 0;
}
