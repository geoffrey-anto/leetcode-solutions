class Solution {
public: 
    int minimumDeletions(string word, int k) {
        map<char, int> mp;
        
        for(auto i: word) {
            mp[i]++;
        }
        
        vector<int> freq;

        for(auto &[k, v]: mp) {
            freq.push_back(v);
        }

        int cnt = INT_MAX;
        int sum = 0;
        sort(begin(freq), end(freq));

        for(int i=0; i<freq.size(); i++) {
            int curr = 0;
            for(int j=freq.size()-1; j>=i; j--) {
                curr += max(0, freq[j]-freq[i] - k);
            }
            cnt = min(cnt, curr+sum);
            sum += freq[i];
        }

        return cnt;
    }
};
