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
    vector<int> largestValues(TreeNode* root) {
        vector<int> largest;
        if(!root) return largest;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int sz = q.size();
            int max_v = std::numeric_limits<int>::min();;

            for(int i = 0; i < sz; ++i){
                TreeNode* curr = q.front();q.pop();
                max_v = max(max_v, curr->val); 

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }

            largest.push_back(max_v);
        }

        return largest;
    }
};