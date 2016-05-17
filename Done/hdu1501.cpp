#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;
int ok(int x,int y) {
	if(x<0||y<0) return 0;
	return 1;
}

int main() {
	int k,n,dp[501][501];
	char s[501],s1[501],s2[501];
	scanf("%d",&n);
	for(k=1; k<=n; k++) {
		scanf("%s%s%s",s1,s2,s);
		int len1=strlen(s1),len2=strlen(s2);
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		for(int i=0; i<=len1; i++)
			for(int j=0; j<=len2; j++) {
				if(ok(i-1,j)&&s[i+j-1]==s1[i-1]&&dp[i-1][j])
					dp[i][j]=1;
				if(ok(i,j-1)&&s[i+j-1]==s2[j-1]&&dp[i][j-1])
					dp[i][j]=1;
			}
		printf("Data set %d: ",k);
		if(dp[len1][len2])
			puts("yes");
		else
			puts("no");
	}
	return 0;
}
