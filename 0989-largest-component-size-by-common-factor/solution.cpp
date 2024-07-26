class UnionFind {
    public: 
    vector<int> rank, parent;

    UnionFind(int n) {
        rank = vector<int> (n+1, 0);
        parent = vector<int> (n+1, 0);

        iota(begin(parent), end(parent), 0);
    }

    int find(int u) {
        if(parent[u] == u) {
            return u;
        }

        return parent[u] = find(parent[u]);
    }

    void unite(int u, int v) {
        int ulp = find(u);
        int vlp = find(v);

        if(ulp == vlp) {
            return;
        }

        if(ulp > vlp) {
            parent[vlp] = ulp;
            rank[ulp]++;
        } else {
            parent[ulp] = vlp;
            rank[vlp]++;
        }

        return;
    }
};

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int mx = *max_element(begin(nums), end(nums));
        UnionFind* uf = new UnionFind(mx);

        for(auto i: nums) {
            // cout << i << " -> ";
            for(int x=2; x<=sqrt(i); x++) {
                if(i % x == 0) {
                    // cout << x << " " ;
                    uf->unite(i, x);
                    uf->unite(i/ x, x);
                }
            }
            // cout << endl;
        }

        unordered_map<int, int> groups;

        for(auto i: nums) {
            int parent = uf->find(i);

            groups[parent]++;
        }

        int ans = 0;

        for(auto &[k, v]: groups) {
            // cout << k << " -> " << v << endl;
            ans = max(ans, v);
        }

        return ans;
    }
};
