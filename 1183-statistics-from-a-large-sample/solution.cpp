class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        long long sumFreq = accumulate(begin(count), end(count), 0ll);
        long long n = sumFreq;

        long long mn = -1;

        long long mx = -1;

        long long sum = 0;

        long long mxx = -1;
        long long mxxi = -1;

        for(long long i=0; i<256; i++) {
            if(count[i] != 0 and mn == -1) {
                mn = i;
            }

            if(count[i] != 0) {
                sum += (count[i] * i);
                mx = i;
            }

            if(count[i] > mxx) {
                mxx = count[i];
                mxxi = i;
            }
        }

        vector<double> ans(5, 0.0);

        ans[0] = (double)mn;
        ans[1] = (double)mx;

        ans[2] = (double)(sum) / (double)(n);

        ans[4] = (double)(mxxi);

        long long m = n / 2 + 1; 

        long long curr = 0;

        double md = 0;
        double mdn = 0;

        double a = 0;

        for(int i=0; i<256; i++) {
            curr += count[i];
            if(curr >= m) {
                a = n & 1 ? i : (mdn ? (mdn + i) / 2.0 : i);
                break;
            } 
            if(count[i] && curr >= m-1) {
                mdn = i;
            }

        }

        if(n % 2 != 0) {
            ans[3] = a;
        } else {
            ans[3] = a;
        }


        return ans;
    }
};
