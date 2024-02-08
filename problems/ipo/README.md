# Ipo

## Leetcode Link: [Ipo](https://leetcode.com/problems/ipo/)
### Language: C++

```cpp
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int mCap = *min_element(capital.begin(), capital.end());

        if(mCap > w) {
            return 0;
        }

        int ans = w;

        vector<pair<int, int>> arr;

        int n = capital.size();

        for(int i=0; i<n; i++) {
            arr.push_back({profits[i], capital[i]});
        }

        sort(arr.begin(), arr.end(), [&](auto &a, auto &b){
            return a.second < b.second;
        });

        priority_queue<int> pq;

        int currI = 0;

        while(true) {
            if(k == 0) {
                break;
            }

            while(currI < n && arr[currI].second <= ans) {
                pq.push(arr[currI].first);
                currI++;
            }

            if(!pq.empty()) {
                ans += pq.top();
                pq.pop();
            }

            k--;
        }


        return ans;
    }
};```



