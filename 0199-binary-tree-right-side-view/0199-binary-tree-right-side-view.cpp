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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> canSee;
        if(!root) return canSee;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int sz = q.size();

            for(int i = 0; i < sz; ++i){
                TreeNode* curr = q.front();q.pop();

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);

                if(i == sz-1){
                    canSee.push_back(curr->val);
                }
            }
        }

        return canSee;
    }
};