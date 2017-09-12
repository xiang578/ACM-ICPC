#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <math.h>
#include <set>
#include <time.h>
#include <cmath>
using namespace std;

int n;

int main() {
  int n;
  scanf("%d",&n);

  int a,b;
  b=n/2+1;
  for(;;)
  {
      a=n-b;
      if(__gcd(a,b)==1) break;
      b++;
  }
  cout<<a<<" "<<b;
  return 0;
}
