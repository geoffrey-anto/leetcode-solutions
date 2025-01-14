class Solution {
public:
    template<typename T>
    auto setIntersection(set<T> &a, set<T> &b) {
        int count = 0;
        for (auto value : a)
            if (b.find(value) != b.end())
                count++;
        return count; 
    }

    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<int> ans(n, 0);

        set<int> sa, sb;

        for(int i=0; i<n; i++) {
            sa.insert(a[i]);
            sb.insert(b[i]);

            ans[i] = setIntersection(sa, sb);
        }

        return ans;
    }
};
