class Solution {
public:
    vector<vector<int>> mem;
    void perm(vector<int> x, int i, int l){
        if(x.size()==i){
            mem.push_back(x);
            return;
        }
        for(int j=i;j<=l;j++){
            swap(x[i],x[j]);
            perm(x,i+1,l);
            swap(x[j],x[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        perm(nums, 0, nums.size()-1);
        return mem;
    }
};