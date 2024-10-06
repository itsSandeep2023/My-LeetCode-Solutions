class Solution {
public:
    void go(vector<int>& cnd, int& target, int idx, int cursum, vector<vector<int>>& res, vector<int> &vec)
    {
        if(cursum == target)
        {
            res.push_back(vec);
            return;
        }

        if(idx>=cnd.size() or cursum>target) return;

        
        vec.push_back(cnd[idx]);
        go(cnd, target, idx, cursum + cnd[idx], res, vec);
        vec.pop_back();
        go(cnd, target, idx + 1, cursum, res, vec);
    }
    
    vector<vector<int>> combinationSum(vector<int>& cnd, int target) {
        ios::sync_with_stdio(false);
        
        vector<vector<int>> res;
        vector<int> vec;
        int cursum{0};

        go(cnd, target, 0, cursum, res, vec);

        return res;
    }
};