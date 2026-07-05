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
#define ll long long
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
const ll mod = 1e9+7;
// s.order_of_key(x) -> values total are small than x
// *s.find_by_order(x)  -> kth small elemnt (index) in pbds
const ll mx = 1e6 + 10;
ll n,k;
vector<ll>ab;
vector<ll>dp(mx,-1);
ll find(ll num)
{
    if(num == 0) return 0;
    if(dp[num] != - 1) return dp[num];
    ll lage = 1e9;
    for(ll i = 0;i<n;i++)
    {
        if(num >= ab[i])
        {
           lage = min(lage,1 + find(num - ab[i]));
        }
    }
    return dp[num] = lage;
}
int main()
{
    cin>>n>>k;
    ab.resize(n);
    for(auto &it : ab) cin>>it;
    find(k);
    int ans = dp[k];
    if(ans > k) cout<<-1<<endl;
    else cout<<ans<<endl;
  return 0;
}


//Tata Goodbye Khatam
