class ComparisonClass {
public:
    bool operator() (vector<int> &pt1, vector<int> &pt2){
        return pow(pt1[0],2)+pow(pt1[1],2) > pow(pt2[0],2)+pow(pt2[1],2);
    }
};


class Solution {
public:
    
//     static bool euclidean(vector<int> &pt1, vector<int> &pt2){
//         return pow(pt1[0],2)+pow(pt1[1],2) < pow(pt2[0],2)+pow(pt2[1],2);
//     }
        
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>,vector<vector<int>>, ComparisonClass> pq;
        for(vector<int> &i:points){
            pq.push(i);
        }
        vector<vector<int>> ans;
        for(int i=0;i<k;i++){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};
