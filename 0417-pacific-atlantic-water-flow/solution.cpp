class Solution {
public:
    vector<int> dir = {0, -1, 0, 1, 0};
    int DIR_SIZE = 4;
    
    bool isValid(int i, int j, int &n, int &m) {
        return i >= 0 and i < n and j >= 0 and j < m;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int n = h.size();
        int m = h[0].size();

        vector<vector<bool>> paci(n, vector<bool>(m,0));

        vector<vector<bool>> atla(n, vector<bool>(m, 0));

        queue<pair<int, int>> qp, qa;

        for(int i=0; i<n; i++) {
            qp.push({i, 0});
            paci[i][0] = true;
            qa.push({i, m-1});
            atla[i][m-1] = true;
        }

        for(int i=0; i<m; i++) {
            qp.push({0, i});
            paci[0][i] = true;
            qa.push({n-1, i});
            atla[n-1][i] = true;
        }

        // bfs for pacific;

        while(!qp.empty()) {
            auto top = qp.front();
            qp.pop();

            for(int d=0; d<DIR_SIZE; d++) {
                int dx = top.first + dir[d];
                int dy = top.second + dir[d+1];

                if(isValid(dx, dy, n, m) and h[dx][dy] >= h[top.first][top.second] and !paci[dx][dy]) {
                    paci[dx][dy] = true;
                    qp.push({dx, dy});
                }
            }
        }

        // bfs for atlantic;
        
        while(!qa.empty()) {
            auto top = qa.front();
            qa.pop();

            for(int d=0; d<DIR_SIZE; d++) {
                int dx = top.first + dir[d];
                int dy = top.second + dir[d+1];

                if(isValid(dx, dy, n, m) and h[dx][dy] >= h[top.first][top.second] and !atla[dx][dy]) {
                    atla[dx][dy] = true;
                    qa.push({dx, dy});
                }
            }
        }

        vector<vector<int>> ans;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(paci[i][j] and atla[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
