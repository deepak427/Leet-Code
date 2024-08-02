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
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        while((head->next != nullptr) && (head->val == head->next->val)){
            head=head->next;
        }

        ListNode* tracker = head;
        ListNode* result = tracker;
        head = head->next;

        while(head != nullptr){
            if( head->next==nullptr || head->val != head->next->val){
                tracker->next = head;
                tracker = head;
            }
            head = head->next;
        }

        return result;
    }
};