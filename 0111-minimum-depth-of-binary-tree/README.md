# [2111. Minimum Depth of Binary Tree (Easy)](https://leetcode.com/problems/minimum-depth-of-binary-tree/)

<p>
  Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.
</p>


###Example 1
```sh
Input: root = [3,9,20,null,null,15,7]
Output: 2
```
###Example 2
```sh
Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5
``

## Solution 1.
```cpp
class Solution {
public:
    int solve(TreeNode* root){
        if(root==nullptr) return 0;
        int l = solve(root->left);
        int r = solve(root->right);
        if(l==0) return 1+r;
        if(r==0) return 1+l;
        return 1+min(l, r);
    }
    int minDepth(TreeNode* root) {
        return solve(root);
    }
};
```
