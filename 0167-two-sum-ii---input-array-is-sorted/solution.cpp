class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(auto it=numbers.begin(); it != numbers.end(); it++) 
            if(binary_search(it+1, end(numbers), target - *it)) 
                return {(int)(it - numbers.begin()) + 1, (int)(find(it+1, end(numbers), target - *it) - begin(numbers)) + 1};

        return {-1, -1};
    }
};
