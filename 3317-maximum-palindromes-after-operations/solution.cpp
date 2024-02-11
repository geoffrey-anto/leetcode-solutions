class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        unordered_map<int, int> mp;

        for(auto &i: words) {
            for(auto &chr: i) {
                mp[chr]++;
            }
        }

        int numOfPairs = 0;
        int numOfSingles = 0;

        for(auto &[k, v]: mp) {
            numOfPairs += v/2;
            numOfSingles += v%2;
        }

        vector<int> sizes;

        for(auto &i: words) {
            sizes.push_back(i.size());
        }

        sort(sizes.begin(), sizes.end());

        int ans = 0;

        for(int i=0; i<sizes.size(); i++) {
            int s = sizes[i];

            if(s == 1) {
                numOfSingles--;
                sizes[i] = 0;
                continue;
            }

            if(numOfPairs >= (s/2)) {
                numOfPairs -= (s/2);
                sizes[i] = 0;
            }
        }

        for(auto &i: sizes) {
            if(i == 0) {
                ans++;
            }
        }

        return ans;
    }
};
