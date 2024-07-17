class DSU {
private:
  vector<int> parent, rank, size;
  int _n;

public:
  DSU(int n) {
    this->_n = n;

    parent.resize(n);
    rank.resize(n);
    // size.resize(n);

    for (int i = 0; i < n; i++) {
      parent[i] = i;
      rank[i] = 1;
    }
  }

  int findUPar(int n) {
    if (parent[n] != n) {
      parent[n] = findUPar(parent[n]);
    }

    return parent[n];
  }

  bool unionByRank(int u, int v) {
    int ulp_u = findUPar(u);
    int ulp_v = findUPar(v);

    if (ulp_u == ulp_v) {
      return false;
    }

    if (rank[ulp_u] > rank[ulp_v]) {
      parent[ulp_v] = ulp_u;
    } else if (rank[ulp_u] < rank[ulp_v]) {
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

    if (ulp_u == ulp_v)
      return false;
    if (size[ulp_u] < size[ulp_v]) {
      parent[ulp_u] = ulp_v;
      size[ulp_v] += size[ulp_u];
    } else {
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

    for (int i = 0; i < _n; i++) {
      if (parent[i] == i) {
        ans++;
      }
    }

    return ans;
  }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        // what if we can remove a node from a cycle in the graph
        // but basically since they asking us to remobe a singular node from the graph
        // there can be only one cycle i guess

        // we need to find the nodes in the cycle and bitmask the index and return the edge at the 
        // last set bit in the mask as the edge to be removed

        // should work
        // dfs from n, if reach again at n it means n is a part of a cycle

        // or check indeg too

        int n = edges.size();

        vector<int> in(n, 0);

        bool type = true;

        for(auto &i: edges) {
            in[i[1]-1]++;
            if(in[i[1]-1] == 2) {
                type = false;
            }
        } 

        if(type) {
            DSU* dsu = new DSU(n);

            vector<int> ans;

            for(auto &edge: edges) {
                // cout << dsu->findUPar(edge[0] - 1) << " " << dsu->findUPar(edge[1] - 1) << endl;
                if(dsu->findUPar(edge[0] - 1) == dsu->findUPar(edge[1] - 1)) {
                    ans = edge;
                }

                dsu->unionByRank(edge[0] - 1, edge[1] - 1);
            }

            return ans;
        } else {
            // means there a in deg with 2 and we need to remove the edge to it
            int node = 1;
            for(int i=0; i<n; i++) {
                if(in[i] == 2) {
                    node = i + 1;
                }
            }

            vector<int> ans;

            for(auto &edge: edges) {
                if(edge[1] == node) {
                    // ans = edge;

                    DSU* dsu = new DSU(n);

                    vector<int> ans1;

                    for(auto &edge1: edges) {
                        if(edge1 == edge) {
                            continue;
                        }

                        // cout << dsu->findUPar(edge[0] - 1) << " " << dsu->findUPar(edge[1] - 1) << endl;
                        if(dsu->findUPar(edge1[0] - 1) == dsu->findUPar(edge1[1] - 1)) {
                            // ans1 = edge1;
                        }

                        dsu->unionByRank(edge1[0] - 1, edge1[1] - 1);
                    }

                    if(dsu->findUPar(edge[0]-1) == dsu->findUPar(edge[1] - 1)) {
                        ans = edge;
                    }
                }
            } 

            return ans;
        }
    }
};
