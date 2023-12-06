class Solution {
public:
    int WEEK = 28;
    int INC = 7;
    
    int getSum(int a, int b) {
        if(b < a) {
            return 0;
        }
        return ((b - a + 1) * (a + b)) / 2;
    }

    int totalMoney(int n) {

        int weeks = n/7;
        int remDays = n%7;

        int moneyForWeeks = (WEEK*weeks) + (INC*getSum(1, weeks-1));

        int moneyForRemDays = getSum(weeks+1, remDays+weeks);

        return moneyForWeeks + moneyForRemDays;
    }
};