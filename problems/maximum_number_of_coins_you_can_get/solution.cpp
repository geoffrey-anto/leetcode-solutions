class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        reverse(piles.begin(),piles.end());
        int n=piles.size();
        int sum=0;
        int x=n/3;
        for(int i=0;i<n-x;i=i+2){
            sum=sum+piles[i+1];
        }
        return sum;
    }
};