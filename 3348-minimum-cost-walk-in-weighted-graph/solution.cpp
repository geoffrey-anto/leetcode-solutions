template <typename T>
void print(T arr)
{
    for (auto i : arr)
    {
        cout << i << ' ';
    }
    cout << endl;
}

class DSU {
    public:
    vector<int> parent, rank, size, totalAnd;
    int _n;

    public:
    DSU(int n) {
        this->_n = n;

        parent.resize(n);
        rank.resize(n);
        size.resize(n);
        totalAnd.resize(n);

        for(int i=0; i<n; i++) {
            parent[i] = i;
            rank[i] = size[i] = 1;
            totalAnd[i] = 0b11111111111111111;
        }
    }

    int findUPar(int n) {
        if(parent[n] != n) {
            parent[n] = findUPar(parent[n]);
        }

        return parent[n];
    } 

    bool unionByRank(int u, int v, int w) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);


        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else {
            parent[ulp_v] = ulp_u;
        }

        totalAnd[ulp_u] = totalAnd[ulp_v] = totalAnd[ulp_u] & totalAnd[ulp_v] & w;

        if(rank[ulp_u] == rank[ulp_v]) {
            rank[ulp_u]++;
            return false;
        }

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
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DSU* dsu = new DSU(n);
        for(auto &edge: edges) {
            dsu->unionByRank(edge[0], edge[1], edge[2]);
        }

        vector<int> ans;


        for(auto &q: query) {
            if(dsu->findUPar(q[0]) != dsu->findUPar(q[1])) {
                ans.push_back(-1);
            } else {
                if(q[0] == q[1]) {
                    ans.push_back(0);
                    continue;
                }
                ans.push_back(dsu->totalAnd[dsu->findUPar(q[0])]);
            }
        }

        return ans;
    }
};
