#include<bits/stdc++.h>
using namespace std;
set<int>st;
map<int,int>r,l;

int main()
{
    int n,x;
    set<int>::iterator it;
    r.clear();
    l.clear();
    cin>>n;
    scanf("%d",&x);
    st.insert(x);
    for(int i=1;i<n;i++)
    {
        cin>>x;
        it=st.lower_bound(x);
        if(it==st.end())
        {
            it--;
            r[*it]=x;

        }
        else if(l[*it]==0)
        {
            //it++;
            l[*it]=x;
        }
        else
        {
            it--;
            r[*it]=x;
        }
         printf("%d ",*it);
         st.insert(x);
    }
    printf("\n");
    return 0;
}
