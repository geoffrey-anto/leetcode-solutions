#define it(v) begin(v), end(v)
class Solution {
public:
    bool diff(string &a, string &b) {
        int d = (stoi(a) - stoi(b));

        // 0123
        // 0232

        return d < 100;
    }
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        sort(it(access_times),  [&](const vector<string> &a, const vector<string>& b){
            if(a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });

        unordered_set<string>ans;

        for(int i=0; i+2<access_times.size(); i++) {

            string& name = access_times[i][0];
            
            if(ans.find(name) != ans.end()) {
                continue;
            }

            // check for the 2rd element after the 
            if(access_times[i+2][0] != name) {
                continue;
            }

            if(diff(access_times[i+2][1], access_times[i][1])) {
                ans.insert(access_times[i][0]);
            }
        }


        return vector<string>(it(ans));
    }
};
