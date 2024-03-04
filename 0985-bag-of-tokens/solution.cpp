class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(begin(tokens), end(tokens));

        if(!tokens.size()) {
            return 0;
        }

        if(power < tokens[0]) {
            return 0;
        }

        int currPower = power;
        int score = 0;

        int i=0;
        int j=tokens.size()-1;

        while(i<=j) {
            if(i == j) {
                if(currPower >= tokens[i]) {
                    score++;
                }
                i++;
                j--;
            } else {
                if(currPower >= tokens[i]) {
                    score++;
                    currPower -= tokens[i];
                    i++;
                } else if(score >= 1) {
                    currPower += tokens[j];
                    score--;
                    j--;
                } else {
                    break;
                }
            }
        }

        return score;
    }
};
