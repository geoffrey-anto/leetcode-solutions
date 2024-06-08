class Solution {
public:
    string clearDigits(string s) {
        while (true) {
            bool foundDigit = false;

            for (int i = 0; i < s.length(); ++i) {
                if (isdigit(s[i])) {
                    foundDigit = true;
                    for (int j = i; j > 0; --j) {
                        if (!isdigit(s[j - 1])) {
                            s.erase(j - 1, 1);
                            break;
                        }
                    }
                    s.erase(i - 1, 1);
                    break;
                }
            }

            if (!foundDigit) break; 
        }
    
        return s;
    }
};
