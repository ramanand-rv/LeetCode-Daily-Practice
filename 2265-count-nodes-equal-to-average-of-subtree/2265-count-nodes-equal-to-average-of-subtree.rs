// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn average_of_subtree(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        fn dfs(node: &Option<Rc<RefCell<TreeNode>>>, count: &mut i32) -> (i64, i64) {
            if let Some(n) = node {
                let n = n.borrow();
                let (ls, lc) = dfs(&n.left, count);
                let (rs, rc) = dfs(&n.right, count);
                let sum = ls + rs + n.val as i64;
                let cnt = lc + rc + 1;
                if sum / cnt == n.val as i64 {   // integer division
                    *count += 1;
                }
                (sum, cnt)
            } else {
                (0, 0)
            }
        }
        let mut count = 0;
        dfs(&root, &mut count);
        count
    }
}