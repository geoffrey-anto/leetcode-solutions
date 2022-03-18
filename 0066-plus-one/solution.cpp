class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        vector<int> ans;
        int carry=1;
        for(int i=n-1;i>=0;i--){
            if(carry!=0){
                int x=(digits[i]+carry)%10;
                carry=(digits[i]+carry)/10;
                ans.push_back(x);
            } else {
                ans.push_back(digits[i]);
            }
        }
        if(carry!=0){
            ans.push_back(carry);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
