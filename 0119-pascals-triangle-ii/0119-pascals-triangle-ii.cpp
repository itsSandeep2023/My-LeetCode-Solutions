class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(1,1);

        for(int i{0}; i<rowIndex; i++)
        {
            int n = ans.size();
            if(i&1)
                ans.push_back(ans.back()*2);
            for(int j{n-1}; j>0; j--)
            {
                ans[j]+=ans[j-1];
            }
            for(auto& x : ans)
                cout<<x<<" ";
            cout<<endl;
        }

        int n = ans.size();
        if(rowIndex&1)
            ans.push_back(ans.back());
        
        for(int i{n-2}; i>=0; i--)
            ans.push_back(ans[i]);

        return ans;
    }
};