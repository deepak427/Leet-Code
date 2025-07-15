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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root) return root;
        if(depth == 1){
            TreeNode* r = new TreeNode(val);
            r->left = root;
            return r;
        }

        queue<TreeNode*> q;
        q.push(root);
        int level = 1;

        while(!q.empty()){
            int sz = q.size();

            for(int i = 0; i < sz; ++i){
                TreeNode* curr = q.front();q.pop();

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);

                if(level == depth-1){
                    TreeNode* l = new TreeNode(val);
                    TreeNode* r = new TreeNode(val);

                    l->left = curr->left;
                    r->right = curr->right;

                    curr->left = l;
                    curr->right = r;
                }
            }

            ++level;
        }

        return root;
    }
};