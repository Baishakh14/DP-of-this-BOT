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
const int mx = 1e6 + 10;
vector<ll>power(mx,0);
vector<int>dp(mx,-1);
ll find(ll n)
{
  if(n == 0) return 1;
  if(dp[n] != -1) return dp[n];
  dp[n] = 0;
  for(int i = 1;i<=6;i++)
  {
    if(n >= i)
    {
     dp[n] = (dp[n] + find(n - i)) % mod;
    }
  }
  return dp[n];
}
int main()
{
  int n;
  cin>>n;
  find(n);
  cout<<dp[n]<<endl;
  return 0;
}
 
 
//Tata Goodbye Khatam
