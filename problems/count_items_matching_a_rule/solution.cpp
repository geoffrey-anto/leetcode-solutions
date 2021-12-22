class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int n=items.size();
        int m=3;
        int c=0;
        for(auto &i:items){
            if(ruleKey=="type" and ruleValue==i[0]){
                c++;
                continue;
            }
            if(ruleKey=="color" and ruleValue==i[1]){
                c++;
                continue;
            }
            if(ruleKey=="name" and ruleValue==i[2]){
                c++;
                continue;
            }
        }
        return c;
    }
};