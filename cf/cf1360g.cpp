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
        int a[123];
        for(int i=0;i<n;i++) {
            cin>>a[i];
        }
        sort(a, a+n);
        // cout<<a[0]<<" "<<a[n-1]<<endl;
        if(a[0]!=a[1]) cout<<a[0]<<endl;
        else cout<<a[n-1]<<endl;
    }  
    return 0;
}