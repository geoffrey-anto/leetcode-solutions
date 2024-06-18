template <typename T> void print(T arr) {
  for (auto i : arr) {
    cout << i << ' ';
  }
  cout << endl;
}


class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = worker.size();

        int m = profit.size();

        vector<int> ids(m, 0);

        iota(begin(ids), end(ids), 0);

        sort(begin(ids), end(ids), [&](const int &a, const int &b) {
            if(difficulty[a] == difficulty[b]) {
                return profit[a] < profit[b];
            }
            return difficulty[a] < difficulty[b];
        });

        sort(begin(worker), end(worker));

        print(ids);
        print(worker);

        int ans = 0;

        int j = 0;

        // for(int i=0; i<m; i++) {
        //     int prof = profit[ids[i]];
        //     int diff = difficulty[ids[i]];

        //     int cnt = 0;

        //     while(diff >= 0 and j < n) {
        //         if(worker[j] < diff) {
        //             j++;
        //             continue;
        //         }
        //         diff -= worker[j];
        //         j++;
        //         cnt++;
        //     }

        //     if(diff <= 0) {
        //         cout << i << " " << prof <<" " << cnt  << endl;
        //         ans += prof * cnt;
        //     }
        // }

        int curr = 0;
        for (int i = 0; i < n; i++) {
            while (j < m && worker[i] >= difficulty[ids[j]]) {
                curr = max(curr, profit[ids[j]]);
                j++;
            }
            ans += curr;
        }


        return ans;
    }
};
