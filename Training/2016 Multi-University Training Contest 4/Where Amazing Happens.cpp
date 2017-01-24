#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>

using namespace std;

const int maxn=32;

map<string,int> aha;

int main()
{
    int t;
    scanf("%d",&t);
    cin.get();
    int cas=1;
    aha.clear();
    aha["Cleveland Cavaliers"]=1;
    aha["Golden State Warriors"]=2;
    aha["San Antonio Spurs"]=5;
    aha["Miami Heat"]=3;
    aha["Dallas Mavericks"]=1;
    aha["L.A. Lakers"]=11;
    aha["Boston Celtics"]=17;
    aha["Detroit Pistons"]=3;
    aha["Chicago Bulls"]=6;
    aha["Houston Rockets"]=2;
    aha["Philadelphia 76ers"]=2;
    aha["Seattle Sonics"]=1;
    aha["Washington Bullets"]=1;
    aha["Portland Trail Blazers"]=1;
    aha["New York Knicks"]=2;
    aha["Milwaukee Bucks"]=1;
    aha["St. Louis Hawks"]=1;
    aha["Philadelphia Warriors"]=2;
    aha["Syracuse Nats"]=1;
    aha["Minneapolis Lakers"]=5;
    aha["Rochester Royals"]=1;
    aha["Baltimore Bullets"]=1;

    while(t--)
    {
        string duru;
        getline(cin,duru);
        printf("Case #%d: %d\n",cas++,aha[duru]);
    }
    return 0;
}
