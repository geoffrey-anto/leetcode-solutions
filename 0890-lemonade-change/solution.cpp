class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int c5 = 0;
        int c10 = 0;
        int c20 = 0;

        for(auto i: bills) {
            if(i == 5) {
                c5++;
            } else if(i == 10) {
                c10++;
                if(c5 > 0) {
                    c5--;
                } else {
                    return false;
                }
            } else if(i == 20) {
                c20++;
                if(c10 > 0) {
                    c10--;
                    if(c5 > 0) {
                        c5--;
                    } else {
                        return false;
                    }
                } else if(c10 == 0) {
                    if(c5 >= 3) {
                        c5 -= 3;
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            } 
        }
        return true;
    }
};
