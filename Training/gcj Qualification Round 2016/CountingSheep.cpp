 #include<bits/stdc++.h>
 using namespace std;
 int a[100],cnt;
 void get(int x)
 {
     int t;
     while(x>0)
     {
         t=x%10;
         if(a[t]==0) {a[t]=1;cnt++;}
         x/=10;
     }
 }
 int main()
 {
     int i,n,_,f;
     map<int,int>mp;
     freopen("A-large.in","r",stdin);
     freopen("out.out","w",stdout);
     scanf("%d",&_);
     for(int k=1;k<=_;k++)
     {
         scanf("%d",&n);
         mp.clear();
         memset(a,0,sizeof(a));
         cnt=0;
         f=1;
         for(i=1;;i++)
         {
             if(mp[n*i]==1) {f=0;break;}
             mp[n*i]=1;
             get(n*i);
             if(cnt==10) break;
         }
         printf("Case #%d: ",k);
         if(f) printf("%d\n",i*n);
         else puts("INSOMNIA");
     }
     return 0;
 }
