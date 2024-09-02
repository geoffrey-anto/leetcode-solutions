class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0ll;
        for(auto &i: chalk) {
            sum += i;
        }

        sum = k % sum;

        for(int i=0; i<chalk.size(); i++) {
            if(chalk[i] > sum) {
                return i;
            } else {
                sum -= chalk[i];
            }
        }

        return -1;
    }
};
