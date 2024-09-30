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

        ListNode* first = new ListNode();
        ListNode* firstcp = first;
        first->next = head;

        while(first != nullptr){
            if(first->next == nullptr){
                break;
            }
            ListNode* dummy = first->next;
            int i = true;
            if(dummy->next == nullptr){
                break;
            }
            if((dummy->next != nullptr) && (dummy->val == dummy->next->val)){
                i = false;
                while((dummy->next != nullptr) && (dummy->val == dummy->next->val)){
                    dummy = dummy->next;
                }
                dummy = dummy->next;
            }
            first->next = dummy;
            if(i){
                first = dummy;
            }
        }

        return firstcp->next;
    }
};