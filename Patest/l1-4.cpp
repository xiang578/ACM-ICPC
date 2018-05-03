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

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    string s;
    vector<string>v;
    while(cin>>s)
    {
        if(s==".") break;
        v.push_back(s);
    }
    
    if(v.size()<=1) cout<<"Momo... No one is for you ..."<<endl;
    else if(v.size()<=13) cout<<v[1]<<" is the only one for you..."<<endl;
    else cout<<v[1]<<" and "<<v[13]<<" are inviting you to dinner..."<<endl;
    return 0; 
}