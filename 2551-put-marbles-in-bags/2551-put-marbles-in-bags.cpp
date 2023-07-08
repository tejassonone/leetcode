//<-------------------------Algorithm---------------->
//set mx and mn as sum of first and last weight
//because it is neccesary to include it in final answer to conclude whole array
//<-------finding min score------------->
//for finding min score we need to sort it in ascending order
//to consume all k bags we have to fill single weight in each bag from smaller one
//after filling k-1 bag with single weight fill last bag with remaing weight
//eg. for k=4 and N=n distribution will be --> [w1], [w2], [w3], [w4-wn]
//<-------finding max score------------->
//do same step as used for finding min score but sort weight in decending order

class Solution {
public:
    typedef long long ll;
    long long putMarbles(vector<int>& wt, int k) {
        int n = wt.size();
        ll mx = wt[0]+wt[n-1];
        ll mn = mx;
        priority_queue<ll, vector<ll>, greater<ll>> mnq;
        priority_queue<ll> mxq;
        for(int i=1; i<n; i++){
            mnq.push(wt[i-1]+wt[i]);
            mxq.push(wt[i-1]+wt[i]);
        }
        for(int i=1; i<k; i++){
            mn +=mnq.top();
            mnq.pop();
            mx +=mxq.top();
            mxq.pop();
        }
        return mx-mn;
    }
};