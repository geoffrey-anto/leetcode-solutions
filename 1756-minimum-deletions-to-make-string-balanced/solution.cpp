class Solution {
public:
    int minimumDeletions(string s) {
        // int l = 0;
        // int r = s.size() - 1;

        // int ans = 0;

        // while(l < r) {
        //     // l -> traverse A and remove conci B
        //     // r -> traverse B and remove conci A

        //     if(s[l] == 'a') {
        //         while(l < r and s[l] == 'a') {
        //             l++;
        //         }
        //     } else {
        //         while(l < r and s[l] == 'b') {
        //             l++;
        //             ans++;
        //         }
        //     }


        //     if(s[r] == 'b') {
        //         while(l < r and s[r] == 'b') {
        //             r--;
        //         }
        //     } else {
        //         while(l < r and s[r] == 'a') {
        //             r--;
        //             ans++;
        //         }
        //     }
        // }

        // return ans;

        int cnt_a = 0;

        for(auto i: s) {
            if(i == 'a') {
                cnt_a++;
            }
        }

        int ans = cnt_a;

        int cnt_b = 0;

        for(auto i: s) {
            if(i == 'a') {
                cnt_a--;
            }

            if(i == 'b') {
                cnt_b++;
            }

            ans = min(ans ,cnt_a + cnt_b);
        }


        return ans;
    }
};
