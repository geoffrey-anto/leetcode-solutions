class UnionFind {
    private:
    vector<int> parent, rank, size;
    int _n;

    public:
    UnionFind(int n) {
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
    bool equationsPossible(vector<string>& equations) {
        UnionFind* uf = new UnionFind(26);

        sort(equations.begin(), equations.end(), [&](const string &a, const string &b) {
            return a[1] > b[1];
        });

        for(auto &eq: equations) {
            int a = eq[0]-'a';
            int b = eq[3]-'a';

            if(eq[1] == '!') {
                if(uf->findUPar(a) == uf->findUPar(b)) {
                    return false;
                } else {
                    continue;
                }
            } else {
                uf->unionBySize(a, b);
            }
        }

        return true;
    }
};
