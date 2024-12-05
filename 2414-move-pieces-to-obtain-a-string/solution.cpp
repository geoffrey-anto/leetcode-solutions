class Solution {
public:
    bool canChange(string start, string target) {
        int i = 0;
        int j = 0;
        int n = start.size();

        while(i < n and j < n) {
            while(i < n and start[i] == '_') {
                i++;
            } 

            while(j < n and target[j] == '_') {
                j++;
            }

            if(i == n and j == n) {
                return true;
            }

            if(j >= n  or i >= n) {
                return false;
            }

            if(start[i] != target[j]) {
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

        while(i < n and start[i] == '_') {
            i++;
        } 

        while(j < n and target[j] == '_') {
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
