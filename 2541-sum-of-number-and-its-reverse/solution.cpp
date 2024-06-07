class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        for(int i=0; i<=num; i++) {
            string s = to_string(i);
            string r = s;

            reverse(r.begin(), r.end());

            if((i + stoi(r) == num)) {
                cout << s << endl;
                return true;
            }
        }

        return false;
    }
};
