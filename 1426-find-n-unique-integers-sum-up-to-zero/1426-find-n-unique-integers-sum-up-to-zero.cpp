class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        int sum = 0;
        for(int i=1; i<n; i++){
            sum +=i;
            res.push_back(i);
        }
        res.push_back(-1*sum);
        return res;
    }
};