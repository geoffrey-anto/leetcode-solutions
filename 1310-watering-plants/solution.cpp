class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n=plants.size();
        int c=capacity;
        int steps=0;
        for(int i=0;i<n;i++){
            if(plants[i]<=c){
                c=c-plants[i];
                steps++;
            } else {
                steps=steps+(i*2)+1;
                c=capacity;
                c=c-plants[i];
            }
        }
        return steps;
    }
};
