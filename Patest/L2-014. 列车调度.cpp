#include<bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;
int n,a[100000+10],b[100000+10];
int cnt,t;

int main()
{
    int n,m,k;
    scanf("%d",&n);
    m=1;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    b[0]=a[0];
    for(int i=0;i<n;i++)
    {
        k=lower_bound(b,b+m,a[i])-b;
        if(k==m)
        {
            m++;
            b[k]=a[i];
        }
        else
        {
            b[k]=a[i];
        }
    }
    printf("%d\n",m);
}
/*int main()
{
    int n;
    scanf("%d",&n);
    int cnt=0;
    a[0]=1e6+10;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&t);
        int ok=0;
        for(int j=0;j<cnt;j++)
        {
            if(a[j]>t)
            {
                ok=1;
                a[j]=t;
                break;
            }
        }
        if(!ok){a[cnt]=t;cnt++;}
    }
    printf("%d\n",cnt);
    return 0;
}*/
