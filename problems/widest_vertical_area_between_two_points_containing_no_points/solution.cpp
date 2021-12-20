class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int mx=0;
        for(int i=0;i<points.size()-1;i++){
            int temp=points[i+1][0]-points[i][0];
            mx=max(mx,temp);
        }
        return mx;
    }
};