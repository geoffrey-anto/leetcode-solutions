class Solution {
public:
    bool isValid(string word) {
        if(word.size() < 3) {
            return false;
        }
        
        int vC = 0;
        int cC = 0;
        
        for(auto i: word) {
            if(i == '@' or i == '#' or i == '$') {
                return false;
            }
            
            if(i >= '0' and i <= '9') {
                continue;
            }
            
            char li = tolower(i);
            if(li == 'a' or li == 'e' or li == 'i' or li == 'o' or li =='u') {
                vC++;
            } else {
                cC++;
            }
        }
        
        if(vC < 1 or cC < 1) {
            return false;
        }
        
        return true;
    }
};
