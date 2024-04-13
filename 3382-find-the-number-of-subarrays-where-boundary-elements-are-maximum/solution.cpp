// // #include <ext/pb_ds/assoc_container.hpp> 
// // #include <ext/pb_ds/tree_policy.hpp> 
// // using namespace __gnu_pbds; 
  
// // #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

// // class Solution {
// // public:
// //     long long numberOfSubarrays(vector<int>& nums) {
// //         // maybe start from end nd check which a ordered_set
// //         // the no of subsarrays is the count of the elements to the right
        
// //         multiset<int> s;
        
// //         long long ans = 0ll;
        
// //         for(auto i=nums.size()-1; i>=0; i--) {
// //             int cnt = s.count(nums[i]);
            
// //             ans += (long long)cnt + 1ll;
            
// //             s.insert(nums[i]);
// //         }
        
// //         return ans;
// //     }
// // };

// struct node {
//     int minimum;
//     int maximum;
// };

// class Solution {
// public:
//     int getMid(int s, int e) { return s + (e - s) / 2; }

//     struct node MaxMinUntill(struct node* st, int ss, int se,
//                              int qs, int qe, int index)
//     {
//         struct node tmp, left, right;
//         if (qs <= ss && qe >= se)
//             return st[index];

//         if (se < qs || ss > qe) {
//             tmp.minimum = INT_MAX;
//             tmp.maximum = INT_MIN;
//             return tmp;
//         }

//         int mid = getMid(ss, se);
//         left = MaxMinUntill(st, ss, mid, qs, qe, 2 * index + 1);
//         right = MaxMinUntill(st, mid + 1, se, qs, qe,
//                              2 * index + 2);
//         tmp.minimum = min(left.minimum, right.minimum);
//         tmp.maximum = max(left.maximum, right.maximum);
//         return tmp;
//     }

//     struct node MaxMin(struct node* st, int n, int qs, int qe)
//     {
//         struct node tmp;

//         if (qs < 0 || qe > n - 1 || qs > qe) {
//             tmp.minimum = INT_MAX;
//             tmp.maximum = INT_MIN;
//             return tmp;
//         }

//         return MaxMinUntill(st, 0, n - 1, qs, qe, 0);
//     }

//     void constructSTUtil(int arr[], int ss, int se,
//                          struct node* st, int si)
//     {
//         if (ss == se) {
//             st[si].minimum = arr[ss];
//             st[si].maximum = arr[ss];
//             return;
//         }

//         int mid = getMid(ss, se);
//         constructSTUtil(arr, ss, mid, st, si * 2 + 1);
//         constructSTUtil(arr, mid + 1, se, st, si * 2 + 2);

//         st[si].minimum = min(st[si * 2 + 1].minimum,
//                              st[si * 2 + 2].minimum);
//         st[si].maximum = max(st[si * 2 + 1].maximum,
//                              st[si * 2 + 2].maximum);
//     }

//     struct node* constructST(int arr[], int n)
//     {
//         int x = (int)(ceil(log2(n)));

//         int max_size = 2 * (int)pow(2, x) - 1;

//         struct node* st = new struct node[max_size];

//         constructSTUtil(arr, 0, n - 1, st, 0);

//         return st;
//     }
    
//     long long numberOfSubarrays(vector<int>& nums) {
//         int arr[nums.size()];
//         for(int i=0; i<nums.size(); i++) {
//             arr[i] = nums[i];
//         }
        
//         struct node* st = constructST(arr, nums.size());
        
//         long long res = (long long)nums.size();
        
//         for(int i=0; i<n; i++) {
            
//         }
        
//         return 0ll;
//     }
// };


















class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        vector<pair<int, int>> st;
        long long ans = 0;

        for(int i=0; i<nums.size(); i++) {
            while(!st.empty() && st.back().first < nums[i]) {
                st.pop_back();
            }

            if(st.empty() or st.back().first > nums[i]) {
                st.push_back({nums[i], 0});
            } 

            ans += st.back().second + 1ll;

            st[st.size() - 1].second++;
        }

        return ans;
    }
};
