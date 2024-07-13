class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        stack<int> st;
        int n = positions.size();

        vector<int> p(n, 0);
        iota(begin(p), end(p), 0);

        sort(begin(p), end(p), [&](const int &a, const int &b) {
            return positions[a] < positions[b];
        });

        vector<int> res;


        for(auto i: p) {
            if(directions[i] == 'R') {
                st.push(i);
            } else {
                while(!st.empty()) {
                    auto x = st.top();

                    if(healths[x] == healths[i]) {
                        healths[i] = 0;
                        healths[x] = 0;
                        st.pop();
                        break;
                    } else if(healths[x] > healths[i]) {
                        healths[i] = 0;
                        healths[x]--;
                        break;
                    } else {
                        healths[x] = 0;
                        healths[i]--; 
                        st.pop();
                    }
                }
            }
        }


        for(int i=0; i<n; i++) {
            if(healths[i] > 0) {
                res.push_back(healths[i]);
            }
        }

        return res;
    }
};
