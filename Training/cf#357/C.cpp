#include<bits/stdc++.h>
using namespace std;
struct cmp
{
    bool operator() (int &a,int &b)
    {
        return a>b;
    }
};
vector<int>ans;
vector<int>ans2;

int main()
{
    string s;
    int n,t;
    priority_queue<int,vector<int>,cmp>q;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        cin>>s;
        if(s=="removeMin")
        {
            if(q.empty())
            {
                t=0;
                ans.push_back(2);
                ans2.push_back(t);
            }
            else q.pop();
            ans.push_back(0);
            ans2.push_back(0);
        }
        else if(s=="insert")
        {
            scanf("%d",&t);
            q.push(t);
            ans.push_back(2);
            ans2.push_back(t);
        }
        else if(s=="getMin")
        {
            scanf("%d",&t);
            if(!q.empty())
            {
                while(q.top()<t)
                {
                    q.pop();
                    ans.push_back(0);
                    ans2.push_back(0);
                    if(q.empty()) break;
                }
            }
            if(q.empty()||q.top()>t)
            {
                q.push(t);
                ans.push_back(2);
                ans2.push_back(t);
            }
            ans.push_back(1);
            ans2.push_back(t);
        }
    }
    printf("%d\n",ans.size());
    for(int i=0; i<ans.size(); i++)
    {
        if(ans[i]==0)
        {
            printf("removeMin\n");
        }
        else if(ans[i]==1)
        {
            printf("getMin %d\n",ans2[i]);
        }
        else if(ans[i]==2)
        {
            printf("insert %d\n",ans2[i]);
        }
    }
    return 0;
}
