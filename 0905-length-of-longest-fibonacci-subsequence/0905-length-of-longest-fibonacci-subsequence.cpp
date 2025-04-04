class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> st;
        
        for(auto &x : arr)
        {
            st.insert(x);
        }

        int ans{2};

        unordered_map<int ,int> mp;

        for(int i{0}; i<n; i++)
        {
            for(int j{i+1}; j<n; j++)
            {
                int a = arr[i];
                int b = arr[j];
                int c = a + b;

                int cnt{2};

                while(st.count(c))
                {
                    if(mp[a] == b)
                    {
                        cout<<"b"<<" -> "<<a<<" "<<b<<endl;
                        break;
                    }
                    mp[a] = b;
                    cnt++;
                    a=b;
                    b=c;
                    c=a+b;
                }

                ans = max(ans, cnt);
            }
        }

        return ans>2?ans:0;
    }
};