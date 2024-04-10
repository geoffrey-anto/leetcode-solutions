class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(begin(deck), end(deck), greater<int>());

        deque<int> ans;

        ans.push_back(deck[0]);

        for(int i=1; i<deck.size(); i++) {
            auto temp = ans.back();
            ans.pop_back();
            ans.push_front(temp);
            ans.push_front(deck[i]);
        }

        vector<int> res;

        while(ans.size() != 0) {
            res.push_back(ans.front());
            ans.pop_front();
        }

        return res;
    }
};
