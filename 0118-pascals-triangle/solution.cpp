class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows==1){
            vector<vector<int>> ans={{1}};
            return ans;
        }
        vector<vector<int>> ans={{1},{1,1}};
        if(numRows==2){
            return ans;
        }
        int n=1;
        for(int i=0;i<numRows-2;i++){
            vector<int> temp;
            temp.push_back(1);
            for(int j=0;j<n;j++){
                temp.push_back(ans[n][j]+ans[n][j+1]);
            }
            temp.push_back(1);
            n++;
            ans.push_back(temp);
        }
        return ans;
    }
};
