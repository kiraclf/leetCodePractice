use std::cell::RefCell;
use std::rc::Rc;

pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
  #[allow(unused)]
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val: val,
            left: None,
            right: None,
        }
    }
}
#[allow(unused)]
pub struct Solution {}
impl Solution {
  #[allow(unused)]
    pub fn find_bottom_left_value(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        match root {
            None => {
                // will not enter
                0
            }
            Some(value) => Solution::find_bottom_left(value, 0).0,
        }
    }

    #[allow(unused)]
    fn find_bottom_left(node: Rc<RefCell<TreeNode>>, depth: i32) -> (i32, i32) {
        let current_node = &(*node).borrow_mut();
        if current_node.left.is_none() && current_node.right.is_none() {
            return (current_node.val, depth);
        }
        let mut res = (0, 0);
        if let Some(left_node) = &current_node.left {
          let left_res = Solution::find_bottom_left(left_node.clone(), depth + 1);
          if left_res.1 > res.1 {
            res = left_res;
          }
        }
        if let Some(right_node) = &current_node.right {
          let right_res = Solution::find_bottom_left(right_node.clone(), depth + 1);
          if right_res.1 > res.1 {
            res = right_res;
          }
        }
        res
    }
}
