use std::{cell::RefCell, rc::Rc};

#[allow(unused)]
struct MyCalendar {
    root: Rc<RefCell<Node>>,
}
impl MyCalendar {
    #[allow(unused)]
    fn new() -> Self {
        MyCalendar {
            root: Rc::new(RefCell::new(Node {
                occuipied: Occuipied::False,
                lazy: true,
                start: 0,
                end: 1000000000,
                left_ptr: None,
                right_ptr: None,
            })),
        }
    }
    #[allow(unused)]
    fn book(&self, start: i32, end: i32) -> bool {
        if MyCalendar::overlap(self.root.clone(), start, end - 1) {
            return false;
        }
        MyCalendar::add(self.root.clone(), start, end - 1);
        return true;
    }

    fn overlap(node: Rc<RefCell<Node>>, start: i32, end: i32) -> bool {
        {
            let my_ref = (*node).borrow();
            if my_ref.occuipied == Occuipied::True {
                return true;
            } else if my_ref.occuipied == Occuipied::False {
                return false;
            }
        }
        MyCalendar::lazy_load(node.clone());
        let my_ref = (*node).borrow();
        let mid = my_ref.start + (my_ref.end - my_ref.start) / 2;
        if start > mid {
            return MyCalendar::overlap(my_ref.right_ptr.as_ref().unwrap().clone(), start, end);
        } else if end <= mid {
            return MyCalendar::overlap(my_ref.left_ptr.as_ref().unwrap().clone(), start, end);
        } else {
            return MyCalendar::overlap(my_ref.left_ptr.as_ref().unwrap().clone(), start, mid)
                || MyCalendar::overlap(my_ref.right_ptr.as_ref().unwrap().clone(), mid + 1, end);
        }
    }

    fn add(node: Rc<RefCell<Node>>, start: i32, end: i32) -> Occuipied {
        {
            let mut my_ref = (*node).borrow_mut();
            if my_ref.start == start && my_ref.end == end {
                my_ref.occuipied = Occuipied::True;
                return my_ref.occuipied;
            }
        }
        MyCalendar::lazy_load(node.clone());
        let mut my_ref = (*node).borrow_mut();
        let node_mid = my_ref.start + (my_ref.end - my_ref.start) / 2;
        let mut left_res =
            (*my_ref.left_ptr.as_ref().unwrap()).borrow_mut().occuipied;
        let mut right_res =
            (*my_ref.right_ptr.as_ref().unwrap()).borrow_mut().occuipied;
        if end <= node_mid {
            left_res = MyCalendar::add(my_ref.left_ptr.as_ref().unwrap().clone(), start, end);
        } else if start > node_mid {
            right_res = MyCalendar::add(my_ref.right_ptr.as_ref().unwrap().clone(), start, end);
        } else {
            left_res = MyCalendar::add(my_ref.left_ptr.as_ref().unwrap().clone(), start, node_mid);
            right_res = MyCalendar::add(
                my_ref.right_ptr.as_ref().unwrap().clone(),
                node_mid + 1,
                end,
            );
        }
        if left_res==Occuipied::True  && right_res==Occuipied::True {
            my_ref.occuipied = Occuipied::True;
            return Occuipied::True;
        } else if left_res==Occuipied::False && right_res == Occuipied::False {
            my_ref.occuipied = Occuipied::False;
            return Occuipied::False;
        }
        my_ref.occuipied = Occuipied::Unknown;
        return Occuipied::Unknown;
    }

    fn lazy_load(node: Rc<RefCell<Node>>) {
        let mut my_ref = (*node).borrow_mut();
        if !my_ref.lazy || (my_ref.start == my_ref.end) {
            return;
        }
        let start = my_ref.start;
        let end = my_ref.end;
        let mid = start + (end - start) / 2;
        let left_node = RefCell::new(Node {
            occuipied: my_ref.occuipied,
            lazy: true,
            start: start,
            end: mid,
            left_ptr: None,
            right_ptr: None,
        });
        let right_node = RefCell::new(Node {
            occuipied: my_ref.occuipied,
            lazy: true,
            start: mid + 1,
            end: end,
            left_ptr: None,
            right_ptr: None,
        });
        my_ref.left_ptr = Some(Rc::new(left_node));
        my_ref.right_ptr = Some(Rc::new(right_node));
        my_ref.lazy = false;
    }
}

struct Node {
    occuipied: Occuipied,
    lazy: bool,
    start: i32,
    end: i32,
    left_ptr: Option<Rc<RefCell<Node>>>,
    right_ptr: Option<Rc<RefCell<Node>>>,
}
#[derive(Debug, Copy, Clone)]
enum Occuipied {
    Unknown,
    True,
    False,
}

impl PartialEq for Occuipied {
    fn eq(&self, other: &Self) -> bool {
        core::mem::discriminant(self) == core::mem::discriminant(other)
    }
}

#[test]
fn it_works() {
    let calendar = MyCalendar::new();
    calendar.book(10, 20);
    assert_eq!(calendar.book(15, 25), false);
    assert_eq!(calendar.book(20, 30), true);
}
