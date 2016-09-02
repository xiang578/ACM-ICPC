/*#include <stdio.h>
#include <string.h>
#include<algorithm>
using namespace std;
const int MAXN=300000;
int t1[MAXN],t2[MAXN],c[MAXN];//��SA������Ҫ���м����������Ҫ��ֵ
//��������ַ�������s�����У���s[0]��s[n-1],����Ϊn,�����ֵС��m,
//��s[n-1]�������s[i]������0��r[n-1]=0
//���������Ժ�������sa������
bool cmp(int *r,int a,int b,int l)
{
    return r[a]==r[b]&&r[a+l]==r[b+l];
}

int da(int str[],int sa[],int rank1[],int height[],int n,int m,int len1)
{
    n++;
    int i,j,p,*x=t1,*y=t2,ans=0;
    //��һ�ֻ����������s�����ֵ�ܴ󣬿ɸ�Ϊ��������
    for(i=0; i<m; i++) c[i]=0;
    for(i=0; i<n; i++) c[x[i]=str[i]]++;
    for(i=1; i<m; i++) c[i]+=c[i-1];
    for(i=n-1; i>=0; i--) sa[--c[x[i]]]=i;
    for(j=1; j<=n; j<<=1)
    {
        p=0;
        //ֱ������sa��������ڶ��ؼ���
        for(i=n-j; i<n; i++) y[p++]=i;
        for(i=0; i<n; i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        //��������y����ľ��ǰ��յڶ��ؼ�������Ľ��
        //���������һ�ؼ���
        for(i=0; i<m; i++) c[i]=0; //�����j�����ڶ��ؼ���Ϊ�յ���С
        for(i=0; i<n; i++) c[x[y[i]]]++;
        for(i=1; i<m; i++) c[i]+=c[i-1];
        for(i=n-1; i>=0; i--) sa[--c[x[y[i]]]]=y[i];
        //����sa��x��������µ�x����
        swap(x,y);
        p=1;
        x[sa[0]]=0;
        for(i=1; i<n; i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
        if(p>=n) break;
        m=p;//�´λ�����������ֵ
    }
    int k=0;
    for(i=0; i<n; i++)
        rank1[sa[i]]=i;
    for(i=0; i<n; i++)
    {
        if(k) k--;
        j=sa[rank1[i]-1];
        while(str[i+k]==str[j+k]) k++;
        height[rank1[i]]=k;
    }
    for(int i=1; i<n; i++)
    {
        if(sa[i-1]>=0&&sa[i]>len1&&sa[i-1]<len1)
            ans=max(ans,height[i]);
        if(sa[i]>=0&&sa[i]<len1&&sa[i-1]>len1)
            ans=max(ans,height[i]);
    }
    return ans;
}

char s1[MAXN],s2[MAXN];
int ch[MAXN];
int sa[MAXN];
int rank1[MAXN];
int height[MAXN];
int main()
{
    int i,len1,len2;
    while(~scanf("%s",s1))
    {
        scanf("%s",s2);
        len1=strlen(s1);
        len2=strlen(s2);
        for(i=0; i<len1; i++)
            ch[i]=s1[i];
        ch[len1]=0;
        for(i=0; i<len2; i++)
            ch[len1+i+1]=s2[i];
        ch[len1+len2+1]=1;
        int ans=da(ch,sa,rank1,height,len1+len2+1,128,len1);
        printf("%d\n",ans);
    }
    return 0;
}*/

#include <stdio.h>
#include <string.h>
#include<algorithm>
using namespace std;
const int MAXN=200000+10;
int t1[MAXN],t2[MAXN],c[MAXN];//��SA������Ҫ���м����������Ҫ��ֵ
//��������ַ�������s�����У���s[0]��s[n-1],����Ϊn,�����ֵС��m,
//��s[n-1]�������s[i]������0��r[n-1]=0
//���������Ժ�������sa������
bool cmp(int *r,int a,int b,int l)
{
    return r[a]==r[b]&&r[a+l]==r[b+l];
}

int da(int str[],int sa[],int rank1[],int height[],int n,int m,int len1)
{
    n++;
    int i,j,p,*x=t1,*y=t2,ans=0;
    //��һ�ֻ����������s�����ֵ�ܴ󣬿ɸ�Ϊ��������
    for(i=0;i<m;i++) c[i]=0;
    for(i=0;i<n;i++) c[x[i]=str[i]]++;
    for(i=1;i<m;i++) c[i]+=c[i-1];
    for(i=n-1;i>=0;i--) sa[--c[x[i]]]=i;
    for(j=1;j<=n;j<<=1)
    {
        p=0;
        //ֱ������sa��������ڶ��ؼ���
        for(i=n-j;i<n;i++) y[p++]=i;
        for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        //��������y����ľ��ǰ��յڶ��ؼ�������Ľ��
        //���������һ�ؼ���
        for(i=0;i<m;i++) c[i]=0;//�����j�����ڶ��ؼ���Ϊ�յ���С
        for(i=0;i<n;i++) c[x[y[i]]]++;
        for(i=1;i<m;i++) c[i]+=c[i-1];
        for(i=n-1;i>=0;i--) sa[--c[x[y[i]]]]=y[i];
        //����sa��x��������µ�x����
        swap(x,y);
        p=1;x[sa[0]]=0;
        for(i=1;i<n;i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
        if(p>=n) break;
        m=p;//�´λ�����������ֵ
    }
    int k=0;
    n--;
    for(i=0;i<=n;i++)
        rank1[sa[i]]=i;
    for(i=0;i<n;i++)
    {
        if(k) k--;
        j=sa[rank1[i]-1];
        while(str[i+k]==str[j+k]) k++;
        height[rank1[i]]=k;

        if(height[rank1[i]]>ans)
            {
               //printf("%d %d\n",sa[i],sa[i-1]);
                if(sa[rank1[i]]>len1&&sa[rank1[i]-1]<len1)
                    ans=height[rank1[i]];
                else if(sa[rank1[i]]<len1&&sa[rank1[i]-1]>len1)
                    ans=height[rank1[i]];
            }
    }
    return ans;
}

char s1[MAXN],s2[MAXN];
int ch[MAXN];
int sa[MAXN];
int rank1[MAXN];
int height[MAXN];
int main()
{
    int i,len1,len2;
    while(~scanf("%s",s1))
    {
        scanf("%s",s2);
        len1=strlen(s1);
        len2=strlen(s2);
        for(i=0; i<len1; i++)
            ch[i]=s1[i];
        ch[len1]=0;
        for(i=0; i<len2; i++)
            ch[len1+i+1]=s2[i];
        ch[len1+len2+1]=1;
        int ans=da(ch,sa,rank1,height,len1+len2+1,128,len1);
        printf("%d\n",ans);
    }
    return 0;
}
