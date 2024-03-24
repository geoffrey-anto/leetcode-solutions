class Node {
    private:
    int n = 26;

    public:
    Node* ref[26];
    int prefix;
    int end;
    int len = 6000;
    int idx = -1;

    Node() {
        memset(ref, 0, sizeof(ref));
        prefix = 0;
        end = 0;
    }

    bool contains(char a) {
        return (ref[a - 'a'] != nullptr);
    }

    void set(char a, Node* node) {
        ref[a - 'a'] = node;
    }

    Node* get(char a) {
        return ref[a - 'a'];
    } 

    void setPrefix() {
        prefix++;
    }

    void setEnd() {
        end++;
    }

    void eraseEnd() {
        end--;
    }

    void erasePrefix() {
        prefix--;
    }

    int getEnd() {
        return end;
    }

    int getPrefix() {
        return prefix;
    }
};

class Trie {
    public:
    Node* root;

    Trie() {
        root = new Node();
    }

    int getSuffix(string &s) {
        int v = 1e8;
        Node* temp = root;
        for(auto &ch: s) {
            if(!temp->contains(ch)) {
                return v;
            }

            temp = temp->get(ch);
            v = temp->idx;
        }

        return v;
    }

    void insert(string &s, int i) {
        Node* temp = root;

        for(auto &ch: s) {
            if(!temp->contains(ch)) {
                Node* node = new Node();
                temp->set(ch, node);
            }
            temp = temp->get(ch);
            temp->setPrefix();
            if(s.size() < temp->len) {
                temp->len = s.size();
                temp->idx = i;
            }
        }
        temp->setEnd();
    }

    int countWordsEqualTo(string &s) {
        Node* temp = root;

        for(auto &ch: s) {
            if(!temp->contains(ch)) {
                return 0;
            }
            temp = temp->get(ch);
        }

        return temp->getEnd();
    }

    int countWordsStartingWith(string &s) {
        Node* temp = root;

        for(auto &ch: s) {
            if(!temp->contains(ch)) {
                return 0;
            }
            temp = temp->get(ch);
        }

        return temp->getPrefix();
    }

    bool isPrefix(string &s) {
        Node* temp = root;

        for(auto &ch: s) {
            if(!temp->contains(ch)) {
                return false;
            }
            temp = temp->get(ch);
        }

        return true;
    }

    void erase(string &s) {
        Node* temp = root;

        for(auto &ch: s) {
            if(!temp->contains(ch)) {
                return;
            }

            temp = temp->get(ch);
            temp->erasePrefix();
        }

        temp->eraseEnd();
    }
};




















class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        Trie* t = new Trie();

        int n = wordsContainer.size();
        int mpos = 0;
        int mval = INT_MAX;

        for(int i=0; i<n; i++) {
            reverse(wordsContainer[i].begin(), wordsContainer[i].end());
            t->insert(wordsContainer[i], i);
            if(wordsContainer[i].size() < mval) {
                mval = wordsContainer[i].size();
                mpos = i;
            }
        }

        vector<int> ans;

        int m = wordsQuery.size();

        for(int i=0; i<m; i++) {
            reverse(wordsQuery[i].begin(), wordsQuery[i].end());
            int idx = t->getSuffix(wordsQuery[i]);

            if(idx == 1e8) {
                idx = mpos;
            } 

            ans.push_back(idx);
        }

        return ans;
    }
};
