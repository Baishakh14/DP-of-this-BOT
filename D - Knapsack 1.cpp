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
int main()
{
    int n,k;
    cin>>n>>k;
    ll dp[k+1];
    memset(dp,0LL,sizeof(dp));
    vector<pair<ll,ll>>ab;
    for(int i = 0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        ab.push_back({x,y});
    }
    ll ans = 0;
    for(auto it : ab)
    {
        for(int i = k;i>=it.first;i--)
        {
            dp[i] = max(dp[i],it.second + dp[i - it.first]);
            ans = max(ans,dp[i]);
        }
    }
    cout<<ans<<endl;
  return 0;
}


//Tata Goodbye Khatam
