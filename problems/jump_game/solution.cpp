class Solution {
public:
    bool canJump(vector<int>& nums) {
        // int curr = nums[0];
        // int i = 0;
        // int n = nums.size();
        // if(n == 1) return true;

        // while(i<n) {
        //     if(curr == 0 && i < n - 1 ) {
        //             cout << "t" << endl;

        //         return false;
        //     }
        //     if(curr >= n - 1) {
        //             cout << "t" << endl;

        //         return true;
        //     }
        //     int mx = 0;
        //     int pos = i+1;
        //     cout<<nums[i]<<endl;
        //     if (nums[i] + i >= n-1) {
        //             cout << "t2" << endl;

        //         return true;
        //     }

        //     for(int j=i; j<i+curr; j++) {
        //         if(j >= n-1) {
        //             cout << "t1" << endl;
        //             return true;
        //         }

        //         cout << i+1 << i+curr << endl;

        //         mx = max(mx, j+nums[j]);


        //     }
        //     i = i+curr+1;
        //     curr = mx;
        // }

        // return true;

        int l=0,r=0;
        int n=nums.size();
        while(r<n-1 and l<=r){
            int mx=0;
            for(int i=l;i<=r;i++){
                mx=max(mx,i+nums[i]);
            }
            l=r+1;
            r=mx;
        }
        if(r<n-1){
            return false;
        }
        return true;

    }
};