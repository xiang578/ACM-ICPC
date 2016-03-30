//25组   组员：14计算机1陈勇 140104200104
//			    15软工江昱竹140104400109 沈慧琴140104400117
//				14计算机2项闰冶140104200230
/*
1050. String Subtraction (20)

Given two strings S1 and S2, S = S1 - S2 is defined to be the remaining string after taking all the characters in S2 from S1. Your task is simply to calculate S1 - S2 for any given strings. However, it might not be that simple to do it fast.

Input Specification:

Each input file contains one test case. Each case consists of two lines which gives S1 and S2, respectively. The string lengths of both strings are no more than 104. It is guaranteed that all the characters are visible ASCII codes and white space, and a new line character signals the end of a string.

Output Specification:

For each test case, print S1 - S2 in one line.

Sample Input:
They are students.
aeiou
Sample Output:
Thy r stdnts.
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5;
char s1[N],s2[N];
int c[300];

int main()
{
    int len1,len2,i,j;
    memset(c,0,sizeof(c));
    //读入两个字符串
    gets(s1);
    gets(s2);
    len1=strlen(s1);
    len2=strlen(s2);
    //c数组标记字符是否被删去，1删去,2不删
    for(i=0;i<len2;i++)
        c[s2[i]]=1;
    //输出结果
    for(i=0;i<len1;i++)
        if(!c[s1[i]])printf("%c",s1[i]);
    printf("\n");
    return 0;
}
