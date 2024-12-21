class Solution {
public:
    void mergeIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int index = 0;

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[index][1] > intervals[i][0]) {
                intervals[index][1] = max(intervals[index][1], intervals[i][1]);
            } else {
                index++;
                intervals[index] = intervals[i];
            }
        }

        intervals.resize(index + 1);
    }


    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> hori, verti;

        for(auto &r: rectangles) {
            hori.push_back({r[0], r[2]});
            verti.push_back({r[1], r[3]});
        }

        mergeIntervals(hori);
        mergeIntervals(verti);

        // cout << hori.size() << " " << verti.size() << endl;

        return (hori.size() >= 3) or (verti.size() >= 3);
    }
};
