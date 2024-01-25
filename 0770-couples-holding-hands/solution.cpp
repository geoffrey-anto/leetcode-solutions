class DSU {
private:
    vector<int> rank;
    vector<int> parent;
    int _n;

public:
    DSU(int n) {
        _n = n;
        rank = vector<int> (n, 0);
        parent = vector<int> (n, 0);

        for(int i=0; i<n; i++) {
            parent[i] = i;
        }
    }

    int findUParent(int n) {
        if(parent[n] == n) {
            return n;
        }

        return parent[n] = findUParent(parent[n]);
    }

    void unionByRank(int x, int y) {
        int ulp_x = findUParent(x);
        int ulp_y = findUParent(y);

        if(ulp_x == ulp_y) return;

        if(rank[ulp_x] < rank[ulp_y]) {
            parent[ulp_x] = ulp_y;
        } else if(rank[ulp_x] > rank[ulp_y]) {
            parent[ulp_y] = ulp_x;
        } else {
            parent[ulp_x] = ulp_y;
            rank[ulp_y]++;
        }
    }

    int getComponents() {
        int cnt = 0;

        for(int i=0; i<_n; i++) {
            if(parent[i] == i) {
                cnt++;
            }
        }

        return cnt;
    }
};

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size()/2;

        DSU *dsu = new DSU(n);

        for(int i=0; i<n; i++) {
            int a = row[2*i];
            int b = row[2*i + 1];
            dsu->unionByRank(a/2, b/2);
        }

        return n - dsu->getComponents();
    }
};
