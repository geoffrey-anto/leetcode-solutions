class Node {
    private:
    int n = 26;
    unordered_map<string, Node*> ref;
    int prefix;
    int end;

    public:
    Node() {
        prefix = 0;
        end = 0;
    }

    bool contains(string &a) {
        return (ref.count(a) > 0);
    }

    void set(string &a, Node* node) {
        ref[a] = node;
    }

    Node* get(string &a) {
        return ref[a];
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

    int insert(string &s) {
        Node* temp = root;
        int n = s.size();

        for(int i=0; i<n; i++) {
            string ch = "";
            ch += s[i];
            ch += s[n - i - 1];
            if(!temp->contains(ch)) {
                Node* node = new Node();
                temp->set(ch, node);
            }
            temp = temp->get(ch);
            temp->setPrefix();
        }
        
        return temp->getPrefix() - 1;
    }

};

class Solution {
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        long long ans = 0;

        Trie* t = new Trie();

        for(int i=n-1; i>=0; i--) {
            ans += (long long)t->insert(words[i]);
        }

        return ans;
    }
};
