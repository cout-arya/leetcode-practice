class LRUCache {
public:
    class Node {
    public:
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int _key, int _val) {
            key = _key;
            val = _val;
            next = nullptr;
            prev = nullptr;
        }
    };
    Node* head;
    Node* tail;
    int cap;
    unordered_map<int, Node*> mp;

    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    void addNode(Node* newNode) {
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }
    void deleteNode(Node* delNode) {
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }
    int get(int key_) {
        if (mp.find(key_) != mp.end()) {
            Node* resNode = mp[key_];
            int res = resNode->val;
            mp.erase(key_);
            deleteNode(resNode);
            addNode(resNode);
            mp[key_] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key_, int value) {
        if (mp.find(key_) != mp.end()) {
            Node* existingNode = mp[key_];
            mp.erase(key_);
            deleteNode(existingNode);
        }
        if (mp.size() == cap) {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key_, value));
        mp[key_] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */