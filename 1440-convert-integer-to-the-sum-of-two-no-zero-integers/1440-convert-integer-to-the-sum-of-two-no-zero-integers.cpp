class Solution {
public:
    bool is_valid(int t){
        while(t > 0){
            if(t % 10 == 0) return false;
            t = t / 10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int a=1; a<n; a++){
            int b = n - a;
            if(is_valid(a) and is_valid(b)) return {a, b};
        }
        return {};
    }
};