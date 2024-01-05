class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int left = 0, right = 1000, s = grades.size();
        while (left < right) {
            int k = (left + right + 1) / 2;
            if (k * (k + 1) / 2 > s) {
                right = k - 1;
            } else {
                left = k;
            }
        }
        return left;

        int ans = 0;

        int prevSum = 0;
        int prevSize = 0;

        sort(grades.begin(), grades.end());

        prevSum = grades[0];
        prevSize = 1;
        int n = grades.size();

        for(int i=1; i<n; i++) {
            int s = 0;
            int c = 0;

            if(prevSize + i >= n) {
                return prevSize;
            }
    
            for(int j = 0; j<prevSize+1; j++) {
                c++;
                s += grades[i+j];
            }


            prevSize = c;
            prevSum = s;
        }

        return prevSize;
    }
};
