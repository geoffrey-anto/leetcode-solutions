class MyCalendarTwo {
    vector<pair<int, int>> s;
    vector<pair<int, int>> d;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for (auto i : d) {
            if (i.first < end && i.second > start) {
                return false;
            }
        }

        for (auto i : s) {
            if (i.first < end && i.second > start) {
                d.push_back(make_pair(max(i.first, start), min(i.second, end)));
            } else {
                continue;
            }
        }

        s.push_back(make_pair(start, end));
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
