​<h2><a href="https://leetcode.com/problems/put-marbles-in-bags/">2551. Put Marbles in Bags</a></h2><h3>Hard</h3><hr><div><p>You have k bags. You are given a 0-indexed integer array weights where weights[i] is the weight of the ith marble. You are also given the integer k.

Divide the marbles into the k bags according to the following rules:

No bag is empty.
If the ith marble and jth marble are in a bag, then all marbles with an index between the ith and jth indices should also be in that same bag.
If a bag consists of all the marbles with an index from i to j inclusively, then the cost of the bag is weights[i] + weights[j].
The score after distributing the marbles is the sum of the costs of all the k bags.

Return the difference between the maximum and minimum scores among marble distributions.</p>





## Solution 1.

```cpp
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
```
