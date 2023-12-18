# Car Fleet

## Leetcode Link: [Car Fleet](https://leetcode.com/problems/car-fleet/)
### Language: C++

```cpp
struct Car {
    int pos;
    int speed;
    float time;
};

typedef struct Car Car;

bool cmp(Car a, Car b) {
    if(a.pos == b.pos) return a.time > b.time;
    return a.pos < b.pos;
} 

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<Car> arr;
        int n = position.size();
        for(int i=0; i<n; i++) {
            Car s = Car();
            s.pos = position[i];
            s.speed = speed[i];
            s.time = ((target - position[i]) / (float)speed[i]);
            arr.push_back(s);
        }
        sort(arr.begin(), arr.end(), cmp);
        for(auto i: arr) cout << i.time <<endl;
        int no = 0;
        bool isGrp = false;
        int i = n-1;
        while(i>=0) {
            no++;
            auto temp = arr[i].time;
            while(--i>=0 && arr[i].time <= temp) {
                continue;
            }
        }
        return no;
    }
};```



