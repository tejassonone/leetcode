class Solution {
public:
    typedef long long ll;
    bool isPowerOfFour(int n) {
        int i = 0;
        while(pow(4, i)<n) i++;
        return pow(4, i)==n;
    }
};