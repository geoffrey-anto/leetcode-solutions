class Solution {
public:
    bool getColor(string &a) {
        int x = (a[0] - 'a') + 1;
        int y = (a[1] - '0') + 1;

        return ((x % 2) == (y % 2));
    }
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        return getColor(coordinate1) == getColor(coordinate2);
    }
};
