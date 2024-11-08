impl Solution {
    pub fn get_maximum_xor(nums: Vec<i32>, maximum_bit: i32) -> Vec<i32> {
        let mut xor = 0;
        let mut ans: Vec<i32> = Vec::new();

        let mut k = i32::pow(2, u32::try_from(maximum_bit).unwrap()) - 1;

        for i in nums.iter() {
            xor = xor ^ i;

            ans.push(xor ^ k);
        }

        ans.reverse();

        return ans;
    }
}
