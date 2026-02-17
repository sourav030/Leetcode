class Node {
public:
    int key, value;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        value = v;
        prev = next = nullptr;
    }
};

class LRUCache {
public:
    int capacity;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;

    LRUCache(int cap) {
        capacity = cap;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertAtHead(Node* node) {
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];
        remove(node);
        insertAtHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->value = value;
            remove(node);
            insertAtHead(node);
        } else {
            if (mp.size() == capacity) {
                Node* lru = tail->prev;
                mp.erase(lru->key);
                remove(lru);
                delete lru;
            }
            Node* node = new Node(key, value);
            mp[key] = node;
            insertAtHead(node);
        }
    }
};
