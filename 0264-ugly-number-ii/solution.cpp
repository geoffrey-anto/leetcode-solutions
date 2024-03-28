class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 1) {
            return 1;
        }

        if(n == 2) {
            return 2;
        }

        if(n == 3) {
            return 3;
        }

        set<long long> pq;

        pq.insert(2); pq.insert(3); pq.insert(5);

        long long cnt = 1;

        long long curr = 0;

        while(cnt != n) {
            curr = *pq.begin();
            pq.erase(curr);

            pq.insert(curr * 2ll);
            pq.insert(curr * 3ll);
            pq.insert(curr * 5ll);
            cnt++;
        }  

        return curr;      
    }
};
