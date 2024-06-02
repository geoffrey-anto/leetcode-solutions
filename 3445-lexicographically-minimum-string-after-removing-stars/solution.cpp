class Compare {
public:
    bool operator()(pair<char, int> below, pair<char, int> above)
    {
        if (below.first > above.first) {
            return true;
        }
        else if (below.first == above.first
                 && below.second < above.second) {
            return true;
        }
 
        return false;
    }
};

class Solution {
public:
    string clearStars(string s) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, Compare> pq;

        for(int i=0; i<s.size(); i++) {
            if(s[i] == '*') {
                pq.pop();
            } else {
                pq.push({s[i], i});
            }
        }

        string ans = "";

        vector<pair<char, int>> v;

        while(!pq.empty()) {
            v.push_back(pq.top());
            pq.pop();
        }

        sort(begin(v), end(v), [&](auto &a, auto &b){
            return a.second < b.second;
        });

        for(auto &i: v) {
            ans += i.first;
        }

        return ans;
    }
};
