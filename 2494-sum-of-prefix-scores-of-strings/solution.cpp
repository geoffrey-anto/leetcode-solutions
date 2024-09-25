#include<bits/stdc++.h>
using namespace std;

class Node {
    private:
    int n = 26;

    public:
    Node* ref[26];
    int prefix;
    int end;

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

    void insert(string &s) {
        Node* temp = root;

        for(auto &ch: s) {
            if(!temp->contains(ch)) {
                Node* node = new Node();
                temp->set(ch, node);
            }
            temp->get(ch)->setPrefix();
            temp = temp->get(ch);
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

    int countPrefixScore(string &s) {
        Node* temp = root;
        int ans = 0;

        for(auto &ch: s) {
            ans += temp->get(ch)->getPrefix();
            temp = temp->get(ch);
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();

        Trie* t = new Trie();

        for(auto &i: words) {
            t->insert(i);
        }

        vector<int> ans;

        for(auto &i: words) {
            int cnt = t->countPrefixScore(i);

            ans.push_back(cnt);
        }

        return ans;
    }
};
