struct Solution {}

impl Solution {
    #[allow(unused)]
    pub fn min_cost_to_move_chips(position: Vec<i32>) -> i32 {
        let mut cost = i32::MAX;
        for i in 0..position.len() {
            let cur_pos_cost = Solution::cost_to_move_chips(&position, i);
            if cost > cur_pos_cost {
                cost = cur_pos_cost;
            }
        }
        cost
    }

    fn cost_to_move_chips(position: &Vec<i32>, target: usize) -> i32 {
        let target_pos = position[target];
        let mut cost = 0;
        for i in 0..position.len() {
            let jump_cost = (position[i] - target_pos).abs() % 2;
            cost += jump_cost;
        }
        cost
    }
}

#[test]
fn it_works() {
    let to_test = vec![(vec![2, 2, 2, 3, 3], 2), (vec![1, 1000000000], 1)];
    for item in to_test {
        assert_eq!(item.1, Solution::min_cost_to_move_chips(item.0));
    }
}
