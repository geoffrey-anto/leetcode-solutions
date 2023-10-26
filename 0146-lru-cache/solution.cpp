// Basically maintain a DLL of size capacity
// if put element is already there leave it else append to head 
// if it exceded the cap remove tail and append
// for get if not tjere return -1
// if there remove the ele and append to head
// return the value at key

// For searching in the list use a map to make it faster

class Node {
    public:
    Node* prev;
    Node* next;
    int val;
    int i;

    Node() {
        prev=NULL;
        next=NULL;
        val = 0;
        i=0;
    }

    Node(int v) {
        prev=NULL;
        next=NULL;
        val = v;
    }

    Node(int x, int v) {
        prev=NULL;
        next=NULL;
        val = v;
        i = x;
    }

    Node(Node* p, Node* n, int v) {
        prev=p;
        next=n;
        val = v;
    }
};

class LRUCache {
    void addNode(Node* newnode){
        Node* temp = head->next;

        newnode->next = temp;
        newnode->prev = head;

        head->next = newnode;
        temp->prev = newnode;
    }

    void deleteNode(Node* delnode){
        Node* prevv = delnode->prev;
        Node* nextt = delnode->next;

        prevv->next = nextt;
        nextt->prev = prevv;
    }

public:
    int c;
    Node* head;
    Node* tail;

    unordered_map<int, Node*> mp;
    LRUCache(int capacity) {
        this->c = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;

    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        } else {
            Node* temp = mp[key];
            int ans = temp->val;

            mp.erase(key);
            deleteNode(temp);
            addNode(temp);

            mp[key] = head->next;
            return ans;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* curr = mp[key];
            mp.erase(key);
            deleteNode(curr);
        }

        if(mp.size() == c){
            mp.erase(tail->prev->i);
            deleteNode(tail->prev);
        }

        Node* temp = new Node(key, value);

        addNode(temp);
        mp[key] = head->next;

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
