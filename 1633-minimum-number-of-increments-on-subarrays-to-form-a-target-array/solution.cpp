class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int curr = target[0];

        int n = target.size();

        for(int i=0; i<n-1; i++) {
            if(target[i] > target[i+1]) {
                continue;
            } else if(target[i] == target[i+1]) {
                continue;
            } else {
                curr += target[i+1] - target[i];
            }
        }

        return curr;
    }
};
