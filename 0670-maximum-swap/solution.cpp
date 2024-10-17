// class Solution {
// public:
//     int maximumSwap(int num) {
//         string s = to_string(num);

//         int mx = s.size() - 1;
//         int mn = s.size() - 1;

//         for(int i=s.size()-1; i>=0; i--) {
//             int curr = s[i] - '0';

//             if(curr <= s[mn] - '0') {
//                 mn = i;
//             }

//             if(curr > s[mx] - '0') {
//                 mx = i;
//             }
//         }

//         cout << mx << " " << mn << endl;
//         cout << s[mx] << " " << s[mn] << endl;

//         if(mn < mx and s[mx] > s[mn]) {
//             swap(s[mx], s[mn]);
//         }

//         return stoi(s);
//     }
// };

class Solution {
public:
    int maximumSwap(int num) {
        string st = to_string(num);
        int n = st.size();
        priority_queue<pair<char, int>> pq;
        for(int i = 0; i < n; i++)
        {
            pq.push({st[i], i});
        }
        for(int j = 0; j < n; j++)
        {
            while(! pq.empty() && pq.top().second < j)
                pq.pop();
                if(pq.top().first > st[j])
                {
                    swap(st[j], st[pq.top().second]);
                    break;
                }            
        }
        return stoi(st);
    }
};
