template <typename T> void print(T arr) {
  for (auto i : arr) {
    cout << i << ' ';
  }
  cout << endl;
}

class Solution {
public:
    int val(char a) {
        if(a == '.') {
            return 0;
        }

        if(a == 'X') {
            return -1;
        } else {
            return 1;
        }
    }

    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();

        int m = grid[0].size();
        int ans = 0;

        vector<vector<int>> pre1(n+1, vector<int> (m+1, 0));
        vector<vector<int>> pre2(n+1, vector<int> (m+1, 0));


        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                pre1[i][j] = (grid[i][j] == 'X' ? 1 : 0);
                pre2[i][j] = (grid[i][j] == 'Y' ? 1 : 0);

                if(i>0) pre1[i][j] += pre1[i-1][j];
                if(j>0) pre1[i][j] += pre1[i][j-1];
                if(i>0 && j>0) pre1[i][j] -= pre1[i-1][j-1];

                if(i>0) pre2[i][j] += pre2[i-1][j];
                if(j>0) pre2[i][j] += pre2[i][j-1];
                if(i>0 && j>0) pre2[i][j] -= pre2[i-1][j-1];

                if(pre1[i][j] != 0 and (pre1[i][j] == pre2[i][j])) {
                    ans++;
                }

            }
        }

        // for(auto i: pre1) {
        //     print(i);
        // }
        // for(auto i: pre2) {
        //     print(i);
        // }

        return ans;
    }
};
