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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA = 0;
        int lengthB = 0;
        ListNode *headACopy = headA;
        ListNode *headBCopy = headB;


        while(headA != nullptr){
            headA = headA->next;
            lengthA++;      
        }

        while( headB != nullptr){     
            headB = headB->next;    
            lengthB++;  
        }   

        if(lengthA < lengthB){
            for(int i = 0; i < (lengthB-lengthA); ++i){
                headBCopy=headBCopy->next;
            }
        }else {
            for(int i = 0; i < (lengthA-lengthB); ++i){
                headACopy=headACopy->next;
            }            
        }

        while(headACopy != nullptr && headBCopy != nullptr){
            if(headACopy==headBCopy){
                return headACopy;
            }
            headACopy=headACopy->next;
            headBCopy=headBCopy->next;
        }

        return nullptr;
    }
};