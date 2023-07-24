class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long p = abs((long)n);
        
        while(p){
            if(p&1){
                ans = ans*x;
            }
            p >>=1;
            x = x*x;
        }
        if(n<0) return 1/ans;
        return ans;
    }
};