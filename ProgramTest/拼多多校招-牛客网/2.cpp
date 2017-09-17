#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;

int cnt=0;
char t[1000000],a[1000000],b[1000000],ans[10000000];


int main()
{
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(ans,0,sizeof(ans));
    scanf("%s",t);
    int lena=strlen(t);
    for(int i=lena-1,j=0;i>=0;i--,j++)
    {
        a[j]=t[i]-'0';
    }
    scanf("%s",t);
    int lenb=strlen(t);
    for(int i=lenb-1,j=0;i>=0;i--,j++)
    {
        b[j]=t[i]-'0';
    }
    //printf("%s %s\n",a,b);
    int now;
    int cnt=-1;
    for(int i=0;i<lena;i++)
    {
        now=i;
        int jin = 0;
        for(int j=0;j<lenb;j++)
        {
            int tmp=a[i]*b[j]+jin+ans[now];
            //printf("%d %d %d\n",tmp,tmp%10,tmp/10);
            ans[now] = tmp%10;
            jin = tmp / 10;
            now++;
            cnt = max(now,cnt);
        }
        while(jin!=0)
        {
            int tmp=jin+ans[now];
            ans[now] = tmp%10;
            jin = tmp/10;
            cnt = max(now,cnt);
        }
    }
    while(ans[cnt]==0&&cnt!=0) cnt--;
    for(int i=cnt;i>=0;i--)
        printf("%c",ans[i]+'0');
    puts("");
    return 0;
}