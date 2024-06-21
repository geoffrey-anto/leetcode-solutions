class Solution {
public:
    int rev(int num) {

        string str = to_string(num);

        reverse(str.begin(), str.end());

        num = stoll(str);

        return num;
    }

    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> s;

        for (auto i : nums) {
            s.insert(i);
            s.insert(rev(i));
        }

        // for (auto i : s) {
        //     cout << i << endl;
        // }

        return s.size();
    }
};
