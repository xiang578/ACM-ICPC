#include<stdio.h>
#include<math.h>
int main ()
{
	int money,y;
	double d,y1,y2;
	while(scanf("%d",&money)!=EOF){
		if (money<250)
			d=0.01;
		else if (money>=250&&money<500)
			d=0.02;
		else if (money>=500&&money<1000)
			d=0.05;
		else if (money>=1000&&money<2000)
			d=0.08;
		else if (money>=2000&&money<3000)
			d=0.10;
		else if (money>3000)
			d=0.12;
		y1=money*d;
	   if (money<200)
		   y2=0;
	   else if (money>=200&&money<400)
		   y2=12;
	   else if (money>=400&&money<800)
		   y2=30;
	   else if (money>=800&&money<1600)
		   y2=75;
	   else if (money>=1600&&money<2400)
		   y2=175;
	   else if (money>=2400&&money<3000)
		   y2=280;
		   else if (money>=3000)
		   y2=375;
		   if (y1>y2)
		   {	   y=y1;
		   printf ("方案一折扣最大，消费者最多可省%d元钱\n",y);
		   }
		   else
			{   y=y2;
printf ("方案二折扣最大，消费者最多可省%d元钱\n",y);
	}
}
return 0;
}
