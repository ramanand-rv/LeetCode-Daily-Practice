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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode l3;
        ListNode *cur = &l3;
        
        for(; l1 && l2; cur = cur->next){
            if(l1->val < l2->val){
                cur->next = l1;
                l1 = l1-> next;
            }
            else{
                cur->next = l2;
                l2 = l2->next;
            }
        }
        cur->next = (l1) ? l1 : l2;
        return l3.next;
    }
};