int dp[21][21]={};
class Solution {
public:
    int solve(vector<int> &nums, int l, int r){
        if(l>r) return 0;
        if(l==r) return nums[l];
        if(dp[l][r]!=-1) return dp[l][r];
        return dp[l][r] = max(nums[l] - solve(nums, l+1, r), nums[r]-solve(nums, l, r-1));
     }
    bool PredictTheWinner(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, nums.size()-1)>=0;
    }
};