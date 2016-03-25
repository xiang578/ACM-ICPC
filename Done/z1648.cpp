#include <stdio.h>
struct Point
{
    double x,y;
};

Point a[2048],b[2048];

Point operator - (Point m,Point n)
{
    Point c;
    c.x=m.x-n.x;
    c.y=m.y-n.y;
    return c;
}

double cross(Point m,Point n)
{
    return m.x*n.y-n.x*m.y;
}

int main()
{
    int i,j,n;
    int flag;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
            scanf("%lf%lf%lf%lf",&a[i].x,&a[i].y,&b[i].x,&b[i].y);
        flag=1;
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(cross(a[i]-a[j],b[j]-a[j])*cross(b[j]-a[j],b[i]-a[j])>0)
                {
                    if(cross(a[j]-a[i],b[i]-a[i])*cross(b[i]-a[i],b[j]-a[i])>0)
                        flag=0;
                }
                if(flag==0) break;
            }
            if(flag==0) break;
        }

        if(flag) printf("ok!\n");
        else printf("burned!\n");
    }
    return 0;
}
