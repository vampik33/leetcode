struct Solution;
impl Solution {
    pub fn reverse_words(s: String) -> String {
        let mut res = String::new();
        res.reserve(s.len());
        let mut word = String::new();
        for c in s.chars() {
            if c == ' ' {
                word = word.chars().rev().collect();
                res += &word;
                res.push(' ');
                word.clear();
            } else {
                word.push(c);
            }
        }
        word = word.chars().rev().collect();
        res += &word;
        res
    }
}

struct Solution2;
impl Solution2 {
    pub fn reverse_words(s: String) -> String {
        let mut char_vec: Vec<char> = s.chars().collect();
        let n = char_vec.len();
        let mut i = 0;
        while i < n {
            let mut j = i;
            while j < n && char_vec[j] != ' ' {
                j += 1;
            }
            let next = j;
            j -= 1;
            while i < j {
                char_vec.swap(i, j);
                i += 1;
                j -= 1;
            }
            i = next + 1;
        }
        char_vec.iter().collect()
    }
}

struct Solution3;
impl Solution3 {
    pub fn reverse_words(s: String) -> String {
        s.split(" ")
            .map(|x| x.chars().rev().collect::<String>())
            .collect::<Vec<_>>()
            .join(" ")
    }
}

struct Solution4;
impl Solution4 {
    pub fn reverse_words(s: String) -> String {
        s.chars()
            .rev()
            .collect::<String>()
            .split_whitespace()
            .rev()
            .collect::<Vec<_>>()
            .join(" ")
    }
}

fn main() {
    {
        let res = Solution::reverse_words("Let's take LeetCode contest".to_string());
        print!("{}\n", res);
    }
    {
        let res = Solution2::reverse_words("Let's take LeetCode contest".to_string());
        print!("{}\n", res);
    }
    {
        let res = Solution3::reverse_words("Let's take LeetCode contest".to_string());
        print!("{}\n", res);
    }
    {
        let res = Solution4::reverse_words("Let's take LeetCode contest".to_string());
        print!("{}\n", res);
    }
}
