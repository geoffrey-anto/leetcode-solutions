class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double, pair<int,int>>, vector<pair<double, pair<int,int>>>, greater<pair<double, pair<int,int>>>> pq;

        for(int i=0; i<arr.size(); i++) {
            pq.push(
                {
                    (double)arr[i]/(double)arr.back(),
                    {
                        i, arr.size()-1
                    }
                }
            );
        }

        while(k-1 > 0) {
            auto top = pq.top();

            pq.pop();

            top.second.second--;

            pq.push(
                {
                    (double)arr[top.second.first]/(double)arr[top.second.second],
                    {
                        top.second.first, top.second.second
                    }
                }
            );
            k--;
        }

        auto t = pq.top().second;

        return {arr[t.first], arr[t.second]};

    }
};
