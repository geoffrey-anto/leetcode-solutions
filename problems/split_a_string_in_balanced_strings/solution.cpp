class Solution {
public:
    int balancedStringSplit(string s) {
        int cnt=0;
        int temp = 0;
        for(auto i:s){
            if(i=='L'){
                temp--;
            } else {
                temp++;
            }
            if(temp == 0){
                cnt++;
            }
        }
        return cnt;
    }
};