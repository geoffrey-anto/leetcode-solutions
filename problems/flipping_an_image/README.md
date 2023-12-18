# Flipping An Image

## Leetcode Link: [Flipping An Image](https://leetcode.com/problems/flipping-an-image/)
### Language: C++

```cpp
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(auto &i:image){
            reverse(i.begin(),i.end());
            for(auto &j:i){
                if(j==0){
                    j=1;
                } else {
                    j=0;
                }
            }
        }
        return image;
    }
};```



