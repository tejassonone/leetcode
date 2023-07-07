class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        //keep only unique elememt in nums array
        nums.erase(unique(begin(nums), end(nums)), end(nums));
        int ans = n;
        int j=0;
        for(int i=0; i<nums.size(); i++){
            //difference of mx-mn = n-1--> mn+n>mx
            //iterate until it will not get invalid and find maximum possible length of subarray
            while(j<nums.size() and nums[j]<nums[i]+n) j++;
            int len = j-i;
            //subtract length from total to know how many nums should replace
            ans = min(ans, n-len);
        }
        return ans;
    }
};