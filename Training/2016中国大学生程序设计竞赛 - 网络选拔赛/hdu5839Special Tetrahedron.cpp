#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,y,z;
}p[1024];

//1¹²Ãæ
int check(node p0,node p1,node p2,node p3)
{
    node s1,s2,s3;
    s1.x=p1.x-p0.x;s1.y=p1.y-p0.y;s1.z=p1.z-p0.z;
    s2.x=p2.x-p0.x;s2.y=p2.y-p0.y;s2.z=p2.z-p0.z;
    s3.x=p3.x-p0.x;s3.y=p3.y-p0.y;s3.z=p3.z-p0.z;
    int ans=s1.x*s2.y*s3.z+s1.y*s2.z*s3.x+s1.z*s2.x*s3.y-s1.z*s2.y*s3.x-s1.x*s2.z*s3.y-s1.y*s2.x*s3.z;
    if(ans==0) return 1;
    else return 0;
}

int dis(node p1,node p2)
{
    return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)+(p1.z-p2.z)*(p1.z-p2.z);
}

vector<int>v;
int main()
{
    int cas=0,ans,_,n,ans1,ans2;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z);
        ans1=0;
        ans2=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                v.clear();
                for(int k=0;k<n;k++)
                {
                    if(k==i||k==j) continue;
                    if(dis(p[k],p[i])==dis(p[k],p[j]))
                        v.push_back(k);
                }
                for(int a=0;a<v.size();a++)
                {
                    for(int b=a+1;b<v.size();b++)
                    {
                        //if(i==1&&j==2) printf("%d %d\n",v[a],v[b]);
                        if(dis(p[v[a]],p[i])!=dis(p[v[b]],p[i])) continue;
                        if(check(p[v[a]],p[v[b]],p[i],p[j])) continue;
                        if(dis(p[i],p[j])==dis(p[v[a]],p[v[b]])&&dis(p[v[a]],p[i])==dis(p[i],p[j]))
                        {
                            //printf("   %d %d %d %d\n",i,j,v[a],v[b]);
                            ans1++;
                        }
                        else
                        {   //printf("====%d %d %d %d\n",i,j,v[a],v[b]);
                            ans2++;
                        }
                    }
                }
            }
        }
        //printf("%d %d\n",ans1,ans2);
        ans=ans1/6+ans2/2;
        printf("Case #%d: %d\n",++cas,ans);
    }
    return 0;
}
