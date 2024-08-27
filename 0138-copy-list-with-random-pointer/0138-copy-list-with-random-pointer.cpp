/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return head;
        }

        unordered_map<Node*, Node*> old_to_new;
        Node* copyHead = head;
        Node* resultHead = new Node(head->val);
        Node* last = resultHead;
        old_to_new[head] = resultHead;

        head = head->next;

        while(head != NULL){
            Node* newNode = new Node(head->val);
            last->next = newNode;
            last = newNode;
            old_to_new[head] = newNode;            
            head = head->next;            
        }

        Node* copyHeadResult = resultHead;

        while(copyHead != NULL){
            if(copyHead->random != NULL){
                copyHeadResult->random = old_to_new[copyHead->random];
            }
            copyHead = copyHead->next;  
            copyHeadResult = copyHeadResult->next;          
        }

        return resultHead;
    }
};