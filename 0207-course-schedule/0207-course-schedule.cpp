class Solution {
public:
    bool canFinish(int nc, vector<vector<int>>& pr) {
        vector<int> ind(nc, 0);
        vector<int> al[nc];
        for(auto v : pr){
            al[v[1]].push_back(v[0]);
            ind[v[0]]++;
        }
        queue<int> q;
        for(int i=0; i<nc; i++){
            if(ind[i]==0) q.push(i);
        }
        int cnt=0;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            cnt++;
            for(int t : al[cur]){
                if(--ind[t]==0) q.push(t);
            }
        }
        return cnt==nc;
    }
};