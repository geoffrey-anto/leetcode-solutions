class Robot {
    public:
    int pos;
    int h;
    char d;
    int i;

    Robot(int a, int b, char c, int f) {
        pos = a;
        h = b;
        d = c;
        i = f;
    }
};

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& p, vector<int>& h, string d) {
        vector<Robot> v;
        int n = p.size();
        vector<int> idx;

        for(int i=0; i<n; i++) {
            idx.push_back(i);
            v.push_back(Robot(p[i], h[i], d[i], i));
        }


        sort(begin(idx), end(idx), [&](int a, int b) {
            if(v[a].pos < v[b].pos) {
                return true;
            } else {
                return false;
            }
        });


        vector<int> health(h);

        stack<int> st;

        for(auto i: idx) {
            if(v[i].d == 'R') {
                st.push(i);
            } else {
                while(!st.empty()) {
                    // cout << health[i] << "-" << health[x] << endl;
                    auto x = st.top();

                    if(health[x] == health[i]) {
                        health[i] = 0;
                        health[x] = 0;
                        st.pop();
                        break;
                    } else if(health[x] > health[i]) {
                        health[i] = 0;
                        health[x]--;
                        break;
                    } else {
                        health[x] = 0;
                        health[i]--; 
                        st.pop();
                    }
                }
            }
        }


        vector<int> ans;

        for(int i=0; i<n; i++) {
            if(health[i] > 0) {
                ans.push_back(health[i]);
            }
        }


        return ans;
    }
};
