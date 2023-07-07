<h2><a href="https://leetcode.com/problems/maximize-the-confusion-of-an-exam/">2024. Maximize the Confusion of an Exam</a></h2><h3>Medium</h3><hr><div><p>A teacher is writing a test with <code>n</code> true/false questions, with <code>'T'</code> denoting true and <code>'F'</code> denoting false. He wants to confuse the students by <strong>maximizing</strong> the number of <strong>consecutive</strong> questions with the <strong>same</strong> answer (multiple trues or multiple falses in a row).</p>

<p>You are given a string <code>answerKey</code>, where <code>answerKey[i]</code> is the original answer to the <code>i<sup>th</sup></code> question. In addition, you are given an integer <code>k</code>, the maximum number of times you may perform the following operation:</p>

<ul>
	<li>Change the answer key for any question to <code>'T'</code> or <code>'F'</code> (i.e., set <code>answerKey[i]</code> to <code>'T'</code> or <code>'F'</code>).</li>
</ul>

<p>Return <em>the <strong>maximum</strong> number of consecutive</em> <code>'T'</code>s or <code>'F'</code>s <em>in the answer key after performing the operation at most</em> <code>k</code> <em>times</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> answerKey = "TTFF", k = 2
<strong>Output:</strong> 4
<strong>Explanation:</strong> We can replace both the 'F's with 'T's to make answerKey = "<u>TTTT</u>".
There are four consecutive 'T's.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> answerKey = "TFFT", k = 1
<strong>Output:</strong> 3
<strong>Explanation:</strong> We can replace the first 'T' with an 'F' to make answerKey = "<u>FFF</u>T".
Alternatively, we can replace the second 'T' with an 'F' to make answerKey = "T<u>FFF</u>".
In both cases, there are three consecutive 'F's.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> answerKey = "TTFTTFTT", k = 1
<strong>Output:</strong> 5
<strong>Explanation:</strong> We can replace the first 'F' to make answerKey = "<u>TTTTT</u>FTT"
Alternatively, we can replace the second 'F' to make answerKey = "TTF<u>TTTTT</u>". 
In both cases, there are five consecutive 'T's.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == answerKey.length</code></li>
	<li><code>1 &lt;= n &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>answerKey[i]</code> is either <code>'T'</code> or <code>'F'</code></li>
	<li><code>1 &lt;= k &lt;= n</code></li>
</ul>
</div>



## Solution 1.

```cpp
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
```
Check this "[C++ Maximum Sliding Window Cheatsheet Template!](https://leetcode.com/problems/frequency-of-the-most-frequent-element/discuss/1175088/C%2B%2B-Maximum-Sliding-Window-Cheatsheet-Template!)".
