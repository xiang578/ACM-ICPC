#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int num[15];
int dp[15][3];
//dp[i][k]
//i:��λ
//k:3��״̬��0-û��3\8��1-��3��2-��8

//posΪ��ǰ�������λ��Ȩ�ر�ʾ����Ҳ����ʣ��pos+1λ��������
//have-״̬;
//lim-��������Ƿ���������1-�����ԣ�0-����
int dfs(int pos,int have,int lim)
{
    //printf("%d\n",pos);
    int n,i,ans=0,have_x;
    if(pos<=0&&have!=0) return 1;
    if(pos==0) return 0;
    //if(pos<0) return 0;
    //�Ѿ���������
    if(!lim&&dp[pos][have]!=-1)
        return dp[pos][have];

    //�жϱ�λö�ٵķ�Χ
    n=lim?num[pos]:9;
    for(i=0; i<=n; i++)
    {
        have_x=have;
        if(have==0&&i==3)
            have_x=1;
        if(have==0&&i==8)
            have_x=2;
        if(have==1&&i==8)
            continue;
        if(have==2&&i==3)
            continue;
        ans+=dfs(pos-1,have_x,lim&&i==n);
    }

    //dp[pos][mod][have]Ҫ�������pos֮�����������Ľ��
    //����dfs(...,1)��dfs(...,0)���������lim=1ʱ����¼dp���ܻᵼ�´���
    //����ÿһ��dfs(...,1)��Ҫ���¼���
    if(!lim)
        dp[pos][have]=ans;
    return ans;
}

int main()
{
    int n,i,_,l,r,a1,a2;
    memset(dp,0xff,sizeof(dp));
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&l,&r);
        if(l==1) a1=0;
        else
        {
            n=l-1;
            memset(num,0,sizeof(num));
            i=0;
            while(n)
            {
                num[++i]=n%10;
                n/=10;
            }
            a1=dfs(i,0,1);
        }

        n=r;
        memset(num,0,sizeof(num));
        i=0;
        while(n)
        {
            num[++i]=n%10;
            n/=10;
        }
        a2=dfs(i,0,1);
        printf("%d\n",a2-a1);
    }
    return 0;
}
