class Node {
    private:
    int n = 26;

    public:
    Node* ref[26];
    int prefix;
    int end;

    string word;

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

    void setEnd(string &w) {
        word = w;
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
        temp->setEnd(s);
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
    vector<string> st;
    void f(int i, int j, vector<vector<char>> &board, Node* t, int n, int m, int l = 0) {
        if(i < 0 or i == n or j < 0 or j == m) {
            return;
        }

        if(board[i][j] == '{' or !t->contains(board[i][j])) {
            return;
        }
        
        char c = board[i][j];
        t = t->get(board[i][j]);
        board[i][j] = '{';

        if(t->word.size() != 0) {
            st.push_back(t->word);
            t->word = "";
        }

        f(i+1, j, board, t, n, m, l+1);
        f(i-1, j, board, t, n, m, l+1);
        f(i, j+1, board, t, n, m, l+1);
        f(i, j-1, board, t, n, m, l+1);

        board[i][j] = c;
        
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* t = new Trie();

        for(auto &i: words) {
            t->insert(i);
        }

        int n = board.size();
        int m = board[0].size();


        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                f(i, j, board, t->root, n, m);
            }
        }

        return st;
    }
};
