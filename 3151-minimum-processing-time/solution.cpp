class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(tasks.begin(), tasks.end());
        sort(processorTime.begin(), processorTime.end());
        
        int idx = processorTime.size()-1;
        int currMx = 0;
        
        for(int i=1; i<tasks.size()+1; i++) {
            currMx = max(currMx, tasks[i-1]);
            
            if(i%4 == 0) {
                processorTime[idx] = processorTime[idx] + currMx;
                currMx = 0;
                idx--;
            }
        }
        
        return *max_element(begin(processorTime), end(processorTime));
    }
};
