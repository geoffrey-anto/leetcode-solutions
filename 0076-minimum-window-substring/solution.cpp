struct Ans {
    int left;
    int right;
};

class Solution {
public:
    bool find(unordered_map<char, int> &map, char x) {
        return map.find(x) != map.end();
    }
    string minWindow(string s, string t) {
        // we cant have a string t greater than s... since duplicated are also counted
        if (s.size() < t.size()) return "";
        int n = s.size();
        int m = t.size();
        unordered_map<char, int> t_map;
        unordered_map<char, int> s_map;

        for(char i: t) {
            t_map[i]++;
        }

        // Pointers to interate the windows
        int left = 0;
        int right = 0;

        int cnt = 0;

        // Global minimum size
        int globalMin = INT_MAX;

        // To store the window containing the answer
        struct Ans ans;
        ans.left = -1;
        ans.right = -1;
        

        for(right = 0; right < n; right++) {
            s_map[s[right]]++;

            // Check if the s[right] is in t... if its there and present correct amt of times
            // update cnt as +1
            if(find(t_map, s[right]) and s_map[s[right]] == t_map[s[right]]) {
                cnt++;
            }

            // this means that all the elements are there in the window
            while (cnt == t_map.size()) {
                int currSize = right - left + 1;

                // Update ig a min found
                if(currSize < globalMin) {
                    globalMin = currSize;
                    ans.left = left;
                    ans.right = right;
                }

                // now remove the rear end element from window
                s_map[s[left]]--;

                // Check if the rear end is in the t string
                // If yes check if the new value is not accepted, i.e, if the cound of s[left] is
                // less than the one in the t string
                // if less reduce the count.. this tells more elements is need to completet string 
                if(find(t_map, s[left])) {
                    if(s_map[s[left]] < t_map[s[left]]) {
                        cnt--;
                    }
                }

                left++;
            }
   
          
        }

        // This means no subarray is found
        if(ans.left == -1 || ans.right == -1) {
            return "";
        }

        int subStrSize = ans.right - ans.left + 1;

        return s.substr(ans.left, subStrSize);
    }
};
