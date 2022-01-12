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
    int minTimeToType(string w) {
        int ans = 0;
        int now = 0;
        for(int i=0;i<w.size();i++) {
            int k=w[i]-'a';
            if(k!=now) {
                ans += min (abs(k-now), min(26+k-now, 26+now-k));
                now = k;
            }
            ans+=1;
            // cout<<ans<<" ";
        }
        // cout<<ans<<endl;
        return ans;
    }

int main()
{
    minTimeToType("abc");
    minTimeToType("bza");
    minTimeToType("zjpc");  
    return 0;
}