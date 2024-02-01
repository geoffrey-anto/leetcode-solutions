class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        // Basically BFS on all the avail boxes
        // if found keys add the num to queue
        
        queue<int> q;
        vector<bool> notSeen(candies.size(), false);

        for(auto &i: initialBoxes) {
            if(status[i] == 1) {
                q.push(i);
            } else {
                notSeen[i] = true;
            }
        }


        int sum = 0;

        while(!q.empty()) {
            auto front = q.front();
            q.pop();

            sum += candies[front];

            for(auto &i: keys[front]) {
                if(status[i] == 0 && notSeen[i]) {
                    q.push(i);
                }
                status[i] = 1;
            }

            for(auto &i: containedBoxes[front]) {
                if(status[i] == 1) {
                    q.push(i);
                } else {
                    notSeen[i] = true;
                }
            }

        }

        return sum;
    }
};
