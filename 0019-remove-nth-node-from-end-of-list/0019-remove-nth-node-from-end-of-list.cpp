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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr){
            return head;
        }

        int length = 0;
        ListNode* copyHead = head;
        ListNode* result = head;

        while(copyHead != nullptr){
            copyHead = copyHead->next;
            length++;
        }

        if(length == 1){
            return nullptr;
        }

        if(n == length){
            return result->next;
        }

        int fromStart = length - n;

        for(int i = 0; i < fromStart-1; ++i){
            head = head->next;
        }

        ListNode* toConnect = head->next->next;
        head->next = toConnect;

        return result;
    }
};