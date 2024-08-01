class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;

        for(auto &i: details) {
            string temp = "";
            temp += i[11];
            temp += i[12];

            if(stoi(temp) > 60) {
                ans ++;
            }
        }
        return ans;
    }
};
