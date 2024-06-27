class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int a, b, c, d;

        a = edges[0][0];
        b = edges[0][1];

        c = edges[1][0];
        d = edges[1][1];

        if(a == c) {
            return a;
        }

        if(b == c) {
            return b;
        }

        if(a == d) {
            return a;
        }

        if(b == d) {
            return b;
        }

        return -1;
    }
};
