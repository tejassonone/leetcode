class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        //declare map to store count of longest subseq to ith element
        //eg - arr = [1,2,3,4], diff = 1 => m[1]=1, m[2]=2, m[3]=3, m[4]=4;
        map<int, int> mp;
        int ans = 1;
        for(int i=0; i<arr.size(); i++){
            //store current element mp as count(arr[i]-diff)+1
            mp[arr[i]] = mp[arr[i]-diff]+1;
        }
        //take maximum subsequence from all store subsequence
        for(int i=0; i<arr.size(); i++){
            ans = max(ans, mp[arr[i]]);
        }
        return ans;
    }
};