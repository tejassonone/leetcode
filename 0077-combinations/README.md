<h2><a href="https://leetcode.com/problems/combinations/">77. Combinations</a></h2><h3>Medium</h3><hr><div><p>Given two integers <code>n</code> and <code>k</code>, return <em>all possible combinations of</em> <code>k</code> <em>numbers chosen from the range</em> <code>[1, n]</code>.</p>

<p>You may return the answer in <strong>any order</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> n = 4, k = 2
<strong>Output:</strong> [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
<strong>Explanation:</strong> There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> n = 1, k = 1
<strong>Output:</strong> [[1]]
<strong>Explanation:</strong> There is 1 choose 1 = 1 total combination.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 20</code></li>
	<li><code>1 &lt;= k &lt;= n</code></li>
</ul>
</div>

Solution
```cpp
class Solution {
public:
    vector<vector<int>> ans;
    void solve(int n, int k, int l, vector<int> t){
        if(t.size()==k){
            ans.push_back(t);
            return;
        }
        for(int i=l; i<=n; i++){
            t.push_back(i);
            solve(n, k, i+1, t);
            t.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> t;
        solve(n, k, 1, t);
        return ans;
    }
};

```
