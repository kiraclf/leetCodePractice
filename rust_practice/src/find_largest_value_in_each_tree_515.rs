use std::cell::RefCell;
use std::rc::Rc;
use std::vec;

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
struct Solution {}
impl Solution {
    #[allow(unused)]
    pub fn largest_values(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut level_nodes: Vec<Rc<RefCell<TreeNode>>> = vec![];
        let mut res: Vec<i32> = vec![];
        // add first node
        match root {
            None => {
                return res;
            }
            Some(node) => {
                level_nodes.push(node.clone());
            }
        }
        while level_nodes.len() != 0 {
            let mut current_size = level_nodes.len();
            let mut current_largest = i32::min_value();
            while current_size > 0 {
                let current_node_rc = level_nodes[0].clone();
                let current_node = current_node_rc.borrow();
                level_nodes.remove(0);
                // check value
                if current_node.val > current_largest {
                    current_largest = current_node.val;
                }
                // append child
                if let Some(left_node) = &current_node.left {
                    level_nodes.push(left_node.clone());
                }
                if let Some(right_node) = &current_node.right {
                    level_nodes.push(right_node.clone());
                }
                current_size -= 1;
            }
            res.push(current_largest);
        }
        res
    }
}

#[test]
fn it_works() {
    let one = Rc::new(RefCell::new(TreeNode::new(1)));
    let two = Rc::new(RefCell::new(TreeNode::new(2)));
    let three = Rc::new(RefCell::new(TreeNode::new(3)));
    let five = Rc::new(RefCell::new(TreeNode::new(5)));
    let three_3 = Rc::new(RefCell::new(TreeNode::new(3)));
    let nine = Rc::new(RefCell::new(TreeNode::new(9)));
    (*one).borrow_mut().left = Some(three.clone());
    (*one).borrow_mut().right = Some(two.clone());
    (*three).borrow_mut().left = Some(five.clone());
    (*three).borrow_mut().right = Some(three_3.clone());
    (*two).borrow_mut().right = Some(nine.clone());
    let res = Solution::largest_values(Some(one.clone()));
    assert_eq!(res, vec![1, 3, 9]);
}
