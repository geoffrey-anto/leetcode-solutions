class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int wl = beginWord.size();

        queue<pair<string, int>> q;

        set<string> st;

        for(auto& i: wordList) {
            st.insert(i);
        }

        q.push({beginWord, 1});

        while(!q.empty()) {
            auto t = q.front();
            q.pop();
            string curr = t.first;
            int depth = t.second;

            for(int i=0; i<wl; i++) {
                auto orgi = curr;
                for(char ch='a'; ch <= 'z'; ch++) {
                    curr[i] = ch;
                    if(st.find(curr) != st.end()) {
                        if(curr == endWord) {
                            return depth+1;
                        }
                        q.push({curr, depth+1});
                        st.erase(curr);
                    }
                }
                curr = orgi;
            }
        }

        return 0;
    }
};
