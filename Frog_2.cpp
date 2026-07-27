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
int inf = INT_MAX;
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>ab(n);
    for(auto &it : ab) cin>>it;
    vector<int>dp(n,inf);
    dp[0] = 0;
    for(int i = 1;i<n;i++)
    {
        for(int j = i-1;j >= max(0,i - k);j--)
        {
            dp[i] = min(dp[i],dp[j] + abs(ab[i] - ab[j]));
        }
    }
    cout<<dp[n-1]<<endl;
  return 0;
}


//Tata Goodbye Khatam
