#include <bits/stdc++.h>
// #include <functional>
// using namespace std;

// class SegTreeLazy {
// public:
//   vector<int> seg;
//   function<int(int, int)> updateFunc;
//   int n = 0;

//   SegTreeLazy(function<int(int, int)> u, int n) {
//     seg = vector<int>(4 * n, 0);
//     this->n = n;
//     this->updateFunc = u;
//   }

//   void build(int i, int l, int h) {
//     if (l == h) {
//       seg[i] = 1;
//       return;
//     }

//     int mid = l + (h - l) / 2;

//     build(2 * i + 1, l, mid);
//     build(2 * i + 2, mid + 1, h);

//     seg[i] = updateFunc(seg[2 * i + 1], seg[2 * i + 2]);
//   }

//   int query(int i, int l, int h, int ql, int qh, int base = 0) {
//     if (l > qh || h < ql) {
//       return base;
//     }

//     if (l >= ql && h <= qh) {
//       return seg[i];
//     }

//     int mid = l + (h - l) / 2;

//     return updateFunc(query(2 * i + 1, l, mid, ql, qh, base),
//                       query(2 * i + 2, mid + 1, h, ql, qh, base));
//   }

//   void update(int i, int l, int h, int idx, int val) {
//     if (l == h) {
//       seg[i] = val;
//       return;
//     }

//     int mid = l + (h - l) / 2;

//     if (idx <= mid) {
//       update(2 * i + 1, l, mid, idx, val);
//     } else {
//       update(2 * i + 2, mid + 1, h, idx, val);
//     }

//     seg[i] = updateFunc(seg[2 * i + 1], seg[2 * i + 2]);
//   }
// };

// class Solution {
// public:
//     vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
//         SegTreeLazy* seg = new SegTreeLazy([](const int a, const int b) {
//             return a + b;
//         }, n);

//         seg->build(0, 0, n-1);

//         vector<int> ans;

//         for(auto &q: queries) {
//             for(int i=q[0]+1; i<=q[1]-1; i++) {
//                 seg->update(0, 0, n-1, i, 0);
//             }

//             ans.push_back(seg->query(0, 0, n-1, 0, n-1, 0) - 1);
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        set<int> s;

        for(int i=0; i<n; i++) {
            s.insert(i);
        }

        vector<int> ans;

        for(auto &i: queries) {
            s.erase(s.lower_bound(i[0] + 1), s.upper_bound(i[1] - 1));

            ans.push_back(s.size() - 1);
        }

        return ans;
    }
};
