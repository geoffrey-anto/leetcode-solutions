class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0;
        int mxCnt = 0;
        for(auto &i: s) {
            if (i != '(' and i != ')') {
                continue;
            } else {
                if (i == '(') {
                    cnt++;
                } else {
                    cnt--;
                }
                mxCnt = max(mxCnt, cnt);
            }
        }

        return mxCnt;
    }
};