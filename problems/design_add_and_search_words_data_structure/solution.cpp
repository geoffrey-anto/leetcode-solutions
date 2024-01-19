class Node {
    public:
    bool f = false;
    Node* ref[26];

    Node(){
        for(int i=0; i<26; i++) {
            ref[i] = NULL;
        }
    }

    bool contains(char c) {
        return (ref[c - 'a'] != NULL);
    }

    void insert(char c) {
        ref[c - 'a'] = new Node();
    }

    Node* getNode(char c) {
        return ref[c - 'a'];
    }

    void setEnd() {
        f = true;
    }

    bool isEnd() {
        return f;
    }

    vector<Node*> getNotNullNodes() {
        vector<Node*> ans;
        for(int i=0; i<26; i++) {
            if(ref[i] != nullptr) {
                ans.push_back(ref[i]);
            }
        }
        return ans;
    }
};

class Trie {
    public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void Add(string s) {
        Node* temp = root;

        for(auto c: s) {
            if(!temp->contains(c)) {
                temp->insert(c);
            }
            temp = temp->getNode(c);
        }
        
        temp->setEnd();
    } 

    bool search(string word) {
        Node* temp = root;
        return _search(word, temp);
    }

    bool _search(string word, Node* node) {
        for (int i = 0; i<word.size() && node; i++) {
            if (word[i] != '.') {
                node = node->getNode(word[i]);
            } else {
                Node* tmp = node;
                for (char j='a'; j <= 'z'; j++) {
                    node = tmp->getNode(j);
                    if (_search(word.substr(i+1), node)) {
                        return true;
                    }
                }
            }
        }
        return node && node->isEnd();
    }
};

class WordDictionary {
public:
    Trie t;
    WordDictionary() {
        Trie t = Trie();
    }
    
    void addWord(string word) {
        t.Add(word);
    }
    
    bool search(string word) {
        return t.search(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */