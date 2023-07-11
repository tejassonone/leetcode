<h2><a href="https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/">863. All Nodes Distance K in Binary Tree</a></h2><h3>Medium</h3><hr><div><p>Given the <code>root</code> of a binary tree, the value of a target node <code>target</code>, and an integer <code>k</code>, return <em>an array of the values of all nodes that have a distance </em><code>k</code><em> from the target node.</em></p>

<p>You can return the answer in <strong>any order</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/06/28/sketch0.png" style="width: 500px; height: 429px;">
<pre><strong>Input:</strong> root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
<strong>Output:</strong> [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> root = [1], target = 1, k = 3
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 500]</code>.</li>
	<li><code>0 &lt;= Node.val &lt;= 500</code></li>
	<li>All the values <code>Node.val</code> are <strong>unique</strong>.</li>
	<li><code>target</code> is the value of one of the nodes in the tree.</li>
	<li><code>0 &lt;= k &lt;= 1000</code></li>
</ul>
</div>


## solution 1
```cp

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> al[501];
    void make_al(TreeNode *root, int parent){
        if(root==nullptr) return;
        if(parent!=-1){
            al[root->val].push_back(parent);
        }
        if(root->left){
            make_al(root->left, root->val);
            al[root->val].push_back(root->left->val);
        }
        if(root->right){
            make_al(root->right, root->val);
            al[root->val].push_back(root->right->val);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        //store all node int adjecency list
        make_al(root, -1);
        //after storing it in adjecency list run BFS on it by level by level
        //after reaching k level break loop and store all kth node value in 'ans' vector
        queue<pair<int, int>> q;
        q.push({target->val, -1});
        while(q.size() and k>0){
            int sz = q.size();
            while(sz--){
                int cur = q.front().first;
                int par = q.front().second;
                q.pop();
                
                for(auto it : al[cur]){
                    if(it==par) continue;
                    q.push({it, cur});
                }
            }
            if(--k==0) break;
        }

        vector<int> ans;
        while(q.size()){
            ans.push_back(q.front().first);
            q.pop();
        }
        return ans;
    }
};
```
