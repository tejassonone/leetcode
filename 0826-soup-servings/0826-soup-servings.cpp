class Solution {
public:
    double helper(int a, int b, vector<vector<double>> &dp){
        if(a<=0 and b>0) return 1;
        if(a<=0 and b<=0) return 0.5;
        if(a>0 and b<=0) return 0;
        if(dp[a][b]!=-1) return dp[a][b];
        double res = 0.25*(helper(a-100, b, dp)+helper(a-75, b-25, dp)+helper(a-50, b-50, dp)+helper(a-25, b-75, dp));
        return dp[a][b] = res;
    }
    double soupServings(int n) {
        // probability extimaly close to 1
        if(n>5000) return 1;
        vector<vector<double>> dp(n+1, vector<double>(n+1, -1));
        return helper(n, n, dp);
    }
};