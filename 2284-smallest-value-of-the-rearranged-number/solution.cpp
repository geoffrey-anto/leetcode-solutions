class Solution {
public:
    long long smallestNumber(long long num) {
        if(num == 0) {
            return 0ll;
        }

        if(num < 0) {
            num *= -1;
            vector<int> v;
            while(num != 0) {
                v.push_back(num%10);
                num /= 10;
            } 

            sort(begin(v), end(v), greater<int>());

            long long ans = 0;

            for(auto &i: v) {
                ans = ans * 10ll + (long long)i;
            }

            return ans*-1ll;
        } else {
            vector<int> v;
            while(num != 0) {
                v.push_back(num%10);
                num /= 10;
            } 

            sort(begin(v), end(v));


            int mn = INT_MAX;

            for(auto i: v) {
                if(i != 0) {
                    mn = i;
                    v.erase(find(begin(v), end(v), i));
                    break;
                }
            }

            long long ans = mn;


            for(auto &i: v) {
                ans = ans * 10ll + (long long)i;
            }

            return ans;
        }
    }
};
