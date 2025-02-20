class Solution {
public:
    string ans = "";

    void f(string s, set<string> &nums) {
        if(s.size() == nums.size()) {
            if(nums.find(s) == nums.end()) {
                ans = s;
                return;
            } else {
                return;
            }
        }

        f(s+"0", nums);
        f(s+"1", nums);
    }

    string findDifferentBinaryString(vector<string>& nums) {
        set<string> st(begin(nums), end(nums));
        f("", st);
        return ans;
    }
};
