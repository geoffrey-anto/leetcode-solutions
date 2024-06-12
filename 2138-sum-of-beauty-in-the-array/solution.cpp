class SegTree {
public:
    int seg[4 * (int)1e5];
    function<int(int, int)> updateFunc;

    SegTree(function<int(int, int)> u) {
        memset(seg, 0, sizeof(seg));
        this->updateFunc = u;
    }

    void build(int i, int l, int h, vector<int>& arr) {
        if (l == h) {
            seg[i] = arr[l];
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
};

class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        SegTree* maxTree = new SegTree([&](int a, int b) { return max(a, b); });

        SegTree* minTree = new SegTree([&](int a, int b) { return min(a, b); });

        maxTree->build(0, 0, n - 1, nums);
        minTree->build(0, 0, n - 1, nums);

        bool flg = false;
        int cnt1 = 0, cnt2 = 0;

        for (int i = 1; i < n - 1; i++) {
            int lMax = maxTree->query(0, 0, n - 1, 0, i - 1, INT_MIN);
            int rMin = minTree->query(0, 0, n - 1, i + 1, n - 1, INT_MAX);

            if (lMax < nums[i] and rMin > nums[i]) {
                cnt1 += 2;
            } else if (nums[i - 1] < nums[i] and nums[i] < nums[i + 1]) {
                cnt1++;
            }
        }

        return cnt1;
    }
};
