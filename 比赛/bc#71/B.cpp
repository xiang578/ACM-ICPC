/*
import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner in=new Scanner(System.in);
        int n=0,t=0;
        t=in.nextInt();
        for(int i=0;i<t;i++)
        {
        	n=in.nextInt();

        		 BigInteger a=BigInteger.ONE;
        		 a=a.multiply(BigInteger.valueOf(n)).multiply(BigInteger.valueOf(n-1)).multiply(BigInteger.valueOf(n-2)).multiply(BigInteger.valueOf(n-3)).divide(BigInteger.valueOf(24));
        		 a=a.add(BigInteger.valueOf(n));
        		 System.out.println(a);
        }
        in.close();
    }

}
*/
/* ***********************************************
Author        :Maltub
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.top
************************************************ */

#include <cstdio>
#include <cstring>
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
//#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
using namespace std;
typedef vector<int> VI;
typedef unsigned long long ll;
const ll mod=1000000007;
const int N=2048;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _,i;
    ll ans,n;
    scanf("%d",&_);
    while(_--)
    {
        cin>>n;
        if(n==2) ans=2;
        else if(n==3) ans=3;
        else if(n==4) ans=5;
        else ans=(n*(n-1)*(n-2)*(n-3)/24)+n;
        cout<<ans<<endl;
    }
    return 0;
}
