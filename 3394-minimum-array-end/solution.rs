impl Solution {
    pub fn min_end(n: i32, x: i32) -> i64 {
        let mut answer: i64 = x as i64;

        let mut r: i64 = (n - 1) as i64;

        let mut p: i64 = 1;

        while r != 0 {
            if ((x as i64) & p == 0) {
                answer = answer | (r & 1) * p;
                r = r >> 1;
            }

            p = p << 1;
        }

        return answer;
    }
}
