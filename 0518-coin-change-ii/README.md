<h2><a href="https://leetcode.com/problems/coin-change-ii/">518. Coin Change II</a></h2><h3>Medium</h3><hr><div><p>You are given an integer array <code>coins</code> representing coins of different denominations and an integer <code>amount</code> representing a total amount of money.</p>

<p>Return <em>the number of combinations that make up that amount</em>. If that amount of money cannot be made up by any combination of the coins, return <code>0</code>.</p>

<p>You may assume that you have an infinite number of each kind of coin.</p>

<p>The answer is <strong>guaranteed</strong> to fit into a signed <strong>32-bit</strong> integer.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> amount = 5, coins = [1,2,5]
<strong>Output:</strong> 4
<strong>Explanation:</strong> there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> amount = 3, coins = [2]
<strong>Output:</strong> 0
<strong>Explanation:</strong> the amount of 3 cannot be made up just with coins of 2.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> amount = 10, coins = [10]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= coins.length &lt;= 300</code></li>
	<li><code>1 &lt;= coins[i] &lt;= 5000</code></li>
	<li>All the values of <code>coins</code> are <strong>unique</strong>.</li>
	<li><code>0 &lt;= amount &lt;= 5000</code></li>
</ul>
</div>

Solution 1 : recursion + memoization
```cpp
class Solution {
public:
    int solve(vector<int> &coin, int amt, int n, vector<vector<int>> &dp){
        if(amt==0) return 1;
        if(n==0) return 0;
        if(dp[n][amt]!=-1) return dp[n][amt];
        
        if(amt<coin[n-1]){
            return dp[n][amt] = solve(coin, amt, n-1, dp);
        }else{
            return dp[n][amt] = solve(coin, amt, n-1, dp) + solve(coin, amt-coin[n-1], n, dp);
        }
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        return solve(coins, amount, n, dp);
    }
};
```


Solution 2 : dp
```cpp
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for(int c : coins){
            for(int i = 0; i<=amount; i++){
                if(i-c>=0) dp[i] += dp[i-c];
            }
        }
        return dp[amount];
    }
};
```
