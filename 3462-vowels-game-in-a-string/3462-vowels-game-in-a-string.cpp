class Solution {
public:
    bool doesAliceWin(string s) {
        vector<char> v = {'a', 'e', 'i', 'o', 'u'};
        int cnt = 0;
        for(char &i : s){
            if(count(v.begin(), v.end(), i)) cnt++;
        }
        if(cnt==0) return false;
        return true;
    }
};