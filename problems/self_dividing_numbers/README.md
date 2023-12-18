# Self Dividing Numbers

## Leetcode Link: [Self Dividing Numbers](https://leetcode.com/problems/self-dividing-numbers/)
### Language: C++

```cpp
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i=left;i<right+1;i++){
            int num = i;
            bool flg=true;
            while(num!=0){
                if(num%10!=0){
                    if((i%(num%10))==0){
                        num/=10;
                        continue;
                    } else {
                        flg = false;
                        num/=10;
                        break;
                    }
                } else {
                    flg=false;
                    break;
                }
                num/=10;
            }
            if(flg){
                ans.push_back(i);
            }
        }
        return ans;
    }
};```



