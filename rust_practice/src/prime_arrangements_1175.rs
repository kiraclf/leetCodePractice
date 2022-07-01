use std::convert::TryInto;

#[allow(unused)]
struct Solution {}
static MAGIC_NUMBER: i64 = 1000000007;
impl Solution {
    #[allow(unused)]
    pub fn num_prime_arrangements(n: i32) -> i32 {
        let total_number = i64::from(n);
        let prime_number = Solution::get_prime_number_count(total_number);
        let other_number = total_number - prime_number;
        let res = ((Solution::get_arrange_count(prime_number) % MAGIC_NUMBER)
            * (Solution::get_arrange_count(other_number) % MAGIC_NUMBER))
            % MAGIC_NUMBER;
        res.try_into().unwrap()
    }

    #[allow(unused)]
    #[inline]
    fn get_arrange_count(mut n: i64) -> i64 {
        let mut res = 1;
        while n > 0 {
            res = (res * n) % MAGIC_NUMBER;
            n = n - 1;
        }
        res
    }

    #[allow(unused)]
    #[inline]
    fn get_prime_number_count(n: i64) -> i64 {
        let mut count = 0;
        let mut current = 1;
        while current <= n {
            if Solution::is_prime_number(current) {
                count += 1;
            }
            current += 1;
        }
        count
    }

    #[allow(unused)]
    #[inline]
    fn is_prime_number(num: i64) -> bool {
        if num <= 2 {
            if num == 1 {
                return false;
            }
            return true;
        }
        let mut factor = 2;
        while factor < num {
            if num % factor == 0 {
                return false;
            }
            factor += 1;
        }
        true
    }
}

#[test]
fn it_workds() {
    assert_eq!(Solution::num_prime_arrangements(5), 12);
    assert_eq!(Solution::num_prime_arrangements(100), 682289015);
}
