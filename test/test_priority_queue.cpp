#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <stdlib.h>
// #include <time.h>
using namespace std;

struct node{
        int p;
        node(int x) {
            p=x;
        }

        bool operator<(const node &b) const
        {
            // 1,3,5
            return p>b.p; // 3 > 5, 0
            // 5,3,1
            // return p<b.p; // 3 < 5, 0
            // if(p>b.p) 
            //     return 0;
            // else
            //     return 1;
        }
    };

int main()
{
    priority_queue<node> pq;
    pq.push(node(1));
    pq.push(node(3));
    pq.push(node(5));
    while(!pq.empty()) {
        cout<<pq.top().p<<endl;
        pq.pop();
    }
    return 0;
}