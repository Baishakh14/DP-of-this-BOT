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
    int n;
    cin>>n;
    vector<int>ab(n);
    for(int i = 0;i<n;i++) cin>>ab[i];
    vector<int>dp(n);
    dp[1] = abs(ab[0] - ab[1]);
    dp[0] = 0;
    for(int i = 2;i<n;i++)
    {
        dp[i] = min(dp[i-1] + abs(ab[i] - ab[i-1]),dp[i-2] + abs(ab[i] - ab[i-2]));
    }
    cout<<dp[n-1]<<endl;
  return 0;
}


//Tata Goodbye Khatam
