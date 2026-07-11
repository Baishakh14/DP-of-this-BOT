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
int dp[1001][100001];
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>price(n),page(n);
    for(auto &it : price) cin>>it;
    for(auto &it : page) cin>>it;
    for(int i = 0;i<n;i++)
    {
        for(int j = 1;j<=k;j++)
        {
            if(i > 0)
            {
                dp[i][j] = dp[i-1][j];
            }
            if(price[i] <= j)
            {
                if(i == 0) dp[i][j] = page[i];
                else 
                dp[i][j] = max(dp[i][j],page[i] + dp[i-1][j - price[i]]);
            }
        }
    }
    // for(int i = 0;i<n;i++)
    // {
    //     for(int j = 0;j<=k;j++) cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    cout<<dp[n-1][k]<<endl;
  return 0;
}


//Tata Goodbye Khatam