class Solution {
public:
    typedef long ll;
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());
        int i = 0;
        while(pow(2, i)<=pow(10, 10)){
            string sp2 = to_string(ll(pow(2, i)));
            sort(sp2.begin(), sp2.end());
            if(sp2==s) return true;
            i++;
        }
        return false;        
    }
};