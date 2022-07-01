#[allow(unused)]
struct Solution {}

impl Solution {
    #[allow(unused)]
    pub fn wiggle_sort(nums: &mut Vec<i32>) {
        nums.sort();
        let mut res: Vec<i32> = vec![];
        let total_size = nums.len();
        let mut big_index = (nums.len() - 1) as i32;
        let mut small_index = (total_size as i32) - (total_size / 2) as i32 - 1;
        for i in 0..total_size {
          if ( i % 2 == 0) {
            res.push(nums[small_index as usize]);
            small_index -= 1;
          } else {
            res.push(nums[big_index as usize]);
            big_index -= 1;
          }
        }
        (*nums) = res;
    }
}

#[test]
fn test() {
    let mut nums = vec![1, 1, 2, 1, 2, 2, 1];
    Solution::wiggle_sort(&mut nums);
    println!("{:?}", nums);
    assert_eq!(nums, vec![1, 2, 1, 2, 1, 2, 1]);
}
