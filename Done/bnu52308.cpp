#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n,m;
struct node
{
    int num,id;
    string name;
}p[N];
int cmp(node a,node b)
{    if(a.num==b.num) return a.id>b.id;
    return a.num>b.num;
}
struct cmp1{
    bool operator()(const node a,const node b)
    {
        if(a.num==b.num) return a.id<b.id;
        return a.num<b.num;
    }
};
struct cmp2{
    bool operator()(const node a,const node b)
    {
        if(a.num==b.num) return a.id>b.id;
        return a.num>b.num;
    }
};
map<string,node>mp;
set<node,cmp1>st1;
set<node,cmp2>st2;

int main()
{
    char cmd[10];
    int num,tot;
    string name;
    while(~scanf("%d",&n))
    {
        mp.clear();
        st1.clear();
        st2.clear();
        for(int i=0; i<n; i++)
        {
            cin>>p[i].name>>p[i].num;
            p[i].id=i;
            mp[p[i].name]=p[i];
        }
        sort(p,p+n,cmp);
        int tot=n*0.2;
        for(int i=0;i<tot;i++)
        {
            st1.insert(p[i]);
        }
        for(int i=tot;i<n;i++)
        {
            st2.insert(p[i]);
        }
        sort(p,p+n,cmp);
        tot=n*0.2;
        scanf("%d",&m);
        int cnt=n;
        for(int i=n;i<n+m;i++)
        {
            scanf("%s",cmd);
            cin>>name;
            if(cmd[0]=='-')
            {
                node tmp;
                cnt--;
                tmp=mp[name];
                if(st1.erase(tmp))
                {
                    tot--;
                }
                else
                {
                    st2.erase(tmp);
                }
                int now=cnt*0.2;
                while(tot>now)
                {
                    tot--;
                    tmp=*(st1.begin());
                    st1.erase(tmp);
                    st2.insert(tmp);
                    cout<<tmp.name<<" is not working now."<<endl;
                }
                while(tot<now)
                {
                    tmp=*(st2.begin());
                    st1.insert(tmp);
                    st2.erase(tmp);
                    cout<<tmp.name<<" is working hard now."<<endl;
                    tot++;
                }
            }
            else
            {
                scanf("%d",&num);
                node tmp,t1,t2;
                tmp.id=i;
                tmp.name=name;
                tmp.num=num;
                mp[name]=tmp;
                cnt++;
                int now=cnt*0.2;
                if(st1.size()>=1) t1=*(st1.begin());
                t2=*(st2.begin());
                //printf("111111\n");
                //printf("%d %d\n",tmp.num,t1.num);
                if(st1.size()>=1&&tmp.num>=t1.num)
                {
                    if(now>tot)
                    {
                        st1.insert(tmp);
                        cout<<tmp.name<<" is working hard now."<<endl;
                        tot++;
                    }
                    else
                    {
                        st1.insert(tmp);
                        cout<<tmp.name<<" is working hard now."<<endl;
                        st1.erase(t1);
                        st2.insert(t1);
                        cout<<t1.name<<" is not working now."<<endl;
                    }
                }
                else
                {

                    if(now>tot)
                    {
                        if(tmp.num>=t2.num)
                        {
                            //printf("%d %d\n",tmp.num,t2.num);
                            st1.insert(tmp);
                            cout<<tmp.name<<" is working hard now."<<endl;
                            tot++;
                        }
                        else
                        {
                            st2.insert(tmp);
                            cout<<tmp.name<<" is not working now."<<endl;
                            st2.erase(t2);
                            st1.insert(t2);
                            cout<<t2.name<<" is working hard now."<<endl;
                            tot++;
                        }
                    }
                    else
                    {
                        st2.insert(tmp);
                        cout<<tmp.name<<" is not working now."<<endl;
                    }
                }
            }
        }
    }
    return 0;
}
