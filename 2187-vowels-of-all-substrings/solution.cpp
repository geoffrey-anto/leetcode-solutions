class Solution {
public:
    bool isvowel(char v) {
        return (0x208222>>(v&0x1f))&1;
    }
    long long countVowels(string word) {
        long long ans = 0;

        for(int i=0; i<word.size(); i++) {
            if(isvowel(word[i])) {
                ans += ( (i - 0 + 1) * (word.size()-1 - i + 1) );
            }
        }

        return ans;
    }
};
