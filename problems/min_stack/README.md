# Min Stack

## Leetcode Link: [Min Stack](https://leetcode.com/problems/min-stack/)
### Language: C++

```cpp
class MinStack {
public:
    vector<pair<int,int>> st;
    int currMin;
	
    MinStack() {
        currMin = INT_MAX;
    }
    
    void push(int val) {
        currMin = min(currMin, val);
        if(st.empty()){
            // if no element that is the min element
            st.push_back({val,val});
        }
        else {
            // basically if we take a item the .second will have the min element till tht point
            // So we can just check it its min and update the .sec of new val accordingly
            st.push_back({val,min(st.back().second,val)});    
        }
    }
    
    void pop() { 
        st.pop_back();
        return;
    }
    
    int top() { 
        return st.back().first; 
    }
    
    int getMin() { 
        return st.back().second; 
    }
};```



