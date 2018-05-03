#include<stdio.h>
int main()
{
    double r,h;
    float C1,Sa,Sb,Va,Vb;
    scanf("%lf%lf",&r,&h);
    C1=2*3.14*r;
    Sa=3.14*r*r;
    Sb=4*3.14*r*r;
    Va=4*1.0/3*3.14*r*r*r;
    Vb=3.14*r*r*h;
    printf("C1=%.2f\n",C1);
    printf("Sa=%.2f\n",Sa);
    printf("Sb=%.2f\n",Sb);
    printf("Va=%.2f\n",Va);
    printf("Vb=%.2f\n",Vb);
    return 0;
}
