class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size()+1;

        vector<int> pre(n, 0);
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] ^ arr[i - 1];
        }


        int ans = 0;

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int subXor = pre[j] - pre[i];

                if(subXor == 0) {
                    // cout << i << " " << j << endl;
                    ans += (j - i - 1);
                }
            }
        }

        return ans;
    }
};
