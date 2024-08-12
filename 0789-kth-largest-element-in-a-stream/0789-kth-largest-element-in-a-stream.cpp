class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> q;
    int n;

    KthLargest(int k, vector<int>& nums) {
        ios::sync_with_stdio(false);
        
        n = k;
        for(const auto& x: nums){
            q.push(x);

            if(q.size()>k)
            {
                q.pop();
            }
        }
    }
    
    int add(int val) {
        q.push(val);

        if(q.size()>n)
            q.pop();

        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */