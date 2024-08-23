class Solution {
public:
    string fractionAddition(string expression) {
        ios::sync_with_stdio(false);
        
        int nume = 0;
        int deno = 1;

        int i{0};
        int n = expression.size();
        while (i < n) {
            int curNume{0};
            int curDeno{0};

            bool isNeg = (expression[i] == '-');

            if (expression[i] == '-' or expression[i] == '+')
                i++;

            while (i < n and isdigit(expression[i])) {
                curNume = curNume * 10 + (expression[i] - '0');
                i++;
            }

            if (isNeg)
                curNume *= -1;

            i++;

            while (i < n and isdigit(expression[i])) {
                curDeno = curDeno * 10 + (expression[i] - '0');
                i++;
            }

            nume = nume * curDeno + curNume * deno;
            deno = deno * curDeno;
        }

        int GCD = abs(__gcd(nume, deno));
        nume /= GCD;
        deno /= GCD;

        return to_string(nume) + '/' + to_string(deno);
    }
};