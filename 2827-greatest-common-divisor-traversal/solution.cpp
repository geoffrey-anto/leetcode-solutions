class DSU {
    public:
    vector<int> parent, rank, size;
    int _n;

    DSU(int n) {
        this->_n = n;

        parent.resize(n);
        rank.resize(n);
        size.resize(n);

        for(int i=0; i<n; i++) {
            parent[i] = i;
            rank[i] = size[i] = 1;
        }
    }

    int findUPar(int n) {
        if(parent[n] != n) {
            parent[n] = findUPar(parent[n]);
        }

        return parent[n];
    } 

    bool unionByRank(int u, int v) {
        int ulp_u = parent[u];
        int ulp_v = parent[v];

        if(ulp_u == ulp_v) {
            return false;
        }

        if(rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        } else if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }

        _n--;

        return true;
    }

    bool unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return false;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }

        _n--;

        return true;
    }

    void reset(int node) {
        parent[node] = node;
        rank[node] = 1;
    }

    int getNoOfComponents() {
        int ans = 0;
        
        for(int i=0; i<_n; i++) {
            if(parent[i] == i) {
                ans++;
            }
        }

        return ans;
    }
};



class Solution {
    vector<int> spf;
    
    void sieve(int mx)
    {
        spf = vector<int>(mx, 0);
        spf[1] = 1;
        for (int i = 2; i < mx; i++)
            spf[i] = i;
    
        for (int i = 4; i < mx; i += 2)
            spf[i] = 2;
    
        for (int i = 3; i * i < mx; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j < mx; j += i)
    
                    if (spf[j] == j)
                        spf[j] = i;
            }
        }
    }
    
    vector<int> getFactorization(int x)
    {
        vector<int> ret;
        while (x != 1) {
            ret.push_back(spf[x]);
            x = x / spf[x];
        }
        return ret;
    }

public:
    bool canTraverseAllPairs(vector<int>& nums) {
        unordered_map<int, int> fac;

        DSU d = DSU(nums.size());

        for(int i=0; i<nums.size(); i++) {
            int n = nums[i];
            int f = 2;

            while(f*f <= n) {
                if(n % f == 0) {
                    if(fac.find(f) != fac.end()) {
                        d.unionBySize(fac[f], i);
                    } else {
                        fac[f] = i;
                    }

                    while(n % f == 0) {
                        n = n / f;
                    }
                }
                f++;
            }

            if(n > 1) {
                if(fac.find(n) != fac.end()) {
                    d.unionBySize(i, fac[n]);
                } else {
                    fac[n] = i;
                }
            }
        }

        return d._n == 1;
    }
};
