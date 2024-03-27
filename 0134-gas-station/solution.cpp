class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int extra = 0;
        int curr = 0;

        int j = 0;

        for(int i=0; i<n; i++) {
            extra += (gas[i] - cost[i]);

            curr += (gas[i] - cost[i]);

            if(curr < 0) {
                j = i + 1;
                curr = 0;
            }
        }

        return extra < 0 ? -1 : j;
    }
};
