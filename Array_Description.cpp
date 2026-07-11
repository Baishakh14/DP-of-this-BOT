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
    int n,m;
    cin>>n>>m;
    vector<int>ab(n);
    for(auto &it : ab) cin>>it;
    int dp[n][m+1]; /// index , value;
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<=m;j++) dp[i][j] = 0;
    }
    if(ab[n-1] != 0)
    {
        dp[n-1][ab[n-1]] = 1;
    }
    else 
    {
        for(int i = 1;i<=m;i++)
        {
            dp[n-1][i] = 1;
        }
    }
    for(int i = n-2;i>=0;i--)
    {
        if(ab[i] == 0)
        {
            for(int j = 1;j<=m;j++)
            {
                dp[i][j] = dp[i+1][j] % mod;
                if(j-1 > 0) 
                dp[i][j] = (dp[i][j] + dp[i+1][j-1]) % mod;
                if(j + 1 <= m)
                dp[i][j] = (dp[i][j] + dp[i+1][j+1]) % mod;
            }
        }
        else 
        {
            int j = ab[i];
            dp[i][j] = dp[i+1][j] % mod;
            if(j-1 > 0)
            dp[i][j] = (dp[i][j] + dp[i+1][j-1]) % mod;
            if(j + 1 <= m)
            dp[i][j] = (dp[i][j] + dp[i+1][j+1]) % mod;
        }
    }
    int ans = 0;
    for(int i = 0;i<=m;i++)
    {
        ans = (ans + dp[0][i]) % mod;
    }
    cout<<ans<<endl;
  return 0;
}


//Tata Goodbye Khatam