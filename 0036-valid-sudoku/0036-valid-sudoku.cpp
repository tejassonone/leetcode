class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        int n = b.size();
        map<char, int> mp;
        for(int i=0; i<n; i++){
            mp.clear();
            for(int j=0; j<n; j++){
                if(b[i][j]=='.') continue;
                if(++mp[b[i][j]]==2) return false;
            }
            mp.clear();
            for(int j=0; j<n; j++){
                if(b[j][i]=='.') continue;
                if(++mp[b[j][i]]==2) return false;
            }
        }

        for(int k=0; k<n; k +=3){
            for(int l=0; l<n; l +=3){
                mp.clear();
                for(int i=k; i<k+3; i++){
                    for(int j=l; j<l+3; j++){
                        if(b[i][j]=='.') continue;
                        if(++mp[b[i][j]]==2) return false;
                    }
                }
            }
        }
        
        return true;
    }
};