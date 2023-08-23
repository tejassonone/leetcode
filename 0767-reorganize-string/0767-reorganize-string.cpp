class Solution {
public:
    string reorganizeString(string s) {
        string ans;
        map<char, int> m;
        priority_queue<pair<int, char>> q;
        for(char c : s){
             m[c]++;
        }
        for(auto it : m){
            q.push({it.second, it.first});
        }
        
        while(q.size()>1){
            auto p1 = q.top();
            q.pop();
            auto p2 = q.top();
            q.pop();
            ans +=p1.second;
            ans +=p2.second;
            p1.first -=1;
            p2.first -=1;
            if(p1.first>0) q.push(p1);
            if(p2.first>0) q.push(p2);
        }
        
        if(q.size()==0){
            return ans;
        }else{
            if(q.top().first>1) return "";
            ans +=q.top().second;
            return ans;
        }
        
    }
};