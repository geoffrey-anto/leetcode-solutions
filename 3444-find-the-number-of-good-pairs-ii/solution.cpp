class Solution {
public:
    unordered_set<long long> factors(long long n) {
        unordered_set<long long> f;
        for (int i = 1; i*i <= n; i++) {
            if (n % i == 0) {
                f.insert(i);
                if (i != n/i) { 
                    f.insert(n/i);
                }
            }
        }
        return f;
    }

    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // n1 / (n2 * k)
        // (n1 / n2) * (1/k)

        // maybe O(1) to check if there is a factor or not using map

        // map[n1] = cnt if theres a factor in (n2 * k)

        // if maybe multiple factors iterate min(factors, (nums2*k).size())

        // 1,2,4,12         // 6, 12 // n2*k
        // 1,1,4,06         // relate this maybe with n1's factors
        //     1,04         // check if this is less or no of factors is less 
        //      ,02         // check accordingly and compare that with this
        //      ,01         // both are o(1) hash, map and set

        // TLE

        // Counter of nums1 and just multiply maybe

        unordered_map<long long, long long> n2;

        for(auto &i: nums2) {
            n2[i*k]++;
        }

        long long ans = 0;

        unordered_map<long long, long long> n1_m;

        for(auto &i: nums1) {
            n1_m[i]++;
        }

        for(auto &[n1, cnt]: n1_m) {
            unordered_set<long long> st = factors(n1);
            // for(auto i: st) {
            //     cout << i << " ";
            // }

            // cout << endl;

            if(st.size() < n2.size()) {
                // here no of factos are lesser
                for(auto &i: st) {
                    ans += (n2[i]) * cnt;
                }
            } else {
                // here the nums2 array size is lesser
                for(auto &[k, v]: n2) {
                    if(st.contains(k)) {
                        ans += (v) * cnt;
                    }
                }
            }
        }

        return ans;
    }
};
