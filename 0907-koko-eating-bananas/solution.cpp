#include<bits/stdc++.h>
class Solution {
public:
    int maximumval(vector<int>&piles){
        int n=piles.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(piles[i],maxi);
        }
        return maxi;
    }
    

    double calculatehrs(vector<int>&piles,int hourly){
        double totalh=0;
        int n=piles.size();
        for(int i=0;i<n;i++){
            totalh+=ceil((double)piles[i]/(double)hourly);
        }
        return totalh;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=0;
        int high=maximumval(piles);

        while(low<=high){
            int mid=(low+(high-low)/2);
            double totalh=calculatehrs(piles,mid);
            if(totalh<=h){  
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};
