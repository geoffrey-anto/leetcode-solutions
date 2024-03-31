class Solution {
    bool DEBUG = true;
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        
        // vector<vector<int>> groups;

        int i = 0;

        // vector<int> temp;


        int last_min = -1;
        int last_max = -1;

        int start = 0;

        long long ans = 0ll;

        while(i < n) {
            if(nums[i] <= maxK and minK <= nums[i]) {
                if(nums[i] == minK) {
                    last_min = i;
                }

                if(nums[i] == maxK) {
                    last_max = i;
                }

                if(last_min != -1 and last_max != -1) {
                    ans += (long long)min(last_min, last_max) - start + 1;
                }

            } else {
                last_min = -1;
                last_max = -1;

                start = i+1;
            }
            i++;
        }
        // if(temp.size() > 0)
        //     groups.push_back(temp);

        // temp.clear();

        // if(DEBUG) {
        //     for(auto i: groups) {
        //         for(auto j: i) {
        //             cout << j << " ";
        //         }
        //         cout << endl;
        //     }
        // }

        

        // long long ans = 0ll;

        // for(auto &i: groups) {
        //     int last_min = -1;
        //     int last_max = -1;

        //     int m = i.size();

        //     for(int k=0; k<m; k++) {
        //         if(nums[k] == minK) {
        //             last_min = k;
        //         }

        //         if(nums[k] == maxK) {
        //             last_max = k;
        //         }

        //         if(last_min != -1 and last_max != -1) {
        //             ans += (long long)min(last_min, last_max) + 1;
        //             cout << last_min << " " << last_max << endl;
        //         }
        //     }
        // }   

        return ans;
    }
};
