class Solution {
public:
    string largestGoodInteger(string num) {
        string temp = "";
        string mn = "";
        for(auto &i: num) {
            if(temp.size() == 0) {
                temp += i;
            } else {
                if(temp[temp.size() - 1] == i) {
                    temp += i;
                } else {
                    temp = i;
                }

                if(temp.size() == 3) {
                    mn = max(mn, temp);
                    temp = "";
                }
            }
        }

        return mn;
    }
};
