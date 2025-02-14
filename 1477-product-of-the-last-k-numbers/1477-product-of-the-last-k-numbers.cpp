class ProductOfNumbers {
    vector<int> nums{1};

public:
    ProductOfNumbers() {}

    void add(int num) {
        if (num != 0)
            nums.push_back(nums.back() * num);
        else {
            nums.clear();
            nums.push_back(1);
        }
    }

    int getProduct(int k) {
        int n = nums.size();
        return k < n ? nums.back() / nums[n - 1 - k] : 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */