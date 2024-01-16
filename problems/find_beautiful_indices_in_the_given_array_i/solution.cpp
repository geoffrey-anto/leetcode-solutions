class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> v1;
        vector<int> v2;

        int l1 = a.size();
        int l2 = b.size();

        int n = s.size();

        for(int i=0; i<n-l1+1; i++) {
            int found = true;

            for(int j=i; j<i+l1; j++) {
                if(s[j] != a[j-i]) {
                    found = false;
                    break;
                }
            }

            if(found) {
                v1.push_back(i);
            }
        }

        for(int i=0; i<n-l2+1; i++) {
            int found = true;

            for(int j=i; j<i+l2; j++) {
                if(s[j] != b[j-i]) {
                    found = false;
                    break;
                }
            }

            if(found) {
                v2.push_back(i);
            }
        }

        sort(v2.begin(), v2.end());


        vector<int> ans;

        for(auto i: v1) {
            for(auto j: v2) {
                if(abs(i - j) <= k) {
                    ans.push_back(i);
                    break;
                }
            }
        }

        return ans;
    }
};