class Solution {
public:
    string add(string a, int pos) {
        if(a[pos] == '9') {
            a[pos] = '0';
        } else {
            a[pos] = a[pos]+1;
        }

        return a;
    }
    string sub(string a, int pos) {
        if(a[pos] == '0') {
            a[pos] = '9';
        } else {
            a[pos] = a[pos]-1;
        }

        return a;
    }
    int openLock(vector<string>& deadends, string target) {
        string start = "0000";

        queue<string> q;

        unordered_set<string> st;

        for(auto &i: deadends) {
            st.insert(i);
        }

        q.push(start);

        int depth = 0;
        
        unordered_map<string, bool> vis;

        while(!q.empty()) {
            int sz = q.size();

            for(int i=0; i<sz; i++) {
                string top = q.front();
                q.pop();
                
                if(vis[top]) {
                    continue;
                }

                vis[top] = true;

                if(st.count(top) > 0) {
                    continue;
                }

                if(top == target) {
                    return depth;
                }

                for(int j=0; j<4; j++) {
                    string r = add(top, j);
                    string l = sub(top, j);

                    if(st.count(r) == 0 && !vis[r])
                        q.push(r);
                    if(st.count(l) == 0 && !vis[l])
                        q.push(l);
                }
            }

            depth++;
        }

        return -1;
    }
};
