<h2><a href="https://leetcode.com/problems/reorganize-string/">767. Reorganize String</a></h2><h3>Medium</h3><hr><div><p>Given a string <code>s</code>, rearrange the characters of <code>s</code> so that any two adjacent characters are not the same.</p>

<p>Return <em>any possible rearrangement of</em> <code>s</code> <em>or return</em> <code>""</code> <em>if not possible</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> s = "aab"
<strong>Output:</strong> "aba"
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> s = "aaab"
<strong>Output:</strong> ""
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 500</code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
</ul>
</div>


Solution
```cpp
class Solution {
public:
    string reorganizeString(string s) {
        string ans;
        map<char, int> m;
        priority_queue<pair<int, char>> q;
        for(char c : s){
             m[c]++;
        }
        for(auto it : m){
            q.push({it.second, it.first});
        }
        
        while(q.size()>1){
            auto p1 = q.top();
            q.pop();
            auto p2 = q.top();
            q.pop();
            ans +=p1.second;
            ans +=p2.second;
            p1.first -=1;
            p2.first -=1;
            if(p1.first>0) q.push(p1);
            if(p2.first>0) q.push(p2);
        }
        
        if(q.size()==0){
            return ans;
        }else{
            if(q.top().first>1) return "";
            ans +=q.top().second;
            return ans;
        }
        
    }
};
```
