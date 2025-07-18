/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while(!q.empty()){
            int sz = q.size();

            for(int i = 0; i < sz; ++i){
                TreeNode* curr = q.front(); q.pop();

                if((!curr->left) && (!curr->right)){
                    return level+1;
                }

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }

            ++level;
        }

        return level;
    }
};