class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stack;
        int n=pushed.size();
        int j = 0;
        for (auto x: pushed) {
            stack.push(x);
            while (!stack.empty() && j < n && stack.top() == popped[j]) {
                stack.pop();
                j++;
            }
        }
        return stack.empty();
    }
};
