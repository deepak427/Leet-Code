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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int fVal1 = l1->val;
        int fVal2 = l2->val;
        ListNode* sum = new ListNode((fVal1+fVal2)%10);
        ListNode* c_sum = sum;
        int carry = (fVal1+fVal2)/10;

        l1=l1->next;
        l2=l2->next;

        while(l1 || l2){
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;

            int c_sum = val1+val2+carry;
            carry=c_sum/10;

            sum->next = new ListNode(c_sum%10);

            sum=sum->next;
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;

        }

        if(carry) sum->next = new ListNode(carry);

        return c_sum;
    }
};