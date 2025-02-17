class Solution {
    unordered_set<string> res;
    int n;
public:
    void solve(string &tiles, vector<bool> &ids, string& cur, int idx)
    {
        if(idx>=n)
        {
            if(!res.count(cur))
            {
                res.insert(cur);
                cout<<cur<<" ";

            }
            return;
        }

        for(int i{0}; i<n; i++)
        {
            if(ids[i]==false)
            {
                cur.push_back(tiles[i]);
                ids[i]=true;
                solve(tiles, ids, cur, idx+1);
                cur.pop_back();
                ids[i]=false;
            }
        }

        solve(tiles, ids, cur, idx+1);
    }

    int numTilePossibilities(string tiles) {
        n = tiles.size();
        vector<bool> ids(n, false);
        string cur;
        solve(tiles, ids, cur, 0);
        return res.size()-1;
    }
};