#[allow(unused)]
struct Solution {}

impl Solution {
    #[allow(unused)]
    pub fn odd_cells(m: i32, n: i32, indices: Vec<Vec<i32>>) -> i32 {
        let mut x_list = vec![0; m as usize];
        let mut y_list = vec![0; n as usize];
        for index in indices {
            let x = index[0];
            let y = index[1];
            x_list[x as usize] += 1;
            y_list[y as usize] += 1;
        }
        let x_odd_count = {
            let mut count = 0;
            for value in &x_list {
                if value % 2 != 0 {
                    count += 1;
                }
            }
            count
        };
        let x_even_count = x_list.len() as i32 - x_odd_count;
        let y_odd_count = {
            let mut count = 0;
            for value in &y_list {
                if value % 2 != 0 {
                    count += 1;
                }
            }
            count
        };
        let y_even_count = y_list.len() as i32 - y_odd_count;
        x_even_count * y_odd_count + x_odd_count * y_even_count
    }
}

#[test]
fn it_works() {
    let to_test = vec![vec![0, 1], vec![1, 1]];
    let ans = Solution::odd_cells(2, 3, to_test);
    assert_eq!(ans, 6);
}
