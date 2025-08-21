class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int cnt = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]){
                    int mn = INT_MAX;
                    mn = min(mn, (i > 0 ? mat[i-1][j] : 0));
                    mn = min(mn, (j > 0 ? mat[i][j-1] : 0));
                    mn = min(mn, (i > 0 and j > 0 ? mat[i-1][j-1] : 0));
                    mat[i][j] = 1 + mn;
                    cnt +=mat[i][j];
                }
            }
        }
        return cnt;
    }
};