# Defanging An Ip Address

## Leetcode Link: [Defanging An Ip Address](https://leetcode.com/problems/defanging-an-ip-address/)
### Language: C++

```cpp
class Solution {
public:
    string defangIPaddr(string address) {
        string ans="";
        for(int i=0;i<address.size();i++){
            if('.'==address[i]){
                ans=ans+"[.]";
            } else {
                ans=ans+address[i];
            }
        }
        return ans;
    }
};```



