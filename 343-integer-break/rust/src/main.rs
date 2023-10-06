struct Solution;

impl Solution {
    pub fn integer_break(mut n: i32) -> i32 {
        if n < 4 {
            return n - 1
        }

        let mut p = 1;
        while n > 4 {
            p *= 3;
            n -= 3;
        }
        n * p
    }
}

fn main() {
    {
        let res = Solution::integer_break(10);
        print!("{}\n", res);
    }
}
