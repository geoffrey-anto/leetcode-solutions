class Solution {
public:
    int minTimeToType(string word) {
        int time=0;
        char curr='a';
        for(auto &i:word){
            int forward = abs(int(i)-int(curr));
            int backward = 26 - abs(int(i)-int(curr));
            time += min(forward,backward);
            curr=i;
            time++;
        }
        return time;
    }
};
