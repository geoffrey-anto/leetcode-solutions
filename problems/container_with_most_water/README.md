# Container With Most Water

## Leetcode Link: [Container With Most Water](https://leetcode.com/problems/container-with-most-water/)
### Language: C++

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int max_height=0;
        while(l<r){
            max_height=max(max_height, min(height[l],height[r])*abs(l-r));
            if(height[l]<height[r]){
                l++;
            } else {
                r--;
            }
        }
        return max_height;
    }
};


```



