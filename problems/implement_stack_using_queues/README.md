# Implement Stack Using Queues

## Leetcode Link: [Implement Stack Using Queues](https://leetcode.com/problems/implement-stack-using-queues/)
### Language: C++

```cpp
// class MyStack {
// public:
//     queue<int> q1;
//     queue<int> q2;
//     int t;
//     MyStack() {
//     }
    
//     void push(int x) {
//         q1.push(x);
//         t = x;
//     }
    
//     int pop() {
//         // while q1 has more than 1 elem
//         while (q1.size() > 1) {
//             t = q1.front();
//             q1.pop();
//             q2.push(t);
//         }

//         int val = q1.front();

//         q1.pop();

//         swap(q1, q2);

//         return val;
//     }
    
//     int top() {
//         return t;
//     }
    
//     bool empty() {
//         return q1.empty();
//     }
// };

// /**
//  * Your MyStack object will be instantiated and called as such:
//  * MyStack* obj = new MyStack();
//  * obj->push(x);
//  * int param_2 = obj->pop();
//  * int param_3 = obj->top();
//  * bool param_4 = obj->empty();
//  */

class MyStack {
public:
    deque<int> q1;
    MyStack() {
    }
    
    void push(int x) {
        q1.push_back(x);
    }
    
    int pop() {
        int val = q1.back();
        q1.pop_back();
        return val;
    }
    
    int top() {
        return q1.back();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */```



