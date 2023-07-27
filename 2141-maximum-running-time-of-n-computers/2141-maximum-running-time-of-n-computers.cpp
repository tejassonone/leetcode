class Solution {
public:
    typedef long long ll;
    long long maxRunTime(int n, vector<int>& batt) {
        sort(batt.begin(), batt.end());
        ll sum = accumulate(batt.begin(), batt.end(), 0ll);
        ll l = 1;
        ll r = sum/n;
        ll ans = 1;
        while(l<=r){
            ll m = l + (r-l)/2ll;
            ll cmpcnt = 0;
            ll s = 0;
            for(int i=0; i<batt.size(); i++){
                s +=batt[i];
                if(s>=m){
                    cmpcnt++;
                    s =s-m;
                }
            }
            if(cmpcnt>=n){
                ans = m;
                l = m+1;
            }else{
                r = m-1;
            }
            
        }
        return ans;
    }
};