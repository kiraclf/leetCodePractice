use std::{collections::HashMap, collections::HashSet, rc::Rc};
struct WordFilter {
    root_node: Node,
    reverse_root_node: Node,
}

struct Node {
    index: i32,
    children: HashMap<char, Box<Node>>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl WordFilter {
    #[allow(unused)]
    fn new(words: Vec<String>) -> Self {
        let mut root_node = Node {
            index: -1,
            children: HashMap::new(),
        };
        let mut reverse_node = Node {
            index: -1,
            children: HashMap::new(),
        };
        for (index, word) in words.iter().enumerate() {
            let original = word;
            let reversed = word.chars().rev().collect::<String>();
            Self::add_word(&mut root_node, original, index as i32);
            Self::add_word(&mut reverse_node, &reversed, index as i32)
        }
        let filter = WordFilter {
            root_node: root_node,
            reverse_root_node: reverse_node,
        };
        filter
    }

    fn find_word(&self, word: &str, is_reverse: bool) -> HashSet<i32> {
        let mut res = HashSet::new();
        let mut current_node = {
            if is_reverse {
                &self.reverse_root_node
            } else {
                &self.root_node
            }
        };
        let mut not_match = false;
        for character in word.chars() {
            if !current_node.children.contains_key(&character) {
                not_match = true;
                break;
            }
            current_node = current_node.children.get(&character).unwrap();
        }
        if !not_match {
            Self::get_all_indexs(current_node, &mut res);
        }
        res
    }

    fn get_all_indexs(node: &Node, set: &mut HashSet<i32>) {
        if node.index != -1 {
            set.insert(node.index);
        }
        for next in &node.children {
            Self::get_all_indexs(next.1, set);
        }
    }

    fn add_word(root: &mut Node, word: &str, index: i32) {
        let mut current_node = root;
        for (_, character) in word.chars().enumerate() {
            if !current_node.children.contains_key(&character) {
                // not find character
                let node = Node {
                    index: -1,
                    children: HashMap::new(),
                };
                current_node.children.insert(character, Box::new(node));
            }
            let node = current_node.children.get_mut(&character).unwrap();
            current_node = node;
        }
        current_node.index = index;
    }
    #[allow(unused)]
    fn f(&self, pref: String, suff: String) -> i32 {
        let prefix_set = self.find_word(&pref, false);
        let suff_set = self.find_word(&(suff.chars().rev().collect::<String>()), true);
        let mut ans = -1;
        for suff_value in suff_set {
            if prefix_set.contains(&suff_value) {
                ans = {
                    if suff_value as i32 > ans {
                        suff_value as i32
                    } else {
                        ans
                    }
                }
            }
        }
        ans
    }
}

#[test]
fn it_works() {
    let word_filter = WordFilter::new(vec![String::from("apple")]);
    let ans = word_filter.f(String::from("b"), String::from("e"));
    assert_eq!(ans, -1);
}
