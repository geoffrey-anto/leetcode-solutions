// struct node{
//     char val;
//     int freq;
// };

// class cmpr{
//     public:
//     bool operator()(node &a, node &b){
//         if(a.freq<b.freq){
//             return true;
//         }
//         return false;
//     }
// };

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(int i = 0; i < s.size(); i++)
            mp[s[i]]++;
        
         sort(s.begin(), s.end(), [&](char a, char b) -> bool {
           return (mp[a] != mp[b]? mp[a] > mp[b] : a < b);
        });
        
        return s;
        // priority_queue<node, vector<node>, cmpr> pq;
        // for(auto &i:map){
        //     node temp;
        //     temp.val=i.first;
        //     temp.freq=i.second;
        //     int x = temp.freq;
        //     while(x--){
        //         pq.push(temp);
        //     }
        // }
        // string ans;
        // while(!pq.empty()){
        //     ans+=pq.top().val;
        //     pq.pop();
        // }
        // return ans;
    }
};