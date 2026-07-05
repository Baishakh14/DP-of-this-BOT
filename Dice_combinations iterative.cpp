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
vector<int>dp(mx,0);
int main()
{
  int n;
  cin>>n;
  dp[0] = 1;
  for(int i = 1;i<=n;i++)
  {
    for(int j = 1;j<=6;j++)
    {
      if(j <= i)
      dp[i] = (dp[i] + dp[i - j]) % mod;
    }
  }
  cout<<dp[n]<<endl;
  return 0;
}
 
 
//Tata Goodbye Khatam
