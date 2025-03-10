/*class Solution {
public:
    int getVowelIndex(char a) {
        if(a == 'a') {
            return 0;
        } else if(a == 'e') {
            return 1;
        } else if(a == 'i') {
            return 2;
        } else if(a == 'o') {
            return 3;
        } else if(a == 'u') {
            return 4;
        }

        return -1;
    }

    void check(unordered_map<int, int> &mp) {
        int c = 0;

        for(auto &[k, v]: mp) {
            if(v >= 1) {
                c++;
            }
        }

        return c == 5;
    }

    long long countOfSubstrings(string word, int k) {
        int n = word.size();
        unordered_map<int, int> mp;
        int l = 0;
        for(int r=0; r<k+5-1; r++) {
            if(getVowelIndex(word[r]) != -1) {
                mp[getVowwlIndex(word[i])]++;
            }
        }  

        for(int r=(k+5-1); r<n; r++) {
            int v = getVowelIndex(word[r]);

            if(v != -1) {
                mp[v]++;
            }

            if(check(mp)){
                ans++;
            }

            if(getVowelIndex(word[l]) != -1) {
                mp[getVowwlIndex(word[l])]--;
            }
            l++;
        }
    }
};*/

class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    long long atLeastK(string& word, int k) {
        int n = word.size();
        long long ans = 0;
        int consonants = 0;
        int left = 0;
        unordered_map<char, int> vowel_map;

        for (int right = 0; right < n; right++) {
            if (isVowel(word[right])) {
                vowel_map[word[right]]++;
            } else {
                consonants++;
            }

            while (vowel_map.size() == 5 && consonants >= k) {
                ans += n - right;
                if (isVowel(word[left])) {
                    vowel_map[word[left]]--;
                    if (vowel_map[word[left]] == 0) {
                        vowel_map.erase(word[left]);
                    }
                } else {
                    consonants--;
                }
                left++;
            }
        }
        return ans;
    }

    long long countOfSubstrings(string word, int k) {
        return atLeastK(word, k) - atLeastK(word, k + 1);
    }
};
