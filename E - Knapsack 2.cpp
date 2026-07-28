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
const int mx = 1e5 + 10;
int main()
{
    ll n,k;
    cin>>n>>k;
    vector<pair<ll,ll>>ab;
    int sum = 0;
    for(int i = 0;i<n;i++) 
    {
        int x,y;
        cin>>x>>y;
        ab.push_back({x,y});
        sum += y;
    }
    ll dp[mx];
    for(int i = 0;i<mx;i++) dp[i] = INT_MAX;
    dp[0] = 0;
    for(auto it : ab)
    {
        for(int i = sum;i>=it.second;i--)
        {
            dp[i] = min(dp[i],it.first + dp[i - it.second]);
        }
    }
    ll ans;
    for(int i = 1;i<mx;i++)
    {
        if(dp[i] <= k) ans = i;
    }
    cout<<ans<<endl;
  return 0;
}


//Tata Goodbye Khatam
