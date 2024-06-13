class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(begin(seats), end(seats));
        sort(begin(students), end(students));

        int ans = 0;

        for(auto i=0; i<students.size(); i++) {
            ans += abs(students[i] - seats[i]);
        }

        return ans;
    }
};
