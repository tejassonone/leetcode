class Solution {
public:
    vector<vector<int>> ans;
    void solve(int n, int k, int l, vector<int> t){
        if(t.size()==k){
            ans.push_back(t);
            return;
        }
        for(int i=l; i<=n; i++){
            t.push_back(i);
            solve(n, k, i+1, t);
            t.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> t;
        solve(n, k, 1, t);
        return ans;
    }
};