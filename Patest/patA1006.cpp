#include<bits/stdc++.h>
using namespace std;
struct node
{
    char s[1024];
    int a[5],b[5];
} p[10024];
int cmp1(node n1,node n2)
{
    if(n1.a[0]==n2.a[0])
    {
        if(n1.a[1]==n2.a[1])
        {
            return n1.a[2]<n2.a[2];
        }
        else return n1.a[1]<n2.a[1];
    }
    else return n1.a[0]<n2.a[0];
}

int cmp2(node n1,node n2)
{
    if(n1.b[0]==n2.b[0])
    {
        if(n1.b[1]==n2.b[1])
        {
            return n1.b[2]>n2.b[2];
        }
        else
            return n1.b[1]>n2.b[1];
    }
    else return n1.b[0]>n2.b[0];
}
int main()
{
    int n;
    scanf("%d\n",&n);
    for(int i=0; i<n; i++)
        scanf("%s%d:%d:%d%d:%d:%d",p[i].s,&p[i].a[0],&p[i].a[1],&p[i].a[2],&p[i].b[0],&p[i].b[1],&p[i].b[2]);
    sort(p,p+n,cmp1);
    printf("%s ",p[0].s);
    sort(p,p+n,cmp2);
    printf("%s\n",p[0].s);
    return 0;
}
