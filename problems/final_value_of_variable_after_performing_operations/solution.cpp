class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int n=operations.size();
        int operation=0;
        for(int i=0;i<n;i++){
            if(operations[i]=="++X" or operations[i]=="X++"){
                operation++;
            }
            if(operations[i]=="--X" or operations[i]=="X--"){
                operation--;
            }
        }
        return operation;
    }
};