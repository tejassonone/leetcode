class Solution {
public:
    
    double solve(int a, int b, unordered_map<int, unordered_map<int, double>> &dp){
        if(a<=0){
            return b<=0?0.5:1;
        }
        if(b<=0){
            return 0;
        }
        if(dp.find(a)!=dp.end() and dp[a].find(b)!=dp[a].end()){
            return dp[a][b];
        }
        double ans = solve(a-100, b, dp);
        ans +=solve(a-75, b-25, dp);
        ans +=solve(a-50, b-50, dp);
        ans +=solve(a-25, b-75, dp);
        return dp[a][b] = 0.25*ans;
        
    }
    double soupServings(int n) {
        if(n>5000) return 1;
        unordered_map<int, unordered_map<int, double>> dp;
        return solve(n, n, dp);
    }
};