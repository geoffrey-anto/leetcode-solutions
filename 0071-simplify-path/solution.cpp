class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        int n = path.size();
        string path_norm = "";
        path_norm += path[0];
        char prev = path[0];

        for(int i=1; i<n; i++) {
            if(prev == path[i] and (prev == '/')) {
                continue;
            } else {
                path_norm += path[i];
                prev = path[i];
            }
        }

        vector<string> dirs;

        stringstream ss(path_norm);

        string temp = "";

        while(std::getline(ss, temp, '/')) {
            dirs.push_back(temp);
        }

        for(auto i: dirs) {
            if(i == ".") {
                continue;
            } else if(i == "..") {
                if(!st.empty()) {
                    st.pop_back();
                }
            } else {
                st.push_back(i);
            }
        }

        string ans = "";

        for(auto i: st) {
            ans += i + "/";
        }

        if(ans == "") {
            return "/";
        }

        if(ans[0] != '/'){
            ans = '/' + ans;
        }

        if(ans == "/") {
            return ans;
        }

        return ans.substr(0, ans.size()-1);
    }
};
