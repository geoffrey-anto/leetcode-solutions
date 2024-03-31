class Solution {
public:
    int norm(int a) {
        return a == 0 ? -1 : 1;
    }
    int minimumLevels(vector<int>& possible) {
        int cnt = 0;

        vector<int> presum;
        for(auto i: possible) {
            if(i == 0) {
                cnt--;
            } else {
                cnt++;
            }
            presum.push_back(cnt);
        }

        // int curr = 0;

        // for(int i=1; i<presum.size(); i++) {
        //     if((presum[presum.size()-1] - presum[i] + possible[i] == 0 ? -1 : 1) > presum[i-1]) {
        //         return i;
        //     }
        // }

        int curr = 0;

        for(int i=0; i<presum.size()-1; i++) {
            curr += norm(possible[i]);
            if(curr > cnt - curr) {
                return i+1;
            }
        }


        return -1;
    }
};
