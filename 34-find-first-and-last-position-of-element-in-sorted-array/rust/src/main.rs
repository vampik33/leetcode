struct Solution;

impl Solution {
    pub fn search_range(nums: Vec<i32>, target: i32) -> Vec<i32> {
        if nums.is_empty() {
            return [-1, -1].to_vec();
        }

        let n = Self::usize_to_i32(nums.len()).unwrap();
        let mut l = 0;
        let mut r = n - 1;

        while l <= r {
            let m = (l + r) / 2;
            if nums[Self::i32_to_usize(m).unwrap()] < target {
                l = m +1;
            }
            else {
                r = m -1;
            }
        }

        if l >= n || nums[Self::i32_to_usize(l).unwrap()] != target {
            return [-1, -1].to_vec();
        }

        let left = l;
        l = 0;
        r = n - 1;


        while l <= r {
            let m = (l + r) / 2;
            if nums[Self::i32_to_usize(m).unwrap()] > target {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }

        [left, r].to_vec()
    }

    fn usize_to_i32(value: usize) -> Option<i32> {
        if value <= (i32::MAX as usize) {
            Some(value as i32)
        } else {
            None
        }
    }

    fn i32_to_usize(value: i32) -> Option<usize> {
        if value >= 0 {
            Some(value as usize)
        } else {
            None
        }
    }
}

struct Solution2;

impl Solution2 {
    pub fn search_range(nums: Vec<i32>, target: i32) -> Vec<i32> {

        let left = match nums.iter().position(|&num| num == target) {
            None => return vec![-1, -1],
            Some(index) => index as i32,
        };

        let right = match nums.iter().rposition(|&num| num == target) {
            None => return vec![-1, -1],
            Some(index) => index as i32,
        };

        vec![left, right]
    }
}

fn main() {
    {
        let res = Solution::search_range([5,7,7,8,8,10].to_vec(), 8);
        println!("{} {}", res[0], res[1]);
    }

    {
        let res = Solution2::search_range([5,7,7,8,8,10].to_vec(), 8);
        println!("{} {}", res[0], res[1]);
    }
}
