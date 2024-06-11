class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mp;

        for(int i=0; i<arr2.size(); i++) {
            mp[arr2[i]] = i;
        }

        sort(begin(arr1), end(arr1), [&](int& a, int &b) {
            auto ai = mp.find(a);
            auto bi = mp.find(b);

            if(ai == mp.end() and bi == mp.end()) {
                return a < b;
            } else if(ai == mp.end()) {
                return false;
            } else if (bi == mp.end()){
                return true;
            } else {
                return (*ai).second < (*bi).second;
            }
        });

        return arr1;
    }
};
