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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> traversal;

        if( root == nullptr) return traversal;
        queue<TreeNode*> q1;
        q1.push(root);

        while(!q1.empty()){
            vector<int> c_traversal;

            int sz = q1.size();

            for(int i = 0; i < sz; ++i){
                TreeNode* curr = q1.front(); q1.pop();
                c_traversal.push_back(curr->val);

                if(curr->left != nullptr){
                    q1.push(curr->left);
                }
                if(curr->right != nullptr){
                    q1.push(curr->right);
                }
            }
            
            traversal.push_back(c_traversal);

        }

        return traversal;
    }
};