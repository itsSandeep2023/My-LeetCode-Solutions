class Solution {
    unordered_set<string> res;
    int n;

public:
    void solve(string& tiles, vector<bool>& ids, string& cur)
    {
        for (int i{0}; i < n; i++) {
            if (ids[i] == false) {
                cur.push_back(tiles[i]);
                if(!res.count(cur))
                {
                    res.insert(cur);
                    ids[i] = true;
                    solve(tiles, ids, cur);
                    ids[i] = false;
                }
                cur.pop_back();
            }
        }
    }

    int numTilePossibilities(string tiles) {
        n = tiles.size();
        vector<bool> ids(n, false);
        string cur;
        solve(tiles, ids, cur);
        return res.size();
    }
};