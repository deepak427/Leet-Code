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
    ListNode* reverseList(ListNode* node, ListNode* prev){
        if(!node) return prev;

        ListNode* temp1 = node->next;
        node->next = prev;
        return reverseList(temp1, node);
    }

    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* nList = head;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* l2 = reverseList(slow->next, nullptr);
        slow->next = nullptr;
        bool b = true;

        while(l2!=nList && l2){
            if(b){
                ListNode* temp = nList->next;
                nList->next = l2;
                nList = temp;
                b = !b;
            }else{
                ListNode* temp = l2->next;
                l2->next = nList;
                l2 = temp;
                b = !b;
            }
        }
    }
};