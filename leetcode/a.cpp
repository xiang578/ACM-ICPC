class Solution {
public:
    bool judge(const pair<int,int> a, const pair<int ,int> b) {
    return a.second<b.second;
    }
  
    vector<string> maxNumOfSubstrings(string s) {
      int a[30];
      int l[30];
      int r[30];
      for(int i=0;i<30;i++)
      {
        l[i]=r[i]=-1;
      }
      for(int i=0;i<s.size();i++) {
        int n = s[i] - 'a';
        if (l[n]==-1) l[n]=i;
        r[n]=i;
      }
      
      vector<pair<int,int>> cnt;
      
      for(int i=0;i<26;i++) {
        if(l[i]==-1 || r[i]==-1) continue;
        int L= l[i];
        int R= r[i];
        for(int j=l[i];j<=r[i];j++) {
          L=min(l[s[j]-'a'], L);
          R=max(r[s[j]-'a'], R);
        }
        l[i]=L;
        r[i]=R;
        cnt.push_back(make_pair(i, R-L+1));
      }
      sort(cnt.begin(), cnt.end(), judge);
      int used[30]=0;
      vector<string> ans;
      for(int i=0;i<cnt.size();i++) {
        int ok = 1;
        for(int j=l[i];j<=r[i];j++) {
          if(used[s[j]-'a'] == 1) {
            ok = 0;
            break;
          }
        }
        if (ok) {
          ans.push_back(s.substr(l[i], r[i]-l[i]+1));
          for(int j=l[i];j<=r[i];j++) {
            used[s[j]-'a'] = 1;
          }
         }
        }
      }
      return ans;
    }
};