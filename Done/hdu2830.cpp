#include<bits/stdc++.h>
using namespace std;

int a[1024][1024],h[1024][1024];
int cmp(int n,int m) {
	return n>m;
}

int main() {
	int n,m,ans;
	char s[1024];
	while(~scanf("%d%d",&n,&m)) {
		ans=0;
		for(int i=0; i<n; i++) {
			scanf("%s",s);
			for(int j=0; j<m; j++) {
				a[i][j]=s[j]-'0';
			}
		}
		//printf("%d\n",n);
		memset(h,0,sizeof(h));
		for(int j=0; j<m; j++)
			if(a[0][j]==1) h[0][j]=1;
			
		for(int i=1; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(a[i][j]==0)
					h[i][j]=0;
				else
					h[i][j]=h[i-1][j]+1;
			}
		}
		for(int i=0; i<n; i++) {
			sort(h[i],h[i]+m,cmp);
			
			for(int j=0; j<m; j++) {
				//printf("%d ",h[i][j]);
				ans=max(ans,h[i][j]*(j+1));
			}
			//printf("\n");
		}
		printf("%d\n",ans);
	}
	return 0;
}
