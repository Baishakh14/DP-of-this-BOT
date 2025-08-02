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
const int mx = 4e4+5;
vector<int>pal;
int main()
{
    int n,t;
    cin>>n>>t;
    t+=3;
    vector<int>ab(n);
    for(auto &it : ab) cin>>it;
    vector<vector<int>>dp(n+1,vector<int>(t));
    for(int i = 0;i<n;i++) dp[i][0] = 1;
    for(int i = n-1;i>=0;i--)
    {
        for(int sum = 1;sum<t;sum++)
        {
            int pick = 0;
            int skip = dp[i+1][sum];
            if(ab[i] <= sum) pick = dp[i][sum-ab[i]];
            dp[i][sum] = (pick + skip) % mod;
        }
    }
    cout<<dp[0][t-3]<<endl;
  return 0;
}


//Tata Goodbye Khatam
