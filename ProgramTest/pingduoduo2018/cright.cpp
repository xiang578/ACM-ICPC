#include<iostream>  
#include<cstring>  
#define maxn 1000 
#define mod 1000000007  
using namespace std;  
  
long long dp[maxn][maxn];  
int num[maxn];  
int vis[maxn];  
  
int main()  
{  
        int n, m;  
        cin>>n;  
        memset(dp,0,sizeof(dp));  
        memset(vis,0,sizeof(vis));  
        for(int i=1; i<=n; i++)  
        {  
            cin>>num[i];
            num[i]+=200;
            dp[i][1]=1;  
        }  
        for(int i=2; i<=n; i++)  
        {  
            for(int j=1; j<=n; j++)  
            {  
                for(int k=i-1; k>=1; k--)  
                {  
                    if(num[i]>num[k]&&!vis[num[k]])  
                    {  
                        vis[num[k]]=1;  
                        dp[i][j]+=dp[k][j-1];  
                    }  
                     
                }  
                memset(vis,0,sizeof(vis)); 
            }  
        }  
  
        
        long long ans=0; 
         
        for(m=2;m<=n;m++) {
            memset(vis,0,sizeof(vis));
        for(int i=n; i>=1; i--)  
        {  
            if(vis[num[i]])  
                continue;  
            vis[num[i]] = 1;  
            ans += dp[i][m];
        }  
        //printf("%d %lld\n",m,ans);
    }
        cout<<ans<<endl;   
    return 0;  
}  
