class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0;
        int tens = 0;
        int twentys = 0;

        for(auto &bill: bills) {
            
            int diff = bill - 5;

            if(bill == 5) {
                fives ++;
            } else if(bill == 10) {
                tens ++;
            } else {
                twentys ++;
            }

            if(diff == 0) {
                continue;
            }

            while(diff >= 20 and twentys > 0) {
                diff -= 20;
                twentys -= 1;
            }

            while(diff >= 10 and tens > 0) {
                diff -= 10;
                tens -= 1;
            }

            while(diff >= 5 and fives > 0) {
                diff -= 5;
                fives -= 1;
            }


            if(diff != 0) {
                return false;
            }
        }

        return true;
    }
};
