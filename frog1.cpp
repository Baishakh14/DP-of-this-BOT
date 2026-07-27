/*
Allaih is Almighty
Bismillahhi Rahmanir Rahim
Baishakh
*/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define ll long long
const int mod = 1e9+7;
// s.order_of_key(x) -> values total are small than x
// *s.find_by_order(x)  -> kth small elemnt (index) in pbds
int n,k;
vector<int>dp;
vector<int>ab;
int find(int ind)
{
  if(ind == 0) return 0;
  if(dp[ind] != -1) return dp[ind];
  int one = INT_MAX;
  for(int i = 1;i<=k;i++)
  {
    if(ind - i >= 0)
    one = min(one ,abs(ab[ind] - ab[ind - i]) + find(ind - i)); 
  }
  return dp[ind] = one;
}
int main()
{
  cin>>n;
  k = 2;
  //cin>>k;
  ab.resize(n);
  dp.assign(n,-1);
  for(auto &it : ab) cin>>it;
  find(n-1);
  cout<<dp[n-1]<<endl;
  return 0;
}


//Tata Goodbye Khatam
