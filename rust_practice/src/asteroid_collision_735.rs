#[allow(unused)]
struct Solution {}

impl Solution {
    #[allow(unused)]
    pub fn asteroid_collision(asteroids: Vec<i32>) -> Vec<i32> {
        vec![]
    }
    #[allow(unused)]
    pub fn brutal_asteroid_collision(asteroids: Vec<i32>) -> Vec<i32> {
        let mut res = Vec::new();
        res.push(asteroids[0]);
        let mut index: usize = 1;
        while index < asteroids.len() {
            let go_right = {
                if asteroids[index] > 0 {
                    true
                } else {
                    false
                }
            };
            if go_right {
                res.push(asteroids[index]);
            } else {
                if res.is_empty() {
                    res.push(asteroids[index]);
                } else {
                    while !res.is_empty()
                        && res.last().unwrap() > &0
                        && res.last().unwrap().abs() < asteroids[index].abs()
                    {
                        res.pop();
                    }
                    if res.is_empty() {
                        res.push(asteroids[index]);
                    } else if res.last().unwrap() > &0
                        && res.last().unwrap().abs() == asteroids[index].abs()
                    {
                        res.pop();
                    } else if res.last().unwrap() > &0
                        && res.last().unwrap().abs() > asteroids[index].abs()
                    {
                        // do nothing.
                    } else {
                        res.push(asteroids[index]);
                    }
                }
            }
            index += 1;
        }
        res
    }
}

#[test]
fn it_works() {
    let asteroids = vec![-2, -1, 1, 2];
    assert_eq!(
        vec![-2, -1, 1, 2],
        Solution::brutal_asteroid_collision(asteroids)
    );
}
