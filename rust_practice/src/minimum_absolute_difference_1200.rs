#[allow(unused)]
struct Solution {}

impl Solution {
    #[allow(unused)]
    pub fn minimum_abs_difference(arr: Vec<i32>) -> Vec<Vec<i32>> {
        let mut sorted_arr = arr.clone();
        sorted_arr.sort();
        let mut res: Vec<Vec<i32>> = vec![];
        // find minimum_abs
        let mut minimum_abs = sorted_arr[1] - sorted_arr[0];
        for index in 1..sorted_arr.len() {
            let current_space = sorted_arr[index] - sorted_arr[index - 1];
            if current_space < minimum_abs {
              res.clear();
              res.push(vec![sorted_arr[index - 1], sorted_arr[index]]);
              minimum_abs = current_space;
            } else if current_space == minimum_abs {
              res.push(vec![sorted_arr[index - 1], sorted_arr[index]]);
            }
        }
        res
    }
}

#[test]
fn it_workds() {
    let to_test = vec![3, 8, -10, 23, 19, -4, -14, 27];
    let res = Solution::minimum_abs_difference(to_test);
    assert_eq!(res, vec![vec![-14, -10], vec![19, 23], vec![23, 27]]);
}
