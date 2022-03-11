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
        if(head == NULL) 
            return NULL;
        int listNum = 1;
        ListNode* tail = head;
        
        //find tail and count listNum
        while(tail->next != NULL){
            listNum++;
            tail = tail->next;
        }
        tail->next = head;
        int newHeadIndex = listNum - k % listNum;

        for(int i = 0; i < newHeadIndex; i++){
            tail = tail->next;
        }
        
        head = tail->next;
        tail->next = NULL;

        return head;
    }
};