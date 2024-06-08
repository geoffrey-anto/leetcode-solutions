class Solution {
public:
    vector <int> nextGreaterElements(vector < int > & nums) {
      int n = nums.size();
      vector <int> nge(n, -1);
      stack <int> st;
      for (int i = 2 * n - 1; i >= 0; i--) {
        while (!st.empty() && nums[st.top()] <= nums[i % n]) {
          st.pop();
        }

        if (i < n) {
          if (!st.empty()) nge[i] = st.top();
        }
        st.push(i % n);
      }
      return nge;
    }

    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size();
//         vector<int> nge = nextGreaterElements(skills);
        
//         for(auto i: nge) {
//             cout << i << " ";
//         }
        
//         cout << endl;
        
        
        int curr = 0;
        int cnt = 0;

        for (int i = 1; i < n; ++i) {
            if (skills[curr] <= skills[i]) {
               
                if (1 == k) {
                    return i;
                }
                
                curr = i;
                cnt = 1;
            } else {
                 if (cnt+1 == k) {
                    return curr;
                }
                cnt++;
            }
        }

        return curr;
//         return 0;
    }
};
