class Solution {
public:
    float diagonal(float a, float b) {
        return sqrt((a*a) + (b*b));
    }
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        
        sort(dimensions.begin(), dimensions.end(), [&](auto a, auto b) {
            if(diagonal(a[0], a[1]) == diagonal(b[0], b[1])) {
                return a[0]*a[1] > b[0]*b[1];
            } else {
                return diagonal(a[0], a[1]) > diagonal(b[0], b[1]);
            }
        });
            
        return dimensions[0][0] * dimensions[0][1];
    }
};