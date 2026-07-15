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
int n;
vector<int>coin;
const int mx = 1e5 + 5;
vector<int>ans(mx,0);
int dp[105][mx];
int cnt = 0;
void find(int ind,int sum)
{
  if(dp[ind][sum] != -1) return;
  if(ans[sum] == 0 && sum != 0) cnt++;
  ans[sum] = 1;
  if(ind == n) 
  {
    return;
  }
  dp[ind][sum] = 1;
  find(ind + 1,sum + coin[ind]);
  find(ind + 1,sum);
}
int main()
{
  cin>>n;
  memset(dp,-1,sizeof(dp));
  coin.resize(n);
  for(auto &it : coin) cin>>it;
  find(0,0);
  cout<<cnt<<endl;
  for(int i = 1;i<mx;i++)
  {
    if(ans[i]) cout<<i<<" ";
  }
  return 0;
}


//Tata Goodbye Khatam