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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* current = list1;
        ListNode* next = list2;
        ListNode* result = list1;

        if(list1 == nullptr){
            return list2;
        }

        if(list2 == nullptr){
            return list1;
        } 

        if(list2->val < list1->val){
            current = list2;
            next = list1;
            result = list2;
        }     

        while(current->next != nullptr){
            if(current->next->val < next->val){
                current = current->next;  
            }else {
                ListNode* temp = current->next;
                current->next = next;
                current = next;
                next = temp;
            }
        }   

        current->next = next;      

        return result;

    }
};