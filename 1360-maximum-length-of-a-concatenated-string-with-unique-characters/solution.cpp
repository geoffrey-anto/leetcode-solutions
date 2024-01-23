class Solution {
public:
    bool hasUnique(set<char> &a, set<char> &b) {
        int n1 = a.size();
        int n2 = b.size();

        set<int> temp;
        set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(temp, temp.begin()));

        return temp.size() == 0;
    }

    bool conatinsDup(string &a) {
        set<char> st(a.begin(), a.end());

        return a.size() != st.size();
    }

    int f(int i, vector<set<char>> &a, set<char> prev, int n, int picked=0) {
        if(i == n) {
            if(picked > 0) {
                return 0;
            }
            return INT_MIN;
        }

        int pick = 0;
        int notpick = 0;

        notpick = f(i+1, a, prev, n, picked);
        
        if(hasUnique(a[i], prev)) {
            prev.insert(a[i].begin(), a[i].end());
            pick = a[i].size() + f(i+1, a, prev, n, picked+1);
        }


        return max(pick, notpick);
    }

    int maxLength(vector<string>& arr) {
        vector<set<char>> a;

        for(auto &i: arr) {
            if(conatinsDup(i)) {
                continue;
            }
            a.push_back(set<char> (i.begin(), i.end()));
        }

        int mx = 0;

        mx = max(mx, f(0, a, set<char>(), a.size()));

        return mx;
    }
};
