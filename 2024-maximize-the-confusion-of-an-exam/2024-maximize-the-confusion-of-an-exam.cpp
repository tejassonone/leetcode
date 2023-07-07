class Solution {
public:
    int solve(string s, int k, char ans){
        int res = 0;
        int l=0;
        int r=0;
        for(r=0; r<s.size(); r++){
            //iterate it until we not get invalid condition
            if(s[r]==ans) k--;
            //after getting valid condition store possible answer and make it again invalid
            while(l<s.size() and k<0){
                res = max(res, r-l);
                if(s[l]==ans) k++;
                l++;
            }
        }
        //handle case where it will not enter into valid condtional loop
        if(k>=0) res = max(res, r-l); 
        return res;
    }
    int maxConsecutiveAnswers(string ak, int k) {
        //check it for both cases i.e 'T' and 'F'
        return max(solve(ak, k, 'T'), solve(ak, k, 'F'));
    }
};