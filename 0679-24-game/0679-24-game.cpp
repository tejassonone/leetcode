class Solution {
public:
    double eps = 1e-3;
    vector<double> operations_result(double a, double b){
        vector<double> res;
        res.push_back(a+b);
        res.push_back(a-b);
        res.push_back(b-a);
        res.push_back(a*b);
        res.push_back(a/b);
        res.push_back(b/a);
        return res;
    } 

    bool helper(vector<double> nums){
        if(nums.size()==1) return fabs(nums[0]-24.0)<eps;

        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                vector<double> remain;
                for(int k=0; k<nums.size(); k++){
                    if(k!=i and k!=j) remain.push_back(nums[k]);
                }
                vector<double> res = operations_result(nums[i], nums[j]);
                for(double i : res){
                    remain.push_back(i);
                    if(helper(remain)) return true;
                    remain.pop_back();
                } 
            }
        }
        return false; 
    }
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        for(int i : cards) nums.push_back(double(i));
        return helper(nums);
    }
};