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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(!head || !head->next) 
            return head;
        
        ListNode* dummy = new ListNode(-105, head);
        ListNode* temp = dummy;
        ListNode *temp2;
        
        while(head && head->next){
            temp2 = head->next;
            
            if(head->val == temp2->val){
                while(temp2 && head->val == temp2->val) temp2=temp2->next;    
                temp->next = temp2;
                head = temp2;
            }
            else{
                head = head->next;
                temp = temp->next;
            }    
        }
        
        return dummy->next;
    }
};