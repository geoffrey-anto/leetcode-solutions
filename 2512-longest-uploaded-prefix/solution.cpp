class LUPrefix {
    unordered_set<int> st;
    int n;
    int curr;
public:
    LUPrefix(int n) {
        this->n = n;
        this->curr = 0;
        return;
    }
    
    void upload(int video) {
        this->st.insert(video);
    }
    
    int longest() {
        while(this->st.count(this->curr + 1) > 0) {
            this->curr += 1;
        }

        return this->curr;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */
