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
        ListNode *slowPointer = head;
        ListNode *fastPointer = head;

        while(fastPointer != nullptr && fastPointer->next != nullptr){
            fastPointer = fastPointer->next->next;
            slowPointer = slowPointer->next;
            if(fastPointer == slowPointer){
                return true;
            }
        }

        return false;
    }
};