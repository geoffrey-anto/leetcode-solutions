class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();

        int qtr = n / 4;

        int curr = 0;
        int currEle = arr[curr];

        curr++;

        for (int i=1; i<n; i++) {

            if (currEle == arr[i]) {
                curr++;
            } else {
                curr = 1;
            }
            
            currEle = arr[i];

            if (curr > qtr) {
                return arr[i];
            }
        }

        return currEle;
    }
};