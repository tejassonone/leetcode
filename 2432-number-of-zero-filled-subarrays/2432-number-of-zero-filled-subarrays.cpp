class Solution {
public:
    typedef long long ll;
    long long zeroFilledSubarray(vector<int>& nums) {
        ll res = 0;
        ll cnt = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                cnt++;
                res +=cnt;
            }else{
                cnt = 0;
            }
        }
        return res;
    }
};