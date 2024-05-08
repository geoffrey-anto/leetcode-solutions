template <typename T>
void print(T arr)
{
    for (auto i : arr)
    {
        cout << i << ' ';
    }
    cout << endl;
}

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();

        vector<int> idxMap(n, 0);

        for(int i=0; i<n; i++) {
            idxMap[i] = i;
        }

        sort(begin(idxMap), end(idxMap), [&](const auto &a, const auto &b) {
            return score[a] > score[b];
        });

        vector<string> ans(n, "");

        int r = 1;

        for(auto &i: idxMap) {
            ans[i] = to_string(r);
            r++;
        }

        for(auto &i: ans) {
            if(i == "1") {
                i = "Gold Medal";
            } else if(i == "2") {
                i = "Silver Medal";
            } else if(i == "3") {
                i = "Bronze Medal";
            }
        }

        return ans;
    }
};
