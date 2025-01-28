class NumArray {
    int n;
    vector<int> segTree;

public:
    void buildSegTree(vector<int>& nums, int i, int l, int r) {
        if (l == r) {
            segTree[i] = nums[l];
            return;
        }

        int mid = l + (r - l) / 2;
        buildSegTree(nums, 2 * i + 1, l, mid);
        buildSegTree(nums, 2 * i + 2, mid + 1, r);

        segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
    }

    NumArray(vector<int>& nums) {
        this->n = nums.size();
        segTree = vector<int>(4 * n);
        buildSegTree(nums, 0, 0, n - 1);
    }

    void updateSeg(int& idx, int& val, int i, int l, int r) {
        if (l == r and l == idx) {
            segTree[i] = val;
            return;
        }

        int mid = l + (r - l) / 2;
        if (idx <= mid) {
            updateSeg(idx, val, 2 * i + 1, l, mid);
        } else {
            updateSeg(idx, val, 2 * i + 2, mid + 1, r);
        }

        segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
    }

    void update(int index, int val) {
        updateSeg(index, val, 0, 0, n-1);
    }

    int rangeSum(int i, int l, int r, int& left, int& right) {
        if (l > right or r < left) {
            return 0;
        }

        if (l >= left and r <= right) {
            return segTree[i];
        }

        int mid = l + (r - l) / 2;

        return rangeSum(2 * i + 1, l, mid, left, right) +
               rangeSum(2 * i + 2, mid + 1, r, left, right);
    }

    int sumRange(int left, int right) {
        return rangeSum(0, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */