class AllOne {
    struct Node {
        int count;
        list<string> keys;
        Node *prev, *next;
        Node(int c) : count(c), prev(nullptr), next(nullptr) {}
    };

    unordered_map<string, Node*> mp;

    Node *head, *tail;
    void addNode(Node* prevNode, int count) {
        Node* newNode = new Node(count);
        newNode->next = prevNode->next;
        newNode->prev = prevNode;
        if (newNode->next) {
            newNode->next->prev = newNode;
        }

        prevNode->next = newNode;
        if (prevNode == tail) {
            tail = newNode;
        }
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        if (node->next != nullptr) {
            node->next->prev = node->prev;
        }

        if (node == tail) {
            tail = node->prev;
        }

        delete node;
    }

public:
    AllOne() {
        head = new Node(0);
        tail = head;
    }


    void inc(string key) {
        if (!mp.count(key)) {
            if (head->next == nullptr or head->next->count != 1) {
                addNode(head, 1);
            }

            head->next->keys.push_front(key);
            mp[key] = head->next;
        } else {
            Node* curNode = mp[key];
            int curCount = curNode->count;
            if (curNode->next == nullptr or
                curNode->next->count != curCount + 1) {
                addNode(curNode, curCount + 1);
            }

            curNode->next->keys.push_front(key);
            mp[key] = curNode->next;
            curNode->keys.remove(key);
            if (curNode->keys.empty()) {
                removeNode(curNode);
            }
        }
    }

    void dec(string key) {
        Node* curNode = mp[key];
        int curCount = curNode->count;

        if (curCount == 1) {
            mp.erase(key);
        } 
        else {
            if (curNode->prev->count != curCount - 1) {
                addNode(curNode->prev, curCount - 1);
            }

            curNode->prev->keys.push_front(key);
            mp[key] = curNode->prev;
        }
        curNode->keys.remove(key);
        if (curNode->keys.empty()) {
            removeNode(curNode);
        }
    }

    string getMaxKey() {
        if (tail == head)
            return "";

        return tail->keys.front();
    }

    string getMinKey() {
        if (!head->next)
            return "";

        return head->next->keys.front();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */