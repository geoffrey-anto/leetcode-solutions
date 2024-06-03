// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 
  
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

// class Solution {
// public:
//     bool find132pattern(vector<int>& nums) {
//         ordered_set s;

//         for(auto i: nums) {
//             s.insert(i);

//             if(s.size() > 2) {
//                 int o = s.order_of_key(i);

//                 if(o != 0 and o != s.size()-1) {
//                     cout << i << endl;
//                     return true;
//                 }
//             }
//         }

//         return false;
//     }
// };

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3) {
            return false;
        }
        
        int prevMin = INT_MIN; 
        int potentialPeak = nums.size();
        
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] < prevMin) {
                return true;
            }
            
            while (potentialPeak < nums.size() && nums[i] > nums[potentialPeak]) {
                prevMin = nums[potentialPeak++];
            }
            
            potentialPeak--;
            
            nums[potentialPeak] = nums[i];
        }
        
        return false;
    }
};


