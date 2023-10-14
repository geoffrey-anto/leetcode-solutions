class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        int n = words.size();
        
        vector<string> nums;
        vector<string> nums_rev;
        int prev_cnt = 0;
        
//         for(auto &i: words) {
//             if(i == "prev"){
//                 prev_cnt++;
//             } else {
//                 nums.push_back(i);
//                 nums_rev.insert(nums_rev.begin(),i);
//             }
            
//         }
        
        vector<int> ans;
        int c = 0;
        
        for(int i=0; i<n; i++) {
            if(words[i] == "prev") {
                c++;
                if(c > nums_rev.size()) {
                    ans.push_back(-1);
                } else {
                    ans.push_back(stoi(nums_rev[c-1]));
                }
            } else {
                nums.push_back(words[i]);
                nums_rev.insert(nums_rev.begin(),words[i]);
                c = 0;
            }
        }
        
        return ans;
        
    }
};
