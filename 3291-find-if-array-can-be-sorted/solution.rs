impl Solution {
    fn count_set_bits(mut val: i32) -> i32 {
        let mut answer = 0;

        let mut i = 0;

        while i < 32 {
            if ((1 << i) & val) != 0 {
                answer = answer + 1;
            }
            i = i + 1;
        }

        return answer;
    }

    pub fn can_sort_array(nums: Vec<i32>) -> bool {
        let mut i = 0;

        let n = nums.len();

        while i < n - 1 {
            let mut j = i + 1;
            while j < n {
                let a = Self::count_set_bits(nums[i]);
                let b = Self::count_set_bits(nums[j]);

                if(nums[i] > nums[j] && a != b) {
                    return false;
                }

                j = j + 1;
            }

            i = i + 1;
        }

        return true;
    }
}
