class NumberContainers {
public:
    unordered_map<int, int> idxToNum;
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> numToIdx;

    NumberContainers() {}

    void change(int index, int number) {
        idxToNum[index] = number;
        numToIdx[number].push(index);
    }

    int find(int number) {
        if (!numToIdx.count(number)) {
            return -1;
        }

        auto& pq = numToIdx[number];

        while (!pq.empty()) {
            int idx = pq.top();

            if (idxToNum[idx] == number) {
                return idx;
            }

            pq.pop();
        }

        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */