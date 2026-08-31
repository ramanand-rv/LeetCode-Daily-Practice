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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // Need at least 3 nodes to have a critical point
        if (!head || !head->next || !head->next->next)
            return {-1, -1};

        ListNode* prev = head;
        ListNode* cur = head->next;
        ListNode* nxt = cur->next;

        int idx = 1; // cur is at index 1
        int firstCritical = -1;
        int lastCritical = -1;
        int minDist = INT_MAX;

        while (nxt != nullptr) {
            bool isLocalMax = (cur->val > prev->val && cur->val > nxt->val);
            bool isLocalMin = (cur->val < prev->val && cur->val < nxt->val);

            if (isLocalMax || isLocalMin) {
                if (firstCritical == -1) {
                    firstCritical = idx;
                } else {
                    minDist = min(minDist, idx - lastCritical);
                }
                lastCritical = idx;
            }

            // Slide window forward
            prev = cur;
            cur = nxt;
            nxt = nxt->next;
            idx++;
        }

        if (firstCritical == -1 || lastCritical == firstCritical)
            return {-1, -1};

        int maxDist = lastCritical - firstCritical;
        return {minDist, maxDist};
    }
};