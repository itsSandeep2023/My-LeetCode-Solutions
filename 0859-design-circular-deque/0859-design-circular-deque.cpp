class MyCircularDeque {
    vector<int> dq;
    int f;
    int r;
    int c;
    int k;

public:
    MyCircularDeque(int k) {
        this->k = k;
        dq = vector<int>(k, 0);
        c = 0;
        f = 0;
        r = k - 1;
    }

    bool insertFront(int value) {
        if (isFull())
            return false;

        f = (f - 1 + k) % k;
        dq[f] = value;
        c++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull())
            return false;

        r = (r + 1) % k;
        dq[r] = value;
        c++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty())
            return false;

        f = (f + 1) % k;
        c--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty())
            return false;

        r = (r - 1 + k) % k;
        c--;
        return true;
    }

    int getFront() {
        if (isEmpty())
            return -1;
        return dq[f];
    }

    int getRear() {
        if (isEmpty())
            return -1;
        return dq[r];
    }

    bool isEmpty() { return c == 0; }

    bool isFull() { return c == k; }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */