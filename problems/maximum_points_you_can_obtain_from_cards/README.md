# Maximum Points You Can Obtain From Cards

## Leetcode Link: [Maximum Points You Can Obtain From Cards](https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/)
### Language: C++

```cpp
// class Solution {
// public:
//     int maxScore(vector<int>& arr, int k) {
//         int n = arr.size();
//         int sum = 0;
//         for(auto& i: arr) {
//             sum += i;
//         }

//         // if same size we need all the elements and so return totalsum
//         if(n==k) {
//             return sum;
//         }

//         int noToElim = k;

//         vector<int> preSumLeft(n+1, 0);
//         vector<int> preSumRight(n+1, 0);

//         for(auto i = 1; i < (n+1); i++) {
//             preSumLeft[i] = preSumLeft[i-1] + arr[i-1]; 
//         }

//         for(auto i = n-1; i >= 0; i--) {
//             preSumRight[n-i] = preSumRight[n-i-1] + arr[i]; 
//         }

//         while (k>0) {

//         }
        
//         return -1;
//     }
// };


class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n = arr.size();
        int sum = 0;
        for(int i=0; i<k; i++) {
            sum += arr[i];
        }

        int mx = sum;

        for(int i=k-1; i>=0; i--) {
            sum -= arr[i];
            sum += arr[n-k+i];
            mx = max(mx, sum);
        }

        return mx;
    }
};```



