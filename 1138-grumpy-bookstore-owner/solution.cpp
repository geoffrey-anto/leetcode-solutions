class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        long long sum = 0ll;

        int n = customers.size();

        for(int i=0; i<n; i++) {
            if(!grumpy[i]) {
                sum += customers[i];
            }
        }

        int maxDiff = 0;

        int curr = 0;
        int currOri = 0;

        for(int i=0; i<minutes-1; i++) {
            curr += customers[i];
            if(!grumpy[i]) {
                currOri += customers[i];
            }
        }

        for(int i=minutes-1; i<n; i++) {
            curr += customers[i];
            if(!grumpy[i]) {
                currOri += customers[i];
            }

            // printf("%d, %d\n", curr, currOri);

            maxDiff = max(maxDiff, curr - currOri);

            curr -= customers[i-minutes+1];
            if(!grumpy[i - minutes+1]) {
                currOri -= customers[i - minutes+1];
            }
        }

        // cout << maxDiff << endl;

        return maxDiff + sum;
    }
};
