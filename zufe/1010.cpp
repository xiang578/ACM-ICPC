#include<stdio.h>
#include<math.h>
int main()
{
    double x1,y1,x2,y2,x3,y3,x4,y4,l1,l2,l3,l4,l5;
    while (scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4)!=EOF)
    {
        l1=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        l2=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
        l3=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
        l4=sqrt((x4-x3)*(x4-x3)+(y3-y4)*(y3-y4));
        l5=sqrt((x2-x4)*(x2-x4)+(y2-y4)*(y2-y4));
        double p1,p2,s,s1,s2;
        p1=(l1+l2+l3)/2;
        s1=sqrt(p1*(p1-l1)*(p1-l2)*(p1-l3));
        p2=(l5+l4+l3)/2;
        s2=sqrt(p2*(p2-l3)*(p2-l4)*(p2-l5));
        s=s1+s2;
        printf("area = %.4\n",s);
    }
    return 0;
}
