class Solution {
public:
    typedef long long ll;
    ll mod = 1000000007LL;
    int X;
    int N;
    ll helper(int i, ll sum, vector<vector<ll>> &dp){
        if(sum==0) return 1;
        if(sum<0 || i>N) return 0;
        if(dp[i][sum]!=-1) return dp[i][sum];
        ll el = ll(pow(i, X));
        ll res = helper(i+1, sum-el, dp) + helper(i+1, sum, dp);
        return dp[i][sum] = res%mod;
    }
    int numberOfWays(int n, int x) {
        N = n;
        X = x;
        vector<vector<ll>> dp(n+1, vector<ll>(n+1, -1));
        ll res = helper(1, n, dp);
        return (int)res%mod;
    }
};