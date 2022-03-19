class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int x=coins;
        int ans=0;
        for(int &cost:costs){
            if(cost>x){
                break;
            }
            x-=cost;
            ans++;
        }
        return ans;
    }
};
