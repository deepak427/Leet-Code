/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr){
            return head;
        }

        ListNode* result = head;
        ListNode* current = head->next;
        ListNode* last = head;
        ListNode* first = head;

        while(current != nullptr){
            if( last->val == current->val ){
                first->next = current->next;         
            }else {
                first = current;
            }
            last = current; 
            current = current->next;
        }

        return result;
    }
};