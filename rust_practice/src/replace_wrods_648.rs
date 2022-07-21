struct Solution {}

impl Solution {
    #[allow(unused)]
    pub fn replace_words(dictionary: Vec<String>, sentence: String) -> String {
        let words: Vec<&str> = sentence.split(" ").collect();
        let mut trie = Trie::new();
        let mut ans = String::new();
        for prim in &dictionary {
            trie.insert(prim);
        }
        sentence
            .split_whitespace()
            .map(|s| trie.map(s))
            .collect::<Vec<_>>()
            .join(" ")
    }
}

#[derive(Clone)]
struct Trie {
  next: Vec<Option<Box<Trie>>>,
  end: bool,
}

impl Trie {
  fn new() -> Self {
    Self {
      next: vec![None; 26],
      end: false
    }
  }

  fn insert(&mut self, word: &str) {
    let mut ptr = self;
    for c in word.bytes() {
      let index = (c - b'a') as usize;
      if ptr.next[index].is_none() {
        ptr.next[index] = Some(Box::new(Trie::new()));
      }
      ptr = ptr.next[index].as_mut().unwrap();
    }
    ptr.end = true;
  }

   fn map<'a>(&self, word: &'a str) -> &'a str {
        let mut ptr = self;
        for (i, c) in word.char_indices() {
            if ptr.end {
                return &word[0..i];
            }
            let index = (c as u8 - b'a') as usize;
            if ptr.next[index].is_some() {
                ptr = ptr.next[index].as_ref().unwrap();
            } else {
                break;
            }
        }
        word
    }
}
