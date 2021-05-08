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
    int _;
    cin>>_;
    while(_--){
        int n, a, b;
        map<char,int>mp;
        string s;
        cin>>a>>b;
        cin>>s;
        n = s.size();
        mp['?']=mp['1']=mp['0'] = 0;
        int ok=0;
        for(int i=0;i< (n+1)/2; i++) {
            if(s[i]==s[n-1-i]) 
            {
                mp[s[i]] +=1;
                if(i!=n-1-i) mp[s[i]] +=1;
                continue;
            }
            if(s[i]=='?') s[i] = s[n-1-i];
            else if(s[n-1-i]=='?') s[n-1-i] = s[i];
            else {
                // cout<<i<<":"<<s[i]<<" "<<int(s[n-1-i])<<endl;
                ok=-1;
                break;
            }
            mp[s[i]] +=1;
            if(i!=n-1-i) mp[s[i]] +=1;
        }
        // cout<<s<<" "<<ok<<endl;
        if(ok==-1||mp['1']>b||mp['0']>a||(a%2==1&&b%2==1)||(a%2==1&&mp['1']%2==1)||(b%2==1&&mp['0']%2==1)) {
            cout<<-1<<endl;
            continue;
        }
        for(int i=0;i<(n+1)/2;i++) {
            if(s[i]=='?'){
                if(i!=n-1-i) {
                    if(mp['0']+2<=a) {
                        s[i]=s[n-1-i]='0';
                        mp['0']+=2; 
                    }
                    else {
                        s[i]=s[n-1-i]='1';
                        mp['1']+=2;
                    }
                }
                else {
                    if(mp['0']<a) s[i]='0';
                    else s[i]='1';
                }
            }
        }
        cout<<s<<endl;
    }  
    return 0;
}