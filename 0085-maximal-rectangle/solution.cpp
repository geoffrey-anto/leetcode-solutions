class Solution {
public:
    // Basically just like the Largest histogram problem
    // but here we compute the max area possible for each row
    // take row i and above rows into count and compute over that
    // so row 0 -> 1 0 1 0 0, row 2 -> 3 1 3 2 2 etc...
    // return max among the rows

    // add 1 if the curr row is 1 else if 0 reset the row vector to 0

    int maxAreaForHistoram(vector<int> &arr, int n) {
        stack<int> st;
        st.push(-1);
        vector<int> nextMin(n);
        for(int i=n-1; i>=0; i--) {
            while(st.top() != -1 && arr[st.top()] >= arr[i]) st.pop();

            if(st.empty()) {
                nextMin[i] = arr[i];
                st.push(arr[i]);
            } else {
                nextMin[i] = st.top();
                st.push(i);
            }
        }

        st = stack<int>();
        st.push(-1);
        vector<int> prevMin(n);
        for(int i=0; i<n; i++) {
            while(st.top() != -1 && arr[st.top()] >= arr[i]) st.pop();

            if(st.empty()) {
                prevMin[i] = arr[i];
                st.push(arr[i]);
            } else {
                prevMin[i] = st.top();
                st.push(i);
            }
        }
        int mx = 0;
        for(int i=0; i<n; i++) {
            int l = arr[i];
            if (nextMin[i] == -1) {
                nextMin[i] = n;
            }

            int b = nextMin[i] - prevMin[i] - 1;

            mx = max(mx, l*b);
        }

        return mx;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int mx = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> row(m, 0);
        for(auto &r: matrix) {
            for(int i=0; i<m; i++) {
                if(r[i] == '1') {
                    row[i]++;
                } else {
                    row[i] = 0;
                }
            }

            mx = max(mx, maxAreaForHistoram(row, m));
        }

        return mx;
    }
};
