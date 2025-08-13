class Solution {
public:
    typedef long long ll;
    bool isPowerOfThree(int n) {
        int i = 0;
        while(ll(pow(3, i))<n) i++;
        return ll(pow(3, i))==n;
    }
};