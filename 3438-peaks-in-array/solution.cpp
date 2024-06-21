#include <bits/stdc++.h>
#include <functional>
using namespace std;




class Solution {
public:
    static bool isPeak(const vector<int> &nums, int i) {
        if(i <= 0 or i >= nums.size()-1) {
            return false;
        }

        return nums[i-1] < nums[i] and nums[i] > nums[i+1];
    }

    class SegTree {
        public:
        vector<int> seg, lazy;
        function<int(int, int)> updateFunc;

        SegTree(function<int(int, int)> u, int n) {
            seg = vector<int>(4 * n, 0);
            this->updateFunc = u;
        }

        void build(int i, int l, int h, vector<int> &arr) {
            if (l == h) {
            seg[i] = isPeak(arr, l);
            return;
            }

            int mid = l + (h - l) / 2;

            build(2 * i + 1, l, mid, arr);
            build(2 * i + 2, mid + 1, h, arr);

            seg[i] = updateFunc(seg[2 * i + 1], seg[2 * i + 2]);
        }

        int query(int i, int l, int h, int ql, int qh, int base = 0) {
            if (l > qh || h < ql) {
            return base;
            }

            if (l >= ql && h <= qh) {
            return seg[i];
            }

            int mid = l + (h - l) / 2;

            return updateFunc(query(2 * i + 1, l, mid, ql, qh, base),
                            query(2 * i + 2, mid + 1, h, ql, qh, base));
        }

        void update(int i, int l, int h, int idx, int val) {
            if (l == h) {
            seg[i] = val;
            return;
            }

            int mid = l + (h - l) / 2;

            if (idx <= mid) {
            update(2 * i + 1, l, mid, idx, val);
            } else {
            update(2 * i + 2, mid + 1, h, idx, val);
            }

            seg[i] = updateFunc(seg[2 * i + 1], seg[2 * i + 2]);
        }

        void rangeUpdate(int i, int low, int high, int l, int r, int val) {
            if (lazy[i] != 0) {
                seg[i] += (high - low + 1) * lazy[i];

                if (low != high) {
                lazy[2 * i + 1] += lazy[i];
                lazy[2 * i + 2] += lazy[i];
                }

                lazy[i] = 0;
            }

            if (r < low || l > high || low > high) {
                return;
            }

            if (l <= low && r >= high) {
                seg[i] += (high - low + 1) * val;

                if (low != high) {
                lazy[2 * i + 1] += val;
                lazy[2 * i + 2] += val;
                }

                return;
            }

            int mid = low + (high - low) / 2;

            rangeUpdate(2 * i + 1, low, mid, l, r, val);
            rangeUpdate(2 * i + 2, mid + 1, high, l, r, val);
            seg[i] = updateFunc(seg[2 * i + 1], seg[2 * i + 2]);
        }

        int queryLazy(int i, int low, int high, int l, int r, int val, int base = 0) {
            if (lazy[i] != 0) {
                seg[i] += (high - low + 1) * lazy[i];

                if (low != high) {
                lazy[2 * i + 1] += lazy[i];
                lazy[2 * i + 2] += lazy[i];
                }

                lazy[i] = 0;
            }

            if (r < low || l > high || low > high) {
                return base;
            }

            if (l <= low && r >= high) {
                return seg[i];
            }

            int mid = low + (high - low) / 2;

            int lq = queryLazy(2 * i + 1, low, mid, l, r, val, base);
            int rq = queryLazy(2 * i + 2, mid + 1, high, l, r, val, base);

            return updateFunc(lq, rq);
        }
    };


    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& q) {
        SegTree* s = new SegTree([](const int a, const int b){
            return a + b;
        }, nums.size());

        int n = nums.size();

        // for(int i=1; i<n-1; i++) {
        //     if(nums[i-1] < nums[i] and nums[i] > nums[i+1]) {
        //         s->update(0, 0, n-1, i, 1);
        //     }
        // }

        s->build(0, 0, n-1, nums);

        int m = q.size();

        vector<int> ans;

        for(int i=0; i<m; i++) {
            if(q[i][0] == 1) {
                int l = q[i][1];
                int r = q[i][2];

                if(l == r) {
                    ans.push_back(0);
                    continue;
                }

                if(r - l <= 1) {
                    ans.push_back(0);
                    continue;
                } 


                int nos = s->query(0, 0, n-1, l+1, r-1, 0);

                ans.push_back(nos);
            } else {
                int idx = q[i][1];
                int val = q[i][2];

                nums[idx] = val;
                if(idx > 0) {
                    s->update(0, 0, n-1, idx-1, isPeak(nums, idx-1));
                } 

                s->update(0, 0, n-1, idx, isPeak(nums, idx));

                if(idx < n - 1) {
                    s->update(0, 0, n-1, idx+1, isPeak(nums, idx+1));
                } 
            }
        }

        return ans;
    }
};
