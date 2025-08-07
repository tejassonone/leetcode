class Solution {
public:
    int n;
    int helper_tr(vector<vector<int>>& ft, int i, int j, vector<vector<int>> &dp){
        if(i==n-1 and j==n-1) return 0;
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int collect = 0;
        if(i+1<n and j-1>=0) collect = max(collect, ft[i][j]+helper_tr(ft, i+1, j-1, dp));
        if(i+1<n) collect = max(collect, ft[i][j]+helper_tr(ft, i+1, j, dp));
        if(i+1<n and j+1<n) collect = max(collect, ft[i][j]+helper_tr(ft, i+1, j+1, dp));
        return dp[i][j] = collect;
    }
    int helper_bl(vector<vector<int>>& ft, int i, int j, vector<vector<int>> &dp){
        if(i==(n-1) and j==(n-1)) return 0;
        if(i<=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int collect = 0;
        if(i-1>=0 and j+1<n) collect = max(collect, ft[i][j]+helper_bl(ft, i-1, j+1, dp));
        if(j+1<n) collect = max(collect, ft[i][j]+helper_bl(ft, i, j+1, dp));
        if(i+1<n and j+1<n) collect = max(collect, ft[i][j]+helper_bl(ft, i+1, j+1, dp));
        return dp[i][j] = collect;
    }
    int maxCollectedFruits(vector<vector<int>>& ft) {
        n = ft.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int res = 0;
        // path for child 1
        for(int i=0; i<n; i++) res +=ft[i][i];

        // path for child 2
        res +=helper_tr(ft, 0, n-1, dp);

        // path for child 2
        res +=helper_bl(ft, n-1, 0, dp);

        return res;
    }
};