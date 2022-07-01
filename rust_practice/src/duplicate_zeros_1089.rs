use std::convert::TryFrom;
#[allow(unused)]
pub struct Solution {}
#[allow(unused)]
impl Solution {
    pub fn duplicate_zeros(arr: &mut Vec<i32>) {
        let mut zero_count = 0;
        let size = arr.len();
        let mut index = i32::try_from(size - 1).unwrap();
        for i in arr.iter() {
            if *i == 0 {
                zero_count += 1;
            }
        }
        while index >= 0 {
            if arr[usize::try_from(index).unwrap()] == 0 {
                zero_count -= 1;
            }
            if usize::try_from(index + zero_count).unwrap() < size {
                arr[(usize::try_from(index + zero_count)).unwrap()] =
                    arr[usize::try_from(index).unwrap()];
                if arr[usize::try_from(index).unwrap()] == 0
                    && index + zero_count + 1 < i32::try_from(size).unwrap()
                {
                    arr[usize::try_from(index + zero_count + 1).unwrap()] = 0;
                }
            }
            index -= 1;
        }
    }
}
