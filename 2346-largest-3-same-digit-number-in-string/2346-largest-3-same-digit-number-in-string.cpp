class Solution {
public:
    bool is_good(string s){
        int len = s.size();
        if(len<3) return false;
        for(int i=1; i<len; i++){
            if(s[i-1]!=s[i]) return false;
        }
        return true;
    }
    string largestGoodInteger(string num) {
        string res = "";
        for(int i=0; i<num.size(); i++){
            string t = num.substr(i, 3);
            if(is_good(t)){
                if(res.size()==0) res = t;
                if(t[0]>res[0]) res = t;
            }
        }
        return res;
    }
};