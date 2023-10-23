class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        
        int res = 0;
        
        for(int i=cost.size()-1;i>=0;i-=3){
            res += cost[i];
            if(i > 0){
                res += cost[i-1];
            }
        }
        
        return res;
    }
};