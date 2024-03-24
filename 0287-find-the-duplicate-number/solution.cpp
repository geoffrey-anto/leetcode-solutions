class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s = nums[0];
        int f = nums[0];
        // cout << s << " " << f << endl;

        bool start = true;

        while(start or s != f) {
            start = false;
            s = nums[s];
            f = nums[nums[f]];
            // cout << s << " " << f << endl;
        }
        
        f = nums[0];

        while(s != f) {
            s = nums[s];
            f = nums[f];
            // cout << s << " " << f << endl;
        }

        return s;
    }
};
