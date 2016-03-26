//题目大意：给pat考生排名，输入第一个为考场数，对于每一个考场，给定考生人数，每有个考生有一个考号和成绩
//输出所有考生的排名，格式为 考生号 最终排名 考场号 考场排名
//注意相同分数的考生名次相同，输出时按考号字典序从小到大排列

//思路：对stl中的sort函数进行重载比较函数来排序
//先对每一个考场内的考生进行排序，得到考场排名，只有再对全部考生排序，得到最终排名

#include<bits/stdc++.h>
using namespace std;

struct node
{
    string s;//s为考号
    int num,frk,lrk,ln;//num为分数，frk为最终排名，lrk为考场排名，ln为考场号
} a[300+5],all[30000+5];//a为对考场内排序时使用的，all为全部考生信息

//sort的比较函数
int cmp(node n,node m)
{
    if(n.num==m.num) return n.s<m.s;//  分数相同比较考号
    else return n.num>m.num;//取分数大的
}

int main()
{
    int _,n,i,cnt=0,k,rk;//cnt记录考生数量，确定排名时用的
    scanf("%d",&_);
    for(k=1; k<=_; k++)
    {
        scanf("%d",&n);//考场内总人数
        for(i=0; i<n; i++)
        {
            cin>>a[i].s>>a[i].num;
            a[i].ln=k;//记录考生考场号
        }
        sort(a,a+n,cmp);//排序
        rk=1;
        //统计排名
        for(i=0; i<n; i++)
        {
            if(i>=1)
            {
                if(a[i].num==a[i-1].num)
                    a[i].lrk=a[i-1].lrk;//与前一个分数相同，排名相同
                else a[i].lrk=rk;
            }
            else a[i].lrk=rk;
            rk++;
        }
        //将a合并到all中
        for(i=0;i<n;i++)
        {
            all[cnt]=a[i];
            cnt++;
        }
    }
    sort(all,all+cnt,cmp);//排序
    //统计排名
    rk=1;
    for(i=0; i<cnt; i++)
    {
        if(i>=1)
        {
            if(all[i].num==all[i-1].num)
                all[i].frk=all[i-1].frk;
            else all[i].frk=rk;
        }
        else all[i].frk=rk;
        rk++;
    }
    //输出
    printf("%d\n",cnt);
    for(i=0; i<cnt; i++)
    {
        cout<<all[i].s<<" "<<all[i].frk<<" "<<all[i].ln<<" "<<all[i].lrk<<endl;
    }
    return 0;
}
