class Solution {
public:
    int getNoOfOnes(string &arr) {
        int cnt = 0;
        for(char i: arr) {
            if(i == '1') cnt++;
        }

        return cnt;
    }

    int numberOfBeams(vector<string>& bank) {
        vector<int> preCompute;
        int n = bank.size(), ans = 0;
        for(auto &i: bank) {
            int v = getNoOfOnes(i);
            if(v == 0) {
                continue;
            }
            preCompute.push_back(v);
        }

        if(preCompute.size() == 0){
            return 0;
        }

        if(preCompute.size() == 1) {
            return 0;
        }

        for(int i=0; i<preCompute.size()-1; i++) {
            ans += preCompute[i] * preCompute[i+1];
        }
        return ans;
    }
};
