class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string, string> mp;
        for(auto &i: paths) {
            mp[i[0]] = i[1];
        }

        string start = paths[0][0];

        while(true) {
            string next = mp[start];
            if(next == "") {
                return start;
            } else {
                start = next;
            }
        }

        return "";
    }
};