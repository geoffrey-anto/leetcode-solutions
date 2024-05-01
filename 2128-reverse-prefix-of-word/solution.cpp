class Solution {
public:
    string reversePrefix(string word, char ch) {
        auto pos = find(begin(word), end(word), ch);

        if(pos == word.end()) {
            return word;
        }

        int p = pos - word.begin();

        string a = word.substr(0, p+1);

        reverse(begin(a), end(a));

        return a + word.substr(p+1, word.size() - (p+1));
    }
};
