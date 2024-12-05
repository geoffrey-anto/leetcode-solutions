class Solution {
public:
    bool canTransform(string start, string result) {
        int i = 0;
        int j = 0;
        int n = start.size();

        while(i < n and j < n) {
            while(i < n and start[i] == 'X') {
                i++;
            } 

            while(j < n and result[j] == 'X') {
                j++;
            }

            if(i == n and j == n) {
                return true;
            }

            if(j >= n  or i >= n) {
                return false;
            }

            if(start[i] != result[j]) {
                return false;
            }

            if(start[i] == 'L') {
                if(j <= i) {
                    j++;
                    i++;
                    continue;
                } else {
                    return false;
                }
            } else {
                if(j >= i) {
                    i++; j++; continue;
                } else {
                    return false;
                }
            }
        }

        while(i < n and start[i] == 'X') {
            i++;
        } 

        while(j < n and result[j] == 'X') {
            j++;
        }


        if(i == n and j == n) {
            return true;
        }

        if(j >= n  or i >= n) {
            return false;
        }


        return true;
    }
};
