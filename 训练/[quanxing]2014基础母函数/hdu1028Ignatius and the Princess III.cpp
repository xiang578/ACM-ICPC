#include <iostream>
#include<bits/stdc++.h>
using namespace std;
// Author: Tanky Woo
// www.wutianqi.com
//http://www.wutianqi.com/?p=596
const int _max = 10001;
// c1是保存各项质量砝码可以组合的数目
// c2是中间量，保存每一次的情况
int c1[_max], c2[_max];
int main()
{
    //int n,i,j,k;
    int nNum;   //
    int i, j, k;

    while(scanf("%d",&nNum)!=EOF)
    {
        for(i=0; i<=nNum; ++i)   // 初始化第一个表达式所有项系数为1
        {
            c1[i] = 1;
            c2[i] = 0;
        }
        for(i=2; i<=nNum; ++i)   // 第i个表达式与前i-1个表达式的结果合并
        {

            for(j=0; j<=nNum; ++j)   //第0项到第n项分别与第i个表达式中的每一项相乘
                for(k=0; k+j<=nNum; k+=i)  // 第i个表达式次数增量为i
                {
                    c2[j+k] += c1[j];
                }
            for(j=0; j<=nNum; ++j)     //更新本次计算结果
            {
                c1[j] = c2[j];
                c2[j] = 0;
            }
        }
        cout << c1[nNum] << endl;
    }
    return 0;
}
//①  、首先对c1初始化，由第一个表达式(1+x+x^2+..x^n)初始化，把质量从0到n的所有砝码都初始化为1.
//②  、 i从2到n遍历，这里i就是指第i个表达式，上面给出的第二种母函数关系式里，每一个括号括起来的就是一个表达式。
//③、j 从0到n遍历，这里j就是(前面i個表达式累乘的表达式)里第j个变量，(这里感谢一下seagg朋友给我指出的错误，大家可以看下留言处的讨论)。如(1+x)(1+x^2)(1+x^3)，j先指示的是1和x的系数，i=2执行完之后变为
//（1+x+x^2+x^3）(1+x^3)，这时候j应该指示的是合并后的第一个括号的四个变量的系数。
//④ 、 k表示的是第j个指数，所以k每次增i（因为第i个表达式的增量是i）。
//⑤  、把c2的值赋给c1,而把c2初始化为0，因为c2每次是从一个表达式中开始的。
