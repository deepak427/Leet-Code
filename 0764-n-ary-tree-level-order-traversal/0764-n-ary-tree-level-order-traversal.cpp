/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> traversal;
        if(!root) return traversal;
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            int sz = q.size();

            vector<int> c_traversal;

            for(int i = 0; i < sz; ++i){
                Node* curr = q.front(); q.pop();

                c_traversal.push_back(curr->val);

                for(Node* n: curr->children){
                    q.push(n);
                }
            }

            traversal.push_back(c_traversal);
        }

        return traversal;
    }
};