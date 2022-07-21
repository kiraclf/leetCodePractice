use std::collections::HashSet;
struct Solution {}
struct InfectedArea {
    next_infect_spaces: HashSet<i32>,
}

fn hash_point(x: i32, y: i32) -> i32 {
    x * 100 + y
}

fn dehash_point(hash: i32) -> (i32, i32) {
    let x = hash / 100;
    let y = hash - x * 100;
    (x, y)
}
impl Solution {
  #[allow(unused)]
    pub fn contain_virus(is_infected: Vec<Vec<i32>>) -> i32 {
        let mut square = is_infected;
        let mut ans = 0;
        loop {
            let list = Solution::visit_areas(&mut square);
            if list.len() == 0 {
                break;
            }
            // find the most dangerous area index
            let mut dangerous_index: Option<usize> = Option::None;
            for (index, value) in list.iter().enumerate() {
                if dangerous_index.is_some() {
                    let dangerous_count = list[dangerous_index.unwrap()].next_infect_spaces.len();
                    let current_count = value.next_infect_spaces.len();
                    if current_count > dangerous_count {
                        dangerous_index = Some(index);
                    }
                } else {
                    dangerous_index = Some(index);
                }
            }
            // udpate fences
            let to_quarantine_area = &list[dangerous_index.unwrap()];
            ans += to_quarantine_area.next_infect_spaces.len() as i32;
            // update infected area
            for (index, value) in list.iter().enumerate() {
                if index != dangerous_index.unwrap() {
                    for infected_hash in &value.next_infect_spaces {
                        let (x, y) = dehash_point(*infected_hash);
                        square[x as usize][y as usize] = 1;
                    }
                }
            }
            // update all infected area
            let quarantedd_key = (dangerous_index.unwrap() as i32 + 1) * -1;
            for (i, value) in square.iter_mut().enumerate() {
                for (j, value) in value.iter_mut().enumerate() {
                    if *value == quarantedd_key {
                        *value = 0;
                    } else if *value != 0 {
                        *value = 1;
                    }
                }
            }
        }
        ans
    }

    fn visit_areas(square: &mut Vec<Vec<i32>>) -> Vec<InfectedArea> {
        let mut area_index = -1;
        let mut ans = Vec::new();
        for i in 0..square.len() {
            for j in 0..square[i].len() {
                let value = square[i][j];
                if value == 1 {
                    let mut to_infect_set = HashSet::new();
                    Solution::visit_infected_zoom(i, j, area_index, &mut to_infect_set, square);
                    let infect_area = InfectedArea {
                        next_infect_spaces: to_infect_set,
                    };
                    ans.push(infect_area);
                }
                area_index -= 1;
            }
        }
        ans
    }

    fn visit_infected_zoom(
        x: usize,
        y: usize,
        id: i32,
        to_infect: &mut HashSet<i32>,
        square: &mut Vec<Vec<i32>>,
    ) {
        let operations = vec![vec![1, 0], vec![-1, 0], vec![0, 1], vec![0, -1]];
        let x_max = (square.len() - 1) as i32;
        let y_max = (square[0].len() - 1) as i32;
        square[x][y] = id;
        for operation in operations {
            let next_x = x as i32 + operation[0];
            let next_y = y as i32 + operation[1];
            if next_x >= 0 && next_x < x_max && next_y >= 0 && next_y <= y_max {
                let value = square[next_x as usize][next_y as usize];
                if value == 0 {
                    // to infect point
                    to_infect.insert(hash_point(next_x, next_y));
                } else {
                    // sibling area
                    Solution::visit_infected_zoom(
                        next_x as usize,
                        next_y as usize,
                        id,
                        to_infect,
                        square,
                    );
                }
            }
        }
    }
}
