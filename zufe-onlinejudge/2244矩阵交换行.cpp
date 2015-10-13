#include<stdio.h>
int main()
{
	int i,j,n,m,a[5][5],b[6],x=0,y=0;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++) scanf("%d",&a[i][j]);
	}
	scanf("%d%d",&m,&n);
	if(m>=5||n>=5) printf("error\n");
	else
	{
		for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(a[i][j]==m) x++;
			if(a[i][j]==n) y++;
		}
	}
			if(x>=1&&y>=1)
			{
				for(j=0;j<5;j++)
				{
					b[j]=a[m][j];
					a[m][j]=a[n][j];
				}
				for(j=0;j<5;j++)
				{
					a[n][j]=b[j];
				}
				for(i=0;i<5;i++)
				{
		        for(j=0;j<5;j++)
				{
					if(j==0) printf("%d",a[i][j]);
					else printf(" %d",a[i][j]);
				}
				printf("\n");
				}
			}
			else printf("error\n");
	}
	return 0;
}

