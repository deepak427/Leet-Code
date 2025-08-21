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
    int kthSmallest(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);

        priority_queue<int> heap;

        while(!q.empty()){
            int sz = q.size();

            for(int i = 0; i < sz; ++i){
                TreeNode* curr = q.front();q.pop();
                heap.push(curr->val);
                if(heap.size()>k) heap.pop();

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }

        return heap.top();
    }
};