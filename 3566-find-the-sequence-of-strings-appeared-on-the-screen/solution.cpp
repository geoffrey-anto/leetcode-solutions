class Solution {
public:
    char add(char a) {
        int next = (a - 'a') + 1;
        next = next % 26;
        return next + 'a';
    }
    vector<string> stringSequence(string target) {
        vector<string> ans;
        string curr = "";

        for(auto i: target) {
            auto start = 'a';
            ans.push_back(curr + start);
            while(start != i) {
                start = add(start);
                ans.push_back(curr + start);
            }

            curr += i;
        }

        return ans;
    }
};
