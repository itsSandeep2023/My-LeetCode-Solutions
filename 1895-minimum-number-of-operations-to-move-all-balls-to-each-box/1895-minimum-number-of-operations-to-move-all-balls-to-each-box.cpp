class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> l(n+1);
        int csum{0};
        for(int i{0}; i<n; i++)
        {
            csum += boxes[i]=='1'?1:0;
            l[i+1] = l[i] + csum;
        }

        vector<int> r(n+1);
        csum = 0;
        for(int i{n-1}; i>=0; i--)
        {
            csum+=boxes[i]=='1'?1:0;
            r[i] = r[i+1] + csum;
        }

        vector<int> ans(n);

        for(int i{0}; i<n; i++)
        {
            ans[i] = l[i] + r[i+1];
        }


        return ans;
    }
};