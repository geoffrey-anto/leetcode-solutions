class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int &i:stones){
            pq.push(i);
        }
        while(pq.size()>1){
            int x,y;
            x = pq.top();
            pq.pop();
            y = pq.top();
            pq.pop();
            if(x==y){
                continue;
            }
            pq.push(x-y);
        }
        if(pq.size()==0){
            return 0;
        }
        return pq.top();
    }
};