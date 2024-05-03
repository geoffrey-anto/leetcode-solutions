class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;

        stringstream ss(version1);

        string temp;

        while(getline(ss, temp, '.')) {
            v1.push_back(stoi(temp));
        }

        stringstream ss1(version2);

        while(getline(ss1, temp, '.')) {
            v2.push_back(stoi(temp));
        }

        int n = max(v1.size(), v2.size());

        while(v1.size() < n) {
            v1.push_back(0);
        }

        while(v2.size() < n) {
            v2.push_back(0);
        }

        for(int i=0; i<v1.size(); i++) {
            int l = v1[i];
            int r = v2[i];

            if(l == r) {
                continue;
            }

            if(l < r) {
                return -1;
            } else {
                return 1;
            }
        }

        return 0;
    }
};
