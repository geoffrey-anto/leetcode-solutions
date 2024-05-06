class Solution {
public:
    bool winnerOfGame(string colors) {
        int cnt1 = 0;
        int cnt2 = 0;

        int n = colors.size();

        int b = 0;

        for(int i=0; i<n; i++) {
            if(i == 0) {
                b += (colors[i] == 'B');
                continue;
            }

            if(colors[i] == colors[i-1] and colors[i] == 'B') {
                b++;
            } else {
                if(b >= 3) {
                    cnt1 += (b - 2);
                }
                b = 0;

                if(colors[i] == 'B') {
                    b = 1;
                }
            }
        }

        if(b >= 3) {
            cnt1 += (b - 2);
        }

        b = 0;

        for(int i=0; i<n; i++) {
            if(i == 0) {
                b += (colors[i] == 'A');
                continue;
            }

            if(colors[i] == colors[i-1] and colors[i] == 'A') {
                b++;
            } else {
                if(b >= 3) {
                    cnt2 += (b - 2);
                }
                b = 0;

                if(colors[i] == 'A') {
                    b = 1;
                }
            }
        }

        if(b >= 3) {
            cnt2 += (b-2);
        }

        return cnt2 > cnt1;
    }
};
