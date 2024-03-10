class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = accumulate(begin(apple), end(apple), 0);
        
        sort(capacity.begin(), end(capacity), greater<int>());
        int i = 0;
        
        while(sum > 0 && i < capacity.size()) {
            if(sum >= capacity[i]) {
                sum -= capacity[i];
                i++;
            } else {
                int c = capacity[i];
                
                capacity[i] -= sum;
                
                sum -= c;
                
                i++;
            }
        }
        
        return i;
    }
};
