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
    int NUM_DIGITS_MAX = 10;

    long long f(vector<vector<long long>> &cnt, int sz) {
        long long ans = 0;

        // basically we get the product of all other counts with a selected digit at ith pos

        // we get the answer in the pairs reversed too so / by 2

        for (int i = 0; i < sz; i++) {
            for (int x = 0; x < NUM_DIGITS_MAX; x++) {
                for (int y = 0; y < NUM_DIGITS_MAX; y++) {
                    if (x == y) {
                        continue;
                    }
                    ans += cnt[i][x] * cnt[i][y];
                }
            }
        }


        return ans / 2;
    }
    long long sumDigitDifferences(vector<int>& nums) {
        int n = nums.size();

        if(n < 2) {
            return 0;
        }


        string s = to_string(nums[0]);


        int sz = s.size();



        vector<vector<long long>> cnt(sz, vector<long long>(NUM_DIGITS_MAX, 0));





        for(int i=0; i<n; i++) {
            for(int j=0; j<sz; j++) {
                cnt[j][to_string(nums[i])[j] - '0']++;
            }
        }

        return f(cnt, sz);
    }
};
