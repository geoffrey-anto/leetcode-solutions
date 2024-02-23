struct Node {
	Node *links[26];
	bool flag = false;

	bool containKey(char ch) {
		return (links[ch - 'a'] != NULL);
	}

	void put(char ch, Node *node) {
		links[ch - 'a'] = node;
	}

	Node *get(char ch) {
		return links[ch - 'a'];
	}

	void setEnd() {
		flag = true;
	}

	bool isEnd() {
		return flag;
	}
};
class Trie {
private:
	Node* root;
public:
	Trie() {

		root = new Node();
	}

	void insert(string word) {

		Node *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->containKey(word[i])) {
				node->put(word[i], new Node());
			}

			node = node->get(word[i]);
		}
		node->setEnd();
	}

	bool search(string word) {
		Node *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->containKey(word[i])) {
				return false;
			}
			node = node->get(word[i]);
		}
		return node->isEnd();
	}

	bool startsWith(string prefix) {
		Node* node = root;
		for (int i = 0; i < prefix.size(); i++) {
			if (!node->containKey(prefix[i])) {
				return false;
			}
			node = node->get(prefix[i]);
		}
		return true;
	}

    bool query(string &s) {
        auto temp = root;
        for(int i=s.size()-1; i>=0; i--) {
            if(!temp->containKey(s[i])) {
                return false;
            }

            temp = temp->get(s[i]);

            if(temp->isEnd()) {
                return true;
            }
        }

        return false;
    }
};

class StreamChecker {
public:
    Trie* t;
    string s = "";

    StreamChecker(vector<string>& words) {
        t = new Trie();

        for(auto &word: words) {
            reverse(word.begin(), word.end());
            t->insert(word);
        }
    }
    
    bool query(char letter) {
        s += letter;

        return t->query(s);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
