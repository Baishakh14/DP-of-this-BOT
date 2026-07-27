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
    vector<int>nums(n);
    n = nums.size();
    for(auto &it : nums) cin>>it;
    int dp[n];
    for(int i = 0;i<n;i++) dp[i] = 1;
    int ans = 1;
    for(int i = 1;i<n;i++)
    {
        for(int j = 0;j<i;j++)
        {
            if(nums[i] > nums[j])
            {
                dp[i] = max(dp[i],dp[j] + 1);
                ans = max(ans,dp[i]);   
            }
        }
    }
    cout<<ans<<endl;
  return 0;
}


//Tata Goodbye Khatam
