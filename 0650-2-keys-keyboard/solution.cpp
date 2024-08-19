class Solution {
private:
    int targetLength;
    vector<vector<int>> cache;

    int calculateMinOps(int currentLength, int clipboardLength) {
        if (currentLength == targetLength) return 0;
        if (currentLength > targetLength) return INT_MAX / 2;

        if (cache[currentLength][clipboardLength] != -1) {
            return cache[currentLength][clipboardLength];
        }

        int pasteOption = 1 + calculateMinOps(currentLength + clipboardLength, clipboardLength);
        int copyPasteOption = 2 + calculateMinOps(currentLength * 2, currentLength);

        int result = min(pasteOption, copyPasteOption);
        cache[currentLength][clipboardLength] = result;

        return result;
    }

public:
    int minSteps(int n) {
        if (n == 1) return 0;
        targetLength = n;
        cache = vector<vector<int>>(n + 1, vector<int>(n / 2 + 1, -1));
        return 1 + calculateMinOps(1, 1);
    }
};

