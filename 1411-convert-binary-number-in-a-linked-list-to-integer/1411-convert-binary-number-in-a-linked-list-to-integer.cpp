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
    int getDecimalValue(ListNode* head) {
        string s = "";
        while(head != nullptr){
            s+=(char)head->val;
            head=head->next;
        }
        int result = 0;
        int  multiplier = 1;
        for(int i = (s.size()-1); i > -1; --i){
            result+=(multiplier*(int)s[i]);
            multiplier*=2;
        }

        return result;
    }
};