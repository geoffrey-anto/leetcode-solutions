class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto ub = upper_bound(begin(letters), end(letters), target);

        if(ub == end(letters)) {
            return letters[0];
        }

        return *ub;
    }
};
