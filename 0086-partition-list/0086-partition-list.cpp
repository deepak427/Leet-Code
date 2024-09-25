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
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp1 = new ListNode();
        ListNode* dummy1 = temp1;

        ListNode* temp2 = new ListNode();
        ListNode* dummy2 = temp2;

        while(head != nullptr){
            if(head->val < x){
                dummy1->next = head;
                dummy1 = head;
            }else{
                dummy2->next = head;
                dummy2 = head;
            }
            head = head->next;
        }

        dummy1->next = temp2->next;
        dummy2->next = nullptr;
        return temp1->next;
    }
};