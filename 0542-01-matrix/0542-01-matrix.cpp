class Solution {
public:
    int dir[5] = {1, 0, -1, 0, 1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> v(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==0){
                    q.push({i, j});
                    mat[i][j] =-1;
                }
            }
        }
        
        while(q.size()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(int k=0; k<4; k++){
                int fx = x + dir[k];
                int fy = y + dir[k+1];
                if(fx>=0 and fx<m and fy>=0 and fy<n and mat[fx][fy]!=-1){
                    v[fx][fy] = 1 + v[x][y];
                    q.push({fx, fy});
                    mat[fx][fy] = -1;
                }
            }
        }
        return v;
    }
};