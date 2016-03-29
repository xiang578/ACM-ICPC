//题目大意：给pat考生排名，输入第一个为考场数，对于每一个考场，给定考生人数，每个考生有考号和成绩
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
} all[30000+5];//all为全部考生信息

//sort的比较函数
int cmp(node n,node m)
{
    if(n.num==m.num) return n.s<m.s;//  分数相同比较考号
    else return n.num>m.num;//取分数大的
}

int r[30000+5],now[30000+5];//r维护当前考场前一名的编号，now记录当前考场的排名

int main()
{
    int _,n,i,cnt=0,k,rk,tmp;//cnt记录考生数量，确定排名时用的
    scanf("%d",&_);
    for(k=1; k<=_; k++)
    {
        scanf("%d",&n);//考场内总人数
        for(i=0; i<n; i++)
        {
            cin>>all[cnt].s>>all[cnt].num;
            all[cnt].ln=k;//记录考生考场号
            cnt++;
        }
    }
    memset(r,0xff,sizeof(r));//初始r为-1
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
        //确定考场排名
        tmp=all[i].ln;
        if(r[tmp]==-1)//考场内第一人记为第一
        {
            all[i].lrk=1;
            now[tmp]=1;
        }
        else if(all[r[tmp]].num==all[i].num)//与前一名分数相同，排名相同
        {
            all[i].lrk=all[r[tmp]].lrk;
        }
        else
        {
            all[i].lrk=now[tmp];//分数不同时，获得新的排名
        }
        r[tmp]=i;//修改r
        now[tmp]++;//排名增加
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
