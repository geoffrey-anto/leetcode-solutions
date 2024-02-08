class DSU {
    public: 
    vector<int> size, parent;
    int _n;
    DSU(int n) {
        size = vector<int> (n, 1);
        parent = vector<int> (n, 0);

        for(int i=0; i<n; i++) {
            parent[i] = i;
        }
        _n = n;
    }

    int findUPar(int n)  {
        if(n == parent[n]) {
            return n;
        }

        return parent[n] = findUPar(parent[n]);
    }

    void unionBySize(int u, int v) {
        int ulp_v = findUPar(v);
        int ulp_u = findUPar(u);

        if(ulp_v == ulp_u) {
            return;
        }

        parent[ulp_v] = ulp_u;
        size[ulp_u] += size[ulp_v];
    }

    int getLargestComponent() {
        int sz = 0;
        for(int i=0; i<_n; i++) {
            if(parent[i] == i && sz < size[i]) {
                sz = size[i];
            }
        }

        return sz;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        DSU dsu = DSU(nums.size());

        for(int i=0; i<nums.size(); i++) {
            if(mp.find(nums[i]) == mp.end()) {
                int num = nums[i];
                if(mp.find(num-1) != mp.end()) {
                    dsu.unionBySize(i, mp[num-1]);
                }

                if(mp.find(num+1) != mp.end()) {
                    dsu.unionBySize(i, mp[num+1]);
                }

                mp[num] = i;
            }
        }

        return dsu.getLargestComponent();
    }
};