class Solution {
public:
    int mp[10];
    int isBeaut(int n) {
        memset(mp, 0, sizeof(mp));
        int c = n;

        while(n) {
            mp[n%10]++;
            n = n / 10;
        }

        for(int i=0; i<10; i++) {
            if(mp[i] != 0 and mp[i] != i) {
                return false;
            }
        }

        return true;
    }
    
    int nextBeautifulNumber(int n) {
        int cnt = n+1;

        while(true) {
            if(isBeaut(cnt)) {
                return cnt;
            }
            cnt++;
        }

        return -1;
    }
};
