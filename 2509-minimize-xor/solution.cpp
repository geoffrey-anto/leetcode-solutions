class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int count1 = 0;

        for(int i=0; i<31; i++) {
            if(((1 << i) & num1) != 0) {
                count1++;
            }
        }

        int count2 = 0;

        for(int i=0; i<31; i++) {
            if(((1 << i) & num2) != 0) {
                count2++;
            }
        }

        if(count1 == count2) {
            return num1;
        }

        int ans = 0;

        for(int i=31; i>=0; i--) {
            cout << ans << endl;
            if(count2 == 0) {
                break;
            }

            if(count1 == 0) {
                break;
            }

            if(((1 << i) & num1) != 0) {
                count2--;
                count1--;
                ans = ans | (1 << i);
            }
        }

        if(count2 != 0) {
            for(int i=0; i<31; i++) {
                if(count2 == 0) {
                    break;;
                }
                if(((1 << i) & ans) == 0) {
                    ans = ans | (1 << i);
                    count2--;
                }
            }
        }

        return ans;
    }
};
