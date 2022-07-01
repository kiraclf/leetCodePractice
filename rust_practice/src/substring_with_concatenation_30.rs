use std::convert::TryInto;

#[allow(unused)]
struct Solution {}

impl Solution {
    #[allow(unused)]
    pub fn find_substring(s: String, words: Vec<String>) -> Vec<i32> {
        // 单词个数
        let word_count = words.len();
        // 单词长度
        let word_size = words[0].len();
        // 答案数组
        let mut ans: Vec<i32> = Vec::new();
        // 存放所有的单词map
        use std::collections::HashMap;
        let mut word_map: HashMap<&str, i32> = HashMap::new();
        for word in words.iter() {
            word_map.insert(word.as_str(), word_map.get(word.as_str()).unwrap_or(&0) + 1);
        }
        // 枚举每个起点
        for i in 0..(s.len() - word_count * word_size + 1) {
            let mut cur_map: HashMap<&str, i32> = HashMap::new();
            let mut error = false;
            for j in 0..word_count {
                // 第 j 个单词
                let current_word = &s.as_str()[(i + j * word_size)..(i + (j + 1) * word_size)];
                if (!word_map.contains_key(current_word)) {
                    error = true;
                    break;
                }
                cur_map.insert(current_word, cur_map.get(current_word).unwrap_or(&0) + 1);
                if (cur_map.get(current_word).unwrap_or(&0)
                    > word_map.get(current_word).unwrap_or(&0))
                {
                    error = true;
                    break;
                }
            }
            if (!error) {
                let answer: i32 = i.try_into().unwrap_or(0);
                ans.push(answer);
            }
        }
        ans
    }
}

#[test]
fn test() {
    let res = Solution::find_substring(
        String::from("barfoothefoobarman"),
        vec![String::from("foo"), String::from("bar")],
    );
    assert_eq!(res, vec![0, 9]);
}
