class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int x,xi,y,yi;
        sscanf(num1.c_str(), "%d+%di",&x,&xi);
        sscanf(num2.c_str(), "%d+%di",&y,&yi);
        string ans = to_string(x*y-xi*yi)+"+"+to_string(xi*y+yi*x)+"i";
        return ans;
    }
};