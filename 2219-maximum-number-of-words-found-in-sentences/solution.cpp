class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int n=sentences.size();
        int mx;
        for(auto i:sentences){
            int c=0;
            for(char j:i){
                if(isspace(j)){
                    c++;
                }
            }
            mx=max(mx,c);
        }
        return mx+1;
    }
};
