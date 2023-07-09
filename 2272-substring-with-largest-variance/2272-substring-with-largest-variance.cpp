class Solution {
public:
    int largestVariance(string s) {
        int res = 0;

        //for getting unique character from string s;
        set<char> st(s.begin(), s.end());

        //iterate nesting loop for taking two character from set st
        for(char a : st){
            for(char b : st){
                //skip same character
                if(a==b) continue;
                int cnta = 0;
                int cntb = 0;
                //use flag for handling one special case eg-(s = "lripaa")
                bool has_b = false; 
                for(int i=0; i<s.size(); i++){
                    if(s[i]==a) cnta++;
                    if(s[i]==b) cntb++;
                    //if it it conatain both cnta and cntb them update it with res 
                    if(cntb>0){
                        res = max(res, cnta-cntb);
                    }
                    //handle for spacial case where a present in last position and b at starting eg(s="lripaa") 
                    else if(cntb==0 and has_b){
                        res = max(res, cnta-1);
                    }
                    //cnta-cntb get negative then set it as zero
                    if(cntb>cnta){
                        cnta = cntb = 0;
                        has_b = true;
                    }
                }
            }
        }
        return res;
    }
};