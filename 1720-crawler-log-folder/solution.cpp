class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;
        
        for(int i=0; i<logs.size(); i++) {
            auto& log = logs[i];
            
            if(log == "./") {
                continue;
            } else if(log == "../") {
                depth = max(0, depth-1);
            } else {
                depth++;
            }
        }
        
        return depth;
    }
};
