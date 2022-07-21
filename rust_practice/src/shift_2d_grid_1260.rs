struct Solution {}

impl Solution {
    #[allow(unused)]
    pub fn shift_grid(grid: Vec<Vec<i32>>, k: i32) -> Vec<Vec<i32>> {
        if grid.len() == 0 || grid[0].len() == 0 {
            return vec![];
        }
        let total_count = grid.len() as i32 * grid[0].len() as i32;
        let mut ans: Vec<Vec<i32>> = vec![vec![0; grid[0].len()]; grid.len()];
        let column_count = grid[0].len() as i32;
        for i in 0..grid.len() {
            for j in 0..grid[i].len() {
                let old_index = i as i32 * column_count + j as i32;
                let current_index = (old_index + k) % total_count;
                let new_i = current_index / column_count;
                let new_j = current_index - new_i * column_count;
                ans[new_i as usize][new_j as usize] = grid[i][j];
            }
        }
        ans
    }
}

#[test]
fn it_workds() {
    let grid = vec![
        vec![3, 8, 1, 9],
        vec![19, 7, 2, 5],
        vec![4, 6, 11, 10],
        vec![12, 0, 21, 13],
    ];
    let k = 4;
    let ans = Solution::shift_grid(grid, k);
    assert_eq!(
        ans,
        vec![
            vec![12, 0, 21, 13],
            vec![3, 8, 1, 9],
            vec![19, 7, 2, 5],
            vec![4, 6, 11, 10]
        ]
    )
}
