class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n);
        int l{0}, csum{0};
        for (int i{0}; i < n; i++) {
            ans[i]=l;
            csum += boxes[i] == '1' ? 1 : 0;
            l += csum;
        }

        csum = 0;
        int r{0};
        for (int i{n - 1}; i >= 0; i--) {
            ans[i]+=r;
            csum += boxes[i] == '1' ? 1 : 0;
            r += csum;
        }

        return ans;
    }
};