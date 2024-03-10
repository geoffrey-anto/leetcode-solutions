class Node {
    public:
    Node* ref[26];
    int index;
    vector<int> list;
    
    Node() {
        index = -1;
        list = vector<int>();
        memset(ref, 0, sizeof(ref));
    }
};

class Solution {
public:
    Node* t;

    vector<vector<int>> palindromePairs(vector<string>& w) {
        t = new Node();
        vector<vector<int>> res;

        for (int i = 0; i < w.size(); i++) {
            addWord(t, w[i], i);
        }

        for (int i = 0; i < w.size(); i++) {
            search(w, i, t, res);
        }

        return res;
    }

private:
    void addWord(Node* t, string& word, int index) {
        for (int i = word.length() - 1; i >= 0; i--) {
            int j = word[i] - 'a';

            if (t->ref[j] == nullptr) {
                t->ref[j] = new Node();
            }

            if (isPalindrome(word, 0, i)) {
                t->list.push_back(index);
            }

            t = t->ref[j];
        }

        t->list.push_back(index);
        t->index = index;
    }

    void search(vector<string>& w, int i, Node* t, vector<vector<int>>& res) {
        for (int j = 0; j < w[i].length(); j++) {  
            if (t->index >= 0 and t->index != i and isPalindrome(w[i], j, w[i].length() - 1)) {
                res.push_back({i, t->index});
            }

            if (!t->ref[w[i][j] - 'a']) return; 
            t = t->ref[w[i][j] - 'a'];
        }

        for (int j : t->list) {
            if (i == j) continue;
            res.push_back({i, j});
        }
    }

    bool isPalindrome(string& word, int i, int j) {
        while (i < j) {
            if (word[i++] != word[j--]) return false;
        }

        return true;
    }
};
