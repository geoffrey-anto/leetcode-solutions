class Solution {
public:
    int getScore(vector<int> &a, vector<int> &b) {
        int ans = 0;

        for(int i=0; i<a.size(); i++) {
            ans += (a[i] == b[i]);
        }

        return ans;
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int maxx = 0;

        if(students.size() == 1) {
            return getScore(students[0], mentors[0]);
        }

        vector<int> v(students.size());

        for(int i=0; i<students.size(); i++) {
            v[i] = i;
        }

        do {
            int ans = 0;

            for(int i=0; i<students.size(); i++) {
                int j = v[i];
                int s = getScore(students[i], mentors[j]);
                ans += s;
            }

            maxx = max(ans, maxx);
        } while(next_permutation(v.begin(), v.end()));

        return maxx;
    }
};
