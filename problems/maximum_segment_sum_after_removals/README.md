# Maximum Segment Sum After Removals

## Leetcode Link: [Maximum Segment Sum After Removals](https://leetcode.com/problems/maximum-segment-sum-after-removals/)
### Language: C++

```cpp
#define ll long long

class DSU {
    public: 
    vector<int> size, parent;
    int _n;
    unordered_map<ll, ll> mp;
    ll mx = 0;

    DSU(int n, vector<int> nums) {
        size = vector<int> (n, 1);
        parent = vector<int> (n, 0);

        for(int i=0; i<n; i++) {
            parent[i] = i;
        }

        for(int i=0; i<n; i++) {
            mp[i] = nums[i];
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

        mp[ulp_u] += mp[ulp_v];

        mx = max(mx, mp[ulp_u]);
    }

    ll getMaxSum() {
        int x = mx;
        
        return mx;
    }

    void updateMax(ll m) {
        mx = max(mx, m);
    }
};

class Solution {
public:
    vector<ll> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        int n = nums.size();

        vector<ll> ans(n, 0);

        vector<bool> vis(n+1, 0);

        DSU dsu = DSU(n, nums);

        for(int i=n-1; i>=0; i--) {
            int q = removeQueries[i];
            vis[q] = true;
            ans[i] = dsu.getMaxSum();

            dsu.updateMax(nums[q]);

            if(q+1 < n && vis[q+1]) {
                dsu.unionBySize(q, q+1);
            }

            if(q-1 >= 0 && vis[q-1]) {
                dsu.unionBySize(q, q-1);
            }

        }    

        return ans;
    }
};```



