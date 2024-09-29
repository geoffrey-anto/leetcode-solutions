class AllOne {
    map<int, unordered_set<string>> strings;
    unordered_map<string, int> freq;
    int minCount = INT_MAX;
    int maxCount = 0;
public:
    AllOne() {
        
    }
    
    void inc(string key) {
        if(freq.find(key) == freq.end()) {
            freq[key] = 1;
            strings[1].insert(key);
        } else {
            int f = freq[key];

            strings[f].erase(key);
            strings[f + 1].insert(key);
            freq[key]++;

            if(strings[f].empty()) {
                strings.erase(f);
            }

            maxCount = max(maxCount, freq[key]);
            minCount = min(minCount, freq[key]);
        }

    }
    
    void dec(string key) {
        int f = freq[key];

        if(f == 1) {
            strings[f].erase(key);

            if(strings[f].empty()) {
                strings.erase(f);
            }

            freq.erase(key);
        } else {
            strings[f].erase(key);
            strings[f-1].insert(key);
            freq[key]--;

            if(strings[f].empty()) {
                strings.erase(f);
            }

            minCount = min(minCount, freq[key]);
            maxCount = max(maxCount, freq[key]);
        }
        
    }
    
    string getMaxKey() {
        if(freq.empty()) {
            return "";
        }

        return (*strings.rbegin()->second.begin());
    }
    
    string getMinKey() {
        if(freq.empty()) {
            return "";
        }

        return (*strings.begin()->second.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
