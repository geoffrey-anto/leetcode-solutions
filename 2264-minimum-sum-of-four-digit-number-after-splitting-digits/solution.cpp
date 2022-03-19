class Solution {
public:
    int minimumSum(int num) {
        vector<int> ans(4);
        ans[0]=num%10;
        num/=10;
        ans[1]=num%10;
        num/=10;
        ans[2]=num%10;
        num/=10;
        ans[3]=num%10;
        num/=10;
        sort(ans.begin(),ans.end());
        return ans[0]*10+ans[3]+ans[1]*10+ans[2];
    }
};
