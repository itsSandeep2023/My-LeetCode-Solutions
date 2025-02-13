class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> q;

        for (auto& x : nums)
            q.push(x);

        int ans{0};
        while (q.size() > 1 and q.top() < k) {
            long long t = q.top() * 2;
            q.pop();
            t += q.top();
            q.pop();
            q.push(t);
            ans++;
        }

        return ans;
    }
};