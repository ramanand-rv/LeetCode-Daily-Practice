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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr)  // if(size linked list == 1 || == 0)
			return head;
			
		ListNode* p2 = head->next->next, *p1 = head->next;
		head->next = p2;
		p1->next = head;
		head = p1;
		
		ListNode* p = head->next; // p is a node stand in front p1 and p2
		while((p1 = p->next) != nullptr && (p2 = p->next->next) != nullptr) { 

			p->next = p2;
			p1->next = p2->next;
			p2->next = p1;
			
			p = p->next->next;
		}
		return head;
    }
};