#include <stdio.h>
#include <string.h>
#include<vector>
#include<algorithm>
using namespace std;
char s[10000+10][20],t[20];
vector<int>ans;
int main()
{
    int cnt=0;
    while(~scanf("%s",&s[cnt]))
    {
        if(s[cnt][0]=='#')
        {
            while(~scanf("%s",t))
            {
                if(t[0]=='#') break;
                ans.clear();
                int ok=0;
                int n=strlen(t);
                for(int i=0;i<cnt;i++)
                {
                    int m=strlen(s[i]);
                    if(n==m)
                    {
                        int f=0;
                        for(int j=0;j<n;j++)
                        {
                            if(s[i][j]!=t[j]) f++;
                            if(f==2) break;
                        }
                        if(f==0) ok=1;
                        else if(f==1) ans.push_back(i);
                    }
                    else if(n+1==m)
                    {
                        int f=0;
                        int k=0;
                        for(int j=0;j<n;j++)
                        {
                            while(t[j]!=s[i][k])
                            {
                                f++;
                                if(f>=2) break;
                                k++;
                            }
                            k++;
                            if(f>=2) break;
                        }
                        if(f<=1) ans.push_back(i);
                    }
                    else if(m+1==n)
                    {
                        int f=0;
                        int k=0;
                        for(int j=0;j<m;j++)
                        {
                            while(s[i][j]!=t[k])
                            {
                                f++;
                                if(f>=2) break;
                                k++;
                            }
                            k++;
                            if(f>=2) break;
                        }
                        if(f<=1) ans.push_back(i);
                    }
                    if(ok) break;
                }
                if(ok==1) printf("%s is correct\n",t);
                else
                {
                    printf("%s:",t);
                    for(int i=0;i<ans.size();i++)
                        printf(" %s",s[ans[i]]);
                    printf("\n");
                }
            }
            cnt=0;
        }
        else cnt++;
    }
    return 0;
}
