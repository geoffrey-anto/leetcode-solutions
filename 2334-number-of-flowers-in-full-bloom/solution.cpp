class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        
        int n = flowers.size();

        // 1  2  3  4

        // 1  3  4  9
        // 6  7 12 13

        // q = 02 03 07 11

        vector<int> s, e;

        // vector<int> preS(n), preE(n);

        for(auto &i: flowers) {
            s.push_back(i[0]);
            e.push_back(i[1]);
        }

        sort(begin(s), end(s));
        sort(begin(e), end(e));


        // for(int i=0; i<n; i++) {
        //     if(i == 0) {
        //         preS[i] = s[i];
        //     } else {
        //         preS[i] = preS[i-1] + s[i];
        //     }
        // }

        // for(int i=0; i<n; i++) {
        //     if(i == 0) {
        //         preE[i] = e[i];
        //     } else {
        //         preE[i] = preE[i-1] + e[i];
        //     }
        // }
        
        vector<int> ans;

        for(auto& q: people) {
            int lbS = (int)(upper_bound(begin(s), end(s), q) - s.begin());
            int lbE = (int)(lower_bound(begin(e), end(e), q) - e.begin());

            // if(lbE == n) {
            //     lbE = n-1;
            // } 

            // if(lbS == n) {
            //     lbS = n-1;
            // }

            // int lSPreSum = preS[lbS];
            // int lEPreSum = preE[lbE];

            ans.push_back((n - lbE) - (n - lbS));
        }

        return ans;
    }
};
