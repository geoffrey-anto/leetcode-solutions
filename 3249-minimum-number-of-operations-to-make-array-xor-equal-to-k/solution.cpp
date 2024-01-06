class Solution {
private:
    int countBits(int number) 
    {     
        return (int)log2(number)+1; 
    } 
public:
    int minOperations(vector<int>& nums, int k) {
        // take bits in k
        // to take the xor of the values
        
        // xor => 1 ^ 1 = 0 ; Opposite is 1 else 0
        
        // if i have to get the ith bit of k we have to make the no of ith bits all nos with eq 0 and 1 if the ith bit of k is 1
        
        // so just compare all the bits ;
        
        // ig i can pad all the bits with 0 MSB's
        
        int x = nums[0];

        int n = size(nums);

        for(int i=1; i<n; i++) {
            x = x ^ nums[i];
        }

        string xs = bitset<64>(x).to_string();
        string ks = bitset<64>(k).to_string();

        int m = min(xs.size(), ks.size());

        int ans = 0;

        for(int i=0; i<m; i++) {
            if(xs[i] != ks[i]) {
                ans++;
            }
        }

        if(ks.size() != xs.size()) {
            int rem = max(xs.size(), ks.size()) - min(xs.size(), ks.size());
            ans += rem;
        }

        return ans;
    }
};
