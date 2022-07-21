type NodeRef = Box<TreeNode>;
struct TreeNode {
    l: i32,
    r: i32,
    lazy: i32,
    max: i32,
    left: Option<NodeRef>,
    right: Option<NodeRef>,
}

impl TreeNode {
    fn new(l: i32, r: i32) -> NodeRef {
        Box::new(Self {
            l,
            r,
            lazy: 0,
            max: 0,
            left: None,
            right: None,
        })
    }

    fn left(&mut self) -> &mut NodeRef {
        self.left.get_or_insert(TreeNode::new(self.l, self.mid()))
    }

    fn right(&mut self) -> &mut NodeRef {
        self.right
            .get_or_insert(TreeNode::new(self.mid() + 1, self.r))
    }

    fn mid(&self) -> i32 {
        ((self.r - self.l) >> 1) + self.l
    }

    fn push_down(&mut self) {
        self.left().lazy += self.lazy;
        self.right().lazy += self.lazy;
        self.max += self.lazy;
        self.lazy = 0;
    }

    fn add(&mut self, range: (i32, i32), k: i32) -> i32 {
        if range.0 <= self.l && self.r <= range.1 {
            self.lazy += k;
            self.max + self.lazy
        } else {
            self.push_down();
            if range.0 <= self.mid() {
                self.max = self.max.max(self.left().add(range, k));
            }
            if self.mid() < range.1 {
                self.max = self.max.max(self.right().add(range, k));
            }
            self.max
        }
    }

    fn sum(&mut self, range: (i32, i32)) -> i32 {
        if range.0 <= self.l && self.r <= range.1 {
            self.max + self.lazy
        } else {
            self.push_down();
            let mut ret = i32::MIN;
            if range.0 <= self.mid() {
                ret = ret.max(self.left().sum(range));
            }
            if self.mid() < range.1 {
                ret = ret.max(self.right().sum(range));
            }
            ret
        }
    }
}
#[allow(unused)]
struct MyCalendarTwo {
    tree: NodeRef,
}

impl MyCalendarTwo {
    #[allow(unused)]
    fn new() -> Self {
        Self {
            tree: TreeNode::new(0, 1e9 as i32),
        }
    }
    #[allow(unused)]
    fn book(&mut self, start: i32, end: i32) -> bool {
        if self.tree.sum((start, end - 1)) >= 2 {
            false
        } else {
            self.tree.add((start, end - 1), 1);
            true
        }
    }
}

#[test]
fn it_works() {
    let mut calendar = MyCalendarTwo::new();
    let add_list = vec![
        vec![47, 50],
        vec![1, 10],
        vec![27, 36],
        vec![40, 47],
        vec![20, 27],
        vec![15, 23],
        vec![10, 18],
        vec![27, 36],
        vec![17, 25],
        vec![8, 17],
        vec![24, 33],
        vec![23, 28],
        vec![21, 27],
        vec![47, 50],
        vec![14, 21],
        vec![26, 32],
        vec![16, 21],
        vec![2, 7],
        vec![24, 33],
        vec![6, 13],
        vec![44, 50],
        vec![33, 39],
        vec![30, 36],
        vec![6, 15],
        vec![21, 27],
        vec![49, 50],
        // vec![38, 45],
        // vec![4, 12],
        // vec![46, 50],
        // vec![13, 21],
    ];
    for value in add_list {
        calendar.book(value[0], value[1]);
    }
}
