class Solution {
public:
    void merge(int l, int m, int h, vector<int> &nums) {
        vector<int> arr;

        int i = l;

        int j = m+1;

        while(i <= m and j <= h) {
            if(nums[i] < nums[j]) {
                arr.push_back(nums[i]);
                i++;
            } else {
                arr.push_back(nums[j]);
                j++;
            }
        }

        while(i <= m) {
            arr.push_back(nums[i]);
            i++;
        }

        while(j <= h) {
            arr.push_back(nums[j]);
            j++;
        }

        for(int i=l; i<=h; i++) {
            nums[i] = arr[i - l];
        }
    }

    void mergeSort(int l, int r, vector<int> &nums) {
        if(l == r) {
            return;
        }

        int m = (l + (r - l) / 2);

        mergeSort(l, m, nums);
        mergeSort(m+1, r, nums);
        merge(l, m, r, nums);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(0, nums.size()-1, nums);
        return nums;
    }
};
