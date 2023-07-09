<h2><a href="https://leetcode.com/problems/substring-with-largest-variance/">2272. Substring With Largest Variance</a></h2><h3>Hard</h3><hr><div><p>The <strong>variance</strong> of a string is defined as the largest difference between the number of occurrences of <strong>any</strong> <code>2</code> characters present in the string. Note the two characters may or may not be the same.</p>

<p>Given a string <code>s</code> consisting of lowercase English letters only, return <em>the <strong>largest variance</strong> possible among all <strong>substrings</strong> of</em> <code>s</code>.</p>

<p>A <strong>substring</strong> is a contiguous sequence of characters within a string.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s = "aababbb"
<strong>Output:</strong> 3
<strong>Explanation:</strong>
All possible variances along with their respective substrings are listed below:
- Variance 0 for substrings "a", "aa", "ab", "abab", "aababb", "ba", "b", "bb", and "bbb".
- Variance 1 for substrings "aab", "aba", "abb", "aabab", "ababb", "aababbb", and "bab".
- Variance 2 for substrings "aaba", "ababbb", "abbb", and "babb".
- Variance 3 for substring "babbb".
Since the largest possible variance is 3, we return it.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s = "abcde"
<strong>Output:</strong> 0
<strong>Explanation:</strong>
No letter occurs more than once in s, so the variance of every substring is 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
</ul>
</div>


## Solution 1.

```cpp
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

```
