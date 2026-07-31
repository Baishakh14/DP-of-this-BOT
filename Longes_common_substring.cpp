                           /// Iterative
#include<bits/stdc++.h>
using namespace std;
const int mx = 1e3 + 10;
int dp[mx][mx];
class Solution {
  public:
    int longCommSubstr(string& a, string& b) {
    memset(dp,0,sizeof(dp));
    int ans = 0;
    a = '1' + a;
    b = '1' + b;
    for(int i = 1;i<a.size();i++)
    {
      for(int j = 1;j<b.size();j++)
      {
        if(a[i] == b[j]) dp[i][j] = 1 + dp[i-1][j-1];
        else dp[i][j] = 0;
        ans = max(ans,dp[i][j]);
      }
    }
    return ans;
};
};
                             /// Recursion
#include<bits/stdc++.h>
using namespace std;
const int mx = 1e3 + 5;
int dp[mx][mx];
class Solution {
  public:
 int find(int i,int j,string &a,string &b)
{
  if(i >= a.size() || j >= b.size()) return 0;  
  if(dp[i][j] != -1) return dp[i][j];
  int ans = 0;
  if(a[i] == b[j]) ans = 1 + find(i + 1,j+1,a,b);
  else 
  {
    return dp[i][j] = 0;
  }
  return dp[i][j] = ans;
}
    int longCommSubstr(string& a, string& b) {
    memset(dp,-1,sizeof(dp));
    int ans = 0;
    int n = a.size();
    int m = b.size();
    for(int i = 0;i<mx;i++)
    {
      for(int j = 0;j<mx;j++) 
      {
        ans = max(ans,find(i,j,a,b));
      }
    }
    return ans;
};
};
