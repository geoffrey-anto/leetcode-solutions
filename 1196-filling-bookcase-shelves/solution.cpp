class Solution {
public:
    int f(int i, vector<vector<int>>& books, int shelfWidth, vector<int> &dp) {
        if(i == books.size()) {
            return 0;
        }

        if(dp[i] != -1) {
            return dp[i];
        }

        int ans = 1e8;

        int currMaxHeight = 0;
        int currWidth = 0;

        for(int j=i; j<books.size(); j++) {
            if(currWidth + books[j][0] <= shelfWidth) {
                currMaxHeight = max(currMaxHeight, books[j][1]);
                currWidth += books[j][0];
                ans = min(ans, currMaxHeight + f(j+1, books, shelfWidth, dp));
            } else {
                break;
            }
        }

        return dp[i] = ans;
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        vector<int> dp(books.size()+2, 0);

        for(int i=books.size()-1; i>=0; i--) {
            int ans = 1e8;

            int currMaxHeight = 0;
            int currWidth = 0;

            for(int j=i; j<books.size(); j++) {
                if(currWidth + books[j][0] <= shelfWidth) {
                    currMaxHeight = max(currMaxHeight, books[j][1]);
                    currWidth += books[j][0];
                    ans = min(ans, currMaxHeight + dp[j+1]);
                } else {
                    break;
                }
            }

            dp[i] = ans;
        }

        return dp[0];
        // return f(0, books, shelfWidth, dp);    
    }
};
