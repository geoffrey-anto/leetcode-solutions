class Solution {
public:
    vector<int> rightShift(vector<int> a, int k){

        while(k--) {
            vector<int> v;
            v.push_back(a[a.size()-1]);
            for(int i=0; i<a.size()-1; i++) {
                v.push_back(a[i]);
            }
            a = v;
        }

        return a;
    }

    vector<int> leftShift(vector<int> a, int k){
        while(k--) {
            vector<int> v;
            for(int i=1; i<a.size(); i++) {
                v.push_back(a[i]);
            }
            v.push_back(a[0]);
            a = v;
        }

        return a;
    }

    bool areSimilar(vector<vector<int>>& mat, int k) {
        vector<vector<int>> v;

        k = k % mat[0].size();

        for(int i=0; i<mat.size(); i++) {
            if((i+1)%2 != 0) {
                v.push_back(rightShift(mat[i], k));
            } else {
                v.push_back(leftShift(mat[i], k));
            }
        }

        return v == mat;
    }
};
