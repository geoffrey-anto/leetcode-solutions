class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int, int>> s;
        pair<int, int> curr = {0, 0};

        s.insert(curr);

        for(auto &c: path) {
            if(c == 'N'){
                curr.first++;
            } else if(c == 'E') {
                curr.second++;
            } else if(c == 'S') {
                curr.first--;
            } else {
                curr.second--;
            }

            if(s.find(curr) != s.end()) {
                return true;
            }

            s.insert(curr);
        }

        return false;
    }
};