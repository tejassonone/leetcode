class Solution {
public:
    int solve(vector<int> &coin, int amt, int n, vector<vector<int>> &dp){
        if(amt==0) return 1;
        if(n==0) return 0;
        if(dp[n][amt]!=-1) return dp[n][amt];
        
        if(amt<coin[n-1]){
            return dp[n][amt] = solve(coin, amt, n-1, dp);
        }else{
            return dp[n][amt] = solve(coin, amt, n-1, dp) + solve(coin, amt-coin[n-1], n, dp);
        }
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        return solve(coins, amount, n, dp);
    }
};