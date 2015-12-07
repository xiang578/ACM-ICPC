/*
*suffix array
*倍增算法 O(n*logn)
*待排序数组长度为n,放在0~n-1中，在最后面补一个0
*da(str ,n+1,sa,rank,height, , );//注意是n+1;
*例如：
*n = 8;
*num[] = { 1, 1, 2, 1, 1, 1, 1, 2, $ };注意num最后一位为0，其他大于0
*rank[] = { 4, 6, 8, 1, 2, 3, 5, 7, 0 };rank[0~n-1]为有效值，rank[n]必定为0无效值
*sa[] = { 8, 3, 4, 5, 0, 6, 1, 7, 2 };sa[1~n]为有效值，sa[0]必定为n是无效值
*height[]= { 0, 0, 3, 2, 3, 1, 2, 0, 1 };height[2~n]为有效值
*
*/
const int MAXN=2000;
int t1[MAXN],t2[MAXN],c[MAXN];//求SA数组需要的中间变量，不需要赋值
//待排序的字符串放在s数组中，从s[0]到s[n-1],长度为n,且最大值小于m,
//除s[n-1]外的所有s[i]都大于0，r[n-1]=0
//函数结束以后结果放在sa数组中
bool cmp(int *r,int a,int b,int l)
{
    return r[a]==r[b]&&r[a+l]==r[b+l];
}

void da(int str[],int sa[],int rank[],int height[],int n,int m)
{
    n++;
    int i,j,p,*x=t1,*y=t2;
    //第一轮基数排序，如果s的最大值很大，可改为快速排序
    for(i=0;i<m;i++) c[i]=0;
    for(i=0;i<n;i++) c[x[i]=str[i]]++;
    for(i=1;i<m;i++) c[i]+=c[i-1];
    for(i=n-1;i>=0;i--) sa[--c[x[i]]=i;
    for(j=1;j<=n;j<<=1)
    {
        p=0;
        //直接利用sa数组排序第二关键字
        for(i=n-j;i<n;i++) y[p++]=i;
        for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        //这样数组y保存的就是按照第二关键字排序的结果
        //基数排序第一关键字
        for(i=0;i<m;i++) c[i]=0;//后面的j个数第二关键字为空的最小
        for(i=0;i<n;i++) c[x[y[i]]]++;
        for(i=1;i<m;i++) c[i]+=c[i-1];
        for(i=n-1;i>=0;i--) sa[--c[x[y[i]]]]=y[i];
        //根据sa和x数组计算新的x数组
        swap(x,y);
        p=1;x[sa[0]]=0;
        for(i=1;i<n;i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
        if(p>=n) break;
        m=p;//下次基数排序的最大值
    }
    int k=0;
    n--;
    for(i=0;i<=n;i++)
        rank[sa[i]]=i;
    for(i=0;i<n;i++)
    {
        if(k) k--;
        j=sa[rank[i]-1];
        while(str[i+k]==str[j+k]) k++;
        height[rank[i]]=k;
    }
}

#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100005;
int wa[N],wb[N],wv[N],ws[N];
int cmp(int *r,int a,int b,int l)
{
    return r[a]==r[b]&&r[a+l]==r[b+l];
}
void da(int *r,int *sa,int n,int m)
{
    int i,j,p,*x=wa,*y=wb;
    // 下面四行是对第一个字母的一个基数排序：基数排序其实就是记录前面有多少个位置被占据了 
    for(i=0;i<m;i++) ws[i]=0; // 将统计字符数量的数组清空 
    for(i=0;i<n;i++) ws[x[i]=r[i]]++; // 统计各种字符的个数 
    for(i=1;i<m;i++) ws[i]+=ws[i-1]; // 进行一个累加，因为前面的小字符集对后面字符的排位有位置贡献 
    for(i=n-1;i>=0;i--) sa[--ws[x[i]]]=i; // 根据位置来排序，sa[x] = i，表示i位置排在第x位
    // wa[x[i]]就是字符集0-x[i]共有多少字符占据了位置，减去自己的一个位置剩下的就是自己的排名了，排名从0开始 
    // 排名过程中主要的过程是对于处于相同字符的字符的排序，因为改变wa[x[i]]值得只会是本身，小于该字符的贡献值
    // 是不变的，对于第一个字符相同的依据是位置关系，在后面将看到通过第二个关键字来确定相同字符的先后关系 
    
    
    // 这以后的排序都是通过两个关键字来确定一个串的位置，也即倍增思想
    // 通过将一个串分解成两部分，而这两部分的位置关系我们都已经计算出来 
    for(j=1,p=1;p<n;j*=2,m=p) 
    {
        for(p=0,i=n-j;i<n;i++) y[p++]=i; // 枚举的串是用于与i位置的串进行合并，由于i较大，因为匹配的串为空串 
        // 由于枚举的是长度为j的串，那么i位置开始的串将凑不出这个长度的串，因此第二关键字应该最小，这其中位置靠前的较小
        for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j; // sa[i]-j开头的串作为第二关键字与编号为sa[i]的串匹配，sa[i]<j的串不用作为第二关键字来匹配 
        for(i=0;i<n;i++) wv[i]=x[y[i]]; // 取出这些位置的第一关键字 
        for(i=0;i<m;i++) ws[i]=0;
        for(i=0;i<n;i++) ws[wv[i]]++;
        for(i=1;i<m;i++) ws[i]+=ws[i-1];
        for(i=n-1;i>=0;i--) sa[--ws[wv[i]]]=y[i]; // 按照第二关键字进行第一关键字的基数排序 
        for(swap(x,y),p=1,x[sa[0]]=0,i=1;i<n;i++) // 对排好序的sa数组进行一次字符集缩小、常数优化 
        x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
    return;
}

int rank[N],height[N];
void calheight(int *r,int *sa,int n) // 这里的n是原串的本来长度，即不包括新增的0 
{
    int i,j,k=0;
    for(i=1;i<=n;i++) rank[sa[i]]=i; // 有后缀数组得到名次数组，排名第0的后缀一定是添加的0 
    for(i=0;i<n;height[rank[i++]]=k) // 以 i 开始的后缀总能够从以 i-1 开始的后缀中继承 k-1 匹配项出来 
    for(k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++); // 进行一个暴力的匹配，但是整个算法的时间复杂度还是O(n)的 
    return;
}

int main() {
    
    return 0;    
}
