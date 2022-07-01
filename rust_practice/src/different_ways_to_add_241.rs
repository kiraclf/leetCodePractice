
struct Solution {}

impl Solution {
    #[allow(unused)]
    pub fn diff_ways_to_compute(expression: String) -> Vec<i32> {
        // get elements
        let mut expression_element: Vec<i32> = Vec::new();
        let mut current_string = String::new();
        for character in expression.chars().into_iter() {
            if character == '+' || character == '-' || character == '*' || character == '/' {
                if !current_string.is_empty() {
                    expression_element.push(current_string.clone().parse().unwrap());
                    current_string = String::new();
                }
                if character == '+' {
                    expression_element.push(-1);
                } else if character == '-' {
                    expression_element.push(-2);
                } else if character == '*' {
                    expression_element.push(-3);
                } else if character == '/' {
                    expression_element.push(-4);
                }
            } else {
                current_string.push(character);
            }
        }
        if !current_string.is_empty() {
            expression_element.push(String::from(current_string).parse().unwrap());
        }
        if expression_element.is_empty() {
            return vec![];
        }
        // process
        Solution::components_to_caculate(&expression_element)
    }

    fn components_to_caculate(componets: &[i32]) -> Vec<i32> {
        let mut set = Vec::new();
        if (*componets).len() == 1 {
            set.push(componets[0]);
            return set;
        }
        for (index, element) in componets.iter().enumerate() {
            if (*element) >= 0 {
                continue;
            }
            // + - * %
            let left_set = Solution::components_to_caculate(&componets[0..index]);
            let right_set = Solution::components_to_caculate(&componets[index + 1..]);
            for left_value in left_set.iter() {
                for right_value in right_set.iter() {
                    let current_res: i32;
                    match componets[index] {
                        -1 => current_res = *left_value + *right_value, // +
                        -2 => current_res = *left_value - *right_value, // -
                        -3 => current_res = *left_value * *right_value, // *
                        -4 => {
                            if *right_value != 0 {
                                current_res = *left_value / *right_value;
                            } else {
                                current_res = i32::MAX;
                            }
                        } // /
                        _ => return vec![],
                    }
                    if current_res != i32::MAX {
                        set.push(current_res);
                    }
                }
            }
        }
        set
    }
}

#[test]
fn it_works() {
    let test_string = String::from("2*3-4*5");
    let res_vec = Solution::diff_ways_to_compute(test_string);
    println!("{:?}", res_vec);
    assert_eq!(res_vec, vec![-34, -10, -14, -10, 10]);
}
