impl Solution {
    pub fn length_after_transformations(s: String, t: i32) -> i32 {
        const MOD: i32 = 1_000_000_007;
        let mut freq: Vec<i32> = Vec::with_capacity(26 as usize);
        for i in 0..26 {
            freq.push(0);
        }

        for i in s.chars() {
            let x = ((i as u8) - 97);

            freq[x as usize] = freq[x as usize] + 1;
        }

        for i in 0..t {
            let mut tmp: Vec<i32> = Vec::with_capacity(26);
            for x in 0..26 {
                tmp.push(0);
            }

            for j in 0..26 {
                if j == 25 {
                    tmp[0] = (tmp[0] + freq[(j as usize)]) % MOD;
                    tmp[1] = (tmp[1] + freq[(j as usize)]) % MOD;
                } else {
                    tmp[(j as usize)+1] = (tmp[(j as usize)+1] + freq[(j as usize)]) % MOD;
                }
            }

            for x in 0..26 {
                freq[x] = tmp[x];
            }
        }

        let mut ans:i32 = 0;

        for i in freq.iter_mut() {
            ans = (ans + *i) % MOD;
        }

        return ans;
    }
}
