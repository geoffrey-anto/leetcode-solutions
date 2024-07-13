#include<bits/stdc++.h>
using namespace std;

char op(char a) {
    if(a == '0') {
        return '1';
    } else {
        return '0';
    }
}

string getBin(int x){
    string s="";
    while(x>0){
        if(x%2==0){
            s.push_back('0');

        }
        else s.push_back('1');
        x/=2;
    }

    while(s.size()<32){
        s.push_back('0');
    }

    reverse(s.begin(),s.end());

    return s;
}

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
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* t = new Trie();
        vector<string> s;

        for(auto i: nums) {
            string a = getBin(i);
            s.push_back(a);

            t->insert(a);
        }

        Node* internalRoot = t->root;

        int ans = 0;

        for(auto i: s) {
            Node* root = internalRoot;

            int res = 0;

            for(int x=0; x<=31; x++) {
                char curr = i[x];

                if(root->contains(op(curr))) {
                    res = res << 1;
                    res = res | 1;
                    root = root->get(op(curr));
                } else {
                    res = res << 1;
                    res = res | 0;
                    root = root->get(curr);
                }
            }

            ans = max(ans, res);
        }

        return ans;
    }
};
