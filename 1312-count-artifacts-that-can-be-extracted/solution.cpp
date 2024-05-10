class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        for(auto &i: dig) {
            vis[i[0]][i[1]] = true;
        }

        int ans = 0;

        for(auto &i: artifacts) {
            int il = i[0];
            int jl = i[1];
            int im = i[2];
            int jr = i[3];

            bool flag = true;

            for(int i=il; i<=im; i++) {
                for(int j=jl; j<=jr; j++) {
                    if(!vis[i][j]) {
                        flag = false;
                        break;
                    }
                }

                if(!flag) {
                    break;
                }
            }

            if(flag) ans++;
        }

        return ans;
    }
};
