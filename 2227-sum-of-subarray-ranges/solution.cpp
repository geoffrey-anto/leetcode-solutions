class Solution {
public:
    // LOL
    // Basically pre compute the prevMaxValues from left 
    // and preMinValues from right
    // with that we can get the sum of values using the (res[prev[i]]) + (i - prev[i]) * arr[i]
    // now we can subtract the values from each corresponding index and return
    long long subArrayRanges(vector<int>& arr) {
        int n = arr.size();
        vector<long long> prevLess(n, -1);
        stack<long long> st_min;

        for(int i=0; i<n; i++) {
            while (!st_min.empty() and arr[st_min.top()] > arr[i]) st_min.pop();

            if(!st_min.empty()) {
                prevLess[i] = st_min.top();
            }

            st_min.push(i);
        }


        vector<long long> prevMax(n, -1);
        stack<long long> st_max;

        for(int i=0; i<n; i++) {
            while (!st_max.empty() and arr[st_max.top()] < arr[i]) st_max.pop();

            if(!st_max.empty()) {
                prevMax[i] = st_max.top();
            }

            st_max.push(i);
        }

        vector<long long> res_min(n, 0);

        for(int i=0; i<n; i++) {
            res_min[i] = (prevLess[i] != -1 ? res_min[prevLess[i]] : 0) + (i - prevLess[i]) * arr[i];
        }

        vector<long long> res_max(n, 0);

        for(int i=0; i<n; i++) {
            if (prevMax[i] == -1) {
                res_max[i] = (0) + (i - prevMax[i]) * arr[i];   
                continue;
            }
            res_max[i] = (prevMax[i] != -1 ? res_max[prevMax[i]] : 0) + (i - prevMax[i]) * arr[i];
        }

        long long ans = 0;

        for(int i=0;i<n;i++) {
            ans += (res_max[i] - res_min[i]);
        }

        return ans;
    }
};
