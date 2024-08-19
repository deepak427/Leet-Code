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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        bool odd = false;

        ListNode* last = nullptr;
        while(fast != nullptr && fast->next != nullptr ){
            if(fast->next->next == nullptr){
                odd = true;
                break;
            }
            fast = fast->next->next;
            ListNode* temp = slow->next;
            slow->next = last;
            last = slow;
            slow = temp;
        }

        ListNode* temp = slow->next;
        if(odd){
            slow->next = last;
        }else{
            slow->next = last;
            slow = last;          
        }

        while(temp != nullptr){
            if(slow->val != temp->val){
                return false;
            }
            slow = slow->next;
            temp = temp->next;
        }

        return true;
    }
};