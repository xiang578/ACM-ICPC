#include<stdio.h>
#include<stdlib.h>
int compare( const void *a , const void *b )
		{
		return *(int *)a-*(int *)b;
		}
int main()
{
	int M,N,i,s,sum,x;
	scanf("%d%d",&M,&N);
	int f[100001],g[100001];
	for(i=0;i<M;i++)
		scanf("%d",&f[i]);
	for(s=0;s<N;s++)
		scanf("%d",&g[s]);
	qsort(f,i,sizeof(f[0]),compare);
	qsort(g,s,sizeof(g[0]),compare);
	if(M>=N)
        sum=0;
    else
    {
        sum=s=0;
        for(i=0;i<M;i++)
        {
		while(g[s]<=f[i]&&s<N)
			{sum+=g[s];s++;}
		if(s==N-1&&g[s]<=f[i])
		{sum=0;break;}
		if(g[s]>f[i])
			s++;
	}
	while(s<N)
		{sum+=g[s];s++;}
    }
	printf("%d\n",sum);
	return 0;
}
