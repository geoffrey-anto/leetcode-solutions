class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end(), greater<int>());
        int l=0;
        int n=people.size();
        int r=n-1;
        int c=0;
        while(l<=r){
            if(people[l]+people[r]<=limit){
                c++;
                l++;
                r--;
            } else {
                c++;
                l++;
            }
        }
        return c;
    }
};
