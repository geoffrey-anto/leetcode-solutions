class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> s;

        stringstream ss(sentence);

        string buf;

        while(ss >> buf) {
            s.push_back(buf);
        }

        for(int i=0; i<s.size(); i++) {
            if(searchWord.size() > s[i].size()) {
                continue;
            }

            bool f = false;

            for(int j=0; j<searchWord.size(); j++) {
                if(s[i][j] != searchWord[j]) {
                    f = true;
                    break;
                }
            }

            if(!f)
                return i + 1;
        }

        return -1;
    }
}; 
