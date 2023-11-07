class Solution {
public:
    int leastInterval(vector<char>& tasks, int k) {
        int arr[26];
        memset(arr, -1, sizeof(arr));
        int n = tasks.size();
        for(int i=0; i<n; i++) {
            arr[tasks[i] - 'A']++;
        }

        priority_queue<pair<int, char>> pq;
        for(int i=0; i<26; i++) {
            int val = arr[i];
            if(arr[i] == -1) {
                continue;
            } else {
                pq.push(make_pair(val+1, (char)(65+i)));
            }
        }


        int cnt = 0;
        while(pq.size() > 0) {
            // curr top element
            auto currTop = pq.top();
            if(currTop.first == 1) {
                cnt += pq.size();
                break;
            }
            cnt++;
            vector<pair<int, char>> temp;
            temp.push_back(currTop);
            pq.pop();

            for(int i=0; i<k; i++) {
                if(!pq.empty()) {
                    temp.push_back(pq.top());
                    pq.pop();
                }
                cnt++;
            }

            for(auto& t: temp) {
                if(t.first > 1) {
                    pq.push(make_pair(t.first-1, t.second));
                }
            }
        }
        return cnt;
    }
};