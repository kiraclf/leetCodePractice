use std::{borrow::BorrowMut, cell::RefCell, rc::Rc};

#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None,
        }
    }
}

struct Solution {}

impl Solution {
    #[allow(unused)]
    pub fn prune_tree(root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        let my_root = Some(Rc::new(RefCell::new(TreeNode::new(1))));
        {
            let mut my_root_borrow = (**(my_root.as_ref().unwrap())).borrow_mut();
            my_root_borrow.left = Some(root.as_ref().unwrap().clone());
        }
        Solution::contains_one(
            root.as_ref().unwrap().clone(),
            my_root.as_ref().unwrap().clone(),
            true,
        );
        if my_root.as_ref().unwrap().borrow().left.is_some() {
            Some(
                my_root
                    .as_ref()
                    .unwrap()
                    .borrow()
                    .left
                    .as_ref()
                    .unwrap()
                    .clone(),
            )
        } else {
            None
        }
    }

    fn contains_one(
        node: Rc<RefCell<TreeNode>>,
        parent: Rc<RefCell<TreeNode>>,
        is_left: bool,
    ) -> bool {
        let current_value = (*node).borrow().val;
        let left_is_none = { (*node).borrow().left.is_none() };
        let right_is_none = { (*node).borrow().right.is_none() };
        // leaf handle
        if left_is_none && right_is_none {
            if current_value == 0 {
                Solution::delete_node(parent.clone(), is_left);
                return false;
            } else {
                return true;
            }
        }
        let mut left_have_one = false;
        let left_is_some: bool = { (*node).borrow().left.is_some() };
        if left_is_some {
            let next_node = (*node).borrow().left.as_ref().unwrap().clone();
            left_have_one = Solution::contains_one(next_node, node.clone(), true);
        }
        let mut right_have_one = false;
        let right_is_some: bool = { (*node).borrow().right.is_some() };
        if right_is_some {
            let next_node = (*node).borrow().right.as_ref().unwrap().clone();
            right_have_one = Solution::contains_one(next_node, node.clone(), false);
        }
        if !left_have_one && !right_have_one && current_value == 0 {
            Solution::delete_node(parent.clone(), is_left);
            return false;
        }
        true
    }

    fn delete_node(parent: Rc<RefCell<TreeNode>>, is_left: bool) {
        if is_left {
            (*parent).borrow_mut().left = None;
        } else {
            (*parent).borrow_mut().right = None;
        }
    }
}

#[test]
fn it_works() {
    let mut root = TreeNode::new(1);
    let mut right_1 = TreeNode::new(0);
    let left_2 = TreeNode::new(0);
    let right_2 = TreeNode::new(1);
    right_1.left = Some(Rc::new(RefCell::new(left_2)));
    right_1.right = Some(Rc::new(RefCell::new(right_2)));
    root.right = Some(Rc::new(RefCell::new(right_1)));

    let res = Solution::prune_tree(Some(Rc::new(RefCell::new(root))));
    assert_eq!(res.is_some(), true);
    assert_eq!(res.as_ref().unwrap().borrow().val, 1);
    assert_eq!(res.as_ref().unwrap().borrow().right.is_some(), true);
    assert_eq!(
        res.as_ref()
            .unwrap()
            .borrow()
            .right
            .as_ref()
            .unwrap()
            .borrow()
            .val,
        0
    );
    assert_eq!(
        res.as_ref()
            .unwrap()
            .borrow()
            .right
            .as_ref()
            .unwrap()
            .borrow()
            .left
            .is_none(),
        true
    );
    assert_eq!(
        res.as_ref()
            .unwrap()
            .borrow()
            .right
            .as_ref()
            .unwrap()
            .borrow()
            .right
            .is_some(),
        true
    );
    assert_eq!(
        res.as_ref()
            .unwrap()
            .borrow()
            .right
            .as_ref()
            .unwrap()
            .borrow()
            .right
            .as_ref()
            .unwrap()
            .borrow()
            .val,
        1
    );
}
