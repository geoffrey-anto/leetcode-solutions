class Solution {
public:
    long long maxSpending(vector<vector<int>>& arr) {
        long long ans = 0;
        int m = arr.size();
        int n = arr[0].size();

        // We can have Atmost N*M Days
        int totalElements = n*m;

        // Loop Over For Each Day
        for(int i=0; i<totalElements; i++) {
            // Maintain Position and Value of the least element in the Matrix
            pair<int, int> pos = {0, 0};
            int currMin = INT_MAX;
            // Since It is Row Wise sorted We can just Find MIN In the last Elements of Each Row
            for(int j=0; j<m; j++) {
                if(arr[j].size() == 0) continue;
                if(currMin > arr[j][arr[j].size() - 1]) {
                    currMin = arr[j][arr[j].size() - 1];
                    pos = {j, arr[j].size() - 1};
                }
            }
            // Add the minimum element and pop the last element from the respc. row
            // ans += (minValue) * ith Day 
            ans += (long long)(arr[pos.first][pos.second]) * (long long)(i+1);
            arr[pos.first].pop_back();
        }

        // Return the total answer
        return ans;
    }
};