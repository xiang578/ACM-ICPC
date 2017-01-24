#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<cstdio>
#include<bitset>
#include<string>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long LL;
const int low(int x) { return x&-x; }
const int INF = 0x7FFFFFFF;
const int mod = 1e9 + 7;
const int maxn = 50;
int T, n, m, a[maxn];
LL c[maxn][maxn];

int main()
{
	c[0][0] = 1;
	for (int i = 1; i < maxn; i++)
	{
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; j++)
		{
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
		}
	}
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		sort(a, a + n);
		LL L = 0, R = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; i + j < n; j++)
			{
				if (j & 1)
				{
					R += c[n - i - 1][j] * a[i];
				}
				else
				{
					L += c[n - i - 1][j] * a[i];
				}
			}
		}
		cout << abs(L - R) << endl;
	}
	return 0;
}
