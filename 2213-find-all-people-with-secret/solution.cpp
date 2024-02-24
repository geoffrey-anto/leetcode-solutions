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

        rank[0] = INT_MAX;
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
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        // sort(meetings.begin(), meetings.end(), [&](const vector<int> &a, const vector<int> &b) {
        //     return a[2] < b[2];
        // });

        map<int, vector<pair<int, int>>> adj;

        for(auto &i: meetings) {
            adj[i[2]].push_back({i[0], i[1]});
        }

        DSU* d = new DSU(n+1);

        d->unionByRank(0, firstPerson);

        for(auto &t: adj) {
            // cout << t.first << endl;
            // get the meetings for time time 

            for(auto &n: t.second) {
                d->unionByRank(n.first, n.second);
            }


            for(auto &[x, y]: t.second) {
                // cout << x << " " << y << endl; 
                // this shows it is connected to 0 (node which has the initial secret)
                if(d->findUPar(x) == d->findUPar(0)) {
                    continue;
                }

                // not conn so reset
                d->reset(x);
                d->reset(y);
            }

        }

        vector<int> ans;

        for(int i=0; i<n; i++) {
            if(d->findUPar(i) == d->findUPar(0)) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
