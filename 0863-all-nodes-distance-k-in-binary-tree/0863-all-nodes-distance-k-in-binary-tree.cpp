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