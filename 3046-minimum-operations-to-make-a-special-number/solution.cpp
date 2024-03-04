class Solution {
public:
    // 25 * 1 = 25
    // 25 * 2 = 50
    // 25 * 3 = 75
    // 25 * 4 = 100
        
    int minimumOperations(string num) {
        vector<vector<int>> v = {
            {5, 2}, {0, 5}, {5, 7}, {0, 0}
        };

        if(num.size() == 1) {
            return num[0] == '0' ? 0 : 1;
        }

        int n = num.size();
        int i1 = 0, i2 = 0, i3 = 0, i4 = 0;

        for(int i=n-1; i>=0; i--) {
            if(v[0][i1] == num[i]-'0') {
                i1++;
            } 

            if(v[1][i2] == num[i]-'0') {
                i2++;
            } 

            if(v[2][i3] == num[i]-'0') {
                i3++;
            } 

            if(v[3][i4] == num[i]-'0') {
                i4++;
            } 

            if(v[0].size() == i1) {
                return (n-i - i1);
            }

            if(v[1].size() == i2) {
                return (n-i - i2);
            }

            if(v[2].size() == i3) {
                return (n-i - i3);
            }

            if(v[3].size() == i4) {
                return (n-i - i4);
            }
        }

        return (n) - count(begin(num), end(num), '0');
    }
};
