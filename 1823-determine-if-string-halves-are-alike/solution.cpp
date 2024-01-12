class Solution {
private:
    bool isVovel(char x)
    {
        if (x == 'a' || x == 'e' || x == 'i' || x == 'o'
            || x == 'u' || x == 'A' || x == 'E' || x == 'I'
            || x == 'O' || x == 'U')
            return true;
        else
            return false;
    }
public:
    bool halvesAreAlike(string s) {
        int c1 = 0, c2 = 0;

        int n = s.size();

        for(int i=0; i<n/2; i++) {
            if(isVovel(s[i])) {
                c1++;
            }
        }

        for(int i=n/2; i<n; i++) {
            if(isVovel(s[i])) {
                c2++;
            }
        }

        return c1 == c2;
    }
};
