class Solution {
public:
    unordered_map<int, int> mp;
    vector<vector<int>> dir = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0},
        {1, 1},
        {1, -1},
        {-1, 1},
        {-1, -1},
    };

    unordered_map<int, int> primes;
    
    bool valid(int i, int j, int n, int m) {
        return i >=0 && i < n and j >= 0 && j < m;
    }

    bool isPrime(int n) {
        if(primes.find(n) != primes.end()) {
            return primes[n];
        }

        for(int i=2; i<=sqrt(n); i++) {
            if(n % i == 0) {
                return primes[n] = false;
            }
        }

        return primes[n] =  true;
    }

    void f(int i, int j, int d, vector<vector<int>>& mat, int n, int m, int carry) {
        carry = carry * 10 + mat[i][j];

        if(carry > 10 && mat[i][j] % 2 != 0 && isPrime(carry)) {
            mp[carry]++;
        }
        
        int dx = dir[d][0];
        int dy = dir[d][1];

        int nx = i + dx;
        int ny = j + dy;

        if(valid(nx, ny, n, m)) {
            f(nx, ny, d, mat,n, m, carry);
        }
    }

    int mostFrequentPrime(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                for(int d=0; d < dir.size(); d++) {
                    f(i, j, d, mat, n, m, 0);
                }
            }
        }

        int mx = -1;
        int mi = -1;

        for(auto &[k, v]: mp) {
            // printf("key: %d, value: %d", k ,v);
            if(mx < v) {
                mx = v;
                mi = k;
            } else if(mx == v) {
                if(k > mi) {
                    mi = k;
                }
            }
        }

        return mi;
    }
};
