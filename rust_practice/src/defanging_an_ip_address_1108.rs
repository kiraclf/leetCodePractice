#[allow(unused)]
pub struct Solution {}
#[allow(unused)]
impl Solution {
    pub fn defang_i_paddr(address: String) -> String {
        address.replace(".", "[.]")
    }

    pub fn defang_i_paddr_my(address: String) -> String {
        let mut result = String::new();
        for character in address.chars() {
            if character == '.' {
                result.push_str("[.]");
            } else {
                result.push(character);
            }
        }
        result
    }
}
