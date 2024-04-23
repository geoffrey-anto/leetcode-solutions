#include<bits/stdc++.h>
using namespace std;

class Node {
    private:
    int n = 26;

    public:
    Node* ref[26];
    int prefix;
    int end;

    priority_queue<int> top3;

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

    void setPrefix(int v) {
        top3.push(v);
        if(top3.size() > 3) {
            top3.pop();
        }
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

    priority_queue<int> getPrefix() {
        return top3;
    }
};

class Trie {
    public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(string &s, int v) {
        Node* temp = root;

        for(auto &ch: s) {
            if(!temp->contains(ch)) {
                Node* node = new Node();
                temp->set(ch, node);
            }
            temp = temp->get(ch);
            temp->setPrefix(v);
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

    priority_queue<int> countWordsEqualToPre(string &s) {
        Node* temp = root;

        for(auto &ch: s) {
            if(!temp->contains(ch)) {
                return priority_queue<int>();
            }
            temp = temp->get(ch);
        }

        return temp->getPrefix();
    }

    int countWordsStartingWith(string &s) {
        Node* temp = root;

        for(auto &ch: s) {
            if(!temp->contains(ch)) {
                return 0;
            }
            temp = temp->get(ch);
        }

        return temp->getEnd();
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
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie* t = new Trie();

        sort(products.begin(), products.end());

        map<int, string> ref;
        map<string, int> mp;

        int c = 0;

        for(auto i: products) {
            ref[c] = i;
            mp[i] = c;
            c++;
        }

        c = 0;

        for(auto &i: products) {
            t->insert(i, c);
            c++;
        }

        string s = "";

        vector<vector<string>> ans;

        for(int i=0; i<searchWord.size(); i++) {
            s += searchWord[i];

            auto a = t->countWordsEqualToPre(s);

            vector<string> temp;

            while(!a.empty()) {
                temp.push_back(ref[a.top()]);
                a.pop();

            }

            reverse(begin(temp), end(temp));

            ans.push_back(temp);
        }

        return ans;
    }
};
