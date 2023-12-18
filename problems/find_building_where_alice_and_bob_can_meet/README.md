# Find Building Where Alice And Bob Can Meet

## Leetcode Link: [Find Building Where Alice And Bob Can Meet](https://leetcode.com/problems/find-building-where-alice-and-bob-can-meet/)
### Language: C++

```cpp
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& heights) {
        stack<int> st;
        set<int> arr;
        int n = heights.size();

        vector<int> nextGreater(n, -1);

        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && heights[st.top()] <= heights[i]) {
                st.pop();
            }

            if(!st.empty()) {
                arr.insert(st.top());
                nextGreater[i] = st.top();
            }

            st.push(i);
        }

        // for(auto i:arr) {
        //     cout << i << endl;
        // }

        cout<< endl;

        // for(auto i: nextGreater){
        //     cout << i << endl;
        // }

        return nextGreater;
    }
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        //  0  1  2  3  4  5
        // [6, 4, 8, 5, 2, 7];
        // [2, 2, -1, 5, 5, -1] // take this for Q and find the next greatest element
        // [0,1]
        // [0,3]
        // [2,4]
        // [3,4]
        // [2,2]

                int n = heights.size();

                vector<int> ans;

        auto nextGreater = nextGreaterElements(heights);

        for(auto q: queries) {
            int a = q[0];
            int b = q[1];
            if(a == b) {
                ans.push_back(a);
                continue;
            }

            if(a > b) {
                swap(a,b);
            }
            int xa = nextGreater[a];
            int xb = nextGreater[b];

            if(heights[a] < heights[b]) {
                ans.push_back(b);
                continue;
            }


            if(xa == -1 or xb == -1) {
                ans.push_back(-1);
                continue;
            }

            // if() {
            //     ans.push_back(xb);
            //     continue;
            // }


            while ( xb >= 0 && xb < n && heights[xb] <= heights[a] ) {
                if(xb >= 0 && xb < n) {
                    xb = nextGreater[xb];
                } else {
                    break;
                }
            }


        ans.push_back(xb);


        }

        return ans;
    }
};```



