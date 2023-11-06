class MedianFinder {
public:
    double median;
    priority_queue<int> q1;
    priority_queue<int,vector<int>,greater<int>> q2;
    MedianFinder() {
        median=0;
    }

    
    void addNum(int num) {
        int n = q1.size();
        int m = q2.size();
        if(n == m) {
            if(num > median){
                q2.push(num);
                median = q2.top();
            }
            else{
                q1.push(num);
                median = q1.top();
            }
        } else if(n > m) {
            if(num > median){
                q2.push(num);
            }
            else{
                q2.push(q1.top());
                q1.pop();
                q1.push(num);
            }
        } else {
            if(num > median){
                q1.push(q2.top());
                q2.pop();
                q2.push(num);
            }
            else{
                q1.push(num);
            }
        }

        if(n!=m) {
            median = (q2.top() + q1.top())/2.0;
        }
    }
    
    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
