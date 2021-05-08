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
        scanf("%d",&n);
        int a[212345];
        n+=2;
        long long s = 0;
        for(int i=0;i<n;i++) {
            scanf("%d",a+i);
            s+=a[i];
        }
        // sort(a, a+n);
        if(a[n-1]<a[n-2]) swap(a[n-1],a[n-2]);
        
        for(int i=0;i<n-2;i++) {
            if(a[i]>a[n-1]) {
                swap(a[i], a[n-2]);
                swap(a[n-2], a[n-1]);
            } else if(a[i]>a[n-2]) {
                swap(a[i], a[n-2]);
            }
            // s+=a[i];
        }
        // cout<<a[n-2]<<" "<<a[n-1]<<endl;
        // cout<<s<<endl;
        if(s-a[n-1]-a[n-2] == a[n-2]) {
            for(int i=0;i<n-2;i++) {
                // cout<<a[i]<<" ";
                printf("%d ",a[i]);
            }
            printf("\n");
        } else {
            s = s- a[n-1];
            // cout<<s<<endl;
            int ok=0;
            for(int j=0;j<n-1;j++) {
                if(s-a[j] == a[n-1]) {
                    ok = 1;
                    for(int i=0;i<n-1;i++) {
                        // cout<<a[i]<<" ";
                        if(i==j) continue;
                        printf("%d ",a[i]);
                    }
                    printf("\n");
                }
                if(ok) break;
            }
            if( ok ==0) printf("-1\n");
        }
    }  
    return 0;
}