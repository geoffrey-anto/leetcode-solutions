class Solution {
public:
    string largestPalindrome(int n, int k) {
        if(k == 1) {
            return string(n, '9');
        }

        if(k == 2) {
            if(n > 2) {
                return "8" + string(n-2, '9') + "8";
            } else {
                return string(n, '8');
            }
        }

        if(k == 4) {
            if(n > 3) {
                return "88" + string(n-4, '9') + "88";
            } else {
                return string(n, '8');
            }
        }

        if(k == 5) {
            if(n > 2) {
                return "5" + string(n-2, '9') + "5";
            } else {
                return string(n, '5');
            }
        }

        if(k == 9 or k == 3) {
            return string(n, '9');
        }

        if(k == 6) {
            if(n <= 2) {
                return string(n, '6');
            } else if(n % 2 != 0) {
                return "8" + string(n / 2 - 1, '9') + "8" + string(n / 2 - 1, '9') + "8";
            } else {
                return "8" + string(n / 2 - 2, '9') + "77" + string(n / 2 - 2, '9') + "8";
            }
        }

        if(k == 8) {
            if(n > 6) {
                return "888" + string(n-6, '9') + "888";
            } else {
                return string(n, '8');
            }
        }

        map<int, string> dic = {
            {0, ""}, {1, "7"}, {2, "77"}, {3, "959"}, {4, "9779"},
            {5, "99799"}, {6, "999999"}, {7, "9994999"}, {8, "99944999"},
            {9, "999969999"}, {10, "9999449999"}, {11, "99999499999"}
        };

        int l = n / 12;
        int r = n % 12;

        string result;
        result.append(6 * l, '9');
        result += dic[r];
        result.append(6 * l, '9');

        return result;
    }
};
