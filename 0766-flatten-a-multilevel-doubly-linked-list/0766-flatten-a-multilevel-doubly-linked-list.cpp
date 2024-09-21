/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* node = head;

        while(node != NULL){
            if(node->child != NULL){
                Node* temp2 = node->child;
                while(temp2->next != NULL){
                    temp2 = temp2->next;
                }
                temp2->next = node->next;
                if(node->next != NULL){
                    node->next->prev = temp2;
                }     
                node->next = node->child;
                node->child->prev = node;           
                node->child = NULL;
            }
            node = node->next;
        }

        return head;
    }
};