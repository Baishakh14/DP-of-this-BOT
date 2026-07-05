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
vector<ll>dp;
vector<int>ab;
ll find(int num)
{
    if(num == 0) return 1;
    if(dp[num] != -1) return dp[num];
    dp[num] = 0;
    for(int i = 0;i<n;i++)
    {
        if(num >= ab[i])
        {
           dp[num] = (dp[num] + find(num - ab[i])) % mod;
        }
    }
    return dp[num];
}
int main()
{
    cin>>n>>k;
    dp.resize(k + 1);
    for(int i = 0;i<=k;i++) dp[i] = -1;
    ab.resize(n);
    for(auto &it : ab) cin>>it;
    find(k);
    cout<<dp[k]<<endl;
  return 0;
}


//Tata Goodbye Khatam
