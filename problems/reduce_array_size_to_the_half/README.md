# Reduce Array Size To The Half

## Leetcode Link: [Reduce Array Size To The Half](https://leetcode.com/problems/reduce-array-size-to-the-half/)
### Language: C++

```cpp
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> map;
        for(auto &i:arr){
            if(map.find(i)==map.end()){
                map[i]=1;
            } else {
                map[i]++;
            }
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>> pq;
        for(auto& i:map){
            pq.push(make_pair(i.second,i.first));
        }
        int ans=arr.size();
        int n=arr.size()/2;
        int x=0;
        while(ans>n){
            auto i=pq.top();
            pq.pop();
            ans-=i.first;
            x++;
        }
        return x;
    }
};```



