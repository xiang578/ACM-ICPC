#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
string a,b,c;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    cin>>c>>a>>b;
    reverse(c.begin(),c.end());
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    string ans="";
    int add=0;
    for(int i=0;;i++)
    {
        if(i>=a.size()&&i>=b.size()&&add==0) break;
        int x=0;
        int y=0;
        if(i<a.size()) x=a[i]-'0';
        if(i<b.size()) y=b[i]-'0';
        int t=x+y+add;
        if(c[i]=='0') ans+=t%10+'0',add=t/10;
        else ans+=t%(c[i]-'0')+'0',add=t/(c[i]-'0');
        //printf("%d %d %d\n",x,y,t);
        //cout<<ans<<endl;
    }
    reverse(ans.begin(),ans.end());
    int i=0;
    if(ans=="0") {cout<<"0"<<endl;return 0;}
    for(;ans[i]=='0';i++);
    for(;i<ans.size();i++)
        printf("%c",ans[i]);
    cout<<endl;
    return 0;
}