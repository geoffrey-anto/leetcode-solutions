class Solution {
public:
    void insert(priority_queue<int> &pq, int k, int v) {
        while(k--) {
            pq.push(v);
        }
    }
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        priority_queue<int> pq;
        
        insert(pq, numOnes, 1);
        insert(pq, numZeros, 0);
        insert(pq, numNegOnes, -1);
        
        int sum = 0;
        
        while(k--) {
            sum += pq.top();
            pq.pop();
        }
        
        return sum;
    }
};
