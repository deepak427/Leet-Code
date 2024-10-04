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
    ListNode* mergeList(ListNode* &head1, ListNode* &head2){
        ListNode* result = new ListNode();
        ListNode* returnResult = result;
        while(head1 != nullptr && head2 != nullptr){
            if(head1->val <= head2->val){
                result->next = head1;
                head1 = head1->next;
            }else{
                result->next = head2;
                head2 = head2->next;
            }
            result = result->next;
        }

        if(head1 != nullptr){
            result->next = head1;
        }else{
            result->next = head2;
        }

        return returnResult->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return nullptr;
        }

        ListNode* result = lists[0];

        ListNode* start = lists[0];

        for(int i = 1; i < lists.size(); ++i){
            start = mergeList(start, lists[i]);
        }

        return start;
    }
};