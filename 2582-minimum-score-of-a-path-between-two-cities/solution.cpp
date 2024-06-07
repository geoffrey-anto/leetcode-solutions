auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

template <typename T> void print(T arr) {
  for (auto i : arr) {
    cout << i << ' ';
  }
  cout << endl;
}


class DSU {
private:
  vector<int> parent, rank, size, score;
  int _n;

public:
  DSU(int n) {
    this->_n = n;

    parent.resize(n);
    rank.resize(n);
    // size.resize(n);
    score.resize(n);

    for (int i = 0; i < n; i++) {
      parent[i] = i;
      rank[i] = 1;
      score[i] = INT_MAX;
     }
  }

  int findUPar(int n) {
    if (parent[n] != n) {
      parent[n] = findUPar(parent[n]);
    }

    return parent[n];
  }

  bool unionByRank(int u, int v, int val) {
    int ulp_u = findUPar(u);
    int ulp_v = findUPar(v);

    if (ulp_u == ulp_v) {
      // continue;
    } else if (rank[ulp_u] > rank[ulp_v]) {
      parent[ulp_v] = ulp_u;
    } else if (rank[ulp_u] < rank[ulp_v]) {
      parent[ulp_u] = ulp_v;
    } else {
      parent[ulp_v] = ulp_u;
      rank[ulp_u]++;
    }

    score[ulp_u] = min(score[ulp_u], score[ulp_v]);
    score[ulp_u] = min(score[ulp_u], val);
    score[ulp_v] = min(score[ulp_u], score[ulp_v]);
    score[ulp_v] = min(score[ulp_v], val);

    return true;
  }

  bool unionBySize(int u, int v) {
    int ulp_u = findUPar(u);
    int ulp_v = findUPar(v);

    if (ulp_u == ulp_v) {
      return false;
    }
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


  int getMin() {
    int ans = INT_MAX;

    for(auto i=1; i<this->_n; i++) {
        if(findUPar(parent[i]) == findUPar(parent[1])) {
            ans = min(ans, score[i]);
        }
    }
    return ans;
  }
};

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        DSU* dsu = new DSU(n+1);

        for(auto &i: roads) {
            dsu->unionByRank(i[0], i[1], i[2]);
        }

        return dsu->getMin();
    }
};
