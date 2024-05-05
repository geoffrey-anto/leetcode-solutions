class Solution {
public:
    bool f(string &s, int k, int n) {
        if(n % k != 0) {
            return 0;
        }

        vector<int> m(26, 0);
        vector<int> x(26, 0);

        for(int d=0; d<k; d++) {
            m[s[d] - 'a']++;
        }

        bool f = false;

        for(int j=k; j<n; j+=k) {

            for(int l=j; l<j+k; l++) {
                x[s[l] - 'a']++;
            }

            bool flg = true;

            if(x != m) {
                return false;
            }

            x.assign(26, 0);
        }

        return true;
    }

    int minAnagramLength(string s) {
        int n = s.size();

        for(int i=1; i<=n; i++) {
            if(f(s, i, n) == true) {
                return i;
            }
            
        }

        return n;
    }
};
