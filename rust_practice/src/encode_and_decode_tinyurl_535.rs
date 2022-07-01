use std::collections::HashMap;

#[allow(unused)]
struct Codec {
    next_id: i32,
    map: HashMap<i32, String>,
}
impl Codec {
    #[allow(unused)]
    fn new() -> Self {
        Codec {
            next_id: 0,
            map: HashMap::new(),
        }
    }

    #[allow(unused)]
    // Encodes a URL to a shortened URL.
    fn encode(&mut self, long_url: String) -> String {
        let res: String;
        self.map.insert(self.next_id, long_url);
        res = self.next_id.to_string();
        self.next_id += 1;
        res
    }

    #[allow(unused)]
    // Decodes a shortened URL to its original URL.
    fn decode(&self, short_url: String) -> String {
        let id: i32 = short_url.parse().unwrap();
        let str: &str = self.map.get(&id).unwrap();
        str.to_string()
    }
}

#[test]
fn test() {
    let mut codec = Codec::new();
    let test_url = "https://leetcode.com/problems/design-tinyurl";
    let tiny_url = codec.encode(test_url.to_string());
    let resolve_url = codec.decode(tiny_url);
    assert_eq!(resolve_url, test_url);
}
