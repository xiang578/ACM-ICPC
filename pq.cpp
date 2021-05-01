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
    priority_queue<int, vector<int>, greater<int> >pq1;
    pq1.push(29);
    pq1.push(12);
    pq1.push(400);
    while(!pq1.empty()) {
        cout<<pq1.top()<<endl;
        pq1.pop();
    }
    priority_queue<int>pq2;
    pq2.push(29);
    pq2.push(12);
    pq2.push(400);
    while(!pq2.empty()) {
        cout<<pq2.top()<<endl;
        pq2.pop();
    }
    vector<vector<int> > vv={{2, 3}, {1, 4}, {3, 4}, {3, 5}, {3,3}};
    sort(vv.begin(), vv.end(), [](vector<int>a, vector<int>b){
        if(a[0]==b[0]) {
            return a[1]<b[1];
        }else
            return a[0]<b[0];
    });
    for(auto v:vv) {
        cout<<v[0]<<" "<<v[1]<<endl;
    }
    return 0;
}