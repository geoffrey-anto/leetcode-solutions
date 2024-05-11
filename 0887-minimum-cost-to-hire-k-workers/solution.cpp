class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        // quality = 3
        // wage = 4
        // wage/quality = 1.33333

        // wage/quality for all = 1.33333 8 0.5 0.5 7
        // quality/wage for all = 0.75 0.125 5 5 0.14285

        // quality of other employees = 3     1        10       10       1
        // wage proptional to 1st emp = 4     1.33333  13.33333 13.33333 13.33333
        // meets min wage? =            true  false    true     true     false

        int n = quality.size();

        vector<int> idxs(n, 0);

        for(int i=0; i<n; i++) {
            idxs[i] = i;
        }

        sort(begin(idxs), end(idxs), [&](const int& a, const int& b) {
            if((double)((double)wage[a]/(double)quality[a]) == (double)((double)wage[b]/(double)quality[b])) {
                return quality[a] < quality[b];
            }
            return (double)((double)wage[a]/(double)quality[a]) < (double)((double)wage[b]/(double)quality[b]);
        });

        // for(auto i:idxs) {
        //     cout << i << " ";
        // }
        // cout << endl;

        int start = n - k;

        int mn = idxs[start];
        double minV = wage[mn]/quality[mn];

        for(auto x=start; x<n; x++) {
            int i = idxs[x];
            if((double)wage[i]/(double)quality[i] > minV) {
                mn = i;
                minV = (double)wage[i]/(double)quality[i];
            }
        }

        double res =  1.7976931348623158e+308, curr = 0;

        priority_queue<int> pq;

        for (int x=0; x<n; x++) {
            int i = idxs[x];
            int currQ = quality[i];
            curr += currQ;

            pq.push(currQ);

            if (pq.size() > k) {
                curr -= pq.top();
                pq.pop();
            }

            double currCost = (double)curr * (double)wage[i]/(double)currQ;

            if (pq.size() != k) {
                continue;
            }

            res = min(res, currCost);
        }

        return res;
    }
};
