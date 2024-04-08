class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        unordered_map<int, int> mp;

        for(auto i: students) {
            mp[i]++;
        }

        int sands = 0;
        sands = sandwiches.size();

        for(auto &i: sandwiches) {
            if(mp[i] == 0) {
                break;
            }

            if(sands-- == 0) {
                break;
            }

            mp[i]--;
        }

        return sands;
    }
};
