class Solution {
public:
    string interpret(string command) {
        int n = command.size();
        string ans;
        for(int i=0;i<n;i++){
            if(command[i] == 'G'){
                ans+=command[i];
                continue;
            } else if(command[i] == '(' and command[i+1] == ')'){
                ans=ans+'o';
                i=i+1;
            } else if(command[i] == '(' and command[i+1] == 'a'){
                ans=ans+"al";
                i=i+3;
            }
        }
        return ans;
    }
};
