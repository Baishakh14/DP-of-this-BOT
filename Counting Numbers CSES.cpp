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
ll dp[20][11][2][2];/// position,last digit,is_tight,leading zero
string s;
ll find(ll pos,ll pn,ll tight,ll lz)
{
    if(pos == s.size()) return 1;
    ll val = dp[pos][pn][tight][lz];
    if(val != -1) return val;
    ll lim = (tight == 1?s[pos] - '0' : 9);
    ll ans = 0;
    for(ll i = 0;i<=lim;i++)
    {
        ll ntight = tight && (i == lim); /// check wheater its tight or not;
        if(lz == 1) /// is leading zero is going;
        {
            if(i == 0) /// still leading zero;
            ans += find(pos+1,10,ntight,1);
            // no leading zero;
            else ans += find(pos + 1,i,ntight,0);
        }
        else 
        {
            if(i == pn) continue;
            ans += find(pos+1,i,ntight,0);
        }
    }
    return dp[pos][pn][tight][lz] = ans;
}
int main()
{
    ll a,b;
    cin>>a>>b;
    s = to_string(b);
    memset(dp,-1,sizeof(dp));
    ll first = find(0,10,1,1);
    s.clear();
    a -= 1;
    s = to_string(a);
    memset(dp,-1,sizeof(dp));
    ll second = find(0,10,1,1);
    cout<<-(second - first)<<endl;
  return 0;
}


//Tata Goodbye Khatam
