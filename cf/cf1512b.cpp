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
        int n;
        cin>>n;
        string a[500];
        vector<int>x;
        vector<int>y;
        for(int i=0;i<n;i++) {
            cin>>a[i];
            for(int j=0;j<n;j++) {
                if(a[i][j] == '*') {
                    x.push_back(i);
                    y.push_back(j);
                }
            }
        }
        if(x[0]==x[1]) {
            if(x[0]==n-1) {
                a[x[0]-1][y[0]] = '*';
                a[x[0]-1][y[1]] = '*';
            } else {
                a[x[0]+1][y[0]] = '*';
                a[x[0]+1][y[1]] = '*';
            }
        } else if(y[0]==y[1]) { 
            if(y[0]==n-1) {
                a[x[0]][y[0]-1] = '*';
                a[x[1]][y[0]-1] = '*';
            } else {
               a[x[0]][y[0]+1] = '*';
               a[x[1]][y[0]+1] = '*'; 
            }
        } else {
            a[x[0]][y[1]]='*';
            a[x[1]][y[0]]='*';
        }
        for(int i=0;i<n;i++) {
            cout<<a[i]<<endl;
        }
    }  
    return 0;
}