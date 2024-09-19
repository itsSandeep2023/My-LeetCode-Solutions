class Solution {
public:
    vector<int> diffWaysToCompute(string exp) {
        vector<int> res;

        for (int i{0}; i < exp.size(); i++) {
            if (exp[i] == '+' or exp[i] == '-' or exp[i] == '*') {
                vector<int> l_res = diffWaysToCompute(exp.substr(0, i));
                vector<int> r_res =
                    diffWaysToCompute(exp.substr(i + 1, exp.size()));

                for (int& x : l_res) {
                    for (int& y : r_res) {
                        if (exp[i] == '+') {
                            res.push_back(x + y);
                        } else if (exp[i] == '-') {
                            res.push_back(x - y);
                        } else if (exp[i] == '*') {
                            res.push_back(x * y);
                        }
                    }
                }
            }
        }

        if (res.empty())
            return {stoi(exp)};

        return res;
    }
};