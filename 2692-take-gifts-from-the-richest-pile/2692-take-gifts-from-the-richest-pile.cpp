class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        ios::sync_with_stdio(false);

        priority_queue<int> pq;

        long long ans{0};

        for (auto& x : gifts) {
            pq.push(x);
        }

        while (k--) {
            pq.push(sqrt(pq.top()));
            pq.pop();
        }

        while (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};