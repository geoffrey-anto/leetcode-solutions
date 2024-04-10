class DSU {
    private:
    vector<int> parent, rank, size;
    int _n;

    public:
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
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

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

    unordered_map<int, string> getComponents(string &s) {
        unordered_map<int, string> ans;
        for(int i=0; i<_n; i++) {
            ans[findUPar(parent[i])] += s[i];
        }

        return ans;
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        DSU* dsu = new DSU(s.size());

        for(auto &pair: pairs) {
            dsu->unionByRank(pair[0], pair[1]);
        }

        auto components = dsu->getComponents(s);

        for(auto &[k, v]: components) {
            sort(begin(v), end(v), greater<char>());
        }
        
        string ans = "";

        for(int i=0; i<s.size(); i++) {
            int comp = dsu->findUPar(i);

            ans += components[comp].back();
            components[comp].pop_back();
        }

        return ans;
    }
};
