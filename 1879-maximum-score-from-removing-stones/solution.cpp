class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> pq;
        int score=0;
        pq.push(a);
        pq.push(b);
        pq.push(c);
        while(pq.size()>1){
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            x-=1;
            y-=1;
            if(x>0){
                pq.push(x);
            }
            if(y>0){
                pq.push(y);
            }
            score++;
        }
        return score;
    }
};
