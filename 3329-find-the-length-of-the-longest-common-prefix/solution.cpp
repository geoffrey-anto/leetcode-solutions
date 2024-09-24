#include<bits/stdc++.h>
using namespace std;

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

    int getLongestPre(string &s) {
        Node* temp = root;
        int ans = 0;
        for(auto &ch: s) {
            if(!temp->contains(ch)) {
                return ans;
            }

            ans++;
            temp = temp->get(ch);
        }

        return ans;
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
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie* t = new Trie();

        if(arr1.size() > arr2.size()) {
            swap(arr1, arr2);
        }

        for(auto i: arr1) {
            string temp = to_string(i);

            t->insert(temp);
        }

        int ans = 0;

        for(auto i: arr2) {
            string temp = to_string(i);

            ans = max(ans, t->getLongestPre(temp));
        }

        return ans;
    }
};
