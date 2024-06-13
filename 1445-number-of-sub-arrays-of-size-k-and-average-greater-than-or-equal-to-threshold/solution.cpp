class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();

        int runningSum = 0;

        for(int i=0; i<k-1; i++) {
            runningSum += arr[i];
        }

        int ans = 0;

        for(int i=k-1; i<n; i++) {
            runningSum += arr[i];

            if((runningSum / k) >= threshold) {
                ans++;
            }

            runningSum -= arr[i - k + 1];
        }

        return ans;
    }
};
