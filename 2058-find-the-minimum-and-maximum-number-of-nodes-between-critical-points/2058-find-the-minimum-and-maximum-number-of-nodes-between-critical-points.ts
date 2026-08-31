/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function nodesBetweenCriticalPoints(head: ListNode | null): number[] {
    if (!head || !head.next || !head.next.next) return [-1, -1];

    let prev = head;
    let cur = head.next;
    let nxt = cur.next;

    let idx = 1; // cur is at index 1
    let firstCritical = -1;
    let lastCritical = -1;
    let minDist = Infinity;

    while (nxt !== null) {
        const isLocalMax = cur.val > prev.val && cur.val > nxt.val;
        const isLocalMin = cur.val < prev.val && cur.val < nxt.val;

        if (isLocalMax || isLocalMin) {
            if (firstCritical === -1) {
                firstCritical = idx;
            } else {
                minDist = Math.min(minDist, idx - lastCritical);
            }
            lastCritical = idx;
        }

        // Slide window forward
        prev = cur;
        cur = nxt;
        nxt = nxt.next;
        idx++;
    }

    if (firstCritical === -1 || lastCritical === firstCritical) {
        return [-1, -1];
    }

    const maxDist = lastCritical - firstCritical;
    return [minDist, maxDist];
};