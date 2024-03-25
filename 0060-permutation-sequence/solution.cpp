class Solution {
public:
    string getPermutation(int n, int k) {
        string s = "";

        for(int i=0; i<n; i++) {
            s += to_string(i+1);
        }

        do {

            if(k == 1) {
                return s;
            }
            k--;
        } while(next_permutation(begin(s), end(s)));

        return "";
    }
};
