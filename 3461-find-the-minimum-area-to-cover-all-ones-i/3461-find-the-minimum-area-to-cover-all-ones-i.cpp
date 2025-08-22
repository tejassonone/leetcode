class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int l = INT_MAX;
        int t = INT_MAX;
        int r = INT_MIN;
        int b = INT_MIN;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]){
                    l = min(l, j);
                    t = min(t, i);
                    r = max(r, j);
                    b = max(b, i);
                }
            }
        }
        if(l==INT_MAX) return 0;
        int res = (r-l+1)*(b-t+1);
        return res;
    }
};