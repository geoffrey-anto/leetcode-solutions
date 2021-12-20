class CustomStack {
    int maxSize;
    vector<pair<int,int>> stack;
public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if(stack.size() == maxSize) return;
        stack.push_back({x,0});
    }
    
    int pop() {
        if(stack.empty()) return -1;
        auto [a,b] = stack.back(); stack.pop_back();
        if(!stack.empty()) stack.back().second += b;
        return a+b;
    }
    
    void increment(int k, int val) {
        if(stack.empty()) return;
        stack[min(int(stack.size()-1), k-1)].second += val;
    }
};