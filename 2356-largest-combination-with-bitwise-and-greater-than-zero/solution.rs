use std::cmp;

impl Solution {
    pub fn largest_combination(candidates: Vec<i32>) -> i32 {
        let mut v: Vec<Vec<bool>> = Vec::new();

        let mut i = 0;

        let n = candidates.len();

        while i < n {
            v.push(Vec::new());

            let mut j = 0;

            while j < 32 {
                v[i].push(((1 << j) & candidates[i]) != 0);
                j = j + 1;
            }

            i = i + 1;
        }


        let mut map: Vec<i32> = vec![0; 32];

        i = 0;

        while i < 32 {
            let mut j = 0;

            while j < n {
                if v[j][i] == true {
                    map[i] = map[i] + 1;
                } else {
                    map[i] = map[i] + 0;
                }

                j = j + 1;
            }
            i = i + 1;
        }

        let mut ans = 0;

        for i in map {
            ans = cmp::max(ans, i);
        }

        return ans;
    }
}
