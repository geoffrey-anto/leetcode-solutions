class StockSpanner {
    stack<pair<int, int>> st;
    int i;
public:
    StockSpanner() {
        i = 0;
        st = stack<pair<int, int>>();
    }
    
    int next(int price) {
        // if empty at first make a new entry and push and return 1 since this is the first
        if (st.empty()) {
            st.push(std::make_pair(price, i++));
            return 1;
        } else {
            // now pop out till u find the element which is greater than the curr
            while(!st.empty() and st.top().first <= price) st.pop();
            
            // if no ele in stack we push the prev span along with value and inc. span
            if(st.empty()) {
                st.push(make_pair(price, i));
                i++;
                return i;
            } else {
                // if elem we get the prev span from the top then push a new record with curr price
                // and the span value 
                int val = i - st.top().second;
                st.push(make_pair(price, i));
                i++;
                return  val;
            }
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */