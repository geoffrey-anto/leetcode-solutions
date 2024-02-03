class Node {
    public:
    Node* ref[26];
    bool f;
    int cp;

    Node() {
        f = false;
        for(auto &r: ref) {
            r = NULL;
        }
        cp = 0;
    }

    bool isValid(char a) {
        return (ref[a - 'a'] != NULL);
    }

    Node* get(char a) {
        return ref[a - 'a'];
    }

    void put(char a, Node* n) {
        ref[a - 'a'] = n;
    }

    bool getEnd() {
        return f;
    }

    void setEnd() {
        f = true;
    }

    void clearEnd() {
        f = true;
    }

    void incPrefixCount() {
        cp++;
    }

    int getPrefixCount() {
        return cp;
    }
};

class Trie {
    public:
    Node* ref;

    Trie() {
        ref = new Node();
    }

    void insert(string s) {
        Node* temp = ref;

        for(int i=0; i<s.size(); i++) {
            if(!(temp->isValid(s[i]))) {
                Node* nw = new Node();
                temp->put(s[i], nw);
            }
            temp = temp->get(s[i]);
            temp->incPrefixCount();
        }

        temp->setEnd();
    }

    string getMaxPrefix(int n, int lim) {
        Node* temp = ref;
        string ans = "";
        int count = 0;

        while(true){
            if(count == lim) {
                break;
            }
            int cnt = -1;
            int pos = -1;

            for(int i=0; i<26; i++) {
                if(temp->isValid((char)('a'+i))) {
                    int c = temp->get((char)('a'+i))->getPrefixCount();
                    if(c == n) {
                        cnt = c;
                        pos = i;
                    }
                }
            }

            if(cnt == n) {
                ans += (char)('a'+pos);
            } else {
                break;
            }
            temp = temp->get((char)('a'+pos));
            count ++;
        }

        return ans;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie t = Trie();

        for(auto &i: strs) {
            t.insert(i);
        }

        string ans = t.getMaxPrefix(strs.size(), (*max_element(begin(strs), end(strs))).size());

        return ans;
    }
};
