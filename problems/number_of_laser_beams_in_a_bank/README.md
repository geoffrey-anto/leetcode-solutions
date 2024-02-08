# Number Of Laser Beams In A Bank

## Leetcode Link: [Number Of Laser Beams In A Bank](https://leetcode.com/problems/number-of-laser-beams-in-a-bank/)
### Language: Python

```py
class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        mx = 0
        l=[]
        l=[i.count('1') for i in bank if i.count('1') != 0]
        if len(l) == 1:
            return 0;
        else:
            mx=0
            for i in range(len(l)-1):
                mx=mx+l[i]*l[i+1]
            return mx
        return -1```



# Number Of Laser Beams In A Bank

## Leetcode Link: [Number Of Laser Beams In A Bank](https://leetcode.com/problems/number-of-laser-beams-in-a-bank/)
### Language: C++

```cpp
class Solution {
public:
    int getNoOfOnes(string &arr) {
        int cnt = 0;
        for(char i: arr) {
            if(i == '1') cnt++;
        }

        return cnt;
    }

    int numberOfBeams(vector<string>& bank) {
        vector<int> preCompute;
        int n = bank.size(), ans = 0;
        for(auto &i: bank) {
            int v = getNoOfOnes(i);
            if(v == 0) {
                continue;
            }
            preCompute.push_back(v);
        }

        if(preCompute.size() == 0){
            return 0;
        }

        if(preCompute.size() == 1) {
            return 0;
        }

        for(int i=0; i<preCompute.size()-1; i++) {
            ans += preCompute[i] * preCompute[i+1];
        }
        return ans;
    }
};```



