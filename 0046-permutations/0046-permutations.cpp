class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int> &nums, int l){
        if(l==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=l; i<nums.size(); i++){
            swap(nums[i], nums[l]);
            solve(nums, l+1);
            swap(nums[i], nums[l]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        solve(nums, 0);
        return ans;
    }
};