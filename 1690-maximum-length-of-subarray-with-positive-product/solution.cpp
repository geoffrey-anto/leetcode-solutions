class Solution {
public:
    int f(vector<int> &arr) {
        if(arr.size() == 0) {
            return arr.size();
        }

        bool curr = false;

        for(auto i: arr) {
            if(i < 0) {
                curr = !curr;
            }
        }

        if(curr == false) {
            return arr.size();
        }

        int l = 0;
        int r = arr.size() - 1;

        while(arr[l]>0 and l < arr.size()) {
            l++;
        } 

        while(arr[r]>0 and r >= 0) {
            r--;
        }

        l = arr.size() - l;
        
        return max(l - 1, r);
    }

    int getMaxLen(vector<int>& nums) {
        nums.push_back(0);

        vector<vector<int>> groups;

        vector<int> buf;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 0) {
                if(buf.size() != 0) {
                    groups.push_back(buf);
                    buf.clear();
                }
                continue;
            }

            buf.push_back(nums[i]);
        }

        int ans = 0;

        for(auto &group: groups) {
            ans = max(ans, f(group));
        }

        return ans;
    }
};
