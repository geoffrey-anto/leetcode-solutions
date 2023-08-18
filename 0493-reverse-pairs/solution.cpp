class Solution {
public:  
    void merge(vector<int> &a, int s, int m, int e, int &c) {
        int l = s;
        int h = m+1;
        vector<int> temp;
        while(l<=m && h<=e) {
            if(a[l] > a[h]) {
                temp.push_back(a[h]);
                h++;
            } else {
                temp.push_back(a[l]);
                l++;
            }
        }

        while(l<=m){
            temp.push_back(a[l]);
            l++;
        }

        while(h<=e){
            temp.push_back(a[h]);
            h++;
        }

        for(int i=s; i<=e; i++) {
            a[i] = temp[i-s];
        }
        return;
    }

    void countInver(vector<int> &a, int s, int m, int e, int &c) {
        int r = m+1;
        for(int i=s; i<=m; i++) {
            while(r <= e && (long long)a[i] > (long long)2*a[r]) {
                r++;
            }
            c += (r - m - 1);
        }
    }

    void f(vector<int> &a, int s, int e, int &c) {
        if(s>=e) {
            return;
        }
        int m = (s + e) / 2;
        f(a, s, m, c);
        f(a, m+1, e, c);
        countInver(a, s, m, e, c);
        merge(a, s, m, e, c);
    }

    int reversePairs(vector<int>& nums) {
        int count = 0;
        f(nums, 0, nums.size()-1, count);
        return count;
    }
};
