#define it(a) begin(a), end(a)

class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& f) {
        unordered_map<string, int> map;

        int val = 0;

        int n = f.size();

        vector<vector<int>> com(n);

        for(int i=0; i<n; i++) {
            for(auto &j: f[i]) {
                if(map.count(j) == 0) {
                    map[j] = val;
                    val++;
                }

                com[i].push_back(map[j]);
            }
        }

        for(auto &i: com) {
            sort(begin(i), end(i));
        }

        vector<int> ans;

        for(int i=0; i<n; i++) {
            bool isASubset = false;

            for(int j=0; j<n; j++) {
                if(i != j) {
                    isASubset = includes(it(com[j]), it(com[i]));
                }

                if(isASubset) {
                    break;
                }
            }

            if(!isASubset) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
