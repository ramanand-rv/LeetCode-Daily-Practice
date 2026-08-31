# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        # Need at least 3 nodes to have a critical point
        if not head or not head.next or not head.next.next:
            return [-1, -1]

        prev = head
        cur = head.next
        nxt = cur.next

        idx = 1  # cur is at index 1
        first_critical = -1
        last_critical = -1
        min_dist = float("inf")

        while nxt:
            is_local_max = cur.val > prev.val and cur.val > nxt.val
            is_local_min = cur.val < prev.val and cur.val < nxt.val

            if is_local_max or is_local_min:
                if first_critical == -1:
                    first_critical = idx
                else:
                    min_dist = min(min_dist, idx - last_critical)
                last_critical = idx

            # Slide window forward
            prev = cur
            cur = nxt
            nxt = nxt.next
            idx += 1

        if first_critical == -1 or last_critical == first_critical:
            return [-1, -1]

        max_dist = last_critical - first_critical
        return [min_dist, max_dist]
