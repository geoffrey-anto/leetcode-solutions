class Node {
    private:
    int n = 26;

    public:
    Node* ref[26];
    int prefix;
    int end;
    int val = INT_MAX;

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

    void setEnd(int cost) {
        val = min(this->val, cost);
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

    void insert(string &s, int cost) {
        Node* temp = root;

        for(auto &ch: s) {
            if(!temp->contains(ch)) {
                Node* node = new Node();
                temp->set(ch, node);
            }
            temp = temp->get(ch);
            temp->setPrefix();
        }
        temp->setEnd(cost);
    }

    pair<int, int> countWordsEqualTo(string &s) {
        Node* temp = root;

        for(auto &ch: s) {
            if(!temp->contains(ch)) {
                return {0, 0};
            }
            temp = temp->get(ch);
        }

        return {temp->getEnd(), temp->val};
    }

    pair<int, int> countWordsStartingWith(string &s) {
        Node* temp = root;

        for(auto &ch: s) {
            if(!temp->contains(ch)) {
                return {0, 0};
            }
            temp = temp->get(ch);
        }

        return {temp->getPrefix(), temp->val};
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
    int f(int i, string &target, Node* t, vector<int> &dp) {
        if(i == target.size()) {
            return 0;
        }

        if(dp[i] != -1) {
            return dp[i];
        }

        int ans = 1e9;
        Node* temp = t;

        for(int j=i; j<target.size(); j++) {
            if(!temp->contains(target[j])) {
                break;
            }

            temp = temp->get(target[j]);
            if(temp->val != INT_MAX)
                ans = min(ans, temp->val + f(j+1, target, t, dp));
        }

        return dp[i] = ans;
    }

    int minimumCost(string &target, vector<string>& words, vector<int>& costs) {
        Trie* t = new Trie();
        int x = 0;

        for(auto &i: words) {
            t->insert(i, costs[x]);
            x++;
        }

        vector<int> dp(target.size() + 2, -1);
        Node* node = t->root;

        for(int i=target.size() - 1; i>=0; i--) {
            int ans = 1e9;

            Node* temp = node;

            for(int j=i; j<target.size(); j++) {
                if(!temp->contains(target[j])) {
                    break;
                }

                temp = temp->get(target[j]);
                if(temp->val != INT_MAX){
                    ans = min(ans, temp->val + dp[j+1]);
                }
            }

            dp[i] = ans;
        }

        int ans = dp[0];

        // int ans = f(0, target, t->root, dp);

        return ans == 1e9 ? -1 : ans + 1;
    }
};
