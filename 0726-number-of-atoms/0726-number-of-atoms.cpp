class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.size();

        stack<unordered_map<string, int>> st;
        st.push(unordered_map<string, int>());

        int i{0};
        while (i < n) {
            if (formula[i] == '(') {
                st.push(unordered_map<string, int>());
                i++;
            } else if (formula[i] == ')') {
                unordered_map<string, int> curr = st.top();
                st.pop();
                i++;

                string mult;
                while (i < n and isdigit(formula[i])) {
                    mult += formula[i];
                    i++;
                }

                if (!mult.empty()) {
                    int mi = stoi(mult);
                    for (auto& it : curr) {
                        curr[it.first] = it.second * mi;
                    }
                }

                for (auto& it : curr) {
                    st.top()[it.first] += it.second;
                }
            } else {
                string curstr;
                curstr.push_back(formula[i++]);
                while (i < n and isalpha(formula[i]) and islower(formula[i])) {
                    curstr.push_back(formula[i++]);
                }

                string curcnt;
                while (i < n and isdigit(formula[i])) {
                    curcnt += formula[i++];
                }

                int curcntint = !curcnt.empty() ? stoi(curcnt) : 1;
                st.top()[curstr] += curcntint;
            }
        }

        map<string, int> smp(st.top().begin(), st.top().end());
        string ans;

        for (auto& it : smp) {
            ans += it.first;
            if (it.second > 1) {
                ans += to_string(it.second);
            }
        }

        return ans;
    }
};