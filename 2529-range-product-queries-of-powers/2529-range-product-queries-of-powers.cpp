class Solution {
public:
    typedef long long ll;
    ll mod = 1000000007LL;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> p;
        for(int i=0; i<31; i++){
            if(n >> i & 1) p.push_back(1<<i);
        }
        vector<int> res;
        for(auto &it : queries){
            int l = it[0];
            int r = it[1];
            ll prod = 1LL;
            for(int i=l; i<=r; i++){
                prod *=p[i];
                prod %=mod;
            }
            res.push_back(int(prod));
        }
        return res;
    }
};