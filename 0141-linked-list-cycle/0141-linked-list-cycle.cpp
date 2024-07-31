/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode l(0);
        while( head != nullptr){
            if(head == &l){
                return true;
            }
            ListNode *temp = head->next;
            head->next = &l;
            head = temp;
        }

        return false;
    }
};