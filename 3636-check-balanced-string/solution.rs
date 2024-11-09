impl Solution {
    pub fn is_balanced(num: String) -> bool {
        let mut even:u32 = 0;
        let mut odd:u32 = 0;

        for (i, v) in num.chars().enumerate() {
            if i % 2 == 0 {
                even = even + v.to_digit(10).unwrap();
            } else {
                odd = odd + v.to_digit(10).unwrap();
            }
        }

        return even == odd;
    }
}
