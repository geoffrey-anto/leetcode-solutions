class Solution {
public:
    string customSortString(string order, string s) {
        int n = s.length();
        int m = order.length();

        unordered_map<char, int> cache;

        auto comp = [&](const char &a, const char &b) {
            if(cache.find(a) == cache.end()) {
                cache[a] = order.find(a);
            }
            if(cache.find(b) == cache.end()){
                cache[b] = order.find(b);
            }
            
            return cache[a] < cache[b];
        };

        sort(s.begin(), s.end(), comp);

        return s;
    }
};
