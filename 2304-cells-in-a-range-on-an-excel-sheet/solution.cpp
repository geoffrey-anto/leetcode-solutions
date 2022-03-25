class Solution {
public:
    vector<string> cellsInRange(string s) {
        int c1,c2;
        int r1,r2;
        c1=(int)s[0];
        c2=(int)s[3];
        r1=(int)s[1];
        r2=(int)s[4];
        vector<string> v;
        for(int i=c1;i<=c2;i++){
            for(int j=r1;j<=r2;j++){
                string x="";
                x+=(char)i;
                x+=(char)j;
                v.push_back(x);
            }
        }
        return v;
    }
};
