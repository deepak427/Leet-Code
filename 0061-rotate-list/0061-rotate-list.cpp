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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        int size = 0;
        ListNode* c_head = head;

        while(c_head->next != nullptr){
            ++size;
            c_head = c_head->next;
        }
        ++size;
        if(size == 1) return head;
        c_head->next = head;
        c_head = head;

        for(int i = 1; i < size-(k%size); ++i){
            c_head = c_head->next;
        }
        ListNode* res = c_head->next;
        c_head->next = nullptr;

        return res;

    }
};