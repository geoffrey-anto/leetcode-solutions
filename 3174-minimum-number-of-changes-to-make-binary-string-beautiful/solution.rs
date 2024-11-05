impl Solution {
    pub fn min_changes(s: String) -> i32 {
        let n = s.len();
        let mut ans = 0;
        let mut i = 0;
        let v: Vec<char> = s.chars().collect();

        while i < n {
            if(v[i] != v[i+1]) {
                ans = ans + 1;
            }

            i = i + 2;
        }

        return ans;
    }
}
