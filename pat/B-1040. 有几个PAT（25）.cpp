//25组   组员： 14计算机1陈勇 140104200104
//				15软工江昱竹140104400109 沈慧琴140104400117
//				14计算机2项闰冶140104200230
/*
字符串APPAPT中包含了两个单词“PAT”，其中第一个PAT是第2位(P),第4位(A),第6位(T)；
第二个PAT是第3位(P),第4位(A),第6位(T)。
现给定字符串，问一共可以形成多少个PAT？
输入格式：
输入只有一行，包含一个字符串，长度不超过105，只包含P、A、T三种字母。
输出格式：
在一行中输出给定字符串中包含多少个PAT。由于结果可能比较大，只输出对1000000007取余数的结果。
输入样例：
APPAPT
输出样例：
2
解题思路：
假设只统计T，有多少个T结果就是多少。
假设只统计AT，对于每一个s[i]='A',可以组成的"AT"只与之后s[i...len]中T的个数有关。
统计PAT，只用考虑每一个'P'后面"AT"的数量。
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
char s[1000000+10];

int main()
{
    while(~scanf("%s",s))
    {
        int len=strlen(s);
        ll pa=0,pt=0,ans=0;
        for(int i=len-1;i>=0;i--)
        {
            if(s[i]=='A') pa+=pt;//对于每一个‘A’，可以组成新的"AT"的数量，即为s[i...len]中‘T’的数量pt，pa为s[i...len]之间AT的数量
            else if(s[i]=='T') pt++;//统计s[i...len]中‘T’的数量
            else  if(s[i]=='P') ans=(ans+pa)%mod;//对于每个'P'，每次新增PAT数量为P之后AT的数量
        }
        printf("%lld\n",ans);
    }
    return 0;
}
