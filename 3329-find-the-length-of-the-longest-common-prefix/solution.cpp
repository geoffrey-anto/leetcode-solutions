class Node {
    private:
    int n = 10;

    public:
    Node* ref[10];
    int prefix;
    int end;

    Node() {
        memset(ref, 0, sizeof(ref));
        prefix = 0;
        end = 0;
    }

    bool contains(char a) {
        return (ref[a - '0'] != nullptr);
    }

    void set(char a, Node* node) {
        ref[a - '0'] = node;
    }

    Node* get(char a) {
        return ref[a - '0'];
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

    void insert(string &s) {
        Node* temp = root;

        for(auto &ch: s) {
            if(!temp->contains(ch)) {
                Node* node = new Node();
                temp->set(ch, node);
            }
            temp = temp->get(ch);
            temp->setPrefix();
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

    int getLongestPrefix(string &s) {
        Node* temp = root;

        int mx = 0;

        for(auto &ch: s) {
            if(!temp->contains(ch)) {
                return mx;
            }
            temp = temp->get(ch);
            mx++;
        }

        return mx;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie* t = new Trie();

        for(auto &i: arr1) {
            string s = to_string(i);
            t->insert(s);
        }

        int mx = 0;

        for(auto &i: arr2) {
            string s = to_string(i);
            mx = max(mx, t->getLongestPrefix(s));
        }

        return mx;
    }
};
