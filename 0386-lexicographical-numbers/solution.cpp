class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        // Iterate over numbers 1 to 9 as root nodes
        for (int i = 1; i <= 9; ++i) {
            dfs(i, n, result);
        }
        return result;
    }
    
    // Helper function for DFS traversal
    void dfs(int curr, int n, vector<int>& result) {
        if (curr > n) return;  // Stop recursion if current number exceeds n
        result.push_back(curr); // Add current number to result
        
        // Try to generate the next lexicographical number
        for (int i = 0; i <= 9; ++i) {
            if (curr * 10 + i > n) break;  // If the number exceeds n, stop recursion
            dfs(curr * 10 + i, n, result); // Recursive call
        }
    }
};
