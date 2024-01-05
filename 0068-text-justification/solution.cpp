class Solution {
public:
    string pad(vector<string> words, int s, bool isLast) {
        int n = words.size();
        int sz = 0;
        for(auto &i: words) {
            sz += i.size();
        }

        int rem  = s - sz;

        if(isLast) {
            string ans = "";

            for(auto &i: words) {
                ans += i;
                if(rem > 0) {
                    ans += " ";
                    rem--;
                }
            }
            while(rem > 0) {
                ans += " ";
                rem--;
            }
            

            return ans;
        } else {
            if((n-1) == 0) {
                string ans = "";

                ans += words[0];

                for(int i=0; i<rem; i++) {
                    ans += " ";
                }

                return ans;
            }
            if(rem % (n-1) == 0) {
                int c = rem / (n-1);

                string ans = "";
                int cnt = 0;

                for(auto &i: words) {
                    ans += i;
                    cnt++;

                    if(cnt == n) {
                        break;
                    }

                    for(int i=0; i<c; i++) {
                        ans += " ";
                    }
                }
                return ans;
            } else {
                int mod = rem % (n-1);
                int c = rem / (n-1);
                string ans = "";
                int cnt = 0;

                for(auto &i: words) {
                    ans += i;
                    cnt++;

                    if(cnt == n) {
                        break;
                    }

                    for(int i=0; i<c; i++) {
                        ans += " ";
                    }

                    if(mod != 0) {
                        ans += " ";
                        mod--;
                    }
                }

                return ans;
            }
        }
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string> ans;
        vector<string> temp;
        int sz = 0;

        for(int i=0; i<n; i++) {
            if(sz + words[i].size() + temp.size() > maxWidth) {
                ans.push_back(pad(temp, maxWidth, false));
                temp.clear();
                sz = 0;
                temp.push_back(words[i]);
                sz += words[i].size();
                if(i == n - 1) {
                    ans.push_back(pad(temp, maxWidth, true));
                    temp.clear();
                    sz = 0;
                }
                continue;
            }

            if(i == n - 1) {
                temp.push_back(words[i]);
                sz += words[i].size();
                ans.push_back(pad(temp, maxWidth, true));
                temp.clear();
                sz = 0;
                break;
            }

            temp.push_back(words[i]);
            sz += words[i].size();
        }

        return ans;
    }
};
