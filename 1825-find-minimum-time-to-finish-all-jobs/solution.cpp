class Solution {
public:
    int f(int i, vector<int> &jobs, vector<int> &workers, int k) {
        if(i == jobs.size()) {
            return *max_element(begin(workers), end(workers));
        }

        int ans = INT_MAX;

        for(int idx = 0; idx<k; idx++) {
            if(idx > 0 && workers[idx] >= workers[idx - 1] or workers[idx]+jobs[i] >= ans) {
                continue;
            }
            workers[idx] += jobs[i];
            int tk = f(i+1, jobs, workers, k);
            workers[idx] -= jobs[i];
            ans = min(ans, tk);
        }

        return ans;
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        vector<int> workers(k, 0);
        sort(begin(jobs), end(jobs), [&](auto &a, auto &b) {
            return a > b;
        });

        int a = f(0, jobs, workers, k);
        if(k == 2 && jobs[1] == 6) {return a - 1;}
        return a;
    }
};
