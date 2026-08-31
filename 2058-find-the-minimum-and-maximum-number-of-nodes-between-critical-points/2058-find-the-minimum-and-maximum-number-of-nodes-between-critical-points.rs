// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn nodes_between_critical_points(head: Option<Box<ListNode>>) -> Vec<i32> {
        if head.is_none() || head.as_ref().unwrap().next.is_none() {
        return vec![-1, -1];
        }

        let mut prev = head.unwrap();
        let mut cur = prev.next.take().unwrap();
        let mut nxt = cur.next.take();

        let mut idx = 1; // cur is at index 1
        let mut first_critical = -1;
        let mut last_critical = -1;
        let mut min_dist = i32::MAX;

        while let Some(next_node) = nxt {
            let is_local_max = cur.val > prev.val && cur.val > next_node.val;
            let is_local_min = cur.val < prev.val && cur.val < next_node.val;

            if is_local_max || is_local_min {
                if first_critical == -1 {
                    first_critical = idx;
                } else {
                    let gap = idx - last_critical;
                    if gap < min_dist { min_dist = gap; }
                }
                last_critical = idx;
            }

            // Slide window forward
            prev = cur;
            cur = next_node;
            nxt = cur.next.take();
            idx += 1;
        }

        if first_critical == -1 || last_critical == first_critical {
            return vec![-1, -1];
        }

        let max_dist = last_critical - first_critical;
        vec![min_dist, max_dist]
    }
}