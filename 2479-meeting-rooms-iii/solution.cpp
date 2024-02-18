class Solution {
    bool DEBUG = false;
public:
    int mostBooked(int n, vector<vector<int>>& m) {
        sort(m.begin(), m.end());

        if(DEBUG && false){
            for(auto &i: m) {
                printf("start: %d, end: %d\n", i[0], i[1]);
            }
        }

        priority_queue<long long, vector<long long>, greater<long long>> rooms;

        //                  end, roomno
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> used;

        vector<int> vis(n, 0);

        for(auto i=0; i<n; i++) {
            rooms.push(i);
        }

        for(int i=0; i<m.size(); i++) {
            int gEndTime, gRoomNo;

            // free rooms till start time
            while(used.size() != 0 && used.top().first <= m[i][0]) {
                // more rooms end at same time
                rooms.push(used.top().second);
                used.pop();
            }

            // no more avail to take
            if(rooms.size() == 0) {
                // take the most earliest room avail
                // get the end time
                // start the curr meeting at that time and push into queue with the same room no

                auto [endTime, roomNo] = used.top();
                used.pop();

                rooms.push(roomNo);

                long long startTimeOfMeeting = m[i][0];

                if(startTimeOfMeeting > endTime) {
                    endTime = startTimeOfMeeting;
                }

                long long duration = m[i][1] - m[i][0];

                used.push({
                    endTime+duration,
                    rooms.top()
                });

                gEndTime = endTime+duration;
                gRoomNo = rooms.top();

                vis[rooms.top()]++;

                rooms.pop();
            } else {
                // here there is a room available
                // get the smallest room and push the meeting into used
                long long duration = m[i][1] - m[i][0];
                long long endTime = m[i][0] + duration;

                auto roomNo = rooms.top();
                rooms.pop();

                gEndTime = endTime;
                gRoomNo = roomNo;

                used.push({
                    endTime,
                    roomNo,
                });

                vis[roomNo]++;
            }
            if(DEBUG && false)
                printf("Assigned Meeting: %d, With End Time: %d, To Room No: %d\n", i, gEndTime, gRoomNo);
        }

        if(DEBUG) {
            cout << used.size() << endl;
        }


        if(DEBUG) {
            cout << endl;
            for(int i=0; i<n; i++) {
                printf("RoomNo: %d, Visited: %d\n", i, vis[i]);
            }
        }

        int mx = -1;
        int mi = -1;

        for(int i=0; i<n; i++) {
            if(mx < vis[i]) {
                mx = vis[i];
                mi = i;
            }
        }

        return mi;
        
    }
};
