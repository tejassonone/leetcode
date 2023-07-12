class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        int n = g.size();
        // store directed graph in reverse order
        vector<vector<int>> al(n);
        //store outdegree to find terminal node and traverse to find safe node
        vector<int> outd(n);
        queue<int> q;
        vector<int> ans;
        for(int i=0; i<n; i++){
            for(auto v : g[i]){
                al[v].push_back(i);
            }
            outd[i] = g[i].size();
            if(outd[i]==0) q.push(i); 
        }

        while(q.size()){
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for(auto v : al[u]){
                if(--outd[v]==0) q.push(v);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};