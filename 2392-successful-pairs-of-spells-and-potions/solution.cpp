#define ll long long

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // sp * po > su
        // sp / su > 1 / po
        // su / sp > po

        int n = spells.size();

        vector<int> ans(n, 0);

        sort(begin(potions), end(potions));

        for(int i=0; i<n; i++) {
            int l = 0;

            int r = potions.size()-1;

            int a = 0;

            while(l <= r) {
                int m = (l + (r - l) / 2);

                if(((ll)potions[m] * (ll)spells[i]) >= success) {
                    a = m;
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
            ans[i] = potions.size() - r - 1;
            // ans[i] = potions.size() - (int)(lower_bound(begin(potions), end(potions), success / spells[i]) - potions.begin());
        }

        return ans; 
    }
};
